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


int SelectProfileForm::exec()
{
	profileListBox->clear();
	idxDefaultProfile = -1;
	
	// Get list of all profiles
	QStringList profiles;
	QString error;
	if (!SelectProfileForm::getUserProfiles(profiles, error)) {
		QMessageBox::critical(this, PRODUCT_NAME, error);
		return QDialog::Rejected;
	}
	
	// If there are no profiles then the user has to create one
	if (profiles.isEmpty()) {
		QMessageBox::information(this, PRODUCT_NAME,
			"Before you can use Twinkle, you must create a user "\
			"profile.\nClick OK to create a profile.");
		
		int useWizard = QMessageBox::question(this, PRODUCT_NAME,
			"You can use the profile editor to create a profile. "\
			"With the profile editor you can change many settings "\
			"to tune the SIP protocol, RTP and many other things.\n"\
			"Alternatively you can use the wizard to quickly setup a "\
			"user profile. The wizard asks you only a few essential "\
			"settings. If you create a user profile with the wizard you "\
			"can still edit the full profile with the profile editor at a later "\
			"time.\n"\
			"Choose what method you wish to use.",
			"&Wizard", "&Profile editor", QString::null);
		
		if (useWizard == 0) {
			wizardProfile();
		} else if (useWizard == 1) {
			newProfile();
		} else {
			return QDialog::Rejected;
		}
		
		if (profileListBox->count() == 0) {
			// No profile has been created.
			return QDialog::Rejected;
		}
		selectedProfile = profileListBox->currentText();
		selectedProfile.append(".cfg");
		
		QMessageBox::information(this, PRODUCT_NAME,
			"Next you may adjust the system settings. "\
			"You can change these settings always at a later time.\n"\
			"Click OK to view and adjust the system settings.");
		
		SysSettingsForm f(this, "system settings", true);
		f.exec();
		
		return QDialog::Accepted;
	}
	
	// Put the profiles in the profile list box
	for (QStringList::Iterator i = profiles.begin(); i != profiles.end(); i++) {
		// Strip off the .cfg suffix
		QString profile = *i;
		profile.truncate(profile.length() - 4);
		profileListBox->insertItem(
			QPixmap::fromMimeSource("penguin-small.png"), profile);
	}
	
	// Set first profile as selected
	profileListBox->setSelected(0, true);
	runPushButton->setFocus();
	
	// Show the modal dialog
	return QDialog::exec();
}

void SelectProfileForm::runProfile()
{
	selectedProfile = profileListBox->currentText();
	selectedProfile.append(".cfg");
	accept();
}

void SelectProfileForm::editProfile()
{
	QString profile = profileListBox->currentText();
	profile.append(".cfg");
	
	// Read selected config file
	string error_msg;
	user_config = new t_user();
	MEMMAN_NEW(user_config);
	if (!user_config->read_config(profile.ascii(), error_msg)) {
		((t_gui *)ui)->cb_show_msg(this, error_msg, MSG_WARNING);
		MEMMAN_DELETE(user_config);
		delete user_config;
		return;
	}
	
	// Show the edit user profile form (modal dialog)
	UserProfileForm f(this, "edit user profile", true);
	f.exec();
	
	MEMMAN_DELETE(user_config);
	delete user_config;
}

void SelectProfileForm::newProfile()
{
	// Ask user for a profile name
	GetProfileNameForm getProfileNameForm(this, "get profile name", true);
	if (!getProfileNameForm.execNewName()) return;
	
	// Create file name
	QString profile = getProfileNameForm.getProfileName();
	QString filename = profile;
	filename.append(".cfg");
	
	// Create a new user config
	user_config = new t_user();
	MEMMAN_NEW(user_config);
	user_config->set_config(filename.ascii());
	
	// Show the edit user profile form (modal dialog)
	UserProfileForm f(this, "edit user profile", true);
	if (f.exec()) {
		// New profile created
		// Add the new profile to the profile list box
		profileListBox->insertItem(
			QPixmap::fromMimeSource("penguin-small.png"), profile);
		
		// Make the new profile the selected profile
		// Do not change this without changing the exec method.
		// When there are no profiles, the exec methods relies on the
		// fact that afer creation of the profile it is selected.
		profileListBox->setSelected(profileListBox->count() - 1, true);
		
		// Enable buttons that act on a profile
		editPushButton->setEnabled(true);
		deletePushButton->setEnabled(true);
		runPushButton->setEnabled(true);
	}
	
	MEMMAN_DELETE(user_config);
	delete user_config;
}

void SelectProfileForm::deleteProfile()
{
	QString profile = profileListBox->currentText();
	QString msg = "Are you sure you want to delete profile '";
	msg.append(profile).append("'?");
	QMessageBox *mb = new QMessageBox("Delete profile", msg,
			QMessageBox::Warning,
			QMessageBox::Yes,
			QMessageBox::No,
			QMessageBox::NoButton,
			this);
	MEMMAN_NEW(mb);
	if (mb->exec() == QMessageBox::Yes) {
		// Delete file
		QDir d = QDir::home();
		d.cd(USER_DIR);
		QString filename = profile;
		filename.append(".cfg");
		QString fullname = d.filePath(filename);
		if (!QFile::remove(fullname)) {
			// Failed to delete file
			QMessageBox::critical(this, PRODUCT_NAME,
				"Failed to delete profile.");
		} else {
			// Delete possible backup of the profile
			QString backupname = fullname;
			backupname.append("~");
			(void)QFile::remove(backupname);
			
			// Delete profile from profile list box
			profileListBox->removeItem(profileListBox->currentItem());
			if (profileListBox->count() == 0) {
				// There are no profiles anymore
				// Disable buttons that act on a profile
				editPushButton->setEnabled(false);
				deletePushButton->setEnabled(false);
				runPushButton->setEnabled(false);
			} else {
				profileListBox->setSelected(0, true);
			}
		}
	}
	
	MEMMAN_DELETE(mb);
	delete mb;
}

