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
    clickSoundEffect.setSource(QUrl("qrc:/sound/explosion.wav")); 
    missSoundEffect.setSource(QUrl("qrc:/sound/miss.wav")); 


    targetButton = new QPushButton(this);
    targetButton->resize(25, 25); 
    targetButton->setStyleSheet("QPushButton { background-color: red; color: white; }"); 
    connect(targetButton, &QPushButton::clicked, this, &GameWindow::buttonClicked);

    connect(gameTimer, &QTimer::timeout, this, &GameWindow::updateTime);
    gameTimer->start(1000); 

    connect(buttonTimer, &QTimer::timeout, this, &GameWindow::updateGame);
    buttonTimer->start(1000);

    updateGame();
}

GameWindow::~GameWindow() {
    delete ui;
}

void GameWindow::updateGame() {
    int x = QRandomGenerator::global()->bounded(0, this->width() - targetButton->width());
    int y = QRandomGenerator::global()->bounded(0, this->height() - targetButton->height());
    targetButton->move(x, y);
    targetButton->show(); 
}

void GameWindow::buttonClicked() {

    score++;
    ui->scoreLabel->setText(QString("Score: %1").arg(score));
    targetButton->hide(); 
    clickSoundEffect.play(); 

}

void GameWindow::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event); standard

    if (!targetButton->geometry().contains(event->pos()) && !targetButton->isHidden()) {
        missSoundEffect.play(); 
    }
}


void GameWindow::updateTime() {
    if (timeLeft > 0) {
        timeLeft--;
        ui->timeLabel->setText(QString("Temps: %1s").arg(timeLeft));
    } else {
        gameTimer->stop();
        buttonTimer->stop();
        targetButton->setEnabled(false); 
        

    
        endSoundEffect.play();
        
        QTimer::singleShot(1000, this, [this]() {
            auto reply = QMessageBox::question(this, "Fin de la partie", QString("Votre score est %1. Voulez-vous recommencer ?").arg(score),
                                               QMessageBox::Yes | QMessageBox::No);
            
            if (reply == QMessageBox::Yes) {
                restartGame(); 
            } else {
                
            }
        });
    }
}

void GameWindow::restartGame() {
    score = 0;
    timeLeft = 60;

    ui->scoreLabel->setText(QString("Score: %1").arg(score));
    ui->timeLabel->setText(QString("Temps: %1s").arg(timeLeft));

    targetButton->setEnabled(true);
    targetButton->show();

    gameTimer->start(1000); 
    buttonTimer->start(1000); 

    updateGame();
}


void GameWindow::setGameTime(int time) {
    timeLeft = time;
    ui->timeLabel->setText(QString("Temps: %1s").arg(timeLeft)); 
}

void GameWindow::setButtonInterval(int interval) {
    buttonInterval = interval; 
}

void GameWindow::initializeGame() {
    score = 0;
    ui->scoreLabel->setText(QString("Score: %1").arg(score));
    targetButton->setEnabled(true);
    targetButton->show();
    ui->timeLabel->setText(QString("Temps: %1s").arg(timeLeft));

    gameTimer->start(1000); 
    buttonTimer->start(buttonInterval); 

    updateGame(); 
}