#include "ConfigDialog.h"

ConfigDialog::ConfigDialog(QWidget *parent) : QDialog(parent) {
    // Création des SpinBoxes pour les paramètres
    delayBetweenTargetsSpinBox = new QSpinBox(this);
    delayBetweenTargetsSpinBox->setRange(100, 5000);
    delayBetweenTargetsSpinBox->setValue(1000); // Valeur par défaut

    gameTimeSpinBox = new QSpinBox(this);
    gameTimeSpinBox->setRange(10, 300);
    gameTimeSpinBox->setValue(60); // Valeur par défaut

    // Bouton OK et Cancel
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    // Layout
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
