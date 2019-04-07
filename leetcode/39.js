function solve(candidates, path, index, ret, target) {
    if (target === 0) {
        ret.push(path);
        return;
    }
    const curVal = candidates[index];
    const loopCount = Math.floor(target / curVal);
    for (let i = 0; i <= loopCount; i++) {
        const segment = [];
        for (let j = 0; j < i; j++) segment.push(curVal);
        const newPath = path.concat(segment);
        solve(candidates, newPath, index + 1, ret, target - i * curVal);
    }
}


var combinationSum = function(candidates, target) {
    candidates = candidates.filter(c => c <= target).sort((a, b) => a - b);
	const ret = [];
	if (candidates.length == 0) return ret;
	const path = [];
	solve(candidates, path, 0, ret, target);
	return ret;
};