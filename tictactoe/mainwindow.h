#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/** @file mainwindow.h */

#include <QMainWindow>
#include <QPushButton>

#include "board.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, Board *board = nullptr);
    ~MainWindow();

private slots:
    void on_pos0_clicked();
    void on_pos1_clicked();
    void on_pos2_clicked();
    void on_pos3_clicked();
    void on_pos4_clicked();
    void on_pos5_clicked();
    void on_pos6_clicked();
    void on_pos7_clicked();
    void on_pos8_clicked();

private:
    Ui::MainWindow *ui;
    Board *board;
    QPushButton *buttons[NUM_POS];

    /**
     * @brief Handles button clicks at a position on the board.
     * @param pos
     */
    void buttonClicked(size_t pos);

    /**
     * @brief Updates the board position text.
     */
    void updateButtons();

    /**
     * @brief Disables all board position buttons.
     */
    void disableButtons();

    /**
     * @brief Updates the status label based on specific gameboard elements.
     */
    void updateStatus();

    /**
     * @brief Sets a buttons display font.
     * @param pos
     */
    void setButtonStyle(size_t pos);
};
#endif // MAINWINDOW_H
