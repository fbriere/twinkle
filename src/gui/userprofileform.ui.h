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


// Indices of categories in the category list box
#define idxCatUser		0
#define idxCatSipServer	1
#define idxCatRtpAudio	2
#define idxCatSipProtocol	3
#define idxCatNat		4
#define idxCatAddrFmt	5
#define idxCatTimers	6

// Indices of audio codecs in the codec list boxes
#define idxCodecG711a	0
#define idxCodecG711u	1
#define idxCodecGsm	2
#define idxCodecNone	3

// Indices of call hold variants in the call hold variant list box
#define idxHoldRfc2543	0
#define idxHoldRfc3264	1

// Indices of SIP extension support types in the list box
#define idxExtDisabled	0
#define idxExtSupported	1
#define idxExtRequired	2
#define idxExtPreferred	3

void UserProfileForm::init()
{
	QRegExp rxNoSpace("\\S*");
	
	// Set validators
	// USER
	usernameLineEdit->setValidator(new QRegExpValidator(rxNoSpace, this));
	domainLineEdit->setValidator(new QRegExpValidator(rxNoSpace, this));
	authNameLineEdit->setValidator(new QRegExpValidator(rxNoSpace, this));
	
	// SIP SERVER
	registrarLineEdit->setValidator(new QRegExpValidator(rxNoSpace, this));
	proxyLineEdit->setValidator(new QRegExpValidator(rxNoSpace, this));
	
	// NAT
	publicIPLineEdit->setValidator(new QRegExpValidator(rxNoSpace, this));
}

void UserProfileForm::showCategory( QListBoxItem *item )
{
	if (item->text() == "User") {
		settingsWidgetStack->raiseWidget(pageUser);
	} else if (item->text() == "SIP server") {
		settingsWidgetStack->raiseWidget(pageSipServer);
	} else if (item->text() == "RTP audio") {
		settingsWidgetStack->raiseWidget(pageRtpAudio);
	} else if (item->text() == "SIP protocol") {
		settingsWidgetStack->raiseWidget(pageSipProtocol);
	} else if (item->text() == "NAT") {
		settingsWidgetStack->raiseWidget(pageNat);
	} else if (item->text() == "Address format") {
		settingsWidgetStack->raiseWidget(pageAddressFormat);
	} else if (item->text() == "Timers") {
		settingsWidgetStack->raiseWidget(pageTimers);
	}
}

// Convert a codec to an index in the codec combobox
int UserProfileForm::codec2indexComboItem(short codec) {
	switch(codec) {
	case SDP_FORMAT_G711_ALAW:	
		return idxCodecG711a;
	case SDP_FORMAT_G711_ULAW:
		return idxCodecG711u;
	case SDP_FORMAT_GSM:
		return idxCodecGsm;
	}
	
	return idxCodecNone;
}

short UserProfileForm::indexComboItem2codec(int index) {
	switch(index) {
	case idxCodecG711a:
		return SDP_FORMAT_G711_ALAW;
	case idxCodecG711u:
		return SDP_FORMAT_G711_ULAW;
	case idxCodecGsm:
		return SDP_FORMAT_GSM;
	}
	
	return -1;
}

// Convert t_ext_support to an index in the SIP extension combo box
int UserProfileForm::ext_support2indexComboItem(t_ext_support ext) {
	switch(ext) {
	case EXT_DISABLED:
		return idxExtDisabled;
	case EXT_SUPPORTED:
		return idxExtSupported;
	case EXT_REQUIRED:
		return idxExtRequired;
	case EXT_PREFERRED:
		return idxExtPreferred;
	default:
		return idxExtDisabled;
	}
	
	return idxExtDisabled;
}

t_ext_support UserProfileForm::indexComboItem2ext_support(int index) {
	switch(index) {
	case idxExtDisabled:
		return EXT_DISABLED;
	case idxExtSupported:
		return EXT_SUPPORTED;
	case idxExtRequired:
		return EXT_REQUIRED;
	case idxExtPreferred:
		return EXT_PREFERRED;
	}
	
	return EXT_DISABLED;
}

