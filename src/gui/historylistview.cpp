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

#include "historylistview.h"
#include "util.h"

HistoryListViewItem::HistoryListViewItem( QListView * parent, const t_call_record &cr, QString label2, QString label3, QString label4, QString label5, QString label6, QString label7, QString label8 ) :
		QListViewItem(parent, time2str(cr.time_start).c_str(), label2, label3,
			      label4, label5, label6, label7, label8)
{
	call_record = cr;
}

int HistoryListViewItem::compare ( QListViewItem * i, int col, bool ascending ) const
{
	if (col != HISTCOL_TIMESTAMP) {
		return QListViewItem::compare(i, col, ascending);
	}
	if (call_record.time_start < ((HistoryListViewItem *)i)->get_time_start()) {
		return -1;
	}
	if (call_record.time_start == ((HistoryListViewItem *)i)->get_time_start()) {
		return 0;
	}
	return 1;
}

time_t HistoryListViewItem::get_time_start(void) const
{
	return call_record.time_start;
}

t_call_record HistoryListViewItem::get_call_record(void) const
{
	return call_record;
}
