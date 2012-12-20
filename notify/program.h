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

#ifndef MAIN_H_
#define MAIN_H_

#include <coastal-qt-config.h>
#include <coastal.h>
#include <QApplication>
#include <QTranslator>
#include <QSettings>
#include <QMenu>
#include <QTimer>
#include <iostream>

class Options
{
public:
    qreal opacity;
    unsigned timeout;
    bool show_icons;
    bool modified;

    Options();
    ~Options();
};

class Main : public CoastalMain
{
Q_OBJECT
public:
    Main();
    virtual ~Main();
    
    Options options;

public slots:
    void action(QSystemTrayIcon::ActivationReason reason);
};

class Notice : public QDialog
{
Q_OBJECT

private:
    QTimer timer;

public:
    Notice(Options& options, const char *title, const char *summary = NULL, const char *icon = NULL);
    ~Notice();

    static unsigned count(void);
};

#endif

