/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

/*
    Copyright (C) 2005-2006  Michel de Boer <michelboer@xs4all.nl>

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

#ifdef HAVE_KDE
#include <kabc/addressbook.h>
#include <kabc/addressee.h>
#include <kabc/addresseelist.h>
#include <kabc/phonenumber.h>
#include <kabc/stdaddressbook.h>

#define ABOOK	((KABC::AddressBook *)addrBook)
#endif

void GetAddressForm::init() 
{
#ifdef HAVE_KDE
	addrBook = (void *)KABC::StdAddressBook::self(false);
	loadAddresses();
	
	connect(ABOOK, 
		SIGNAL(addressBookChanged(AddressBook *)),
		this, SLOT(loadAddresses()));
	
	sipOnlyCheckBox->setChecked(sys_config->get_ab_show_sip_only());
#endif
}

void GetAddressForm::reload()
{
#ifdef HAVE_KDE
	ABOOK->disconnect();
	KABC::StdAddressBook::close();
	addrBook = (void *)KABC::StdAddressBook::self(false);
	loadAddresses();
	
	connect(ABOOK, 
		SIGNAL(addressBookChanged(AddressBook *)),
		this, SLOT(loadAddresses()));
#endif
}

void GetAddressForm::show()
{
#ifdef HAVE_KDE
	QDialog::show();
	
	if (addressListView->childCount() == 0) {
		QMessageBox::information(this, PRODUCT_NAME,
			"<p>"
			"You seem not to have any contacts with a phone number "
			"in <b>KAddressbook</b>, KDE's address book application. "
			"Twinkle retrieves all contacts with a phone number from "
			"KAddressbook. To manage your contacts you have to "
			"use KAddressbook."
			"</p>");
	}
#endif
}

void GetAddressForm::loadAddresses()
{
#ifdef HAVE_KDE
	// Explicit loading of address book is not needed as it is 
	// automatically loaded.
	// if (!ABOOK->load()) return;
	
	addressListView->clear();
	for (KABC::AddressBook::Iterator i = ABOOK->begin(); i != ABOOK->end(); i++)
	{
		KABC::PhoneNumber::List phoneNrs = i->phoneNumbers();
		for (KABC::PhoneNumber::List::iterator j = phoneNrs.begin();
		j != phoneNrs.end(); j++)
		{
			QString phone = (*j).number();
			if (!sys_config->get_ab_show_sip_only() ||
			    phone.startsWith("sip:"))
			{
				new QListViewItem(addressListView, i->realName(), 
					  (*j).typeLabel(), phone);
			}
		}
	}
	
	QListViewItem *first = addressListView->firstChild();
	if (first) addressListView->setSelected(first, true);
#endif
}

void GetAddressForm::selectAddress()
{
#ifdef HAVE_KDE
	int colName, colPhone;
	
	for (int i = 0; i < addressListView->columns(); i++) {
		if (addressListView->columnText(i) == "Name") {
			colName = i;
		} else if (addressListView->columnText(i) == "Phone") {
			colPhone = i;
		}
	}
	
	QListViewItem *item = addressListView->selectedItem();
	if (item) {
		QString name(item->text(colName));
		QString phone(item->text(colPhone));
		phone = phone.stripWhiteSpace();
			
		emit address(name, phone);
		
		// Signal display name and url combined.
		t_display_url du(t_url(phone.ascii()), name.ascii());
		emit address(du.encode().c_str());
	}
	
	accept();
#endif
}

void GetAddressForm::toggleSipOnly(bool on)
{
#ifdef HAVE_KDE
	string msg;
	
	sys_config->set_ab_show_sip_only(on);
	
	// Ignore write failures. If for some reason the system config
	// could not be written, then this settings is lost after exiting Twinkle.
	// No need to bother the user at this point.
	(void)sys_config->write_config(msg);
	
	loadAddresses();
#endif
}
