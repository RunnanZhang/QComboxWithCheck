#ifndef RSLASCOMBOX_H
#define RSLASCOMBOX_H
#include "rslasnamespace.h"
#include <QComboBox>
using namespace RSLasSelectType;

class RSLasCombox : public QComboBox
{
	Q_OBJECT

public:
    explicit RSLasCombox(QWidget *parent = 0);
    ~RSLasCombox();
    void setType(RSComBoxType type);

signals:
    void comboxClick(RSComBoxType type);

private:
    void mousePressEvent(QMouseEvent * e);

private:
    RSComBoxType m_nType;
};

#endif // RSLASCOMBOX_H
