function validate(board, begin, end) {
  const s = new Set();
  for (let i = begin[0]; i <= end[0]; i++) {
    for (let j = begin[1]; j <= end[1]; j++) {
      if (board[i][j] == ".") continue;
      if (s.has(board[i][j])) return false;
      s.add(board[i][j]);
    }
  }
  return true;
}

/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
  for (let i = 0; i < 9; i++) {
    if (!validate(board, [i, 0], [i, 8])) return false;
    if (!validate(board, [0, i], [8, i])) return false;
  }
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      const begin = [i * 3, j * 3];
      const end = [i * 3 + 2, j * 3 + 2];
      if (!validate(board, begin, end)) return false;
    }
  }
  return true;
};
