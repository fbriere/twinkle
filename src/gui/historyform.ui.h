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

QString str2html(const QString &s)
{
	QString result(s);
	
	result.replace('&', "&amp;");
	result.replace('<', "&lt;");
	result.replace('>', "&gt;");
	
	return result;
}

void HistoryForm::init()
{
	
	historyListView->setSorting(HISTCOL_TIMESTAMP, false);
	historyListView->setColumnWidthMode(HISTCOL_FROMTO, QListView::Manual);
	historyListView->setColumnWidth(HISTCOL_FROMTO, 200);
	historyListView->setColumnWidthMode(HISTCOL_SUBJECT, QListView::Manual);
	historyListView->setColumnWidth(HISTCOL_SUBJECT, 200);
	
	inCheckBox->setChecked(true);
	outCheckBox->setChecked(true);
	successCheckBox->setChecked(true);
	missedCheckBox->setChecked(true);
	profileCheckBox->setChecked(true);
	
	loadHistory();
}

void HistoryForm::loadHistory()
{
	historyListView->clear();
	list<t_call_record> history;
	call_history->get_history(history);
	for (list<t_call_record>::iterator i = history.begin(); i != history.end(); i++) {
		if (i->direction == t_call_record::DIR_IN && !inCheckBox->isChecked()) {
			continue;
		}
		if (i->direction == t_call_record::DIR_OUT && !outCheckBox->isChecked()) {
			continue;
		}
		if (i->invite_resp_code < 300 && !successCheckBox->isChecked()) {
			continue;
		}
		if (i->invite_resp_code >= 300 && !missedCheckBox->isChecked()) {
			continue;
		}
		if (i->user_profile != user_config->get_profile_name() &&
		    profileCheckBox->isChecked())
		{
			continue;
		}
		
		HistoryListViewItem *item = new HistoryListViewItem(historyListView,
			*i,
			i->get_direction().c_str(),
			(i->direction == t_call_record::DIR_IN ?
			 ui->format_sip_address(i->from_display, i->from_uri).c_str() :
			 ui->format_sip_address(i->to_display, i->to_uri).c_str()),
			i->subject.c_str(),
			i->invite_resp_reason.c_str());
		
		// Set direction icon
		item->setPixmap(HISTCOL_DIRECTION, (i->direction == t_call_record::DIR_IN ?
				    QPixmap::fromMimeSource("1leftarrow-yellow.png") :
				    QPixmap::fromMimeSource("1rightarrow.png")));
		
		// Set status icon
		item->setPixmap(HISTCOL_STATUS, (i->invite_resp_code < 300 ?
				    QPixmap::fromMimeSource("ok.png") :
				    QPixmap::fromMimeSource("cancel.png")));
	}
	
	QListViewItem *first = historyListView->firstChild();
	if (first) {
		historyListView->setSelected(first, true);
		showCallDetails(first);
	} else {
		cdrTextEdit->clear();
	}
}

// Update history when triggered by a call back function on the user
// interface.
void HistoryForm::update()
{
	// There is no need to update the history when the window is
	// hidden.
	if (isShown()) loadHistory();
}

void HistoryForm::show()
{
	if (isShown()) {
		raise();
		return;
	}
	
	loadHistory();
	QDialog::show();
	raise();
}

void HistoryForm::showCallDetails(QListViewItem *item)
{
	QString s;
	
	t_call_record cr = ((HistoryListViewItem *)item)->get_call_record();
	cdrTextEdit->clear();
	
	s = "<table>";
	
	// Left column: header names
	s += "<tr><td><b>";
	s += "Call start:<br>";
	s += "Call answer:<br>";
	s += "Call end:<br>";
	s += "Direction:<br>";
	s += "From:<br>";
	s += "To:<br>";
	if (cr.reply_to_uri.is_valid()) s += "Reply to:<br>";
	if (cr.referred_by_uri.is_valid()) s += "Referred by:<br>";
	s += "Subject:<br>";
	s += "Released by:<br>";
	s += "Status:<br>";
	if (!cr.far_end_device.empty()) s += "Far end device:<br>";
	s += "User profile:";
	s += "</b></td>";
	
	// Right column: values
	s += "<td>";
	s += time2str(cr.time_start).c_str();
	s += "<br>";
	if (cr.time_answer != 0) {
		s += time2str(cr.time_answer).c_str();
	}
	s += "<br>";
	s += time2str(cr.time_end).c_str();
	s += "<br>";
	s += cr.get_direction().c_str();
	s += "<br>";
	s += str2html(ui->format_sip_address(cr.from_display, cr.from_uri).c_str());
	if (cr.from_organization != "") {
		s += ", ";
		s += str2html(cr.from_organization.c_str());
	}
	s += "<br>";
	s +=  str2html(ui->format_sip_address(cr.to_display, cr.to_uri).c_str());
	if (cr.to_organization != "") {
		s += ", ";
		s +=  str2html(cr.to_organization.c_str());
	}
	s += "<br>";
	if (cr.reply_to_uri.is_valid()) {
		s +=  str2html(ui->format_sip_address(cr.reply_to_display, cr.reply_to_uri).c_str());
		s += "<br>";
	}
	if (cr.referred_by_uri.is_valid()) {
		s +=  str2html(ui->format_sip_address(
				cr.referred_by_display, cr.referred_by_uri).c_str());
		s += "<br>";
	}
	s +=  str2html(cr.subject.c_str());
	s += "<br>";
	s += cr.get_rel_cause().c_str();
	s += "<br>";
	s += int2str(cr.invite_resp_code).c_str();
	s += ' ';
	s +=  str2html(cr.invite_resp_reason.c_str());
	s += "<br>";
	if (!cr.far_end_device.empty()) {
		s += str2html(cr.far_end_device.c_str());
		s += "<br>";
	}
	s +=  str2html(cr.user_profile.c_str());
	s += "</td></tr>";
	
	s += "</table>";
	
	cdrTextEdit->setText(s);
}

void HistoryForm::popupMenu(QListViewItem *item, const QPoint &pos)
{
	if (!item) return;
	
	HistoryListViewItem *histItem = (HistoryListViewItem *)item;
	
	QIconSet inviteIcon(QPixmap::fromMimeSource("invite.png"));
	QIconSet deleteIcon(QPixmap::fromMimeSource("editdelete.png"));
	QPopupMenu menu(this);
	
	int itemCall = menu.insertItem(inviteIcon, "Call...");
	int itemDelete = menu.insertItem(deleteIcon, "Delete");
	int selected = menu.exec(pos);
	
	if (selected == -1) return;
	
	if (selected == itemCall) {
		call(item);
	} else if (selected == itemDelete) {
		call_history->delete_call_record(histItem->get_call_record().get_id());
	}
}

void HistoryForm::call(QListViewItem *item)
{
	if (!item) return;
	
	HistoryListViewItem *histItem = (HistoryListViewItem *)item;
	t_call_record cr = histItem->get_call_record();
	
	if (cr.direction == t_call_record::DIR_IN && cr.reply_to_uri.is_valid()) {
		// Call to the Reply-To contact
		emit call(ui->format_sip_address(cr.reply_to_display, cr.reply_to_uri).c_str());
	} else {
		// For incoming calls, call to the From contact
		// For outgoing calls, call to the To contact
		emit call(item->text(HISTCOL_FROMTO));
	}
}

void HistoryForm::clearHistory()
{
	call_history->clear();
}
