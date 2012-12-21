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

#ifndef _COASTAL_H_
#define _COASTAL_H_

#include <QIcon>
#include <QDialog>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDesktopServices>
#include <QSystemTrayIcon>
#include <QUrl>
#include <QDir>
#include <QProcess>
#include <QDebug>

class CoastalAbout : public QDialog
{
Q_OBJECT

protected:
    friend class CoastalMain;

    CoastalAbout(QWidget *parent);

    void setImage(QGraphicsScene& scene);
    void setVersion(const QString& text);
    void setAbout(const QString& text);
    void setCopyright(const QString& text);
};

class CoastalNotify : public QObject
{
    Q_OBJECT
public:
    typedef enum {
        None,
        DBUS
    } type_t;

    typedef enum {
        Expired     = 1,
        Dismissed   = 2,
        ForceClosed = 3,
        Unknown     = 4
    } reason_t;

    typedef enum
    {
        Low         = 0,
        Normal      = 1,
        High        = 2
    } priority_t;

    CoastalNotify(const QString& title, const QString& body, const QString& icon = "info", QObject* parent = NULL);
    ~CoastalNotify();

    bool update(void);
    void release(void);

    void setTitle(const QString& title);
    void setBody(const QString& body);
    void setIcon(const QString& icon);
    void setTimeout(int timeout);

    bool setActions(const QStringList& actions, int defaction = -1);
    bool setPriority(priority_t priority);

    static type_t getType(void);

private slots:
    void dbus_action(uint id, QString key);
    void dbus_close(uint, uint);

signals:
    void closed(reason_t reason);
    void activated(int action);

private:
    void *_dbus;
    uint _id;
    bool _updated;

    QString _title;
    QString _body;
    QString _icon;
    QStringList _actions;
    QVariantMap _hints;
    int _action;
    int _timeout;
};

class CoastalMain : public QMainWindow
{
Q_OBJECT

protected:
    const char *program_version, *program_about, *program_copyright, *program_name;
    const char *url_support;
    QSystemTrayIcon *trayicon;

    CoastalMain();

public slots:
    void about(void);
    void support(void);
};

class Coastal
{
public:
    static bool env(const char *id, char *buffer, size_t size);

    static QString env(const QString& id);

    static QString extension(const QString& filename);

    static QString mimefile(const QString& filename);

    static QString mimetype(const QString& extension);

    static bool browser(const QString& url);

    static bool open(const QString& filename);

    static bool notify(const QString& title, const QString& body, const QString& icon = "info");

    static bool away(void);
};

#endif

