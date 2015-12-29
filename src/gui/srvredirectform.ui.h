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


void SrvRedirectForm::init()
{
	cfAlwaysGroupBox->setEnabled(false);
	cfBusyGroupBox->setEnabled(false);
	cfNoanswerGroupBox->setEnabled(false);
}

void SrvRedirectForm::show()
{
	// Store previous values to restore when user cancels
	oldAlwaysActive = cfAlwaysCheckBox->isChecked();
	oldBusyActive = cfBusyCheckBox->isChecked();
	oldNoanswerActive = cfNoanswerCheckBox->isChecked();
	
	oldAlwaysDst1 = cfAlwaysDst1LineEdit->text();
	oldAlwaysDst2 = cfAlwaysDst2LineEdit->text();
	oldAlwaysDst3 = cfAlwaysDst3LineEdit->text();
	
	oldBusyDst1 = cfBusyDst1LineEdit->text();
	oldBusyDst2 = cfBusyDst2LineEdit->text();
	oldBusyDst3 = cfBusyDst3LineEdit->text();
	
	oldNoanswerDst1 = cfNoanswerDst1LineEdit->text();
	oldNoanswerDst2 = cfNoanswerDst2LineEdit->text();
	oldNoanswerDst3 = cfNoanswerDst3LineEdit->text();
	
	QDialog::show();
}

void SrvRedirectForm::cancel()
{
	// Restore old values
	cfAlwaysCheckBox->setChecked(oldAlwaysActive);
	cfBusyCheckBox->setChecked(oldBusyActive);
	cfNoanswerCheckBox->setChecked(oldNoanswerActive);
	
	cfAlwaysDst1LineEdit->setText(oldAlwaysDst1);
	cfAlwaysDst2LineEdit->setText(oldAlwaysDst2);
	cfAlwaysDst3LineEdit->setText(oldAlwaysDst3);
	
	cfBusyDst1LineEdit->setText(oldBusyDst1);
	cfBusyDst2LineEdit->setText(oldBusyDst2);
	cfBusyDst3LineEdit->setText(oldBusyDst3);
	
	cfNoanswerDst1LineEdit->setText(oldNoanswerDst1);
	cfNoanswerDst2LineEdit->setText(oldNoanswerDst2);
	cfNoanswerDst3LineEdit->setText(oldNoanswerDst3);
	
	reject();
}
		
void SrvRedirectForm::validate()
{
	list<t_url> cfDestAlways, cfDestBusy, cfDestNoanswer;
	bool valid = false;
	
	// Redirect unconditional
	valid = validate(cfAlwaysCheckBox->isChecked(), 
		 cfAlwaysDst1LineEdit, cfAlwaysDst2LineEdit, cfAlwaysDst3LineEdit,
		 cfDestAlways);
	if (!valid) {
		cfTabWidget->setCurrentPage(0);
		return;
	}
	
	// Redirect busy
	valid = validate(cfBusyCheckBox->isChecked(), 
		 cfBusyDst1LineEdit, cfBusyDst2LineEdit, cfBusyDst3LineEdit,
		 cfDestBusy);
	if (!valid) {
		cfTabWidget->setCurrentPage(1);
		return;
	}
	
	// Redirect no answer
	valid = validate(cfNoanswerCheckBox->isChecked(), 
		 cfNoanswerDst1LineEdit, cfNoanswerDst2LineEdit, 
		 cfNoanswerDst3LineEdit,
		 cfDestNoanswer);
	if (!valid) {
		cfTabWidget->setCurrentPage(2);
		return;
	}
	
	emit destinations(cfDestAlways, cfDestBusy, cfDestNoanswer);
	accept();
}


// Validate 3 destinations if cf_active is true.
// Returns true when all destinations are valid (first must be set, others may be empty)
// dest_list containst the encoded destinations when valid.
// If cf_active is false then the 3 destinations will be cleared.
bool SrvRedirectForm::validate(bool cf_active,
			       QLineEdit *dst1, QLineEdit *dst2, QLineEdit *dst3,
			       list<t_url> &dest_list)
{
	t_url destination;
	
	dest_list.clear();
	
	if (!cf_active) {
		dst1->clear();
		dst2->clear();
		dst3->clear();
		return true;
	}
	
	// 1st choice destination
	destination.set_url(ui->expand_destination(dst1->text().ascii()));
	if (destination.is_valid()) {
		dest_list.push_back(destination);
	} else {
		dst1->selectAll();
		return false;
	}
	
	// 2nd choice destination
	if (!dst2->text().isEmpty()) {
		destination.set_url(ui->expand_destination(
			dst2->text().ascii()));
		if (destination.is_valid()) {
			dest_list.push_back(destination);
		} else {
			dst2->selectAll();
			return false;
		}
	}
	
	// 3rd choice destination
	if (!dst3->text().isEmpty()) {
		destination.set_url(ui->expand_destination(
			dst3->text().ascii()));
		if (destination.is_valid()) {
			dest_list.push_back(destination);
		} else {
			dst3->selectAll();
			return false;
		}
	}
	
	return true;
}

void SrvRedirectForm::toggleAlways(bool on)
{
	if (on) {
		cfAlwaysGroupBox->setEnabled(true);
	} else {
		cfAlwaysGroupBox->setEnabled(false);
	}
}

void SrvRedirectForm::toggleBusy(bool on)
{
	if (on) {
		cfBusyGroupBox->setEnabled(true);
	} else {
		cfBusyGroupBox->setEnabled(false);
	}
}

void SrvRedirectForm::toggleNoanswer(bool on)
{
	if (on) {
		cfNoanswerGroupBox->setEnabled(true);
	} else {
		cfNoanswerGroupBox->setEnabled(false);
	}
}
