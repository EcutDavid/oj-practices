var removeOuterParentheses = function (S) {
  let parts = [];

  let l = 0;
  let r = 0;
  let openCounter = 0;
  while (l < S.length && r < S.length) {
    if (S[r] == "(") openCounter++;
    else openCounter--;

    if (openCounter == 0) {
      // Plz, don't use .substring
      parts.push(S.substr(l, r - l + 1));
      l = r + 1;
    }
    r++;
  }
  parts = parts.map(d => d.substr(1, d.length - 2));
  return parts.join("");
};