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

#include "address_finder.h"
#include "gui.h"

t_address_finder *t_address_finder::instance = NULL;

t_address_finder::t_address_finder() {
#ifdef HAVE_KDE
	abook = KABC::StdAddressBook::self(false);
	connect(abook, 
		SIGNAL(addressBookChanged(AddressBook *)),
		this, SLOT(invalidate_cache()));
#endif
}

void t_address_finder::find_address(t_user *user_config, const t_url &u) 
{
	if (u == last_url) return;
	
	last_url = u;
	last_name.clear();
	last_photo = QImage();
	
#ifdef HAVE_KDE
	for (KABC::AddressBook::Iterator i = abook->begin(); i != abook->end(); i++)
	{
		// Normalize url using number conversion rules
		t_url u_normalized(u);
		string normalized_user = user_config->convert_number(u.get_user());
		u_normalized.set_user(normalized_user);
		
		KABC::PhoneNumber::List phoneNrs = i->phoneNumbers();
		for (KABC::PhoneNumber::List::iterator j = phoneNrs.begin();
		j != phoneNrs.end(); j++)
		{
			QString phone = (*j).number();
			string full_address = ui->expand_destination(
					user_config, phone.ascii());
			
			t_url url_phone(full_address);
			if (!url_phone.is_valid()) continue;
			
			if (u_normalized.user_host_match(url_phone,
				user_config->get_remove_special_phone_symbols(),
				user_config->get_special_phone_symbols()))
			{
				last_name = i->realName().ascii();
				last_photo = i->photo().data();
				return;
			}
		}
	}
#endif
	
	return;
}

t_address_finder *t_address_finder::get_instance(void) {
	if (!instance) {
		instance = new t_address_finder();
		// No MEMMAN audit as this instance will only be
		// cleaned up by process termination.
	}
	
	return instance;
}

string t_address_finder::find_name(t_user *user_config, const t_url &u) {
	find_address(user_config, u);
	return last_name;
}

QImage t_address_finder:: find_photo(t_user *user_config, const t_url &u) {
	find_address(user_config, u);
	return last_photo;
}
	
void t_address_finder::invalidate_cache(void) {
	last_url.set_url("");
}
