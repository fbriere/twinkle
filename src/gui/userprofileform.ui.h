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

// Indices of call hold variants in the call hold variant list box
#define idxHoldRfc2543	0
#define idxHoldRfc3264	1

// Indices of SIP extension support types in the list box
#define idxExtDisabled	0
#define idxExtSupported	1
#define idxExtRequired	2
#define idxExtPreferred	3

// Indices of RTP audio tabs
#define idxRtpCodecs	0
#define idxRtpIlbc		1
#define idxRtpSpeex	2
#define idxRtpDtmf		3

// Codec labels
#define labelCodecG711a		"G.711 A-law"
#define labelCodecG711u		"G.711 u-law"
#define labelCodecGSM		"GSM"
#define labelCodecSpeexNb		"speex-nb (8 kHz)"
#define labelCodecSpeexWb	"speex-wb (16 kHz)"
#define labelCodecSpeexUwb	"speex-uwb (32 kHz)"
#define labelCodecIlbc		"iLBC"

// Indices of iLBC modes
#define idxIlbcMode20	0
#define idxIlbcMode30	1

// Indices of DTMF transport modes in the DTMF transport list box
#define idxDtmfAuto	0
#define idxDtmfRfc2833	1
#define idxDtmfInband	2

// Columns in the number conversion list view
#define colExpr		0
#define colReplace		1

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
	
#ifndef HAVE_SPEEX
	// Speex
	speexGroupBox->hide();
	rtpAudioTabWidget->setTabEnabled(rtpAudioTabWidget->page(idxRtpSpeex), false);
#endif
#ifndef HAVE_ILBC
	// iLBC
	ilbcGroupBox->hide();
	rtpAudioTabWidget->setTabEnabled(rtpAudioTabWidget->page(idxRtpIlbc), false);
#endif
	
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

// Convert a label to a codec
t_audio_codec UserProfileForm::label2codec(const QString &label) {
	if (label == labelCodecG711a) {
		return CODEC_G711_ALAW;
	} else if (label == labelCodecG711u) {
		return CODEC_G711_ULAW;
	} else if (label == labelCodecGSM) {
		return CODEC_GSM;
	} else if (label == labelCodecSpeexNb) {
		return CODEC_SPEEX_NB;
	} else if (label == labelCodecSpeexWb) {
		return CODEC_SPEEX_WB;
	} else if (label == labelCodecSpeexUwb) {
		return CODEC_SPEEX_UWB;
	} else if (label == labelCodecIlbc) {
		return CODEC_ILBC;
	}
	return CODEC_NULL;
}

