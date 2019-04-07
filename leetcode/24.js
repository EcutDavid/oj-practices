var swapPairs = function(head) {
    if (!head || !head.next) return head;
    const newHead = head.next;

    let cur = head;
    let prev = undefined;
    while(cur && cur.next) {
        const curNext = cur.next;
        const curNextNext = curNext.next;
        if (prev) {
            prev.next = curNext;
        }
        prev = cur;
        curNext.next = cur;
        cur.next = curNextNext;
        cur = curNextNext;
    }

    return newHead;
};