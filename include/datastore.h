#ifndef DATASTORE_H
#define DATASTORE_H

#include <QtCore>
#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QListWidgetItem>

class FileEntry
{
public:
    QString filePath;
    int usageCount;

    explicit FileEntry(QString path);
    static bool isMore(FileEntry *a, FileEntry *b);
};

struct RunEntry
{
    QString command;
    QString execPath;
};

class DataStore : public QObject
{
    Q_OBJECT
public:
    explicit DataStore(QObject *parent = 0);
    ~DataStore();
    void loadData();
    void saveData();

    // getters and setters follow

    void setPreset(int pos, QString path);
    QString getPreset(int pos);
    void setExtension(QString extension, QString openPath, QString editPath);
    QString getNotes();
    void setNotes(QString notes);

    QString getFileBrowser() const;
    void setFileBrowser(const QString &value);

    QString getTerminalEmulator() const;
    void setTerminalEmulator(const QString &value);

    QListWidgetItem* getExtMapItem(QString key);
    int getExtMapSize();
    void setExtMapItem(QString key, QListWidgetItem *widget);
    void deleteExtMapItem(QString key);
    bool extMapContains(QString key);
    QStringList getExtMapKeys();

    QString getOpenAppsItem(QString key);
    void setOpenAppsItem(QString key, QString value);
    void deleteOpenAppsItem(QString key);

    QString getEditMapItem(QString key);
    void setEditMapItem(QString key, QString value);
    void deleteEditMapItem(QString key);

    QString getRecentFile(int pos);
    int getRecentFileCount();
    void pushRecentFile(QString path);

    QString getPopularFile(int pos);
    int getPopularFileCount();

signals:

public slots:

private:
    QString presets[10];
    QString notes;
    QString fileBrowser;
    QString terminalEmulator;

    // extension configuration data
    QMap<QString, QListWidgetItem*> extMap;
    QMap<QString, QString> openApps; // ext -> open
    QMap<QString, QString> editApps; // ext -> edit

    QStringList recentFiles;
    QList<FileEntry*> fileLog; // sorted list of file entries based on usage count
    QMap<QString, FileEntry*> fileEntryIndex; //inde of path of file entries


    QSqlDatabase myDB;
};

#endif // DATASTORE_H