// Populate the form
// isRunning indicates if Twinkle is currently running
void UserProfileForm::populate( bool isRunning )
{
	QString s;
	
	// Set user profile name in the titlebar
	s = PRODUCT_NAME;
	s.append(" - User profile: ").append(user_config->get_profile_name().c_str());
	setCaption(s);
	
	// In running mode not all settings can be changed.
	sipUdpPortTextLabel->setEnabled(!isRunning);
	sipUdpPortSpinBox->setEnabled(!isRunning);
	
	// Select the User category
	categoryListBox->setSelected(idxCatUser, true);
	settingsWidgetStack->raiseWidget(pageUser);
	
	// Set focus on first field
	displayLineEdit->setFocus();
	
	// Set the values of the user_config object in the form
	// USER
	displayLineEdit->setText(user_config->display.c_str());
	usernameLineEdit->setText(user_config->name.c_str());
	domainLineEdit->setText(user_config->domain.c_str());
	organizationLineEdit->setText(user_config->organization.c_str());
	authRealmLineEdit->setText(user_config->auth_realm.c_str());
	authNameLineEdit->setText(user_config->auth_name.c_str());
	authPasswordLineEdit->setText(user_config->auth_pass.c_str());
	
	// SIP SERVER
	registrarLineEdit->setText(user_config->registrar.encode_noscheme().c_str());
	expirySpinBox->setValue(user_config->registration_time);
	regAtStartupCheckBox->setChecked(user_config->register_at_startup);
	useProxyCheckBox->setChecked(user_config->use_outbound_proxy);
	proxyTextLabel->setEnabled(user_config->use_outbound_proxy);
	proxyLineEdit->setEnabled(user_config->use_outbound_proxy);
	if (user_config->use_outbound_proxy) {
		proxyLineEdit->setText(user_config->
				       outbound_proxy.encode_noscheme().c_str());
	} else {
		proxyLineEdit->clear();
	}
	allRequestsCheckBox->setChecked(user_config->all_requests_to_proxy);
	allRequestsCheckBox->setEnabled(user_config->use_outbound_proxy);
	proxyNonResolvableCheckBox->setChecked(user_config->non_resolvable_to_proxy);
	proxyNonResolvableCheckBox->setEnabled(user_config->use_outbound_proxy);
	
	// RTP AUDIO
	rtpPortSpinBox->setValue(user_config->rtp_port);
	
	// Set codec combo boxes to 'none'.
	codec2ComboBox->setCurrentItem(idxCodecNone);
	codec3ComboBox->setCurrentItem(idxCodecNone);
	
	// Set codec combo boxes to values from user config
	int codecChoice = 0;
	for (list<unsigned short>::iterator i = user_config->codecs.begin();
	i != user_config->codecs.end(); i++)
	{
		codecChoice++;
		if (codecChoice == 1) {
			codec1ComboBox->setCurrentItem(codec2indexComboItem(*i));
		} else if (codecChoice == 2) {
			codec2ComboBox->setCurrentItem(codec2indexComboItem(*i));
		} else if (codecChoice == 3) {
			codec3ComboBox->setCurrentItem(codec2indexComboItem(*i));
		}
	}
	
	ptimeSpinBox->setValue(user_config->ptime);
	dtmfPayloadTypeSpinBox->setValue(user_config->dtmf_payload_type);
	dtmfDurationSpinBox->setValue(user_config->dtmf_duration);
	dtmfPauseSpinBox->setValue(user_config->dtmf_pause);
	dtmfVolumeSpinBox->setValue(user_config->dtmf_volume);
	
	// SIP PROTOCOL
	sipUdpPortSpinBox->setValue(user_config->sip_udp_port);
	
	switch(user_config->hold_variant) {
	case HOLD_RFC2543:
		holdVariantComboBox->setCurrentItem(idxHoldRfc2543);
		break;
	default:
		holdVariantComboBox->setCurrentItem(idxHoldRfc3264);
		break;
	}
	
	maxForwardsCheckBox->setChecked(user_config->check_max_forwards);
	regTimeCheckBox->setChecked(user_config->registration_time_in_contact);
	compactHeadersCheckBox->setChecked(user_config->compact_headers);
	allowRedirectionCheckBox->setChecked(user_config->allow_redirection);
	askUserRedirectCheckBox->setEnabled(user_config->allow_redirection);
	askUserRedirectCheckBox->setChecked(user_config->ask_user_to_redirect);
	maxRedirectTextLabel->setEnabled(user_config->allow_redirection);
	maxRedirectSpinBox->setEnabled(user_config->allow_redirection);
	maxRedirectSpinBox->setValue(user_config->max_redirections);
	ext100relComboBox->setCurrentItem(
			ext_support2indexComboItem(user_config->ext_100rel));
	allowReferCheckBox->setChecked(user_config->allow_refer);
	askUserReferCheckBox->setEnabled(user_config->allow_refer);
	askUserReferCheckBox->setChecked(user_config->ask_user_to_refer);
	refereeHoldCheckBox->setEnabled(user_config->allow_refer);
	refereeHoldCheckBox->setChecked(user_config->referee_hold);
	referrerHoldCheckBox->setChecked(user_config->referrer_hold);
	refreshReferSubCheckBox->setChecked(user_config->auto_refresh_refer_sub);
	
	// NAT
	if (user_config->use_nat_public_ip) {
		natStaticRadioButton->setChecked(true);
	} else if (user_config->use_stun) {
		natStunRadioButton->setChecked(true);
	} else {
		natNoneRadioButton->setChecked(true);
	}
	
	publicIPTextLabel->setEnabled(user_config->use_nat_public_ip);
	publicIPLineEdit->setEnabled(user_config->use_nat_public_ip);
	publicIPLineEdit->setText(user_config->nat_public_ip.c_str());
	stunServerTextLabel->setEnabled(user_config->use_stun);
	stunServerLineEdit->setEnabled(user_config->use_stun);
	stunServerLineEdit->setText(user_config->stun_server.
				    encode_noscheme().c_str());
	
	// ADDRESS FORMAT
	displayTelUserCheckBox->setChecked(user_config->display_useronly_phone);
	numericalUserIsTelCheckBox->setChecked(
			user_config->numerical_user_is_phone);
	
	// TIMERS
	tmrNoanswerSpinBox->setValue(user_config->timer_noanswer);
	tmrNatKeepaliveSpinBox->setValue(user_config->timer_nat_keepalive);
}

