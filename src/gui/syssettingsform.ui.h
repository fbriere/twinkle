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

// Indices of categories in the category list box
#define idxCatAudio	0
#define idxCatLog		1

void SysSettingsForm::showCategory( QListBoxItem *item )
{
	if (item->text() == "Audio") {
		settingsWidgetStack->raiseWidget(pageAudio);
	} else if (item->text() == "Log") {
		settingsWidgetStack->raiseWidget(pageLog);
	}
}

string SysSettingsForm::comboItem2oss_dev(QString item)
{
	for (list<t_oss_device>::iterator i = list_oss_dev.begin(); 
	i != list_oss_dev.end(); i++)
	{
		if (i->get_description() == item.ascii()) {
			return i->device;
		}
	}
	
	return "";
}

void SysSettingsForm::populate()
{
	// Select the Audio category
	categoryListBox->setSelected(idxCatAudio, true);
	settingsWidgetStack->raiseWidget(pageAudio);
	
	// Set focus on first field
	ringtoneComboBox->setFocus();
	
	// Audio settings
	list_oss_dev = sys_config->get_oss_devices();
	ringtoneComboBox->clear();
	speakerComboBox->clear();
	micComboBox->clear();
	int idx = 0;
	for (list<t_oss_device>::iterator i = list_oss_dev.begin(); 
	i != list_oss_dev.end(); i++, idx++) {
		string item = i->get_description();
		ringtoneComboBox->insertItem(QString(item.c_str()));
		speakerComboBox->insertItem(QString(item.c_str()));
		micComboBox->insertItem(QString(item.c_str()));
		
		if (sys_config->dev_ringtone == i->device) {
			ringtoneComboBox->setCurrentItem(idx);
		}
		if (sys_config->dev_speaker == i->device) {
			speakerComboBox->setCurrentItem(idx);
		}
		if (sys_config->dev_mic == i->device) {
			micComboBox->setCurrentItem(idx);
		}
	}
	
	// Log settings
	logMaxSizeSpinBox->setValue(sys_config->log_max_size);
	logDebugCheckBox->setChecked(sys_config->log_show_debug);
	logSipCheckBox->setChecked(sys_config->log_show_sip);
	logStunCheckBox->setChecked(sys_config->log_show_stun);
	logMemoryCheckBox->setChecked(sys_config->log_show_memory);
}

void SysSettingsForm::validate()
{
	// Audio
	string dev;
	dev = comboItem2oss_dev(ringtoneComboBox->currentText());
	if (dev != "") sys_config->dev_ringtone = dev;
	dev = comboItem2oss_dev(speakerComboBox->currentText());
	if (dev != "") sys_config->dev_speaker = dev;
	dev = comboItem2oss_dev(micComboBox->currentText());
	if (dev != "") sys_config->dev_mic = dev;
	
	// Log
	sys_config->log_max_size = logMaxSizeSpinBox->value();
	sys_config->log_show_debug = logDebugCheckBox->isChecked();
	sys_config->log_show_sip = logSipCheckBox->isChecked();
	sys_config->log_show_stun = logStunCheckBox->isChecked();
	sys_config->log_show_memory = logMemoryCheckBox->isChecked();
	
	// Save user config
	string error_msg;
	if (!sys_config->write_config(error_msg)) {
		// Failed to write config file
		((t_gui *)ui)->cb_show_msg(this, error_msg, MSG_CRITICAL);
		return;
	}
	
	accept();
}

void SysSettingsForm::show()
{
	populate();
	QDialog::show();
}


