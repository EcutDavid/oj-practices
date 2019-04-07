var longestCommonPrefix = function(strs) {
	if (strs.length == 0) return "";

    let start = 0;
    let end = 0;
    while(true) {
        let canContinue = true;
        const target = strs[0][end];
        for (const str of strs) {
            if (str.length === end) {
                canContinue = false;
                    break;
            }
            if (str[end] != target) {
                canContinue = false;
                break;
            }
        }
        if (!canContinue) break;
        end++;
	}
	return strs[0].substring(start, end);
};