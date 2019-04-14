function calcListLen(l) {
  let len = 0;
  while (l) {
    l = l.next;
    len++;
  }
  return len;
}

function getFirstReachableNode(lA, lB) {
  const lALen = calcListLen(lA);
  const lBLen = calcListLen(lB);
  for (let i = 0; i < Math.abs(lALen - lBLen); i++) {
    if (lALen > lBLen) lA = lA.next;
    else lB = lB.next;
  }
  while (lA && lA !== lB) {
    lA = lA.next;
    lB = lB.next;
  }
  return lA;
}

const n1 = { val: 1 };
const n2 = { val: 2 };
const n3 = { val: 3 };
const n4 = { val: 4 };
const n5 = { val: 5 };
const n6 = { val: 6 };

n1.next = n2;
n2.next = n3;
n4.next = n3;
n3.next = n5;
n5.next = n6;

const lA = n1;
const lB = n4;
console.log(getFirstReachableNode(lA, lB));
