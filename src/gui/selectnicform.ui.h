/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, preserving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
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

void SelectNicForm::init()
{
	idxDefaultNic = -1;
}

void SelectNicForm::setAsDefault()
{
	// Only show the information when the default button is
	// pressed for the first time.
	if (idxDefaultNic == -1) {
		QMessageBox::information(this, PRODUCT_NAME,
			"If you want to remove or "
			"change the default at a later time, you can do that "
			"via the system settings.");
	}
	
	// Store current index as the changeItem method also changes
	// the current index as a side effect.
	int idxNewDefault = nicListBox->currentItem();
	
	// Restore pixmap of the old default
	if (idxDefaultNic != -1) {
		nicListBox->changeItem(
			QPixmap::fromMimeSource("kcmpci16.png"),
			nicListBox->text(idxDefaultNic),
			idxDefaultNic);
	}
	
	// Set pixmap of the default
	idxDefaultNic = idxNewDefault;
	nicListBox->changeItem(
		QPixmap::fromMimeSource("twinkle16.png"),
		nicListBox->text(idxDefaultNic),
		idxDefaultNic);	
	
	// Write default to system settings
	QStringList l = QStringList::split(':', nicListBox->currentText());
	sys_config->set_start_user_host(l[1].ascii());
	string error_msg;
	if (!sys_config->write_config(error_msg)) {
		// Failed to write config file
		((t_gui *)ui)->cb_show_msg(this, error_msg, MSG_CRITICAL);
	}
}
