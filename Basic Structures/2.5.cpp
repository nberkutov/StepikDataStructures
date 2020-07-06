#include <iostream>
using namespace std;

template <class Item>
class Stack {
 private:
  Item* data;
  Item* max;
  int size;

 public:
  Stack(int _size) {
    data = new Item[_size];
    max = new Item[_size];
    size = 0;
  }

  ~Stack() {}

  bool empty() { return size == 0; }

  void push(Item item) {
    if (size == 0) {
      max[size] = item;
    } else {
      if (item > max[size - 1]) {
        max[size] = item;
      } else {
        max[size] = max[size - 1];
      }
    }
    data[size++] = item;
  }

  Item pop() { return data[--size]; }

  Item Max() {
    int ind = size - 1;
    return max[ind];
  }
};

class Queue {
 private:
  Stack<int>* push_stack;
  Stack<int>* pop_stack;
  int count;

  void replace() {
    while (!push_stack->empty()) {
      pop_stack->push(push_stack->pop());
    }
  }

 public:
  Queue(int size) {
    push_stack = new Stack<int>(size);
    pop_stack = new Stack<int>(size);
    count = 0;
  }

  bool empty() { return count == 0; }

  void push(int item) {
    push_stack->push(item);
    count++;
  }

  int pop() {
    if (pop_stack->empty()) {
      replace();
    }
    count--;
    return pop_stack->pop();
  }

  int max() {
    if (pop_stack->Max() > push_stack->Max()) {
      return pop_stack->Max();
    } else {
      return push_stack->Max();
    }
  }

  int size() {
    return count;
  }
};

int main() {
  int n, m;
  
  cin >> n;
  int* A = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  cin >> m;
  Queue q(m);
  
  int k = 0;
  while (k <= n)
  {
    if (q.size() == m){
      cout << q.max() << " ";
      q.pop();
    }
    q.push(A[k++]);
  }

  return 0;
}