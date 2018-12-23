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

#include "incoming_call_image_provider.h"

IncomingCallImageProvider::IncomingCallImageProvider(const QString &defaultFileName)
	: QQuickImageProvider(QQuickImageProvider::Image), m_defaultImage(defaultFileName)
{
}

QImage IncomingCallImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
	QImage image = m_currentImage.isNull() ? m_defaultImage : m_currentImage;

	if (size)
		*size = image.size();

	if (requestedSize.isValid())
		image = image.scaled(requestedSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

	return image;
}

void IncomingCallImageProvider::setImage(const QImage& image)
{
	m_currentImage = image;
	emit imageChanged();
}
