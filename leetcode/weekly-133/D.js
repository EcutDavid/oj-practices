/**
 * @param {string[]} words
 */
var StreamChecker = function(words) {
  this.suffix = {};
  this.prevQuery = [];
  words.forEach(w => {
    let cur = this.suffix;
    for (let i = w.length - 1; i >= 0; i--) {
      if (!cur[w[i]]) cur[w[i]] = {};

      cur = cur[w[i]];
      if (i == 0) cur.isEnd = true;
    }
  });
};

/**
 * @param {character} letter
 * @return {boolean}
 */
StreamChecker.prototype.query = function(letter) {
  this.prevQuery.push(q);
  let cur = this.suffix;
  const q = letter;

  for (let i = this.prevQuery.length - 1; i >= 0; i--) {
    const q = this.prevQuery[i];
    cur = cur[q];
    if (!cur) return false;
    if (cur.isEnd) return true;
  }
  return false;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * var obj = new StreamChecker(words)
 * var param_1 = obj.query(letter)
 */
