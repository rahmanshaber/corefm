/*
CoreFM is a filemanager

CoreFM is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see {http://www.gnu.org/licenses/}. */

#ifndef MIMEUTILS_H
#define MIMEUTILS_H

#include "fileutils.h"

#include <QFileInfo>
#include <QProcess>
#include <QMimeDatabase>
#include <QMimeType>

#include "utilities.h"

/**
 * @class MimeUtils
 * @brief Helps with mime type management
 * @author Michal Rost
 * @date 29.4.2013
 */
class MimeUtils : public QObject {
  Q_OBJECT

public:
    explicit MimeUtils(QObject* parent = nullptr);
    virtual ~MimeUtils();
    void openInApp(QString exe, const QFileInfo &file, QObject* processOwner = nullptr);
    void openInApp(const QFileInfo &file, QObject* processOwner = nullptr);
    void setDefaultsFileName(const QString &fileName);
    void setDefault(const QString &mime, const QStringList &apps);
    QStringList getDefault(const QString &mime) const;
    QStringList getMimeTypes() const;
    QString getDefaultsFileName() const;

public slots:
    void generateDefaults();
    void saveDefaults();
    void loadDefaults();

private:
    bool defaultsChanged;
    QString defaultsFileName;
    Properties* defaults;


};

#endif // MIMEUTILS_H