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
    return (Entry) -1;
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
