function walk(root, level, ret) {
	if (!root) return;
	if (!ret[level]) ret[level] = [];

	ret[level].push(root.val);
	walk(root.left, level + 1, ret);
    walk(root.right, level + 1, ret);
}

var levelOrder = function(root) {
    var ret = [];
	walk(root, 0, ret);
	return ret;
};