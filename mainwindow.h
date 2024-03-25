#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include <memory>
#include "card.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

private slots:

    static void quit();

    void sync();

    void shuffle();

    void sort();

private:
    Ui::MainWindow* ui;
    std::vector<std::unique_ptr<QPushButton>> m_buttons;
    std::vector<Card> m_cards;
};

#endif // MAINWINDOW_H