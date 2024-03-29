#include "GameWindow.h"
#include "ui_GameWindow.h"
#include <QRandomGenerator>
#include <QSoundEffect>
#include <QMessageBox>

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow),
    gameTimer(new QTimer(this)),
    buttonTimer(new QTimer(this)) {
    ui->setupUi(this);

    endSoundEffect.setSource(QUrl("qrc:/sound/end.wav"));
    clickSoundEffect.setSource(QUrl("qrc:/sound/explosion.wav")); // Chemin vers le fichier son du clic
    missSoundEffect.setSource(QUrl("qrc:/sound/miss.wav")); // Chemin vers le fichier son de raté


    // Configuration initiale du bouton cible
    targetButton = new QPushButton(this);
    targetButton->resize(25, 25); // Rend le bouton plus petit
    targetButton->setStyleSheet("QPushButton { background-color: red; color: white; }"); // Bouton rouge avec texte blanc
    connect(targetButton, &QPushButton::clicked, this, &GameWindow::buttonClicked);

    // Timer pour mettre à jour le temps
    connect(gameTimer, &QTimer::timeout, this, &GameWindow::updateTime);
    gameTimer->start(1000); // Mise à jour toutes les secondes

    // Timer pour déplacer le bouton de façon aléatoire
    connect(buttonTimer, &QTimer::timeout, this, &GameWindow::updateGame);
    buttonTimer->start(1000); // Déplace le bouton toutes les 0.5 secondes pour une apparition plus rapide

    updateGame(); // Placement initial du bouton
}

GameWindow::~GameWindow() {
    delete ui;
}

void GameWindow::updateGame() {
    int x = QRandomGenerator::global()->bounded(0, this->width() - targetButton->width());
    int y = QRandomGenerator::global()->bounded(0, this->height() - targetButton->height());
    targetButton->move(x, y);
    targetButton->show(); // Assurez-vous que le bouton est visible
}

void GameWindow::buttonClicked() {

    score++;
    ui->scoreLabel->setText(QString("Score: %1").arg(score));
    targetButton->hide(); // Cache le bouton immédiatement après le clic
    clickSoundEffect.play(); // Joue le son de clic

}

void GameWindow::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event); // Appel à la méthode parent pour conserver le comportement standard

    // Vérifie si le clic est en dehors du bouton
    if (!targetButton->geometry().contains(event->pos()) && !targetButton->isHidden()) {
        missSoundEffect.play(); // Joue le son de raté
    }
}


void GameWindow::updateTime() {
    if (timeLeft > 0) {
        timeLeft--;
        ui->timeLabel->setText(QString("Temps: %1s").arg(timeLeft));
    } else {
        gameTimer->stop();
        buttonTimer->stop();
        targetButton->setEnabled(false); // Désactive le bouton à la fin du jeu
        
        // Joue le son de fin de jeu

    
        endSoundEffect.play();
        
        // Attend que le son soit joué (supposez une durée fixe ou vérifiez de manière asynchrone)
        QTimer::singleShot(1000, this, [this]() {
            // Affiche le score et demande si l'utilisateur veut recommencer
            auto reply = QMessageBox::question(this, "Fin de la partie", QString("Votre score est %1. Voulez-vous recommencer ?").arg(score),
                                               QMessageBox::Yes | QMessageBox::No);
            
            if (reply == QMessageBox::Yes) {
                restartGame(); // Vous devez implémenter cette méthode pour redémarrer le jeu
            } else {
                // Optionnel : fermez l'application ou retournez à l'écran d'accueil
            }
        });
    }
}

void GameWindow::restartGame() {
    // Réinitialiser le score et le temps
    score = 0;
    timeLeft = 60; // Supposons que la durée initiale de votre jeu soit de 60 secondes

    // Mettre à jour les affichages de score et de temps
    ui->scoreLabel->setText(QString("Score: %1").arg(score));
    ui->timeLabel->setText(QString("Temps: %1s").arg(timeLeft));

    // Réactiver le bouton cible s'il était désactivé à la fin du jeu
    targetButton->setEnabled(true);
    targetButton->show();

    // Redémarrer les timers pour le jeu et pour déplacer le bouton cible
    gameTimer->start(1000); // Mise à jour du temps toutes les secondes
    buttonTimer->start(1000); // Déplacement du bouton toutes les 0.5 secondes

    // Placer le bouton cible à une position initiale
    updateGame();
}


void GameWindow::setGameTime(int time) {
    timeLeft = time;
    ui->timeLabel->setText(QString("Temps: %1s").arg(timeLeft)); // Mise à jour immédiate du label de temps
}

void GameWindow::setButtonInterval(int interval) {
    buttonInterval = interval; // Sauvegarde l'intervalle dans la variable membre
}

void GameWindow::initializeGame() {
    score = 0;
    ui->scoreLabel->setText(QString("Score: %1").arg(score));
    targetButton->setEnabled(true);
    targetButton->show();
    ui->timeLabel->setText(QString("Temps: %1s").arg(timeLeft));

    gameTimer->start(1000); // Mise à jour du temps toutes les secondes
    buttonTimer->start(buttonInterval); // Utilise l'intervalle configuré par l'utilisateur

    updateGame(); // Placement initial du bouton cible
}