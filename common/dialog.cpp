// Copyright (C) 2011 David Sugar, Tycho Softworks
//
// This file is part of coastal-qt.
//
// Coastal-qt is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// coastal-qt is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with coastal-qt.  If not, see <http://www.gnu.org/licenses/>.

#include <coastal-qt-config.h>
#include <coastal.h>
#include <ui_about.h>

CoastalDialog::CoastalDialog() :
QDialog(NULL)
{
    dialog_version = VERSION;
    dialog_about = dialog_name = "Coastal Dialog";
    dialog_copyright = "2013 David Sugar";

    trayicon = NULL;
    url_support = "https://github.com/dyfet/coastal-qt/issues";

    Q_INIT_RESOURCE(coastal);
}

void CoastalDialog::support(void)
{
    Coastal::browser(url_support);
}

void CoastalDialog::about(void)
{
    QString title = tr("About ") + dialog_name;
    CoastalAbout info(this);
    info.setWindowTitle(title);
    info.setVersion(tr("Version: ") + dialog_version);
    info.setAbout(tr(dialog_about));
    info.setCopyright(tr("Copyright (c) ") + dialog_copyright);
    QIcon icon = windowIcon();
    QPixmap image = icon.pixmap(48, 48, QIcon::Normal, QIcon::On);
    QGraphicsScene scene;
    QGraphicsPixmapItem *item = scene.addPixmap(image);
    item->setVisible(true);
    info.setImage(scene);
    info.exec();
}
