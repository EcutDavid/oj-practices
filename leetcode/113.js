function walk(node, target, path, ret) {
	if (!node) return;
	if (!node.right && !node.left && (node.val === target)) {
		ret.push(path.concat(node.val));
        return;
    }
    walk(node.left, target - node.val, path.concat(node.val), ret);
    walk(node.right, target - node.val, path.concat(node.val), ret);
}

var pathSum = function(root, sum) {
    const ret = [];
    walk(root, sum, [], ret);
    return ret;
};