// Show the form
// isRunning indicates if Twinkle is currently running
void UserProfileForm::show(bool isRunning)
{
	populate(isRunning);
	
	// Show form
	QDialog::show();
}

// Modal execution
int UserProfileForm::exec()
{
	populate(false);
	return QDialog::exec();
}

void UserProfileForm::validate()
{
	QString s;
	
	// Validity check user page
	// SIP username is mandatory
	if (usernameLineEdit->text().isEmpty()) {
		categoryListBox->setSelected(idxCatUser, true);
		settingsWidgetStack->raiseWidget(pageUser);
		((t_gui *)ui)->cb_show_msg(this, "You must fill in a user name for your SIP account.",
				MSG_CRITICAL);
		usernameLineEdit->setFocus();
		return;
	}
	
	// SIP user domain is mandatory
	if (domainLineEdit->text().isEmpty()) {
		categoryListBox->setSelected(idxCatUser, true);
		settingsWidgetStack->raiseWidget(pageUser);
		((t_gui *)ui)->cb_show_msg(this, 
				"You must fill in a domain name for your SIP account.\n"
				"This could be the hostname or IP address of your PC "
				"if you want direct PC to PC dialing.",
				MSG_CRITICAL);
		domainLineEdit->setFocus();
		return;
	}
	
	// Registrar
	if (!registrarLineEdit->text().isEmpty()) {
		s = USER_SCHEME;
		s.append(':').append(registrarLineEdit->text());
		t_url u(s.ascii());
		if (!u.is_valid() || u.get_user() != "") {
			categoryListBox->setSelected(idxCatSipServer, true);
			settingsWidgetStack->raiseWidget(pageSipServer);
			((t_gui *)ui)->cb_show_msg(this, "Invalid value for registrar.", 
						   MSG_CRITICAL);
			registrarLineEdit->setFocus();
			registrarLineEdit->selectAll();
			return;
		}
	}
	
	// Outbound proxy
	if (useProxyCheckBox->isChecked()) {
		s = USER_SCHEME;
		s.append(':').append(proxyLineEdit->text());
		t_url u(s.ascii());
		if (!u.is_valid() || u.get_user() != "") {
			categoryListBox->setSelected(idxCatSipServer, true);
			settingsWidgetStack->raiseWidget(pageSipServer);
			((t_gui *)ui)->cb_show_msg(this, "Invalid value for outbound proxy.", 
					MSG_CRITICAL);
			proxyLineEdit->setFocus();
			proxyLineEdit->selectAll();
			return;
		}
	}
	
	// NAT public IP
	if (natStaticRadioButton->isChecked()) {
		if (publicIPLineEdit->text().isEmpty()){
			categoryListBox->setSelected(idxCatNat, true);
			settingsWidgetStack->raiseWidget(pageNat);
			((t_gui *)ui)->cb_show_msg(this, "Value for public IP address missing.",
					MSG_CRITICAL);
			publicIPLineEdit->setFocus();
			return;
		}
	}
	
	// STUN server
	if (natStunRadioButton->isChecked()) {
		s = "stun:";
		s.append(stunServerLineEdit->text());
		t_url u(s.ascii());
		if (!u.is_valid() || u.get_user() != "") {
			categoryListBox->setSelected(idxCatNat, true);
			settingsWidgetStack->raiseWidget(pageNat);
			((t_gui *)ui)->cb_show_msg(this, "Invalid value for STUN server.", 
					MSG_CRITICAL);
			stunServerLineEdit->setFocus();
			stunServerLineEdit->selectAll();
			return;
		}
	}
	
	// Clear outbound proxy if not used
	if (!useProxyCheckBox->isChecked()) {
		proxyLineEdit->clear();
	}
	
	// Clear NAT public IP if not used
	if (!natStaticRadioButton->isChecked()) {
		publicIPLineEdit->clear();
	}
	
	// Clear STUN server if not used
	if (!natStunRadioButton->isChecked()) {
		stunServerLineEdit->clear();
	}
	
	// Set all values in the user_config object
	// USER
	if (user_config->name != usernameLineEdit->text().ascii() ||
	    user_config->display != displayLineEdit->text().ascii() ||
	    user_config->domain != domainLineEdit->text().ascii())
	{
		user_config->display = displayLineEdit->text().ascii();
		user_config->name = usernameLineEdit->text().ascii();
		user_config->domain = domainLineEdit->text().ascii();
		emit sipUserChanged();
	}
	
	user_config->organization = organizationLineEdit->text().ascii();
	user_config->auth_realm = authRealmLineEdit->text().ascii();
	user_config->auth_name = authNameLineEdit->text().ascii();
	user_config->auth_pass = authPasswordLineEdit->text().ascii();
	
	// SIP SERVER
	user_config->use_registrar = !registrarLineEdit->text().isEmpty();
	s = USER_SCHEME;
	s.append(':').append(registrarLineEdit->text());
	user_config->registrar.set_url(s.ascii());
	user_config->registration_time = expirySpinBox->value();
	user_config->register_at_startup = regAtStartupCheckBox->isChecked();
	
	user_config->use_outbound_proxy = useProxyCheckBox->isChecked();
	s = USER_SCHEME;
	s.append(':').append(proxyLineEdit->text());
	user_config->outbound_proxy.set_url(s.ascii());
	user_config->all_requests_to_proxy = allRequestsCheckBox->isChecked();
	user_config->non_resolvable_to_proxy = 
			proxyNonResolvableCheckBox->isChecked();
	
	// RTP AUDIO
	if (user_config->rtp_port != rtpPortSpinBox->value()) {
		user_config->rtp_port = rtpPortSpinBox->value();
		emit rtpPortChanged();
	}
	
	user_config->codecs.clear();
	short codec;
	codec = indexComboItem2codec(codec1ComboBox->currentItem());
	if (codec >= 0) user_config->codecs.push_back(codec);
	codec = indexComboItem2codec(codec2ComboBox->currentItem());
	if (codec >= 0 &&
	    std::find(user_config->codecs.begin(), user_config->codecs.end(), codec) ==
	    user_config->codecs.end()) 
	{
		user_config->codecs.push_back(codec);
	}
	codec = indexComboItem2codec(codec3ComboBox->currentItem());
	if (codec >= 0 &&
	    std::find(user_config->codecs.begin(), user_config->codecs.end(), codec) ==
	    user_config->codecs.end()) 
	{
		user_config->codecs.push_back(codec);
	}
	
	user_config->ptime = ptimeSpinBox->value();
	user_config->dtmf_payload_type = dtmfPayloadTypeSpinBox->value();
	user_config->dtmf_duration = dtmfDurationSpinBox->value();
	user_config->dtmf_pause = dtmfPauseSpinBox->value();
	user_config->dtmf_volume = dtmfVolumeSpinBox->value();
	
	// SIP PROTOCOL
	user_config->sip_udp_port = sipUdpPortSpinBox->value();
	
	switch(holdVariantComboBox->currentItem()) {
	case idxHoldRfc2543:
		user_config->hold_variant = HOLD_RFC2543;
		break;
	default:
		user_config->hold_variant = HOLD_RFC3264;
		break;
	}
	
	user_config->check_max_forwards = maxForwardsCheckBox->isChecked();
	user_config->registration_time_in_contact = regTimeCheckBox->isChecked();
	user_config->compact_headers = compactHeadersCheckBox->isChecked();
	user_config->allow_redirection = allowRedirectionCheckBox->isChecked();
	user_config->ask_user_to_redirect = askUserRedirectCheckBox->isChecked();
	user_config->max_redirections = maxRedirectSpinBox->value();
	user_config->ext_100rel = indexComboItem2ext_support(
			ext100relComboBox->currentItem());
	user_config->allow_refer = allowReferCheckBox->isChecked();
	user_config->ask_user_to_refer = askUserReferCheckBox->isChecked();
	user_config->referee_hold = refereeHoldCheckBox->isChecked();
	user_config->referrer_hold = referrerHoldCheckBox->isChecked();
	user_config->auto_refresh_refer_sub = refreshReferSubCheckBox->isChecked();
	
	// NAT
	user_config->use_nat_public_ip = natStaticRadioButton->isChecked();
	user_config->nat_public_ip = publicIPLineEdit->text().ascii();
	user_config->use_stun = natStunRadioButton->isChecked();
	
	if (user_config->stun_server.encode_noscheme() != 
	    stunServerLineEdit->text().ascii()) 
	{
		s = "stun:";
		s.append(stunServerLineEdit->text());
		user_config->stun_server.set_url(s.ascii());
		emit stunServerChanged();
	}
	
	// ADDRESS FORMAT
	user_config->display_useronly_phone = 
			displayTelUserCheckBox->isChecked();
	user_config->numerical_user_is_phone = 
			numericalUserIsTelCheckBox->isChecked();
	
	// TIMERS
	user_config->timer_noanswer = tmrNoanswerSpinBox->value();
	user_config->timer_nat_keepalive = tmrNatKeepaliveSpinBox->value();
	
	// Save user config
	string error_msg;
	if (!user_config->write_config(user_config->get_filename(), error_msg)) {
		// Failed to write config file
		((t_gui *)ui)->cb_show_msg(this, error_msg, MSG_CRITICAL);
		return;
	}
	
	accept();
}


