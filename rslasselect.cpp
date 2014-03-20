#include "rslasselect.h"
#include "ui_rslasselect.h"
#include <QDebug>
#include <QStringList>
#include <QMouseEvent>
#include <QResizeEvent>

RSLasSelect::RSLasSelect(QStringList list, QWidget *parent) :
    QWidget(parent), ui(new Ui::RSLasSelect)
{
    ui->setupUi(this);
    QStringList::const_iterator it;
    for (it = list.constBegin(); it != list.constEnd(); ++it)
    {
        new QListWidgetItem(*it, ui->wListWidget);
    }
    ui->wListWidget->setSelectionMode(QAbstractItemView::MultiSelection);

    parent->installEventFilter(this);
    this->installEventFilter(this);
    //this->setAttribute(Qt::WA_NoMousePropagation);
}

RSLasSelect::~RSLasSelect()
{
    delete ui;
}

bool RSLasSelect::eventFilter(QObject *obj, QEvent *ev)
{
    if (obj == parent() && ev->type() == QEvent::MouseButtonPress)
    {
        this->hide();
    }
    if(obj == this->parent() && ev->type() == QEvent::Resize)
    {
        QResizeEvent *event = static_cast<QResizeEvent *>(ev);
        QRect locationRect = this->geometry();
        int nX = locationRect.x();
        int nY = locationRect.y();
        int nW = locationRect.width() + event->size().width() - event->oldSize().width();
        int nH = locationRect.height()+ event->size().height() - event->oldSize().height();
        this->setGeometry(nX, nY, nW, nH);
        //return true;
    }
    if(obj == this && ev->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *event = static_cast<QMouseEvent *>(ev);

        QWidget::mousePressEvent(event);
        event->accept();

        return true;
    }
    return QWidget::eventFilter(obj, ev);
}

//void RSLasSelect::mousePressEvent(QMouseEvent * event)
//{
//    event->accept();
//}

void RSLasSelect::wOkClicked()
{
    QList<QListWidgetItem *> list = ui->wListWidget->selectedItems();
    for(int i = 0; i < list.count(); ++i)
    {
        qDebug()<<list.at(i)->text();

    }
    this->hide();
}

void RSLasSelect::wAllClicked()
{
    ui->wListWidget->selectAll();
}

void RSLasSelect::wNoneClicked()
{
    ui->wListWidget->clearSelection();
}
