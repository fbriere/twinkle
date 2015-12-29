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
#define idxCatGeneral	0
#define idxCatAudio	1
#define idxCatLog		2

void SysSettingsForm::init()
{
#ifndef HAVE_KDE
	guiUseSystrayCheckBox->setEnabled(false);
	guiHideCheckBox->setEnabled(false);
	startHiddenCheckBox->setEnabled(false);
#endif
}

void SysSettingsForm::showCategory( QListBoxItem *item )
{
	if (item->text() == "General") {
		settingsWidgetStack->raiseWidget(pageGeneral);
	} else if (item->text() == "Audio") {
		settingsWidgetStack->raiseWidget(pageAudio);
	} else if (item->text() == "Log") {
		settingsWidgetStack->raiseWidget(pageLog);
	}
}

string SysSettingsForm::comboItem2audio_dev(QString item)
{
	for (list<t_audio_device>::iterator i = list_audio_dev.begin(); 
	i != list_audio_dev.end(); i++)
	{
		if (i->get_description() == item.ascii()) {
			return i->get_settings_value();
		}
	}
	
	return "";
}

void SysSettingsForm::populate()
{
	QString msg;
	int idx;
	
	// Select the Audio category
	categoryListBox->setSelected(idxCatGeneral, true);
	settingsWidgetStack->raiseWidget(pageGeneral);
	
	// Set focus on first field
	ringtoneComboBox->setFocus();
	
	// Audio settings
	list_audio_dev = sys_config->get_audio_devices();
	ringtoneComboBox->clear();
	speakerComboBox->clear();
	micComboBox->clear();
	idx = 0;
	for (list<t_audio_device>::iterator i = list_audio_dev.begin(); 
	i != list_audio_dev.end(); i++, idx++) {
		string item = i->get_description();
		ringtoneComboBox->insertItem(QString(item.c_str()));
		speakerComboBox->insertItem(QString(item.c_str()));
		micComboBox->insertItem(QString(item.c_str()));
		
		if (sys_config->dev_ringtone.device == i->device) {
			ringtoneComboBox->setCurrentItem(idx);
		}
		if (sys_config->dev_speaker.device == i->device) {
			speakerComboBox->setCurrentItem(idx);
		}
		if (sys_config->dev_mic.device == i->device) {
			micComboBox->setCurrentItem(idx);
		}
	}
	
	// Log settings
	logMaxSizeSpinBox->setValue(sys_config->log_max_size);
	logDebugCheckBox->setChecked(sys_config->log_show_debug);
	logSipCheckBox->setChecked(sys_config->log_show_sip);
	logStunCheckBox->setChecked(sys_config->log_show_stun);
	logMemoryCheckBox->setChecked(sys_config->log_show_memory);
	
	// General settings
#ifdef HAVE_KDE
	guiUseSystrayCheckBox->setChecked(sys_config->gui_use_systray);
	guiHideCheckBox->setChecked(sys_config->gui_hide_on_close);
	guiHideCheckBox->setEnabled(sys_config->gui_use_systray);
#endif
	
	// Call history
	histSizeSpinBox->setValue(sys_config->ch_max_size);
	
	// Startup settings
#ifdef HAVE_KDE
	startHiddenCheckBox->setChecked(sys_config->start_hidden);
#endif
	
	QStringList profiles;
	if (!SelectProfileForm::getUserProfiles(profiles, msg)) {
		((t_gui *)ui)->cb_show_msg(this, msg.ascii(), MSG_CRITICAL);
	}
	profileComboBox->clear();
	profileComboBox->insertItem("none");
	profileComboBox->setCurrentItem(0);
	idx = 1;
	for (QStringList::Iterator i = profiles.begin(); i != profiles.end(); i++, idx++) {
		// Strip off the .cfg suffix
		QString profile = *i;
		profile.truncate(profile.length() - 4);
		profileComboBox->insertItem(profile);
		if (sys_config->start_user_profile == profile.ascii()) {
			profileComboBox->setCurrentItem(idx);
		}
	}
	
	list<t_interface> *l = get_interfaces();
	// The socket routines are not under control of MEMMAN so report
	// the allocation here.
	MEMMAN_NEW(l);
	userHostComboBox->clear();
	userHostComboBox->insertItem("none");
	userHostComboBox->setCurrentItem(0);
	idx = 1;
	for (list<t_interface>::iterator i = l->begin(); i != l->end(); i++, idx++) {
		userHostComboBox->insertItem(i->get_ip_addr().c_str());
		if (sys_config->start_user_host == i->get_ip_addr()) {
			userHostComboBox->setCurrentItem(idx);
		}
	}
	delete l;
	MEMMAN_DELETE(l);
}

void SysSettingsForm::validate()
{
	// Audio
	string dev;
	dev = comboItem2audio_dev(ringtoneComboBox->currentText());
	if (dev != "") sys_config->dev_ringtone = sys_config->audio_device(dev);
	dev = comboItem2audio_dev(speakerComboBox->currentText());
	if (dev != "") sys_config->dev_speaker = sys_config->audio_device(dev);
	dev = comboItem2audio_dev(micComboBox->currentText());
	if (dev != "") sys_config->dev_mic = sys_config->audio_device(dev);
	
	// Log
	sys_config->log_max_size = logMaxSizeSpinBox->value();
	sys_config->log_show_debug = logDebugCheckBox->isChecked();
	sys_config->log_show_sip = logSipCheckBox->isChecked();
	sys_config->log_show_stun = logStunCheckBox->isChecked();
	sys_config->log_show_memory = logMemoryCheckBox->isChecked();
	
	// General
#ifdef HAVE_KDE
	sys_config->gui_use_systray = guiUseSystrayCheckBox->isChecked();
	sys_config->gui_hide_on_close = guiHideCheckBox->isChecked();
#endif
	
	// Call history
	sys_config->ch_max_size = histSizeSpinBox->value();

	// Startup
#ifdef HAVE_KDE
	sys_config->start_hidden = startHiddenCheckBox->isChecked() &&
				   guiUseSystrayCheckBox->isChecked();
#endif
	
	if (profileComboBox->currentItem() == 0) {
		sys_config->start_user_profile.clear();
	} else {
		sys_config->start_user_profile = profileComboBox->currentText().ascii();
	}
	
	if (userHostComboBox->currentItem() == 0) {
		sys_config->start_user_host.clear();
	} else {
		sys_config->start_user_host = userHostComboBox->currentText().ascii();
	}
	
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

int SysSettingsForm::exec()
{
	populate();
	return QDialog::exec();
}