// Convert a codec to a label
QString UserProfileForm::codec2label(t_audio_codec &codec) {
	switch (codec) {
	case CODEC_G711_ALAW:
		return labelCodecG711a;
	case CODEC_G711_ULAW:
		return labelCodecG711u;
	case CODEC_GSM:
		return labelCodecGSM;
	case CODEC_SPEEX_NB:
		return labelCodecSpeexNb;
	case CODEC_SPEEX_WB:
		return labelCodecSpeexWb;
	case CODEC_SPEEX_UWB:
		return labelCodecSpeexUwb;
	case CODEC_ILBC:
		return labelCodecIlbc;
	default:
		return "";
	}
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
	displayLineEdit->setText(current_profile->get_display().c_str());
	usernameLineEdit->setText(current_profile->get_name().c_str());
	domainLineEdit->setText(current_profile->get_domain().c_str());
	organizationLineEdit->setText(current_profile->get_organization().c_str());
	authRealmLineEdit->setText(current_profile->get_auth_realm().c_str());
	authNameLineEdit->setText(current_profile->get_auth_name().c_str());
	authPasswordLineEdit->setText(current_profile->get_auth_pass().c_str());
	
	// SIP SERVER
	registrarLineEdit->setText(current_profile->get_registrar().encode_noscheme().c_str());
	expirySpinBox->setValue(current_profile->get_registration_time());
	regAtStartupCheckBox->setChecked(current_profile->get_register_at_startup());
	useProxyCheckBox->setChecked(current_profile->get_use_outbound_proxy());
	proxyTextLabel->setEnabled(current_profile->get_use_outbound_proxy());
	proxyLineEdit->setEnabled(current_profile->get_use_outbound_proxy());
	if (current_profile->get_use_outbound_proxy()) {
		proxyLineEdit->setText(current_profile->
				       get_outbound_proxy().encode_noscheme().c_str());
	} else {
		proxyLineEdit->clear();
	}
	allRequestsCheckBox->setChecked(current_profile->get_all_requests_to_proxy());
	allRequestsCheckBox->setEnabled(current_profile->get_use_outbound_proxy());
	proxyNonResolvableCheckBox->setChecked(current_profile->get_non_resolvable_to_proxy());
	proxyNonResolvableCheckBox->setEnabled(current_profile->get_use_outbound_proxy());
	
	// RTP AUDIO
	// Codecs
	QStringList allCodecs;
	allCodecs.append(labelCodecG711a);
	allCodecs.append(labelCodecG711u);
	allCodecs.append(labelCodecGSM);
#ifdef HAVE_SPEEX
	allCodecs.append(labelCodecSpeexNb);
	allCodecs.append(labelCodecSpeexWb);
	allCodecs.append(labelCodecSpeexUwb);
#endif
#ifdef HAVE_ILBC
	allCodecs.append(labelCodecIlbc);
#endif
	activeCodecListBox->clear();
	list<t_audio_codec> audio_codecs = current_profile->get_codecs();
	for (list<t_audio_codec>::iterator i = audio_codecs.begin(); i != audio_codecs.end(); i++)
	{
		activeCodecListBox->insertItem(codec2label(*i));
		allCodecs.remove(codec2label(*i));
	}
	availCodecListBox->clear();
	if (!allCodecs.empty()) availCodecListBox->insertStringList(allCodecs);
	
	// G.711
	ptimeSpinBox->setValue(current_profile->get_ptime());
	
	// Speex
	spxVbrCheckBox->setChecked(
			current_profile->get_speex_bit_rate_type() == BIT_RATE_VBR);
	spxVadCheckBox->setChecked(current_profile->get_speex_vad());
	spxDtxCheckBox->setChecked(current_profile->get_speex_dtx());
	spxPenhCheckBox->setChecked(current_profile->get_speex_penh());
	spxComplexitySpinBox->setValue(current_profile->get_speex_complexity());
	spxNbPayloadSpinBox->setValue(current_profile->get_speex_nb_payload_type());
	spxWbPayloadSpinBox->setValue(current_profile->get_speex_wb_payload_type());
	spxUwbPayloadSpinBox->setValue(current_profile->get_speex_uwb_payload_type());
	
	// iLBC
	ilbcPayloadSpinBox->setValue(current_profile->get_ilbc_payload_type());
	
	if (current_profile->get_ilbc_mode() == 20) {
		ilbcPayloadSizeComboBox->setCurrentItem(idxIlbcMode20);
	} else {
		ilbcPayloadSizeComboBox->setCurrentItem(idxIlbcMode30);
	}
	
	// DTMF
	switch (current_profile->get_dtmf_transport()) {
	case DTMF_RFC2833:
		dtmfTransportComboBox->setCurrentItem(idxDtmfRfc2833);
		break;
	case DTMF_INBAND:
		dtmfTransportComboBox->setCurrentItem(idxDtmfInband);
		break;
	default:
		dtmfTransportComboBox->setCurrentItem(idxDtmfAuto);
		break;
	}
	
	dtmfPayloadTypeSpinBox->setValue(current_profile->get_dtmf_payload_type());
	dtmfDurationSpinBox->setValue(current_profile->get_dtmf_duration());
	dtmfPauseSpinBox->setValue(current_profile->get_dtmf_pause());
	dtmfVolumeSpinBox->setValue(-(current_profile->get_dtmf_volume()));
	
	// SIP PROTOCOL
	switch (current_profile->get_hold_variant()) {
	case HOLD_RFC2543:
		holdVariantComboBox->setCurrentItem(idxHoldRfc2543);
		break;
	default:
		holdVariantComboBox->setCurrentItem(idxHoldRfc3264);
		break;
	}
	
	maxForwardsCheckBox->setChecked(current_profile->get_check_max_forwards());
	missingContactCheckBox->setChecked(current_profile->get_allow_missing_contact_reg());
	regTimeCheckBox->setChecked(current_profile->get_registration_time_in_contact());
	compactHeadersCheckBox->setChecked(current_profile->get_compact_headers());
	multiValuesListCheckBox->setChecked(
			current_profile->get_encode_multi_values_as_list());
	useDomainInContactCheckBox->setChecked(
			current_profile->get_use_domain_in_contact());
	allowSdpChangeCheckBox->setChecked(current_profile->get_allow_sdp_change());
	allowRedirectionCheckBox->setChecked(current_profile->get_allow_redirection());
	askUserRedirectCheckBox->setEnabled(current_profile->get_allow_redirection());
	askUserRedirectCheckBox->setChecked(current_profile->get_ask_user_to_redirect());
	maxRedirectTextLabel->setEnabled(current_profile->get_allow_redirection());
	maxRedirectSpinBox->setEnabled(current_profile->get_allow_redirection());
	maxRedirectSpinBox->setValue(current_profile->get_max_redirections());
	ext100relComboBox->setCurrentItem(
			ext_support2indexComboItem(current_profile->get_ext_100rel()));
	allowReferCheckBox->setChecked(current_profile->get_allow_refer());
	askUserReferCheckBox->setEnabled(current_profile->get_allow_refer());
	askUserReferCheckBox->setChecked(current_profile->get_ask_user_to_refer());
	refereeHoldCheckBox->setEnabled(current_profile->get_allow_refer());
	refereeHoldCheckBox->setChecked(current_profile->get_referee_hold());
	referrerHoldCheckBox->setChecked(current_profile->get_referrer_hold());
	refreshReferSubCheckBox->setChecked(current_profile->get_auto_refresh_refer_sub());
	
	// NAT
	if (current_profile->get_use_nat_public_ip()) {
		natStaticRadioButton->setChecked(true);
	} else if (current_profile->get_use_stun()) {
		natStunRadioButton->setChecked(true);
	} else {
		natNoneRadioButton->setChecked(true);
	}
	
	publicIPTextLabel->setEnabled(current_profile->get_use_nat_public_ip());
	publicIPLineEdit->setEnabled(current_profile->get_use_nat_public_ip());
	publicIPLineEdit->setText(current_profile->get_nat_public_ip().c_str());
	stunServerTextLabel->setEnabled(current_profile->get_use_stun());
	stunServerLineEdit->setEnabled(current_profile->get_use_stun());
	stunServerLineEdit->setText(current_profile->get_stun_server().
				    encode_noscheme().c_str());
	
	// ADDRESS FORMAT
	displayTelUserCheckBox->setChecked(current_profile->get_display_useronly_phone());
	numericalUserIsTelCheckBox->setChecked(
			current_profile->get_numerical_user_is_phone());
	removeSpecialCheckBox->setChecked(
			current_profile->get_remove_special_phone_symbols());
	specialLineEdit->setText(current_profile->get_special_phone_symbols().c_str());
	
	conversionListView->clear();
	conversionListView->setSorting(-1);
	list<t_number_conversion> conversions = current_profile->get_number_conversions();
	for (list<t_number_conversion>::reverse_iterator i = conversions.rbegin(); i != conversions.rend(); i++)
	{
		new QListViewItem(conversionListView, i->re.str().c_str(), i->fmt.c_str());
	}
	
	// TIMERS
	tmrNoanswerSpinBox->setValue(current_profile->get_timer_noanswer());
	tmrNatKeepaliveSpinBox->setValue(current_profile->get_timer_nat_keepalive());
	
	// RING TONES
	ringtoneLineEdit->setText(current_profile->get_ringtone_file().c_str());
	ringbackLineEdit->setText(current_profile->get_ringback_file().c_str());
	
	// SCRIPTS
	incomingCallScriptLineEdit->setText(current_profile->get_script_incoming_call().c_str());
	inCallAnsweredLineEdit->setText(current_profile->get_script_in_call_answered().c_str());
	inCallFailedLineEdit->setText(current_profile->get_script_in_call_failed().c_str());
	outCallLineEdit->setText(current_profile->get_script_outgoing_call().c_str());
	outCallAnsweredLineEdit->setText(current_profile->get_script_out_call_answered().c_str());
	outCallFailedLineEdit->setText(current_profile->get_script_out_call_failed().c_str());
	localReleaseLineEdit->setText(current_profile->get_script_local_release().c_str());
	remoteReleaseLineEdit->setText(current_profile->get_script_remote_release().c_str());
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
	map_last_cat.clear();
	initProfileList(profiles, show_profile);
	populate();
	
	// Show form
	QDialog::show();
}

