#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <QDebug>
#include <random>
#include "startdialog.h"
#include <QMessageBox>
#include <QTimer>
#include <QSound>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    StartDialog startDialog(this);
    if (startDialog.exec() == QDialog::Rejected) {
        close(); // Close the main window if dialog is rejected
        delete ui;
    }

    deck.shuffle();

    // player_score = 0;
    // computer_score = 0;

    // player1Hand = deck.dealHand(3);
    // computerHand = deck.dealHand(3);
    player1.setHand(deck.dealHand(3));
    computer.setHand(deck.dealHand(3));
    deck.set_limit(6);

    updateCardImages(player1.getHand(), "player1", 0);
    updateCardImages(player1.getHand(), "player1", 1);
    updateCardImages(player1.getHand(), "player1", 2);
    updateCardImages(computer.getHand(), "computer", 0);
    updateCardImages(computer.getHand(), "computer", 1);
    updateCardImages(computer.getHand(), "computer", 2);

    tableCards = deck.dealHand(3);


    updateTableCards();



}


void MainWindow::restartGame() {
    player1.setScore(0);
    computer.setScore(0);
    deck.shuffle();
    player1.setHand(deck.dealHand(3));
    computer.setHand(deck.dealHand(3));
    deck.set_limit(6);

    ui->player1_score->setText("Player Score: " + QString::number(player1.getScore()));
    ui->computer_score->setText("Computer Score: " + QString::number(computer.getScore()));

    updateCardImages(player1.getHand(), "player1", 0);
    updateCardImages(player1.getHand(), "player1", 1);
    updateCardImages(player1.getHand(), "player1", 2);
    updateCardImages(computer.getHand(), "computer", 0);
    updateCardImages(computer.getHand(), "computer", 1);
    updateCardImages(computer.getHand(), "computer", 2);

    tableCards = deck.dealHand(3);
    updateTableCards();
}

void MainWindow::updateCardImages(const std::vector<Card>& hand, const QString& playerPrefix, int i) {

        int s = static_cast<int>(hand[i].getSuit()) + 1;
        int r = static_cast<int>(hand[i].getRank());
        std::vector<int> validRanks = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12};
        if (std::find(validRanks.begin(), validRanks.end(), r) == validRanks.end()) {
            r = 1;
        }
        QString cardImagePath = ":/card" + QString::number(r) + "/cards/" + QString::number(s) + "/"  + QString::number(r) + ".gif";
        qDebug() << "Card Image Path:" << cardImagePath;

        ClickableLabel* cardLabel = findChild<ClickableLabel*>(playerPrefix + "_c" + QString::number(i + 1));
        if (cardLabel) {
            cardLabel->setStyleSheet("QLabel { image: url(" + cardImagePath + "); }");

            // Disconnect any existing connections to avoid multiple connections
            disconnect(cardLabel, &ClickableLabel::clicked, 0, 0);

            // Capture 'hand', 'i', and 'playerPrefix' in the lambda
            connect(cardLabel, &ClickableLabel::clicked, this, [this, &hand, i, playerPrefix]() {
                QSound::play(":/voices/voices/voice1.wav");
                cardClicked(i);
                QTimer::singleShot(2000, this, &MainWindow::computer_play);
            });
        } else {
            QLabel* cardLabel = findChild<QLabel*>(playerPrefix + "_c" + QString::number(i + 1));
            if (cardLabel) {
                cardLabel->setStyleSheet("QLabel { image: url(" + cardImagePath + "); }");
            }
        }
}



void MainWindow::removeCardImages(const QString& playerPrefix, int i) {


    QString cardImagePath = ":/back/cards/back.gif";

    ClickableLabel* cardLabel = findChild<ClickableLabel*>(playerPrefix + "_c" + QString::number(i + 1));
    if (cardLabel) {
        cardLabel->setStyleSheet("QLabel { image: url(" + cardImagePath + "); }");

        // Disconnect any existing connections to avoid multiple connections
        disconnect(cardLabel, &ClickableLabel::clicked, 0, 0);


    } else {
        QLabel* cardLabel = findChild<QLabel*>(playerPrefix + "_c" + QString::number(i + 1));
        if (cardLabel) {
            cardLabel->setStyleSheet("QLabel { image: url(" + cardImagePath + "); }");
        }
    }


}


