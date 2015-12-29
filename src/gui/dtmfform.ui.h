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


void DtmfForm::init()
{
	QRegExp rxDtmf("[0-9a-dA-D\\*#]+");
	QRegExpValidator *validator = new QRegExpValidator(rxDtmf, 0);
	// Do not report this allocation to MEMMAN as Qt will delete it when
	// the LineEdit is destroyed.
	digitStringLineEdit->setValidator(validator);
}

void DtmfForm::dtmf1()
{
	emit digits("1");
}

void DtmfForm::dtmf2()
{
	emit digits("2");
}

void DtmfForm::dtmf3()
{
	emit digits("3");
}

void DtmfForm::dtmf4()
{
	emit digits("4");
}

void DtmfForm::dtmf5()
{
	emit digits("5");
}

void DtmfForm::dtmf6()
{
	emit digits("6");
}

void DtmfForm::dtmf7()
{
	emit digits("7");
}

void DtmfForm::dtmf8()
{
	emit digits("8");
}

void DtmfForm::dtmf9()
{
	emit digits("9");
}

void DtmfForm::dtmf0()
{
	emit digits("0");
}

void DtmfForm::dtmfStar()
{
	emit digits("*");
}

void DtmfForm::dtmfPound()
{
	emit digits("#");
}

void DtmfForm::dtmfA()
{
	emit digits("A");
}

void DtmfForm::dtmfB()
{
	emit digits("B");
}

void DtmfForm::dtmfC()
{
	emit digits("C");
}

void DtmfForm::dtmfD()
{
	emit digits("D");
}

void DtmfForm::send()
{
	emit digits(digitStringLineEdit->text());
	digitStringLineEdit->clear();
}
