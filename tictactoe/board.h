#ifndef BOARD_H
#define BOARD_H

/** @file #Board.h */

// NOTE to self: the above line is needed for documentation for enums and static vars.
// NOTE to self: remember to set EXTRACT_ALL and EXTRACT_STATIC to yes in doxygen config
// NOTE to self: use hashtag #VARIABLE to refer to VARIABLE

#include <cstdlib>
#include <string>
#include <exception>

/** Defines the number of positions on the #Board. */
static const size_t NUM_POS = 9;
/**
 * This is dependent on #NUM_POS. This is its square root.
 * It assummed that the #Board is a standard tic tac toe #Board, so #DIM and #NUM_POS
 * should not change anyway.
 */
static const size_t DIM = 3;

/**
 * @enum Entry
 * @brief Defines the possible entries for every position on the #Board.
 */
enum class Entry {EMPTY, X, O};

/**
 * @brief Returns a string representation of the #Entry object.
 * @param entry an #Entry object.
 * @return the string "NA" if a non valid Entry index is given. Otherwise:
 * entry       |return
 * ------------|------
 * Entry::EMPTY|" "
 * Entry::X    |"X"
 * Entry::O    |"O"
 */
std::string entryToString(Entry entry);

/**
 * @brief The tictactoe board object.
 */
class Board
{
public:
    /**
     * @brief Constructs the #Board object.
     * @param initial_turn The first turn for the game represented by an #Entry object.
     * Only Entry::X or Entry::O must be given. If neither of these entries are
     * used, the intial turn defaults to Entry::X.
     */
    Board(Entry initial_turn);
    ~Board();

    /**
     * @brief Returns the entry object at a position on the #Board.
     * @param pos the position to retrieve the entry. The position is an index value starting from
     * the top left corner proceeding left to right, then top to bottom. (i.e. the lower right
     * most corner would be at index position 8.)
     * @return the Entry object at the given position. @see Entry.
     * @return -1 (casted to an Entry) if the given position is not valid (i.e. pos >= NUM_POS). @see NUM_POS.
     */
    Entry getEntry(size_t pos);

    /**
     * @brief Sets the Entry object at a position on the #Board.
     * @param entry the Entry enum placed on the #Board.
     * @param pos the postion to place the entry. The position is an index value starting from
     * the top left corner proceeding left to right, then top to bottom. (i.e. the lower right
     * most corner would be at index position 8.)
     * @return true if the position in the #Board was marked successfully.
     * @return false if the position in the #Board cannot be marked because it was not empty.
     */
    bool  setEntry(Entry entry, size_t pos);

    /**
     * @brief Determines the status of #Board.
     * @return either Entry::X or Entry::O if the #Board is at an end state.
     * @return Entry::EMPTY if the #Board is still ongoing.
     * @see Entry
     */
    Entry getStatus();

    /**
     * @brief Returns the #Entry object that represents the current turn of the game state.
     * @return either Entry::X or Entry::O representing the player who has the current turn.
     */
    Entry getTurn();

    /**
     * @brief Returns a graphical string representation of the #Board.
     * @return A graphical ascii #Board string terminating with a newline.
     */
    std::string toString();
private:
    Entry board[NUM_POS];
    Entry current_turn;
};

#endif // BOARD_H
