#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent, Board *board)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->board = board;
    this->buttons[0] = this->ui->pos0;
    this->buttons[1] = this->ui->pos1;
    this->buttons[2] = this->ui->pos2;
    this->buttons[3] = this->ui->pos3;
    this->buttons[4] = this->ui->pos4;
    this->buttons[5] = this->ui->pos5;
    this->buttons[6] = this->ui->pos6;
    this->buttons[7] = this->ui->pos7;
    this->buttons[8] = this->ui->pos8;
    size_t idx = 0;
    while (idx < NUM_POS)
    {
        this->setButtonStyle(idx);
        idx++;
    }
    this->updateButtons();
    this->updateStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->board;
}

void MainWindow::on_pos0_clicked() { this->buttonClicked(0); }
void MainWindow::on_pos1_clicked() { this->buttonClicked(1); }
void MainWindow::on_pos2_clicked() { this->buttonClicked(2); }
void MainWindow::on_pos3_clicked() { this->buttonClicked(3); }
void MainWindow::on_pos4_clicked() { this->buttonClicked(4); }
void MainWindow::on_pos5_clicked() { this->buttonClicked(5); }
void MainWindow::on_pos6_clicked() { this->buttonClicked(6); }
void MainWindow::on_pos7_clicked() { this->buttonClicked(7); }
void MainWindow::on_pos8_clicked() { this->buttonClicked(8); }

void MainWindow::buttonClicked(size_t pos)
{
    Entry current_turn = this->board->getTurn();
    if (this->board->getEntry(pos) != current_turn && this->board->getEntry(pos) == Entry::EMPTY)
    {
        this->board->setEntry(current_turn,pos);
        this->updateButtons();
        this->board->updateTurn();
        this->updateStatus();
    }

}

void MainWindow::updateButtons()
{
    size_t idx = 0;
    while (idx < NUM_POS)
    {
        this->buttons[idx]->setText(
                    QString::fromStdString(entryToString(this->board->getEntry(idx))));
        idx++;
    }
    if (this->board->getStatus() != Entry::EMPTY)
        this->disableButtons();
}

void MainWindow::updateStatus()
{
    QString status = "";
    switch (this->board->getStatus())
    {
    case Entry::X:
        status = "Winner: Player X";
        break;
    case Entry::O:
        status = "Winner: Player O";
        break;
    case Entry::EMPTY:
        status += "It is ";
        status += QString::fromStdString(entryToString(this->board->getTurn()));
        status += "'s turn";
        break;
    default:
        status = "Stalemate";
    }
    this->ui->statusLabel->setText(status);
}

void MainWindow::disableButtons()
{
    size_t idx = 0;
    while (idx < NUM_POS)
    {
        this->buttons[idx]->setDisabled(true);
        idx++;
    }
}

void MainWindow::setButtonStyle(size_t pos)
{
    QFont font = this->buttons[pos]->font();
    font.setPointSize(20); /* this is arbitrary */
    this->buttons[pos]->setFont(font);
}
