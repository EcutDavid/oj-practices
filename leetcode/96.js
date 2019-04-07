var numTrees = function(n) {
    let memo = [1, 1];

    // i eqauls the count of nodes in the BST.
    for (let i = 2; i <= n; i++) {
        let choiceCount = 0;
        // j represents the chosen root node.
        for (let j = 1; j <= i; j++) {
            const leftSideCount = j - 1;
            const rightSideCount = i - j;
            choiceCount += memo[leftSideCount] * memo[rightSideCount];
        }
        memo.push(choiceCount);
    }
	return memo[n];
};