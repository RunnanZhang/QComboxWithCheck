#ifndef RSLASSELECT_H
#define RSLASSELECT_H
#include "rslasnamespace.h"
#include <QWidget>
#include <QStringList>
using namespace RSLasSelectType;

namespace Ui {
class RSLasSelect;
}

class RSLasSelect : public QWidget
{
    Q_OBJECT

public:
    explicit RSLasSelect(QStringList list = QStringList(), QWidget *parent = 0);
    ~RSLasSelect();

signals:
    void okClick(RSComBoxType type);

private slots:
    void wOkClicked();
    void wAllClicked();
    void wNoneClicked();

private:
    bool eventFilter(QObject *obj, QEvent *ev);
    //void mousePressEvent(QMouseEvent * event);

private:
    Ui::RSLasSelect *ui;
};

#endif
