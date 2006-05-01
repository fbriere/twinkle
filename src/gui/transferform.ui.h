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

void TransferForm::init()
{
	getAddressForm = 0;
	
	// Set toolbutton icons for disabled options.
	QIconSet i;
	i = addressToolButton->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("kontact_contacts-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	addressToolButton->setIconSet(i);
	
#ifndef HAVE_KDE
	addressToolButton->setEnabled(false);
#endif
}

void TransferForm::destroy()
{
	if (getAddressForm) {
		MEMMAN_DELETE(getAddressForm);
		delete getAddressForm;
	}
}

void TransferForm::show(t_user *user, const string &dest)
{
	user_config = user;
	toLineEdit->setText(dest.c_str());
	QDialog::show();
}

void TransferForm::reject()
{
	if (user_config->referrer_hold) {
		((t_gui *)ui)->action_retrieve();
	}
	
	QDialog::reject();
}

void TransferForm::validate()
{
	t_display_url dest;
	ui->expand_destination(user_config, toLineEdit->text().stripWhiteSpace().ascii(), dest);
	
	if (dest.is_valid()) {
		emit destination(dest);
		accept();
	} else {
		toLineEdit->selectAll();
	}
}

void TransferForm::closeEvent(QCloseEvent *)
{
	reject();
}

void TransferForm::showAddressBook()
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

void TransferForm::selectedAddress(const QString &address)
{
	toLineEdit->setText(address);
}
