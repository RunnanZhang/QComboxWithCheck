#ifndef RSLASEXPORTDIALOG_H
#define RSLASEXPORTDIALOG_H

#include <QDialog>
#include "rslascombox.h"
class RSLasSelect;

namespace Ui {
class RSLasExportDialog;
}

class RSLasExportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RSLasExportDialog(QWidget *parent = 0);
    ~RSLasExportDialog();

private:
    void init();
    void mousePressEvent(QMouseEvent * event);

private slots:
    void comboxClicked(RSComBoxType type);
    void wExportClicked();
    void wDepthClicked(bool);
    void wTimeClicked(bool);

private:
    Ui::RSLasExportDialog *ui;
    RSLasSelect *m_wellSelect;
    RSLasSelect *m_logTypeSelect;
    RSLasSelect *m_logNameSelect;
};

#endif // RSLASEXPORTDIALOG_H
