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

void InviteForm::init()
{
	getAddressForm = 0;
	
	// Set toolbutton icons for disabled options.
	setDisabledIcon(addressToolButton, "kontact_contacts-disabled.png");
	
#ifndef HAVE_KDE
	addressToolButton->setEnabled(false);
#endif
}

void InviteForm::destroy()
{
	if (getAddressForm) {
		MEMMAN_DELETE(getAddressForm);
		delete getAddressForm;
	}
}

void InviteForm::clear()
{
	inviteComboBox->clearEdit();
	subjectLineEdit->clear();
	inviteComboBox->setFocus();
}

void InviteForm::show(t_user *user_config, const QString &dest, const QString &subject)
{
	((t_gui *)ui)->fill_user_combo(fromComboBox);
	
	// Select from user
	if (user_config) {
		for (int i = 0; i < fromComboBox->count(); i++) {
			if (fromComboBox->text(i) == 
			    user_config->get_profile_name().c_str())
			{
				fromComboBox->setCurrentItem(i);
				break;
			}
		}
	}
	
	inviteComboBox->setEditText(dest);
	subjectLineEdit->setText(subject);
	QDialog::show();
}

void InviteForm::validate()
{
	string display, dest_str;
	t_user *from_user = phone->ref_user_profile(
				fromComboBox->currentText().ascii());
	
	ui->expand_destination(from_user, 
			       inviteComboBox->currentText().stripWhiteSpace().ascii(), 
			       display, dest_str);
	t_url dest(dest_str);
	
	if (dest.is_valid()) {
		addToInviteComboBox(inviteComboBox->currentText());
		emit raw_destination(inviteComboBox->currentText());
		emit destination(from_user, display.c_str(), dest, subjectLineEdit->text());
		accept();
	} else {
		inviteComboBox->setFocus();
		inviteComboBox->lineEdit()->selectAll();
	}
}

// Add a destination to the history list of inviteComboBox
void InviteForm::addToInviteComboBox(const QString &destination)
{
	inviteComboBox->insertItem(destination, 0);
	if (inviteComboBox->count() > SIZE_REDIAL_LIST) {
		inviteComboBox->removeItem(inviteComboBox->count() - 1);
	}
}


void InviteForm::reject()
{
	// Unseize the line
	((t_gui *)ui)->action_unseize();
	QDialog::reject();
}

void InviteForm::closeEvent(QCloseEvent *)
{
	reject();
}

void InviteForm::showAddressBook()
{
	if (!getAddressForm) {
		getAddressForm = new GetAddressForm(
				this, "select address", true);
		MEMMAN_NEW(getAddressForm);
	}
	
	connect(getAddressForm, 
		SIGNAL(address(const QString &)),
		this, SLOT(selectedAddress(const QString &)));
	
	getAddressForm->show();
}

void InviteForm::selectedAddress(const QString &address)
{
	inviteComboBox->setEditText(address);
}
