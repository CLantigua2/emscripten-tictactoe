#include <emscripten/bind.h>
#include <emscripten/val.h>

using namespace emscripten;

val tic_tac_toe() {
    val board_values = val::global("BoardValues");  // Object representing our 3*3 board
    val moves_pending_label = val::global("movesPendingLabel"); // Label returned if there are any pending moves/blocks remaining
    val no_winner_label = val::global("noWinnerLabel"); // Label indicating who won
    val empty_block = val::global("emptyBlock"); //  Indicator for an empty cell on board
    bool moves_pending = false;  // State variable indicating if any blocks are pending

    val solutions[8][3]= {
        { board_values[0][0], board_values[0][1], board_values[0][2]},
        { board_values[1][0], board_values[1][1], board_values[1][2]},
        { board_values[2][0], board_values[2][1], board_values[2][2]},
        { board_values[0][0], board_values[1][0], board_values[2][0]},
        { board_values[0][1], board_values[1][1], board_values[2][1]},
        { board_values[0][2], board_values[1][2], board_values[2][2]},
        { board_values[0][0], board_values[1][1], board_values[2][2]},
        { board_values[0][2], board_values[1][1], board_values[2][0]},
    };

    for (int i = 0; i < 8; i++ ) {
      if((solutions[i][0] != empty_block) && (solutions[i][1] != empty_block) && (solutions[i][2] != empty_block)&& (solutions[i][0] == solutions[i][1]) && ( solutions[i][1] == solutions[i][2] )) {
        return solutions[i][1];
      } else if ((solutions[i][0] == empty_block) || (solutions[i][1] == empty_block) || (solutions[i][2] == empty_block)) {
        moves_pending = true;
      }
    }

      if (moves_pending) {
        return moves_pending_label;
      }

      return no_winner_label;
}

EMSCRIPTEN_BINDINGS(my_module) {
  function("tic_tac_toe", &tic_tac_toe);
}