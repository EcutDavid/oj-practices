function topKFrequent(nums, k) {
  const counter = new Map();
  for (const num of nums) {
    const cur = counter.get(num);
    counter.set(num, (cur ? cur : 0) + 1);
  }

  const ph = new PairHeap();
  for (const d of counter) {
    ph.push([d[1], d[0]]);
  }

  const ret = [];
  for (let i = 0; i < k; i++) {
    ret.push(ph.top[1]);
    ph.pop();
  }
  return ret;
}

// Assumption: there won't be any duplication for the pair's second value.
class PairHeap {
  constructor() {
    this.arr = [];
  }

  parent(index) {
    return (index - 1) / 2;
  }

  leftChild(index) {
    return index * 2 + 1;
  }

  rightChild(index) {
    return index * 2 + 2;
  }

  swap(a, b) {
    const tmp = this.arr[a];
    this.arr[a] = this.arr[b];
    this.arr[b] = tmp;
  }

  push(pair) {
    let cur = this.arr.length;
    this.arr.push(pair);
    while (cur > 0) {
      const parent = this.parent(cur);
      if (this.arr[parent][0] >= this.arr[cur][0]) break;
      this.swap(cur, parent);
      cur = parent;
    }
  }

  top() {
    return this.arr[this.arr.length - 1];
  }

  pop() {
    this.arr[0] = this.arr[this.arr.length - 1];
    this.arr.pop();
    let cur = 0;
    while (true) {
      const left = this.leftChild(cur);
      const right = this.rightChild(cur);
      const indexMax = this.arr.length - 1;

      let largest = cur;
      if (left <= indexMax && this.arr[left][0] > this.arr[largest][0])
        largest = left;
      if (right <= indexMax && this.arr[right][0] > this.arr[largest][0])
        largest = right;

      if (largest == cur) break;
      this.swap(cur, largest);
      cur = largest;
    }
  }
}
