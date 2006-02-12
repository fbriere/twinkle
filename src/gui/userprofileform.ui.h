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


// Indices of categories in the category list box
#define idxCatUser		0
#define idxCatSipServer	1
#define idxCatRtpAudio	2
#define idxCatSipProtocol	3
#define idxCatNat		4
#define idxCatAddrFmt	5
#define idxCatTimers	6
#define idxCatRingTones	7
#define idxCatScripts	8

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
	
	// Set toolbutton icons for disabled options.
	QIconSet i;
	i = openRingtoneToolButton->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("fileopen-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	openRingtoneToolButton->setIconSet(i);
	openRingbackToolButton->setIconSet(i);
	openIncomingCallScriptToolButton->setIconSet(i);
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
	} else if (item->text() == "Ring tones") {
		settingsWidgetStack->raiseWidget(pageRingTones);
	} else if (item->text() == "Scripts") {
		settingsWidgetStack->raiseWidget(pageScripts);
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
void UserProfileForm::populate()
{
	QString s;
	
	// Set user profile name in the titlebar
	s = PRODUCT_NAME;
	s.append(" - User profile: ").append(current_profile->get_profile_name().c_str());
	setCaption(s);
	
	// Select the User category
	categoryListBox->setSelected(idxCatUser, true);
	settingsWidgetStack->raiseWidget(pageUser);
	
	// Set focus on first field
	displayLineEdit->setFocus();
	
	// Set the values of the current_profile object in the form
	// USER
	displayLineEdit->setText(current_profile->display.c_str());
	usernameLineEdit->setText(current_profile->name.c_str());
	domainLineEdit->setText(current_profile->domain.c_str());
	organizationLineEdit->setText(current_profile->organization.c_str());
	authRealmLineEdit->setText(current_profile->auth_realm.c_str());
	authNameLineEdit->setText(current_profile->auth_name.c_str());
	authPasswordLineEdit->setText(current_profile->auth_pass.c_str());
	
	// SIP SERVER
	registrarLineEdit->setText(current_profile->registrar.encode_noscheme().c_str());
	expirySpinBox->setValue(current_profile->registration_time);
	regAtStartupCheckBox->setChecked(current_profile->register_at_startup);
	useProxyCheckBox->setChecked(current_profile->use_outbound_proxy);
	proxyTextLabel->setEnabled(current_profile->use_outbound_proxy);
	proxyLineEdit->setEnabled(current_profile->use_outbound_proxy);
	if (current_profile->use_outbound_proxy) {
		proxyLineEdit->setText(current_profile->
				       outbound_proxy.encode_noscheme().c_str());
	} else {
		proxyLineEdit->clear();
	}
	allRequestsCheckBox->setChecked(current_profile->all_requests_to_proxy);
	allRequestsCheckBox->setEnabled(current_profile->use_outbound_proxy);
	proxyNonResolvableCheckBox->setChecked(current_profile->non_resolvable_to_proxy);
	proxyNonResolvableCheckBox->setEnabled(current_profile->use_outbound_proxy);
	
	// RTP AUDIO
	// Set codec combo boxes to 'none'.
	codec2ComboBox->setCurrentItem(idxCodecNone);
	codec3ComboBox->setCurrentItem(idxCodecNone);
	
	// Set codec combo boxes to values from user config
	int codecChoice = 0;
	for (list<unsigned short>::iterator i = current_profile->codecs.begin();
	i != current_profile->codecs.end(); i++)
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
	
	ptimeSpinBox->setValue(current_profile->ptime);
	dtmfPayloadTypeSpinBox->setValue(current_profile->dtmf_payload_type);
	dtmfDurationSpinBox->setValue(current_profile->dtmf_duration);
	dtmfPauseSpinBox->setValue(current_profile->dtmf_pause);
	dtmfVolumeSpinBox->setValue(current_profile->dtmf_volume);
	
	// SIP PROTOCOL
	switch(current_profile->hold_variant) {
	case HOLD_RFC2543:
		holdVariantComboBox->setCurrentItem(idxHoldRfc2543);
		break;
	default:
		holdVariantComboBox->setCurrentItem(idxHoldRfc3264);
		break;
	}
	
	maxForwardsCheckBox->setChecked(current_profile->check_max_forwards);
	missingContactCheckBox->setChecked(current_profile->allow_missing_contact_reg);
	regTimeCheckBox->setChecked(current_profile->registration_time_in_contact);
	compactHeadersCheckBox->setChecked(current_profile->compact_headers);
	useDomainInContactCheckBox->setChecked(
			current_profile->use_domain_in_contact);
	allowRedirectionCheckBox->setChecked(current_profile->allow_redirection);
	askUserRedirectCheckBox->setEnabled(current_profile->allow_redirection);
	askUserRedirectCheckBox->setChecked(current_profile->ask_user_to_redirect);
	maxRedirectTextLabel->setEnabled(current_profile->allow_redirection);
	maxRedirectSpinBox->setEnabled(current_profile->allow_redirection);
	maxRedirectSpinBox->setValue(current_profile->max_redirections);
	ext100relComboBox->setCurrentItem(
			ext_support2indexComboItem(current_profile->ext_100rel));
	allowReferCheckBox->setChecked(current_profile->allow_refer);
	askUserReferCheckBox->setEnabled(current_profile->allow_refer);
	askUserReferCheckBox->setChecked(current_profile->ask_user_to_refer);
	refereeHoldCheckBox->setEnabled(current_profile->allow_refer);
	refereeHoldCheckBox->setChecked(current_profile->referee_hold);
	referrerHoldCheckBox->setChecked(current_profile->referrer_hold);
	refreshReferSubCheckBox->setChecked(current_profile->auto_refresh_refer_sub);
	
	// NAT
	if (current_profile->use_nat_public_ip) {
		natStaticRadioButton->setChecked(true);
	} else if (current_profile->use_stun) {
		natStunRadioButton->setChecked(true);
	} else {
		natNoneRadioButton->setChecked(true);
	}
	
	publicIPTextLabel->setEnabled(current_profile->use_nat_public_ip);
	publicIPLineEdit->setEnabled(current_profile->use_nat_public_ip);
	publicIPLineEdit->setText(current_profile->nat_public_ip.c_str());
	stunServerTextLabel->setEnabled(current_profile->use_stun);
	stunServerLineEdit->setEnabled(current_profile->use_stun);
	stunServerLineEdit->setText(current_profile->stun_server.
				    encode_noscheme().c_str());
	
	// ADDRESS FORMAT
	displayTelUserCheckBox->setChecked(current_profile->display_useronly_phone);
	numericalUserIsTelCheckBox->setChecked(
			current_profile->numerical_user_is_phone);
	
	// TIMERS
	tmrNoanswerSpinBox->setValue(current_profile->timer_noanswer);
	tmrNatKeepaliveSpinBox->setValue(current_profile->timer_nat_keepalive);
	
	// RING TONES
	ringtoneLineEdit->setText(current_profile->ringtone_file.c_str());
	ringbackLineEdit->setText(current_profile->ringback_file.c_str());
	
	// SCRIPTS
	incomingCallScriptLineEdit->setText(current_profile->script_incoming_call.c_str());
}

void UserProfileForm::initProfileList(list<t_user *> profiles, QString show_profile_name)
{
	profile_list = profiles;
	
	// Initialize user profile combo box
	current_profile_idx = -1;
	profileComboBox->clear();
	
	t_user *show_profile = NULL;
	int show_idx = 0;
	int idx = 0;
	for (list<t_user *>::iterator i = profile_list.begin(); i != profile_list.end(); i++) {
		profileComboBox->insertItem((*i)->get_profile_name().c_str());
		if (show_profile_name == (*i)->get_profile_name().c_str()) {
			show_idx = idx;
			show_profile = *i;
		}
		idx++;
	}
	
	profileComboBox->setEnabled(profile_list.size() > 1);
	current_profile_idx = show_idx;
	
	if (show_profile == NULL) {
		current_profile = profile_list.front();
	} else {
		current_profile = show_profile;
	}
	profileComboBox->setCurrentItem(current_profile_idx);
}

// Show the form
void UserProfileForm::show(list<t_user *> profiles, QString show_profile)
{
	initProfileList(profiles, show_profile);
	populate();
	
	// Show form
	QDialog::show();
}

// Modal execution
int UserProfileForm::exec(list<t_user *> profiles, QString show_profile)
{
	initProfileList(profiles, show_profile);
	populate();
	return QDialog::exec();
}

bool UserProfileForm::validateValues()
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
		return false;
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
		return false;
	}
	
	// Check validity of domain
	s = USER_SCHEME;
	s.append(':').append(domainLineEdit->text());
	t_url u_domain(s.ascii());
	if (!u_domain.is_valid() || u_domain.get_user() != "") {
		categoryListBox->setSelected(idxCatUser, true);
		settingsWidgetStack->raiseWidget(pageUser);
		((t_gui *)ui)->cb_show_msg(this,  "Invalid user name.", MSG_CRITICAL);
		usernameLineEdit->setFocus();
		return false;
	}
	
	// Check validity of user
	s = USER_SCHEME;
	s.append(':').append(usernameLineEdit->text()).append('@');
	s.append(domainLineEdit->text());
	t_url u_user_domain(s.ascii());
	if (!u_user_domain.is_valid()) {
		categoryListBox->setSelected(idxCatUser, true);
		settingsWidgetStack->raiseWidget(pageUser);
		((t_gui *)ui)->cb_show_msg(this,  "Invalid domain.", MSG_CRITICAL);
		domainLineEdit->setFocus();
		return false;
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
			return false;
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
			return false;
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
			return false;
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
			return false;
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
	
	// Set all values in the current_profile object
	// USER
	if (current_profile->name != usernameLineEdit->text().ascii() ||
	    current_profile->display != displayLineEdit->text().ascii() ||
	    current_profile->domain != domainLineEdit->text().ascii())
	{
		current_profile->display = displayLineEdit->text().ascii();
		current_profile->name = usernameLineEdit->text().ascii();
		current_profile->domain = domainLineEdit->text().ascii();
		emit sipUserChanged(current_profile);
	}
	
	current_profile->organization = organizationLineEdit->text().ascii();
	
	if (current_profile->auth_realm != authRealmLineEdit->text().ascii() ||
	    current_profile->auth_name != authNameLineEdit->text().ascii() ||
	    current_profile->auth_pass != authPasswordLineEdit->text().ascii())
	{
		emit authCredentialsChanged(current_profile,
					current_profile->auth_realm);
		
		current_profile->auth_realm = authRealmLineEdit->text().ascii();
		current_profile->auth_name = authNameLineEdit->text().ascii();
		current_profile->auth_pass = authPasswordLineEdit->text().ascii();
	}

	// SIP SERVER
	current_profile->use_registrar = !registrarLineEdit->text().isEmpty();
	s = USER_SCHEME;
	s.append(':').append(registrarLineEdit->text());
	current_profile->registrar.set_url(s.ascii());
	current_profile->registration_time = expirySpinBox->value();
	current_profile->register_at_startup = regAtStartupCheckBox->isChecked();
	
	current_profile->use_outbound_proxy = useProxyCheckBox->isChecked();
	s = USER_SCHEME;
	s.append(':').append(proxyLineEdit->text());
	current_profile->outbound_proxy.set_url(s.ascii());
	current_profile->all_requests_to_proxy = allRequestsCheckBox->isChecked();
	current_profile->non_resolvable_to_proxy = 
			proxyNonResolvableCheckBox->isChecked();
	
	// RTP AUDIO
	current_profile->codecs.clear();
	short codec;
	codec = indexComboItem2codec(codec1ComboBox->currentItem());
	if (codec >= 0) current_profile->codecs.push_back(codec);
	codec = indexComboItem2codec(codec2ComboBox->currentItem());
	if (codec >= 0 &&
	    std::find(current_profile->codecs.begin(), current_profile->codecs.end(), codec) ==
	    current_profile->codecs.end()) 
	{
		current_profile->codecs.push_back(codec);
	}
	codec = indexComboItem2codec(codec3ComboBox->currentItem());
	if (codec >= 0 &&
	    std::find(current_profile->codecs.begin(), current_profile->codecs.end(), codec) ==
	    current_profile->codecs.end()) 
	{
		current_profile->codecs.push_back(codec);
	}
	
	current_profile->ptime = ptimeSpinBox->value();
	current_profile->dtmf_payload_type = dtmfPayloadTypeSpinBox->value();
	current_profile->dtmf_duration = dtmfDurationSpinBox->value();
	current_profile->dtmf_pause = dtmfPauseSpinBox->value();
	current_profile->dtmf_volume = dtmfVolumeSpinBox->value();
	
	// SIP PROTOCOL
	switch(holdVariantComboBox->currentItem()) {
	case idxHoldRfc2543:
		current_profile->hold_variant = HOLD_RFC2543;
		break;
	default:
		current_profile->hold_variant = HOLD_RFC3264;
		break;
	}
	
	current_profile->check_max_forwards = maxForwardsCheckBox->isChecked();
	current_profile->allow_missing_contact_reg = missingContactCheckBox->isChecked();
	current_profile->registration_time_in_contact = regTimeCheckBox->isChecked();
	current_profile->compact_headers = compactHeadersCheckBox->isChecked();
	current_profile->use_domain_in_contact =
			useDomainInContactCheckBox->isChecked();
	current_profile->allow_redirection = allowRedirectionCheckBox->isChecked();
	current_profile->ask_user_to_redirect = askUserRedirectCheckBox->isChecked();
	current_profile->max_redirections = maxRedirectSpinBox->value();
	current_profile->ext_100rel = indexComboItem2ext_support(
			ext100relComboBox->currentItem());
	current_profile->allow_refer = allowReferCheckBox->isChecked();
	current_profile->ask_user_to_refer = askUserReferCheckBox->isChecked();
	current_profile->referee_hold = refereeHoldCheckBox->isChecked();
	current_profile->referrer_hold = referrerHoldCheckBox->isChecked();
	current_profile->auto_refresh_refer_sub = refreshReferSubCheckBox->isChecked();
	
	// NAT
	current_profile->use_nat_public_ip = natStaticRadioButton->isChecked();
	current_profile->nat_public_ip = publicIPLineEdit->text().ascii();
	current_profile->use_stun = natStunRadioButton->isChecked();
	
	if (current_profile->stun_server.encode_noscheme() != 
	    stunServerLineEdit->text().ascii()) 
	{
		s = "stun:";
		s.append(stunServerLineEdit->text());
		current_profile->stun_server.set_url(s.ascii());
		emit stunServerChanged(current_profile);
	}
	
	// ADDRESS FORMAT
	current_profile->display_useronly_phone = 
			displayTelUserCheckBox->isChecked();
	current_profile->numerical_user_is_phone = 
			numericalUserIsTelCheckBox->isChecked();
	
	// TIMERS
	current_profile->timer_noanswer = tmrNoanswerSpinBox->value();
	current_profile->timer_nat_keepalive = tmrNatKeepaliveSpinBox->value();
	
	// RING TONES
	current_profile->ringtone_file = ringtoneLineEdit->text().stripWhiteSpace().ascii();
	current_profile->ringback_file = ringbackLineEdit->text().stripWhiteSpace().ascii();
	
	// SCRIPTS
	current_profile->script_incoming_call = incomingCallScriptLineEdit->
					text().stripWhiteSpace().ascii();
	
	// Save user config
	string error_msg;
	if (!current_profile->write_config(current_profile->get_filename(), error_msg)) {
		// Failed to write config file
		((t_gui *)ui)->cb_show_msg(this, error_msg, MSG_CRITICAL);
		return false;
	}
	
	return true;
}

