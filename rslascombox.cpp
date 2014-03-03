#include "rslascombox.h"
#include "rslasselect.h"
#include <QMouseEvent>
RSLasCombox::RSLasCombox(QWidget *parent) : QComboBox(parent)
{

}

RSLasCombox::~RSLasCombox()
{

}

void RSLasCombox::setType(RSComBoxType type)
{
    m_nType = type;
}

void RSLasCombox::mousePressEvent(QMouseEvent *e)
{
    e->accept();
    emit comboxClick(m_nType);
}