void SelectProfileForm::renameProfile()
{
	QString oldProfile = profileListBox->currentText();
	
	// Ask user for a new profile name
	GetProfileNameForm getProfileNameForm(this, "get profile name", true);
	if (!getProfileNameForm.execRename(oldProfile)) return;
	
	// Create file name for the new profile
	QString newProfile = getProfileNameForm.getProfileName();
	QString newFilename = newProfile;
	newFilename.append(".cfg");
	
	// Create file name for the old profile
	QString oldFilename = oldProfile;
	oldFilename.append(".cfg");
	
	// Rename the file
	QDir d = QDir::home();
	d.cd(USER_DIR);
	if (!d.rename(oldFilename, newFilename)) {
		// Failed to delete file
		QMessageBox::critical(this, PRODUCT_NAME, 
				      "Failed to rename profile.");
	} else {
		// If there is a backup of the profile, rename it too.
		QString oldBackupFilename = oldFilename;
		oldBackupFilename.append("~");
		QString oldBackupFullname = d.filePath(oldBackupFilename);
		if (QFile::exists(oldBackupFullname)) {
			QString newBackupFilename = newFilename;
			newBackupFilename.append("~");
			d.rename(oldBackupFilename, newBackupFilename);
		}
		
		// Change profile name in the list box
		profileListBox->changeItem(
			QPixmap::fromMimeSource("penguin-small.png"), newProfile,
			profileListBox->currentItem());
	}
}

void SelectProfileForm::setAsDefault()
{
	// Only show the information when the default button is
	// pressed for the first time.
	if (idxDefaultProfile == -1) {
		QMessageBox::information(this, PRODUCT_NAME, 
			"If you want to remove or "
			"change the default at a later time, you can do that "
			"via the system settings.");
	}
	
	// Store current index as the changeItem method also changes
	// the current index as a side effect.
	int idxNewDefault = profileListBox->currentItem();
	
	// Restore pixmap of the old default
	if (idxDefaultProfile != -1) {
		profileListBox->changeItem(
			QPixmap::fromMimeSource("penguin-small.png"),
			profileListBox->text(idxDefaultProfile),
			idxDefaultProfile);
	}
	
	// Set pixmap of the default
	idxDefaultProfile = idxNewDefault;
	profileListBox->changeItem(
		QPixmap::fromMimeSource("twinkle16.png"),
		profileListBox->text(idxDefaultProfile),
		idxDefaultProfile);
	
	// Write default to system settings
	sys_config->start_user_profile = profileListBox->currentText().ascii();
	string error_msg;
	if (!sys_config->write_config(error_msg)) {
		// Failed to write config file
		((t_gui *)ui)->cb_show_msg(this, error_msg, MSG_CRITICAL);
	}
}

void SelectProfileForm::wizardProfile()
{
	// Ask user for a profile name
	GetProfileNameForm getProfileNameForm(this, "get profile name", true);
	if (!getProfileNameForm.execNewName()) return;
	
	// Create file name
	QString profile = getProfileNameForm.getProfileName();
	QString filename = profile;
	filename.append(".cfg");
	
	// Create a new user config
	user_config = new t_user();
	MEMMAN_NEW(user_config);
	user_config->set_config(filename.ascii());
	
	// Show the wizard form (modal dialog)
	WizardForm f(this, "wizard", true);
	if (f.exec()) {
		// New profile created
		// Add the new profile to the profile list box
		profileListBox->insertItem(
			QPixmap::fromMimeSource("penguin-small.png"), profile);
		
		// Make the new profile the selected profile
		// Do not change this without changing the exec method.
		// When there are no profiles, the exec methods relies on the
		// fact that afer creation of the profile it is selected.
		profileListBox->setSelected(profileListBox->count() - 1, true);
		
		// Enable buttons that act on a profile
		editPushButton->setEnabled(true);
		deletePushButton->setEnabled(true);
		runPushButton->setEnabled(true);
	}
	
	MEMMAN_DELETE(user_config);
	delete user_config;
}

// Get a list of all profiles. Returns false if there is an error.
bool SelectProfileForm::getUserProfiles(QStringList &profiles, QString &error)
{
	// Find the .twinkle directory in HOME
	QDir d = QDir::home();
	if (!d.cd(USER_DIR)) {
		error = "Cannot find .twinkle directory in your home directory.";
		return false;
	}
	
	// Select all config files
	d.setFilter(QDir::Files);
	d.setNameFilter("*.cfg");
	d.setSorting(QDir::Name | QDir::IgnoreCase);
	profiles = d.entryList();
	
	return true;
}
