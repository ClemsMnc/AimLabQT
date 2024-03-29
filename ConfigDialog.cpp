#include "ConfigDialog.h"

ConfigDialog::ConfigDialog(QWidget *parent) : QDialog(parent) {
    delayBetweenTargetsSpinBox = new QSpinBox(this);
    delayBetweenTargetsSpinBox->setRange(100, 5000);
    delayBetweenTargetsSpinBox->setValue(1000); 

    gameTimeSpinBox = new QSpinBox(this);
    gameTimeSpinBox->setRange(10, 300);
    gameTimeSpinBox->setValue(60); 

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QFormLayout *layout = new QFormLayout(this);
    layout->addRow("Délai entre les cibles (ms):", delayBetweenTargetsSpinBox);
    layout->addRow("Durée de jeu (secondes):", gameTimeSpinBox);
    layout->addWidget(buttonBox);
}

int ConfigDialog::getDelayBetweenTargets() const {
    return delayBetweenTargetsSpinBox->value();
}

int ConfigDialog::getGameTime() const {
    return gameTimeSpinBox->value();
}
