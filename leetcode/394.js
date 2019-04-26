// There are many ways to improve the performance of code below,
// but thought that's not the main point.
// The main point of this question to me is getting the recursion right.
const zeroCode = "0".charCodeAt(0);
const nineCode = "9".charCodeAt(0);

/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(s) {
  if (s.length === 0) return "";

  let index = -1;
  for (let i = 0; i < s.length; i++) {
    const code = s[i].charCodeAt(0);
    if (zeroCode <= code && nineCode >= code) break;
    index = i;
  }
  if (index > -1)
    return s.slice(0, index + 1) + decodeString(s.slice(index + 1));

  let num = 0;
  let open = -1;
  for (let i = 0; i < s.length; i++) {
    if (s[i] === "[") {
      open = i;
      break;
    }
    num = num * 10 + (s[i].charCodeAt(0) - zeroCode);
  }
  let count = 1;
  for (let i = open + 1; i < s.length; i++) {
    if (s[i] === "[") count++;
    if (s[i] === "]") count--;
    if (count === 0) {
      index = i;
      break;
    }
  }
  return (
    decodeString(s.substring(open + 1, index)).repeat(num) +
    decodeString(s.slice(index + 1))
  );
};
