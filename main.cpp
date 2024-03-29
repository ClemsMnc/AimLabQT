#include <QApplication>
#include "GameWindow.h"
#include "ConfigDialog.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ConfigDialog configDialog;
    if (configDialog.exec() == QDialog::Accepted) {
        int delayBetweenTargets = configDialog.getDelayBetweenTargets();
        int gameTime = configDialog.getGameTime();

        GameWindow gameWindow;
        gameWindow.setButtonInterval(delayBetweenTargets); 
        gameWindow.setGameTime(gameTime); 
        gameWindow.initializeGame(); 
        gameWindow.show();

        return app.exec();
    }

    return 0; 
}
