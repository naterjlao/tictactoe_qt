#include "board.h"

#include <cstdlib>

std::string entryToString(Entry entry)
{
    std::string str;
    switch (entry)
    {
    case Entry::EMPTY:
        str = " ";
        break;
    case Entry::X:
        str = "X";
        break;
    case Entry::O:
        str = "O";
        break;
    default:
        str = "NA";
    }
    return str;
}

Board::Board(Entry initial_turn)
{
    size_t idx = 0;
    while (idx < NUM_POS)
    {
        this->board[idx] = Entry::EMPTY;
        idx++;
    }
    if (initial_turn == Entry::O || initial_turn == Entry::X)
        this->current_turn = initial_turn;
    else
        this->current_turn = Entry::X;
}

Board::~Board() {}

Entry Board::getEntry(size_t pos)
{
    if (pos < NUM_POS)
    {
        return this->board[pos];
    }
    else
        return (Entry) -1;
}

bool  Board::setEntry(Entry entry, size_t pos)
{
    if (this->getEntry(pos) == Entry::EMPTY)
    {
        this->board[pos] = entry;
        return true;
    }
    else
        return false;
}

Entry Board::getStatus()
{
    Entry status = Entry::EMPTY;
    Entry players[] = {Entry::X, Entry::O};
    Entry player;
    bool winnerFound, boardFull;
    size_t p_num = 0, pos, delta;
    while (p_num < sizeof(players)/sizeof(Entry)) /** @note this whole section is dependent on a 9 postion board */
    {
        player = players[p_num];
        winnerFound = false;
        /* check columns */
        pos = 0;
        while (pos < DIM && !winnerFound) /** @note very HARDCODED */
        {
            winnerFound = true;
            delta = 0;
            while (delta < DIM)
            {
                winnerFound = winnerFound && (player == this->getEntry(pos+(delta*DIM)));
                delta++;
            }
            pos++;
        }

        /* check rows */
        pos = 0;
        while (pos < NUM_POS && !winnerFound) /** @note very HARDCODED */
        {
            winnerFound = true;
            delta = 0;
            while (delta < DIM)
            {
                winnerFound = winnerFound && (player == this->getEntry(pos+delta));
                delta++;
            }
            pos += DIM;
        }

        /* check diagonals */
        if (!winnerFound) /** @note very HARDCODED */
        {
            if (this->getEntry(4) == player)
            {
                winnerFound = winnerFound || (this->getEntry(0) == player && this->getEntry(8) == player);
                winnerFound = winnerFound || (this->getEntry(2) == player && this->getEntry(6) == player);
            }
        }

        p_num++;

        if (winnerFound)
            break;
    }

    if (winnerFound)
        status = player;
    else { /* check if all spaces are occupied */
        pos = 0;
        boardFull = true;
        while (pos < NUM_POS)
        {
            if (this->getEntry(pos) == Entry::EMPTY)
                boardFull = false;
            pos++;
        }
        if (boardFull)
            status = (Entry) -1;
    }

    return status;
}

Entry Board::getTurn()
{
    return this->current_turn;
}

Entry Board::getNextTurn()
{
    if (this->getStatus() != (Entry) -1 )
        return this->getTurn() == Entry::X ? Entry::O : Entry::X;
    else
        return (Entry) -1;
}

void Board::updateTurn()
{
    if (this->current_turn == Entry::X)
        this->current_turn = Entry::O;
    else
        this->current_turn = Entry::X;
}

std::string Board::toString()
{
    size_t pos = 0;
    std::string result = "";
    while (pos < NUM_POS)
    {
        result += entryToString(this->getEntry(pos));
        pos++;
        if (pos % DIM == 0)
            result += "\n";
        else
            result += "|";
    }
    return result;
}
