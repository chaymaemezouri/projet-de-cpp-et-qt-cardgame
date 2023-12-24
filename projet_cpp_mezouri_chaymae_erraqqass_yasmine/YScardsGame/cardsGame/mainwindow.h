#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "card.h"
#include "deck.h"
#include "player.h"
#include "ClickableLabel.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateCardImages(const std::vector<Card>& hand, const QString& playerPrefix, int i);
    void updateTableCards();
    void removeCardImages(const QString& playerPrefix, int i);
    void cardClicked(int i);
    void computer_play();



private:
    Ui::MainWindow *ui;
    // std::vector<Card> player1Hand;
    // std::vector<Card> computerHand;
    std::vector<Card> tableCards;
    Deck deck;
    Player player1;
    Player computer;
    void checkForWinner();
    void restartGame();

};
#endif // MAINWINDOW_H
