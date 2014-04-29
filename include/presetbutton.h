#ifndef PRESETBUTTON_H
#define PRESETBUTTON_H

#include "hoverbutton.h"
#include <QPushButton>

class PresetButton : public HoverButton
{
    Q_OBJECT
public:
    explicit PresetButton(QWidget *parent = 0);

signals:
    void presetClicked(QString path);

public slots:
    void onClicked();

};

#endif // PRESETBUTTON_H