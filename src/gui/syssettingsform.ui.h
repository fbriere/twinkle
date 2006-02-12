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

// Indices of categories in the category list box
#define idxCatGeneral	0
#define idxCatAudio	1
#define idxCatRingtones	2
#define idxCatNetwork	3
#define idxCatLog		4

void SysSettingsForm::init()
{
	// Set toolbutton icons for disabled options.
	QIconSet i;
	i = openRingtoneToolButton->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("fileopen-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	openRingtoneToolButton->setIconSet(i);
	i = openRingbackToolButton->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("fileopen-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	openRingbackToolButton->setIconSet(i);
}

void SysSettingsForm::showCategory( QListBoxItem *item )
{
	if (item->text() == "General") {
		settingsWidgetStack->raiseWidget(pageGeneral);
	} else if (item->text() == "Audio") {
		settingsWidgetStack->raiseWidget(pageAudio);
	} else if (item->text() == "Ring tones") {
		settingsWidgetStack->raiseWidget(pageRingtones);
	} else if (item->text() == "Network") {
		settingsWidgetStack->raiseWidget(pageNetwork);
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

void SysSettingsForm::populateComboBox(QComboBox *cb, const QString &s)
{
	for (int i = 0; i < cb->count(); i++) {
		if (cb->text(i) == s) {
			cb->setCurrentItem(i);
			return;
		}
	}
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
	
	reduceNoiseMicCheckBox->setChecked(sys_config->au_reduce_noise_mic);
	
	populateComboBox(ossFragmentComboBox, 
			 QString::number(sys_config->oss_fragment_size));
	populateComboBox(alsaPlayPeriodComboBox,
			 QString::number(sys_config->alsa_play_period_size));
	populateComboBox(alsaCapturePeriodComboBox,
			QString::number(sys_config->alsa_capture_period_size));
	
	// Log settings
	logMaxSizeSpinBox->setValue(sys_config->log_max_size);
	logDebugCheckBox->setChecked(sys_config->log_show_debug);
	logSipCheckBox->setChecked(sys_config->log_show_sip);
	logStunCheckBox->setChecked(sys_config->log_show_stun);
	logMemoryCheckBox->setChecked(sys_config->log_show_memory);
	
	// General settings
	guiUseSystrayCheckBox->setChecked(sys_config->gui_use_systray);
	guiHideCheckBox->setChecked(sys_config->gui_hide_on_close);
	guiHideCheckBox->setEnabled(sys_config->gui_use_systray);
	
	// Call history
	histSizeSpinBox->setValue(sys_config->ch_max_size);
	
	// Services
	callWaitingCheckBox->setChecked(sys_config->call_waiting);
	hangupBothCheckBox->setChecked(sys_config->hangup_both_3way);
	
	// Startup settings
	startHiddenCheckBox->setChecked(sys_config->start_hidden);
	
	QStringList profiles;
	if (!SelectProfileForm::getUserProfiles(profiles, msg)) {
		((t_gui *)ui)->cb_show_msg(this, msg.ascii(), MSG_CRITICAL);
	}
	profileListView->clear();
	for (QStringList::Iterator i = profiles.begin(); i != profiles.end(); i++) {
		// Strip off the .cfg suffix
		QString profile = *i;
		profile.truncate(profile.length() - 4);
		QCheckListItem *item = new QCheckListItem(profileListView, 
					profile, QCheckListItem::CheckBox);
		item->setPixmap(0, QPixmap::fromMimeSource("penguin-small.png"));
		
		if (std::find(sys_config->start_user_profiles.begin(), 
			 sys_config->start_user_profiles.end(), profile.ascii()) !=
		    sys_config->start_user_profiles.end())
		{
			item->setOn(true);
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
	
	// Network settings
	sipUdpPortSpinBox->setValue(sys_config->config_sip_udp_port);
	rtpPortSpinBox->setValue(sys_config->rtp_port);
	
	// Ring tone settings
	playRingtoneCheckBox->setChecked(sys_config->play_ringtone);
	defaultRingtoneRadioButton->setChecked(sys_config->ringtone_file.empty());
	customRingtoneRadioButton->setChecked(!sys_config->ringtone_file.empty());
	ringtoneLineEdit->setText(sys_config->ringtone_file.c_str());
	defaultRingtoneRadioButton->setEnabled(sys_config->play_ringtone);
	customRingtoneRadioButton->setEnabled(sys_config->play_ringtone);
	ringtoneLineEdit->setEnabled(!sys_config->ringtone_file.empty());
	openRingtoneToolButton->setEnabled(!sys_config->ringtone_file.empty());
	
	playRingbackCheckBox->setChecked(sys_config->play_ringback);
	defaultRingbackRadioButton->setChecked(sys_config->ringback_file.empty());
	customRingbackRadioButton->setChecked(!sys_config->ringback_file.empty());
	ringbackLineEdit->setText(sys_config->ringback_file.c_str());
	defaultRingbackRadioButton->setEnabled(sys_config->play_ringback);
	customRingbackRadioButton->setEnabled(sys_config->play_ringback);
	ringbackLineEdit->setEnabled(!sys_config->ringback_file.empty());
	openRingbackToolButton->setEnabled(!sys_config->ringback_file.empty());
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
	
	sys_config->au_reduce_noise_mic = reduceNoiseMicCheckBox->isChecked();
	
	sys_config->oss_fragment_size = 
			ossFragmentComboBox->currentText().toInt();
	sys_config->alsa_play_period_size =
			alsaPlayPeriodComboBox->currentText().toInt();
	sys_config->alsa_capture_period_size = 
			alsaCapturePeriodComboBox->currentText().toInt();
	
	// Log
	sys_config->log_max_size = logMaxSizeSpinBox->value();
	sys_config->log_show_debug = logDebugCheckBox->isChecked();
	sys_config->log_show_sip = logSipCheckBox->isChecked();
	sys_config->log_show_stun = logStunCheckBox->isChecked();
	sys_config->log_show_memory = logMemoryCheckBox->isChecked();
	
	// General
	sys_config->gui_use_systray = guiUseSystrayCheckBox->isChecked();
	sys_config->gui_hide_on_close = guiHideCheckBox->isChecked();
	
	// Call history
	sys_config->ch_max_size = histSizeSpinBox->value();
	
	// Services
	sys_config->call_waiting = callWaitingCheckBox->isChecked();
	sys_config->hangup_both_3way = hangupBothCheckBox->isChecked();

	// Startup
	sys_config->start_hidden = startHiddenCheckBox->isChecked() &&
				   guiUseSystrayCheckBox->isChecked();
	
	sys_config->start_user_profiles.clear();
	QListViewItemIterator i(profileListView, QListViewItemIterator::Checked);
	while (i.current()) {
		QCheckListItem *item = (QCheckListItem *)i.current();
		sys_config->start_user_profiles.push_back(item->text().ascii());
		i++;
	}
	
	if (userHostComboBox->currentItem() == 0) {
		sys_config->start_user_host.clear();
	} else {
		sys_config->start_user_host = userHostComboBox->currentText().ascii();
	}
	
	// Network
	if (sys_config->config_sip_udp_port != sipUdpPortSpinBox->value()) {
		sys_config->config_sip_udp_port = sipUdpPortSpinBox->value();
		emit sipUdpPortChanged();
	}
	if (sys_config->rtp_port != rtpPortSpinBox->value()) {
		sys_config->rtp_port = rtpPortSpinBox->value();
		emit rtpPortChanged();
	}
	
	// Ring tones
	sys_config->play_ringtone = playRingtoneCheckBox->isChecked();
	if (sys_config->play_ringtone) {
		if (defaultRingtoneRadioButton->isOn()) {
			sys_config->ringtone_file.clear();
		} else {
			sys_config->ringtone_file = ringtoneLineEdit->
					text().stripWhiteSpace().ascii();
		}
	} else {
		sys_config->ringtone_file.clear();
	}
	
	sys_config->play_ringback = playRingbackCheckBox->isChecked();
	if (sys_config->play_ringback) {
		if (defaultRingbackRadioButton->isOn()) {
			sys_config->ringback_file.clear();
		} else {
			sys_config->ringback_file = ringbackLineEdit->
					text().stripWhiteSpace().ascii();
		}
	} else {
		sys_config->ringback_file.clear();
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

void SysSettingsForm::chooseRingtone()
{
	QString file = QFileDialog::getOpenFileName(
			((t_gui *)ui)->get_last_file_browse_path(),
			"Ring tones (*.wav)", this, "ring tone file dialog",
			"Choose ring tone");
	if (!file.isEmpty()) {
		ringtoneLineEdit->setText(file);
		((t_gui *)ui)->set_last_file_browse_path(QFileInfo(file).dirPath(true));
	}
}

void SysSettingsForm::chooseRingback()
{
	QString file = QFileDialog::getOpenFileName(
			((t_gui *)ui)->get_last_file_browse_path(),
			"Ring back tones (*.wav)", this, "ring back file dialog",
			"Choose ring back tone");
	if (!file.isEmpty()) {
		ringbackLineEdit->setText(file);
		((t_gui *)ui)->set_last_file_browse_path(QFileInfo(file).dirPath(true));
	}
}
