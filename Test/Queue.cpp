#include <iostream>
using namespace std;

template <class Item>
class Queue {
 private:
  Item* data;
  int size;
  int N;
  int front, back;

 public:
  Queue(int _size) {
    size = _size + 1;
    data = new Item[size + 1];
    front = size;
    back = 0;
    N = 0;
  }

  ~Queue() {}

  bool empty() { return front % size == back; }

  void push(Item item) {
    data[back++] = item;
    back = back % size;
    N++;
  }

  Item pop() {
    N--;
    front = front % size;
    return data[front++];
  }

  int count() { return N; }
};