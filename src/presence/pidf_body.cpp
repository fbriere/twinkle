/*
    Copyright (C) 2005-2008  Michel de Boer <michel@twinklephone.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "pidf_body.h"

#include <cassert>
#include <libxml/parser.h>

#include "log.h"
#include "audits/memman.h"

#define PIDF_XML_VERSION	"1.0"
#define PIDF_NAMESPACE		"urn:ietf:params:xml:ns:pidf"

#define IS_PIDF_TAG(node, tag)	((node)->type == XML_ELEMENT_NODE &&\
				(node)->ns &&\
				xmlStrEqual((node)->ns->href, BAD_CAST PIDF_NAMESPACE) &&\
				xmlStrEqual((node)->name, BAD_CAST (tag)))
				
#define IS_PIDF_ATTR(attr, attr_name) ((attr)->type == XML_ATTRIBUTE_NODE &&\
				 (attr)->ns &&\
				 xmlStrEqual((attr)->ns->href, BAD_CAST PIDF_NAMESPACE) &&\
				 xmlStrEqual((attr)->name, BAD_CAST (attr_name)))

bool t_pidf_xml_body::extract_status(void) {
	assert(pidf_doc);

	xmlNode *root_element = NULL;
	
	// Get root
	root_element = xmlDocGetRootElement(pidf_doc);
	if (!root_element) {
		log_file->write_report("PIDF document has no root element.",
			"t_pidf_xml_body::extract_status",
			LOG_NORMAL, LOG_WARNING);
		return false;
	}
	
	// Check if root is <presence>
	if (!IS_PIDF_TAG(root_element, "presence")) {
		log_file->write_report("PIDF document has invalid root element.",
			"t_pidf_xml_body::extract_status",
			LOG_NORMAL, LOG_WARNING);
		return false;
	}
	
	
	
	pres_entity.clear();
	tuple_id.clear();
	basic_status.clear();
	
	// Get presence entity
	xmlChar *prop_entity = xmlGetProp(root_element, BAD_CAST "entity");
	if (prop_entity) {
		pres_entity = (char *)prop_entity;
	} else {
		log_file->write_report("Presence entity is missing.",
			"t_pidf_xml_body::extract_status",
			LOG_NORMAL, LOG_WARNING);
	}
	
	xmlNode *child = root_element->children;
	
	// Process children of root.
	for (xmlNode *cur_node = child; cur_node; cur_node = cur_node->next) {
		// Process tuple
		if (IS_PIDF_TAG(cur_node, "tuple")) {
			process_pidf_tuple(cur_node);
			
			// Process the first tuple and then stop.
			// Currently there is no support for multiple tuples
			// or additional elements.
			break;
		}
	}
	
	return true;
}

void t_pidf_xml_body::process_pidf_tuple(xmlNode *tuple) {
	assert(tuple);
	
	// Get tuple id.
	xmlChar *id = xmlGetProp(tuple, BAD_CAST "id");
	if (id) {
		tuple_id = (char *)id;
	} else {
		log_file->write_report("Tuple id is missing.",
			"t_pidf_xml_body::process_pidf_tuple",
			LOG_NORMAL, LOG_WARNING);
	}
	
	// Find status element
	xmlNode *child = tuple->children;
	for (xmlNode *cur_node = child; cur_node; cur_node = cur_node->next) {
		// Process status
		if (IS_PIDF_TAG(cur_node, "status")) {
			process_pidf_status(cur_node);
			break;
		}
	}
}

void t_pidf_xml_body::process_pidf_status(xmlNode *status) {
	assert(status);
	
	xmlNode *child = status->children;
	for (xmlNode *cur_node = child; cur_node; cur_node = cur_node->next) {
		// Process status
		if (IS_PIDF_TAG(cur_node, "basic")) {
			process_pidf_basic(cur_node);
			break;
		}
	}
}

void t_pidf_xml_body::process_pidf_basic(xmlNode *basic) {
	assert(basic);
	
	xmlNode *child = basic->children;
	if (child && child->type == XML_TEXT_NODE) {
		basic_status = (char*)child->content;
	} else {
		log_file->write_report("<basic> element has no content.",
			"t_pidf_xml_body::process_pidf_basic",
			LOG_NORMAL, LOG_WARNING);
	}
}

void t_pidf_xml_body::create_pidf(void) {
	clear_pidf();
	
	// XML doc
	pidf_doc = xmlNewDoc(BAD_CAST PIDF_XML_VERSION);
	MEMMAN_NEW(pidf_doc);
	pidf_doc->encoding = xmlCharStrdup("UTF-8");
	
	// presence
	xmlNode *node_presence = xmlNewNode(NULL, BAD_CAST "presence");
	xmlNs *ns_pidf = xmlNewNs(node_presence, BAD_CAST PIDF_NAMESPACE, NULL);
	xmlNewProp(node_presence, BAD_CAST "entity", BAD_CAST pres_entity.c_str());
	xmlDocSetRootElement(pidf_doc, node_presence);
	
	// tuple
	xmlNode *node_tuple = xmlNewChild(node_presence, ns_pidf, BAD_CAST "tuple", NULL);
	xmlNewProp(node_tuple, BAD_CAST "id", BAD_CAST tuple_id.c_str());
	
	// status
	xmlNode *node_status = xmlNewChild(node_tuple, ns_pidf, BAD_CAST "status", NULL);
	
	// basic
	xmlNode *node_basic = xmlNewChild(node_status, ns_pidf, 
		BAD_CAST "basic", BAD_CAST basic_status.c_str());
}

void t_pidf_xml_body::clear_pidf(void) {
	if (pidf_doc) {
		MEMMAN_DELETE(pidf_doc);
		xmlFreeDoc(pidf_doc);
		pidf_doc = NULL;
	}
}

t_pidf_xml_body::t_pidf_xml_body() : t_sip_body (),
	pidf_doc(NULL) 
{
}

t_pidf_xml_body::~t_pidf_xml_body() {
	clear_pidf();
}

string t_pidf_xml_body::encode(void) const {
	if (!pidf_doc) {
		t_pidf_xml_body *self = const_cast<t_pidf_xml_body *>(this);
		self->create_pidf();
	}
	assert(pidf_doc);
	
	xmlChar *buf;
	int buf_size;
	
	xmlDocDumpMemory(pidf_doc, &buf, &buf_size);
	string result((char*)buf);
	xmlFree(buf);
	
	return result;
}

t_sip_body *t_pidf_xml_body::copy(void) const {
	t_pidf_xml_body *body = new t_pidf_xml_body(*this);
	MEMMAN_NEW(body);
	
	if (pidf_doc) {
		body->pidf_doc = xmlCopyDoc(pidf_doc, 1);
		if (!body->pidf_doc) {
			log_file->write_report("Failed to copy pidf xml document.",
				"t_pidf_xml_body::copy",
				LOG_NORMAL, LOG_CRITICAL);
		} else {
			MEMMAN_NEW(body->pidf_doc);
		}
	}
	
	return body;
}

t_body_type t_pidf_xml_body::get_type(void) const {
	return BODY_PIDF_XML;
}

t_media t_pidf_xml_body::get_media(void) const {
	return t_media("application", "pidf+xml");
}

string t_pidf_xml_body::get_pres_entity(void) const {
	return pres_entity;
}

string t_pidf_xml_body::get_tuple_id(void) const {
	return tuple_id;
}

string t_pidf_xml_body::get_basic_status(void) const {
	return basic_status;
}

void t_pidf_xml_body::set_pres_entity(const string &_pres_entity) {
	clear_pidf();
	pres_entity = _pres_entity;
}

void t_pidf_xml_body::set_tuple_id(const string &_tuple_id) {
	clear_pidf();
	tuple_id = _tuple_id;
}

void t_pidf_xml_body::set_basic_status(const string &_basic_status) {
	clear_pidf();
	basic_status = _basic_status;
}

bool t_pidf_xml_body::parse(const string &s) {
	assert(pidf_doc == NULL);

	pidf_doc = xmlReadMemory(s.c_str(), s.size(), "noname.xml", NULL, 
		XML_PARSE_NOBLANKS | XML_PARSE_NOERROR | XML_PARSE_NOWARNING);
	if (!pidf_doc) {
		log_file->write_report("Failed to parse pidf xml document.",
			"t_pidf_xml_body::parse",
			LOG_NORMAL, LOG_WARNING);
	} else {
		MEMMAN_NEW(pidf_doc);
		if (!extract_status()) {
			MEMMAN_DELETE(pidf_doc);
			xmlFreeDoc(pidf_doc);
			pidf_doc = NULL;
		}
	}
	
	return (pidf_doc != NULL);
}
