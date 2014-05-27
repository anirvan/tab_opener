#ifndef HISTORYWIDGET_H
#define HISTORYWIDGET_H

#include <QtCore>
#include <QWidget>
#include <QClipboard>

#include "history.h"
#include "historybutton.h"

namespace Ui {
    class HistoryWidget;
}

/**
 * @brief File and Command history widgets
 *
 * Note: This is a dual purpose class: file and command history.
 *       I wanted to avoid mucking around with even more classes and abstraction
 *       for this relatively trivial case, so we just check the History::WidgetType flag
 *       for specific operations and use specific types.
 * Note: The id that is used in the history buttons is:
 *       - for file history the full file path
 *       - for command history the full command plus the working directory
 *         - there is a revese lookup map that is used to interpret the return signals (in buttonSelected)
 */
class HistoryWidget : public QWidget
{
    Q_OBJECT

public:

    explicit HistoryWidget(QWidget *parent = 0);
    ~HistoryWidget();

    void setType(History::WidgetType type);

signals:
    void selectedFileChanged(QString path);
    void selectedCommandChanged(QString command);
    void selectedFolderChanged(QString workingDirectory);

    void filePriActRequested(QString filePath);
    void fileSecActRequested(QString filePath);

    void idSelected(QString id); // internal signal to history buttons

public slots:
    void updateWidget(QList<History::Entry> recentHistory, QList<History::Entry> popularHistory);
    void fileSelected(QString filePath);
    void commandSelected(QString commandString);
    void workingDirectorySelected(QString workingDirectory);

private slots:
    void buttonSelected(QString id);

    void onControl0Clicked();
    void onControl1Clicked();
    void onControl2Clicked();

private:
    HistoryButton *getRecentBtnAt(int pos);
    HistoryButton *getPopularBtnAt(int pos);

    void updateFileHistory(QList<History::Entry> recentHistory, QList<History::Entry> popularHistory);
    void updateCommandHistory(QList<History::Entry> recentHistory, QList<History::Entry> popularHistory);

    Ui::HistoryWidget *ui;

    History::WidgetType type;

    QMap<QString, QStringList> cmdIds;

    QString selectedFile;
    QString selectedCommand;
    QString selectedWorkingDirectory;
};

#endif // HISTORYWIDGET_H
