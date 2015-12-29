/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, preserving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/
/*
    Copyright (C) 2005  Michel de Boer <michelboer@xs4all.nl>

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



void RedirectForm::validate()
{
	t_url destination;
	list<t_url> dest_list;
	
	// 1st choice destination
	destination.set_url(ui->expand_destination(contact1LineEdit->text().ascii()));
	if (destination.is_valid()) {
		dest_list.push_back(destination);
	} else {
		contact1LineEdit->selectAll();
		return;
	}
	
	// 2nd choice destination
	if (!contact2LineEdit->text().isEmpty()) {
		destination.set_url(ui->expand_destination(
			contact2LineEdit->text().ascii()));
		if (destination.is_valid()) {
			dest_list.push_back(destination);
		} else {
			contact2LineEdit->selectAll();
			return;
		}
	}
	
	// 3rd choice destination
	if (!contact3LineEdit->text().isEmpty()) {
		destination.set_url(ui->expand_destination(
			contact3LineEdit->text().ascii()));
		if (destination.is_valid()) {
			dest_list.push_back(destination);
		} else {
			contact3LineEdit->selectAll();
			return;
		}
	}
	
	emit destinations(dest_list);
	accept();
}
