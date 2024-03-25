#include <cassert>
#include <algorithm>
#include <random>
#include <iostream>


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    const QSize CARD_SIZE(71, 94);

    for (auto suit: Card::suits()) {
        QString card_base_name = ":/";
        switch (suit) {
            case Card::diamonds:
                card_base_name += "diamonds";
                break;
            case Card::hearts:
                card_base_name += "hearts";
                break;
            case Card::spades:
                card_base_name += "spades";
                break;
            case Card::clubs:
                card_base_name += "clubs";
                break;
            default:
                assert(false);
        }
        card_base_name = card_base_name + "_";
        for (auto rank: Card::ranks()) {
            const QString card_name = card_base_name + QString::number(rank);
            std::cerr << card_name.toStdString() << "\n";
            Card card(suit, rank, card_name);
            auto button = std::make_unique<QPushButton>(this);
            button->setIcon(card.icon());
            button->setIconSize(CARD_SIZE);
            button->setFixedSize(CARD_SIZE);
            button->setFlat(true);
            int row = static_cast<int>(suit)-1;
            int column = static_cast<int>(rank)-1;
            m_cards.push_back(card);
            m_buttons.push_back(std::move(button));
            ui->gridLayout->addWidget(m_buttons.back().get(), row, column);
        }

        QObject::connect(ui->shuffleButton, SIGNAL(clicked()),
                         this, SLOT(shuffle()));
        QObject::connect(ui->sortButton, SIGNAL(clicked()),
                         this, SLOT(sort()));
        QObject::connect(ui->quitButton, SIGNAL(clicked()),
                         this, SLOT(quit()));
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::quit() {
    QApplication::quit();
}

void MainWindow::sync() {
    // synchronize the button icons with the cards
    auto cardIt = m_cards.begin();
    auto buttonIt = m_buttons.begin();
    while (cardIt != m_cards.end()) {
        (*buttonIt)->setIcon(cardIt->icon());
        ++cardIt;
        ++buttonIt;
    }
    assert(buttonIt == m_buttons.end());
}

void MainWindow::shuffle() {
    static std::default_random_engine g;

    std::shuffle(m_cards.begin(), m_cards.end(), g);

    sync();
}

void MainWindow::sort() {

    std::sort(m_cards.begin(), m_cards.end());
    sync();
}
