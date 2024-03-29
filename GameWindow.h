#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QPushButton>
#include <QSoundEffect>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QWidget {
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    void setButtonInterval(int interval);
    void setGameTime(int time);
    void initializeGame(); 

private slots:
    void updateGame();
    void buttonClicked();
    void updateTime();
    void restartGame();

private:
    Ui::GameWindow *ui;
    QTimer *gameTimer;
    QTimer *buttonTimer;
    QPushButton *targetButton;
    int score = 0;
    int timeLeft = 60;
    int buttonInterval; 
    QSoundEffect clickSoundEffect;
    QSoundEffect missSoundEffect;
    QSoundEffect endSoundEffect;

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // GAMEWINDOW_H
