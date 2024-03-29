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
        gameWindow.setButtonInterval(delayBetweenTargets); // Configurez l'intervalle des cibles
        gameWindow.setGameTime(gameTime); // Configurez la durée du jeu
        gameWindow.initializeGame(); // Préparez le jeu avec les paramètres
        gameWindow.show();

        return app.exec();
    }

    return 0; // Quitte l'application si l'utilisateur annule la configuration
}
