#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QSpinBox>
#include <QPushButton>
#include <QFormLayout>
#include <QDialogButtonBox>

class ConfigDialog : public QDialog {
    Q_OBJECT

public:
    explicit ConfigDialog(QWidget *parent = nullptr);

    int getDelayBetweenTargets() const;
    int getGameTime() const;

private:
    QSpinBox *delayBetweenTargetsSpinBox;
    QSpinBox *gameTimeSpinBox;
};

#endif // CONFIGDIALOG_H
