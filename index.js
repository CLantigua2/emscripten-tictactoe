let current = "X";
var disableBoard = false;
var currentBoardValues = [];
var BoardValues = { 0: [], 1: [], 2: [] };
var movesPendingLabel = "Moves still pending!";
var emptyBlock = "";
var noWinnerLabel = "Oops! Looks like no one won : (";

var Module = {
	onRuntimeInitialized: function () {
		Module.tic_tac_toe();
	},
};

function makeMove(event) {
	if (!disableBoard) {
		event.target.innerHTML = current;
		current = current === "O" ? "X" : "O";
		currentBoardValues = Array.from(
			document.getElementsByClassName("block"),
		).map((item) => {
			return item.innerHTML;
		});
		BoardValues = {
			0: currentBoardValues.slice(0, 3),
			1: currentBoardValues.slice(3, 6),
			2: currentBoardValues.slice(6, 9),
		};
		var result = Module.tic_tac_toe();
		if (result == "X" || result == "O") {
			disableBoard = true;
			document.getElementById("game-status").innerHTML = `${result} Won!!!!`;
		} else {
			document.getElementById("game-status").innerHTML = result;
		}
	}
}

// Reset Game function
function resetGame() {
	disableBoard = false;
	location.reload();
}