void UserProfileForm::validate() {
	if (validateValues()) {
		emit success();
		accept();
	}
}

// User wants to change to another profile
void UserProfileForm::changeProfile(const QString &profileName) {
	if (current_profile_idx == -1) {
		// Initializing combo box
		return;
	}
	
	// Make the current profile permanent.
	if (!validateValues()) {
		// Current values are not valid.
		// Do not change to the new profile.
		profileComboBox->setCurrentItem(current_profile_idx);
		return;
	}
	
	// Change to new profile.
	for (list<t_user *>::iterator i = profile_list.begin(); i != profile_list.end(); i++) {
		if ((*i)->get_profile_name() == profileName.ascii()) {
			current_profile = *i;
			break;
		}
	}
	
	current_profile_idx = profileComboBox->currentItem();
	populate();
}

void UserProfileForm::chooseRingtone()
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

void UserProfileForm::chooseRingback()
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

void UserProfileForm::chooseIncomingCallScript()
{
	QString file = QFileDialog::getOpenFileName(
			((t_gui *)ui)->get_last_file_browse_path(),
			"All files (*)", this, "incoming call script file dialog",
			"Choose incoming call script");
	if (!file.isEmpty()) {
		incomingCallScriptLineEdit->setText(file);
		((t_gui *)ui)->set_last_file_browse_path(QFileInfo(file).dirPath(true));
	}
}