// Modal execution
int UserProfileForm::exec(list<t_user *> profiles, QString show_profile)
{
	map_last_cat.clear();
	initProfileList(profiles, show_profile);
	populate();
	return QDialog::exec();
}

bool UserProfileForm::check_dynamic_payload(QSpinBox *spb, 
					    QValueList<int> &checked_list) 
{
	if (checked_list.contains(spb->value())) {
		categoryListBox->setSelected(idxCatRtpAudio, true);
		settingsWidgetStack->raiseWidget(pageRtpAudio);
		QString msg = "Dynamic payload type ";
		msg += QString().setNum(spb->value());
		msg += " is used more than once.";
		((t_gui *)ui)->cb_show_msg(this, msg.ascii(), MSG_CRITICAL);
		spb->setFocus();
		return false;
	}
	
	checked_list.append(spb->value());
	return true;
}

list<t_number_conversion> UserProfileForm::get_number_conversions()
{
	list<t_number_conversion> conversions;
	QListViewItemIterator it(conversionListView);
	while (it.current()) {
		QListViewItem *item = it.current();
		t_number_conversion c;
		
		try {
			c.re.assign(item->text(colExpr).ascii());
			c.fmt = item->text(colReplace).ascii();
			conversions.push_back(c);
		} catch (boost::bad_expression) {
			// Should never happen as validity has been
			// checked already. Just being defensive here.
		}

		++it;
	}
	
	return conversions;
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
	
	// Check for double RTP dynamic payload types
	QValueList<int> checked_types;
	if (!check_dynamic_payload(spxNbPayloadSpinBox, checked_types) ||
	    !check_dynamic_payload(spxWbPayloadSpinBox, checked_types) ||
	    !check_dynamic_payload(spxUwbPayloadSpinBox, checked_types))
	{
		rtpAudioTabWidget->showPage(tabSpeex);
		return false;
	}
	
	if (!check_dynamic_payload(ilbcPayloadSpinBox, checked_types)) {
		rtpAudioTabWidget->showPage(tabIlbc);
		return false;
	}
	
	if (!check_dynamic_payload(dtmfPayloadTypeSpinBox, checked_types)) {
		rtpAudioTabWidget->showPage(tabDtmf);
		return false;
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
	if (current_profile->get_name() != usernameLineEdit->text().ascii() ||
	    current_profile->get_display() != displayLineEdit->text().ascii() ||
	    current_profile->get_domain() != domainLineEdit->text().ascii())
	{
		current_profile->set_display(displayLineEdit->text().ascii());
		current_profile->set_name(usernameLineEdit->text().ascii());
		current_profile->set_domain (domainLineEdit->text().ascii());
		emit sipUserChanged(current_profile);
	}
	
	current_profile->set_organization(organizationLineEdit->text().ascii());
	
	if (current_profile->get_auth_realm() != authRealmLineEdit->text().ascii() ||
	    current_profile->get_auth_name() != authNameLineEdit->text().ascii() ||
	    current_profile->get_auth_pass() != authPasswordLineEdit->text().ascii())
	{
		emit authCredentialsChanged(current_profile,
					current_profile->get_auth_realm());
		
		current_profile->set_auth_realm(authRealmLineEdit->text().ascii());
		current_profile->set_auth_name(authNameLineEdit->text().ascii());
		current_profile->set_auth_pass(authPasswordLineEdit->text().ascii());
	}

	// SIP SERVER
	current_profile->set_use_registrar(!registrarLineEdit->text().isEmpty());
	s = USER_SCHEME;
	s.append(':').append(registrarLineEdit->text());
	current_profile->set_registrar(t_url(s.ascii()));
	current_profile->set_registration_time(expirySpinBox->value());
	current_profile->set_register_at_startup(regAtStartupCheckBox->isChecked());
	
	current_profile->set_use_outbound_proxy(useProxyCheckBox->isChecked());
	s = USER_SCHEME;
	s.append(':').append(proxyLineEdit->text());
	current_profile->set_outbound_proxy(t_url(s.ascii()));
	current_profile->set_all_requests_to_proxy(allRequestsCheckBox->isChecked());
	current_profile->set_non_resolvable_to_proxy(
			proxyNonResolvableCheckBox->isChecked());
	
	// RTP AUDIO
	// Codecs
	list<t_audio_codec> audio_codecs;
	for (int i = 0; i < activeCodecListBox->count(); i++) {
		audio_codecs.push_back(label2codec(activeCodecListBox->text(i)));
	}
	current_profile->set_codecs(audio_codecs);
	
	// G.711
	current_profile->set_ptime(ptimeSpinBox->value());
	
	// Speex
	current_profile->set_speex_bit_rate_type(
		(spxVbrCheckBox->isChecked() ? BIT_RATE_VBR : BIT_RATE_CBR));
	current_profile->set_speex_vad(spxVadCheckBox->isChecked());
	current_profile->set_speex_dtx(spxDtxCheckBox->isChecked());
	current_profile->set_speex_penh(spxPenhCheckBox->isChecked());
	current_profile->set_speex_complexity(spxComplexitySpinBox->value());
	current_profile->set_speex_nb_payload_type(spxNbPayloadSpinBox->value());
	current_profile->set_speex_wb_payload_type(spxWbPayloadSpinBox->value());
	current_profile->set_speex_uwb_payload_type(spxUwbPayloadSpinBox->value());
	
	// iLBC
	current_profile->set_ilbc_payload_type(ilbcPayloadSpinBox->value());
	switch (ilbcPayloadSizeComboBox->currentItem()) {
	case idxIlbcMode20:
		current_profile->set_ilbc_mode(20);
		break;
	default:
		current_profile->set_ilbc_mode(30);
		break;
	}
	
	// DTMF
	switch (dtmfTransportComboBox->currentItem()) {
	case idxDtmfRfc2833:
		current_profile->set_dtmf_transport(DTMF_RFC2833);
		break;
	case idxDtmfInband:
		current_profile->set_dtmf_transport(DTMF_INBAND);
		break;
	default:
		current_profile->set_dtmf_transport(DTMF_AUTO);
		break;
	}
	
	current_profile->set_dtmf_payload_type(dtmfPayloadTypeSpinBox->value());
	current_profile->set_dtmf_duration(dtmfDurationSpinBox->value());
	current_profile->set_dtmf_pause(dtmfPauseSpinBox->value());
	current_profile->set_dtmf_volume(-(dtmfVolumeSpinBox->value()));
	
	// SIP PROTOCOL
	switch (holdVariantComboBox->currentItem()) {
	case idxHoldRfc2543:
		current_profile->set_hold_variant(HOLD_RFC2543);
		break;
	default:
		current_profile->set_hold_variant(HOLD_RFC3264);
		break;
	}
	
	current_profile->set_check_max_forwards(maxForwardsCheckBox->isChecked());
	current_profile->set_allow_missing_contact_reg(missingContactCheckBox->isChecked());
	current_profile->set_registration_time_in_contact(regTimeCheckBox->isChecked());
	current_profile->set_compact_headers(compactHeadersCheckBox->isChecked());
	current_profile->set_encode_multi_values_as_list(
			multiValuesListCheckBox->isChecked());
	current_profile->set_use_domain_in_contact(
			useDomainInContactCheckBox->isChecked());
	current_profile->set_allow_sdp_change(allowSdpChangeCheckBox->isChecked());
	current_profile->set_allow_redirection(allowRedirectionCheckBox->isChecked());
	current_profile->set_ask_user_to_redirect(askUserRedirectCheckBox->isChecked());
	current_profile->set_max_redirections(maxRedirectSpinBox->value());
	current_profile->set_ext_100rel(indexComboItem2ext_support(
			ext100relComboBox->currentItem()));
	current_profile->set_allow_refer(allowReferCheckBox->isChecked());
	current_profile->set_ask_user_to_refer(askUserReferCheckBox->isChecked());
	current_profile->set_referee_hold(refereeHoldCheckBox->isChecked());
	current_profile->set_referrer_hold(referrerHoldCheckBox->isChecked());
	current_profile->set_auto_refresh_refer_sub(refreshReferSubCheckBox->isChecked());
	
	// NAT
	current_profile->set_use_nat_public_ip(natStaticRadioButton->isChecked());
	current_profile->set_nat_public_ip(publicIPLineEdit->text().ascii());
	current_profile->set_use_stun(natStunRadioButton->isChecked());
	
	if (current_profile->get_stun_server().encode_noscheme() != 
	    stunServerLineEdit->text().ascii()) 
	{
		s = "stun:";
		s.append(stunServerLineEdit->text());
		current_profile->set_stun_server(t_url(s.ascii()));
		emit stunServerChanged(current_profile);
	}
	
	// ADDRESS FORMAT
	current_profile->set_display_useronly_phone(
			displayTelUserCheckBox->isChecked());
	current_profile->set_numerical_user_is_phone(
			numericalUserIsTelCheckBox->isChecked());
	current_profile->set_remove_special_phone_symbols(
			removeSpecialCheckBox->isChecked());
	current_profile->set_special_phone_symbols(
			specialLineEdit->text().stripWhiteSpace().ascii());
	current_profile->set_number_conversions(get_number_conversions());
	
	// TIMERS
	current_profile->set_timer_noanswer(tmrNoanswerSpinBox->value());
	current_profile->set_timer_nat_keepalive(tmrNatKeepaliveSpinBox->value());
	
	// RING TONES
	current_profile->set_ringtone_file(ringtoneLineEdit->text().stripWhiteSpace().ascii());
	current_profile->set_ringback_file(ringbackLineEdit->text().stripWhiteSpace().ascii());
	
	// SCRIPTS
	current_profile->set_script_incoming_call(incomingCallScriptLineEdit->
					text().stripWhiteSpace().ascii());
	current_profile->set_script_in_call_answered(inCallAnsweredLineEdit->
					text().stripWhiteSpace().ascii());
	current_profile->set_script_in_call_failed(inCallFailedLineEdit->
					text().stripWhiteSpace().ascii());
	current_profile->set_script_outgoing_call(outCallLineEdit->
					text().stripWhiteSpace().ascii());
	current_profile->set_script_out_call_answered(outCallAnsweredLineEdit->
					text().stripWhiteSpace().ascii());
	current_profile->set_script_out_call_failed(outCallFailedLineEdit->
					text().stripWhiteSpace().ascii());
	current_profile->set_script_local_release(localReleaseLineEdit->
					text().stripWhiteSpace().ascii());
	current_profile->set_script_remote_release(remoteReleaseLineEdit->
					text().stripWhiteSpace().ascii());
	
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
	
	// Store the current viewed category
	map_last_cat[current_profile] = categoryListBox->index(categoryListBox->selectedItem());
	
	// Change to new profile.
	for (list<t_user *>::iterator i = profile_list.begin(); i != profile_list.end(); i++) {
		if ((*i)->get_profile_name() == profileName.ascii()) {
			current_profile = *i;
			break;
		}
	}
	
	current_profile_idx = profileComboBox->currentItem();
	populate();
	
	// Restore last viewed category
	int idxCat = map_last_cat[current_profile];
	categoryListBox->setSelected(idxCat, true);
	showCategory(categoryListBox->selectedItem());
}

void UserProfileForm::chooseFile(QLineEdit *qle, const QString &filter, const QString &caption) 
{
	QString file = QFileDialog::getOpenFileName(
			((t_gui *)ui)->get_last_file_browse_path(),
			filter, this, "open file dialog",
			caption);
	if (!file.isEmpty()) {
		qle->setText(file);
		((t_gui *)ui)->set_last_file_browse_path(QFileInfo(file).dirPath(true));
	}	
}

void UserProfileForm::chooseRingtone()
{
	chooseFile(ringtoneLineEdit, "Ring tones (*.wav)", "Choose ring tone");
}

void UserProfileForm::chooseRingback()
{
	chooseFile(ringbackLineEdit, "Ring back tones (*.wav)", "Choose ring back tone");
}

void UserProfileForm::chooseIncomingCallScript()
{
	chooseFile(incomingCallScriptLineEdit, "All files (*)", "Choose incoming call script");
}

void UserProfileForm::chooseInCallAnsweredScript()
{
	chooseFile(inCallAnsweredLineEdit, "All files (*)", "Choose incoming call answered script");
}

void UserProfileForm::chooseInCallFailedScript()
{
	chooseFile(inCallFailedLineEdit, "All files (*)", "Choose incoming call failed script");
}

void UserProfileForm::chooseOutgoingCallScript()
{
	chooseFile(outCallLineEdit, "All files (*)", "Choose outgoing call script");
}

void UserProfileForm::chooseOutCallAnsweredScript()
{
	chooseFile(outCallAnsweredLineEdit, "All files (*)", "Choose outgoing call answered script");
}

void UserProfileForm::chooseOutCallFailedScript()
{
	chooseFile(outCallFailedLineEdit, "All files (*)", "Choose outgoing call failed script");
}

void UserProfileForm::chooseLocalReleaseScript()
{
	chooseFile(localReleaseLineEdit, "All files (*)", "Choose local release script");
}

void UserProfileForm::chooseRemoteReleaseScript()
{
	chooseFile(remoteReleaseLineEdit, "All files (*)", "Choose remote release script");
}

void UserProfileForm::addCodec() {
	for (int i = 0; i < availCodecListBox->count(); i++) {
		if (availCodecListBox->isSelected(i)) {
			activeCodecListBox->insertItem(availCodecListBox->text(i));
			activeCodecListBox->setSelected(
					activeCodecListBox->count() - 1, true);
			availCodecListBox->removeItem(i);
			return;
		}
	}
}

void UserProfileForm::removeCodec() {
	for (int i = 0; i < activeCodecListBox->count(); i++) {
		if (activeCodecListBox->isSelected(i)) {
			availCodecListBox->insertItem(activeCodecListBox->text(i));
			availCodecListBox->setSelected(
					availCodecListBox->count() - 1, true);
			activeCodecListBox->removeItem(i);
			return;
		}
	}
}

void UserProfileForm::upCodec() {
	QListBoxItem *lbi = activeCodecListBox->selectedItem();
	if (!lbi) return;
	
	int idx = activeCodecListBox->index(lbi);
	if (idx == 0) return;
	
	QString label = lbi->text();
	activeCodecListBox->removeItem(idx);
	activeCodecListBox->insertItem(label, idx - 1);
	activeCodecListBox->setSelected(idx - 1, true);
}

void UserProfileForm::downCodec() {
	QListBoxItem *lbi = activeCodecListBox->selectedItem();
	if (!lbi) return;
	
	int idx = activeCodecListBox->index(lbi);
	if (idx == activeCodecListBox->count() - 1) return;
	
	QString label = lbi->text();
	activeCodecListBox->removeItem(idx);
	activeCodecListBox->insertItem(label, idx + 1);
	activeCodecListBox->setSelected(idx + 1, true);
}

void UserProfileForm::upConversion() {
	QListViewItem *lvi = conversionListView->selectedItem();
	if (!lvi) return;
	
	QListViewItem *above = lvi->itemAbove();
	if (!above) return;
	
	QListViewItem *newAbove = above->itemAbove();
	
	if (newAbove) {
		lvi->moveItem(newAbove);
	} else {
		above->moveItem(lvi);
	}
		
	lvi->setSelected(true);
}

void UserProfileForm::downConversion() {
	QListViewItem *lvi = conversionListView->selectedItem();
	if (!lvi) return;
	
	QListViewItem *below = lvi->itemBelow();
	if (!below) return;
	
	lvi->moveItem(below);
	lvi->setSelected(true);
}

void UserProfileForm::addConversion() {
	QString expr;
	QString replace;
	
	NumberConversionForm f;
	if (f.exec(expr, replace) == QDialog::Accepted) {
		QListViewItem *last = conversionListView->lastItem();
		if (last) {
			new QListViewItem(conversionListView, last, expr, replace);
		} else {
			new QListViewItem(conversionListView, expr, replace);
		}
	}
}

void UserProfileForm::editConversion() {
	QListViewItem *lvi = conversionListView->selectedItem();
	if (!lvi) return;
	 
	QString expr = lvi->text(colExpr);
	QString replace = lvi->text(colReplace);
	
	NumberConversionForm f;
	if (f.exec(expr, replace) == QDialog::Accepted) {
		lvi->setText(colExpr, expr);
		lvi->setText(colReplace, replace);
	}
}

void UserProfileForm::removeConversion() {
	QListViewItem *lvi = conversionListView->selectedItem();
	if (!lvi) return;
	delete lvi;
}

void UserProfileForm::testConversion() {
	QString number = testConversionLineEdit->text();
	if (number.isEmpty()) return;
	
	bool remove_special_phone_symbols = removeSpecialCheckBox->isChecked();
	QString special_phone_symbols = specialLineEdit->text();
	
	number = remove_white_space(number.ascii()).c_str();
	
	// Remove special symbols
	if (remove_special_phone_symbols &&
	    looks_like_phone(number.ascii(), special_phone_symbols.ascii()))
	{
		number = remove_symbols(
				number.ascii(), special_phone_symbols.ascii()).c_str();
	}
	
	QString msg = number;
	msg += " converts to ";
	msg += current_profile->convert_number(
			number.ascii(), get_number_conversions()).c_str();
	
	((t_gui *)ui)->cb_show_msg(this,  msg.ascii(), MSG_INFO);
}