// Assuming you have a vector<Card> tableCards that holds the current cards on the table.
void MainWindow::updateTableCards() {
    // Find the layout where the table cards should be displayed.
    QHBoxLayout* tableLayout = ui->centralWidget->findChild<QHBoxLayout*>("horizontalLayout_4");

    // Clear existing card labels from the layout
    QLayoutItem* item;
    while ((item = tableLayout->takeAt(0)) != nullptr) {
        delete item->widget(); // Delete the widget
        delete item;           // Delete the layout item
    }

    // Add new card labels to the layout
    for (const Card& card : tableCards) {
        QLabel* cardLabel = new QLabel(this);
        int s = static_cast<int>(card.getSuit()) + 1;
        int r = static_cast<int>(card.getRank());
        QString cardImagePath = ":/card" + QString::number(r) + "/cards/" + QString::number(s) + "/" + QString::number(r) + ".gif";
        cardLabel->setStyleSheet("QLabel { image: url(" + cardImagePath + "); }");
        cardLabel->setMinimumSize(70, 80); // Set the size of the card
        tableLayout->addWidget(cardLabel); // Add to the layout
    }
}


void MainWindow::cardClicked(int cardIndex) {
    // Remove the card from the player's hand
    // This requires access to the player's hand and a way to update it
    QSound::play(":/path/to/click.wav");

    bool cardExists = false;
    for (auto it = tableCards.begin(); it != tableCards.end(); ++it) {
        if (it->getRank() == player1.getCard(cardIndex).getRank()) {
            tableCards.erase(it);
            cardExists = true;
            player1.setScore(player1.getScore() + 1);
            ui->player1_score->setText("Player Score: " + QString::number(player1.getScore()));
            break; // Stop the loop once the card is found and removed
        }
    }

    if (!cardExists) {
        tableCards.push_back(player1.getCard(cardIndex));

    }

    player1.removeCard(cardIndex);

    updateTableCards();

    removeCardImages("player1", cardIndex);
    qDebug() << deck.get_limit();
    if(player1.getHandSize() == 0){
            if (deck.get_limit() > 40){
                checkForWinner();
            }
            else{
                deck.set_limit(3);
                player1.setHand(deck.dealHand(3));
                updateCardImages(player1.getHand(), "player1", 0);
                updateCardImages(player1.getHand(), "player1", 1);
                updateCardImages(player1.getHand(), "player1", 2);
            }
        }
}



void MainWindow::computer_play() {

    bool cardExists = false;
    int cardIndex = 0 ;



    if (computer.getHandSize() == 3) {
        cardIndex = 2 ;
    }

    if (computer.getHandSize() == 2) {
            cardIndex = 1;
    }

    for (auto it = tableCards.begin(); it != tableCards.end(); ++it) {
        if (it->getRank() == computer.getCard(cardIndex).getRank()) {
            tableCards.erase(it);
            cardExists = true;
            computer.setScore(computer.getScore()+1);
            ui->computer_score->setText("Computer Score: " + QString::number(computer.getScore()));
            break; // Stop the loop once the card is found and removed
        }
    }

    if (!cardExists) {
        tableCards.push_back(computer.getCard(cardIndex));
    }

    computer.removeCard(cardIndex);

    updateTableCards();

    removeCardImages("computer", cardIndex);
    // updateCardImages(player1Hand, "player1", cardIndex);

    if(computer.getHandSize() == 0){
        if (deck.get_limit() > 40){
            checkForWinner();
        }
        else{
            deck.set_limit(3);
            computer.setHand(deck.dealHand(3));
            updateCardImages(computer.getHand(), "computer", 0);
            updateCardImages(computer.getHand(), "computer", 1);
            updateCardImages(computer.getHand(), "computer", 2);
        }
    }
}


void MainWindow::checkForWinner() {
    if (player1.getScore() > computer.getScore()) {
        QMessageBox::information(this, "Game Over", "Player 1 wins!");
        close(); // Close the game or reset it
    } else if (computer.getScore() > player1.getScore()) {
        QMessageBox::information(this, "Game Over", "Computer wins!");
        close(); // Close the game or reset it
    }
    else{
        QMessageBox::information(this, "Game Over", "Equals!");
        close(); // Close the game or reset it
    }
}







MainWindow::~MainWindow()
{
    delete ui;
}



