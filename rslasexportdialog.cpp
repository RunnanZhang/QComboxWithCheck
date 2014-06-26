#include "rslasexportdialog.h"
#include "rslasselect.h"
#include "ui_rslasexportdialog.h"
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

RSLasExportDialog::RSLasExportDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::RSLasExportDialog)
{
    ui->setupUi(this);
    init();
}

RSLasExportDialog::~RSLasExportDialog()
{
    delete ui;
}

void RSLasExportDialog::init()
{
    QStringList strList;
    for(int i = 0; i < 100; ++i)
    {
        strList.append(QString::number(i));
    }
    QStringList strList1;
    for(int i = 0; i < 100; ++i)
    {
        strList1.append(QString::number(i*10));
    }
    QStringList strList2;
    for(int i = 0; i < 100; ++i)
    {
        strList2.append(QString::number(i*100));
    }
    m_wellSelect = new RSLasSelect(strList, this);
    m_logTypeSelect = new RSLasSelect(strList1, this);
    m_logNameSelect = new RSLasSelect(strList2, this);
    ui->wRSWellCombox->setType(RSLasSelectType::Well);
    ui->wRSLogTypeCombox->setType(RSLasSelectType::LogType);
    ui->wRSLogNameComBox->setType(RSLasSelectType::LogName);
    connect(ui->wRSWellCombox, SIGNAL(comboxClick(RSComBoxType)), this, SLOT(comboxClicked(RSComBoxType)));
    connect(ui->wRSLogTypeCombox, SIGNAL(comboxClick(RSComBoxType)), this, SLOT(comboxClicked(RSComBoxType)));
    connect(ui->wRSLogNameComBox, SIGNAL(comboxClick(RSComBoxType)), this, SLOT(comboxClicked(RSComBoxType)));
    m_wellSelect->hide();
    m_logTypeSelect->hide();
    m_logNameSelect->hide();
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect (this );
    effect-> setOpacity(0.5);
    ui->wStartEdit-> setGraphicsEffect(effect);

}


void RSLasExportDialog::wDepthClicked(bool bOk)
{
    Q_UNUSED(bOk);
    ui->wStartLabel->setText("Start MD(m):");
    ui->wStartEdit->setText(QString::number(0));
    ui->wEndLabel->setText("End MD(m):");
    ui->wEndEdit->setText(QString::number(10000));
    ui->wIncLabel->setText("Inc(m):");
    ui->wIncEdit->setText(QString::number(0.125));
}

void RSLasExportDialog::wTimeClicked(bool bOk)
{
    Q_UNUSED(bOk);
    ui->wStartLabel->setText("Start TWTSS(ms):");
    ui->wStartEdit->setText(QString::number(0));
    ui->wEndLabel->setText("End TWTSS(ms):");
    ui->wEndEdit->setText(QString::number(10000));
    ui->wIncLabel->setText("Inc(ms):");
    ui->wIncEdit->setText(QString::number(1));
}

void RSLasExportDialog::mousePressEvent(QMouseEvent * event)
{

}


void RSLasExportDialog::comboxClicked(RSLasSelectType::RSComBoxType type)
{
    if(type == Well)
    {
        if(!m_wellSelect->isHidden())
        {
            m_wellSelect->hide();
            return;
        }
        //m_wellSelect->setWindowFlags(Qt::FramelessWindowHint);
        QRect locationRect = ui->wRSWellCombox->geometry();
        QRect insideRect = ui->wRSWellCombox->contentsRect();
        int nX = locationRect.x();
        int nY = locationRect.y() + insideRect.height();
        int nW = insideRect.width();
        int nH = this->geometry().height() - nY - 9;
        m_wellSelect->setGeometry(nX, nY, nW, nH);
        m_wellSelect->show();
        m_logTypeSelect->hide();
        m_logNameSelect->hide();

        QPropertyAnimation *animation = new QPropertyAnimation(m_wellSelect, "geometry");
        //注：如下语句，假如多次快速点击触发，即第一次动画没完成，第二次就开始了，那么会造成内存泄露！
        //因为finish()信号没有发出根本，就不会删除，可以考虑用成员变量的方式改善.
        connect(animation, SIGNAL(finished()), animation, SLOT(deleteLater()));
        animation->setDuration(500);
        animation->setStartValue(QRect(nX, nY, nW, 0));
        animation->setEndValue(QRect(nX, nY, nW, nH));
        animation->start();
    }
    else if(type == LogType)
    {
        if(!m_logTypeSelect->isHidden())
        {
            m_logTypeSelect->hide();
            return;
        }
        QRect locationRect = ui->wRSLogTypeCombox->geometry();
        QRect insideRect = ui->wRSLogTypeCombox->contentsRect();
        int nX = locationRect.x();
        int nY = locationRect.y() + insideRect.height();
        int nW = insideRect.width();
        int nH = this->geometry().height() - nY - 9;;
        m_logTypeSelect->setGeometry(nX, nY, nW, nH);
        m_logTypeSelect->show();
        m_wellSelect->hide();
        m_logNameSelect->hide();

        QPropertyAnimation *animation = new QPropertyAnimation(m_logTypeSelect, "geometry");
        animation->setDuration(500);
        animation->setStartValue(QRect(nX, nY, nW, 0));
        animation->setEndValue(QRect(nX, nY, nW, nH));
        animation->start();
        connect(animation, SIGNAL(finished()), animation, SLOT(deleteLater()));
    }
    else
    {
        if(!m_logNameSelect->isHidden())
        {
            m_logNameSelect->hide();
            return;
        }
        QRect locationRect = ui->wRSLogNameComBox->geometry();
        QRect insideRect = ui->wRSLogNameComBox->contentsRect();
        int nX = locationRect.x();
        int nY = locationRect.y() + insideRect.height();
        int nW = insideRect.width();
        int nH = this->geometry().height() - nY - 9;
        m_logNameSelect->setGeometry(nX, nY, nW, nH);
        m_logNameSelect->show();
        m_wellSelect->hide();
        m_logTypeSelect->hide();

        QPropertyAnimation *animation = new QPropertyAnimation(m_logNameSelect, "geometry");
        animation->setDuration(500);
        animation->setStartValue(QRect(nX, nY, nW, 0));
        animation->setEndValue(QRect(nX, nY, nW, nH));
        animation->start();
        connect(animation, SIGNAL(finished()), animation, SLOT(deleteLater()));
    }
}

void RSLasExportDialog::wExportClicked()
{
}
