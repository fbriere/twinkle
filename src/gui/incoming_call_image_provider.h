/*
    Copyright (C) 2018  Frédéric Brière <fbriere@fbriere.net>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef T_INCOMING_CALL_IMAGE_PROVIDER_H
#define T_INCOMING_CALL_IMAGE_PROVIDER_H

#include <QQuickImageProvider>

// Generic image provider which allows changing the image dynamically from a
// QImage.
//
// (Despite its name, nothing in this class is actually specific to the
// incoming call popup; it could therefore be renamed and used elsewhere if
// necessary.)

class IncomingCallImageProvider : public QObject, public QQuickImageProvider
{
	Q_OBJECT
public:
	IncomingCallImageProvider(const QString &defaultFileName);

	QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);

signals:
	void imageChanged();

public slots:
	void setImage(const QImage& image);

private:
	QImage m_currentImage;
	QImage m_defaultImage;
};

#endif
