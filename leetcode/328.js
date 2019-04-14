var oddEvenList = function(head) {
  if (!head) return null;
  let oddHead = null,
    oddTail = null;
  let evenHead = null,
    evenTail = null;
  let counter = 1;
  while (head) {
    if (counter++ % 2) {
      if (oddHead) oddTail.next = head;
      else oddHead = head;
      oddTail = head;
    } else {
      if (evenHead) evenTail.next = head;
      else evenHead = head;
      evenTail = head;
    }
    head = head.next;
  }
  if (!oddHead) return evenHead;
  if (!evenHead) return oddHead;

  evenTail.next = null;
  oddTail.next = evenHead;
  return oddHead;
};
