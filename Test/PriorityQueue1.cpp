#include <iostream>
using namespace std;

class PriorityMaxHeap {
 private:
  int* heap;
  int maxSize;
  int size;

  void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
  }

  int parent(int i) { return (i - 1) / 2; }

  int left_child(int i) { return 2 * i + 1; }

  int right_child(int i) { return 2 * i + 2; }

  void sift_up(int i) {
    while (i > 0 && heap[parent(i)] < heap[i]) {
      swap(heap[parent(i)], heap[i]);
      i = parent(i);
    }
  }

  void sift_down(int i) {
    int max_index = i;

    int l = left_child(i);
    if (l < size && heap[l] > heap[max_index]) {
      max_index = l;
    }

    int r = right_child(i);
    if (r < size && heap[r] > heap[max_index]) {
      max_index = r;
    }

    if (max_index != i) {
      swap(heap[i], heap[max_index]);
      sift_down(max_index);
    }
  }

 public:
  PriorityMaxHeap(int _size) {
    maxSize = _size;
    size = 0;
    heap = new int[maxSize];
  }

  int get_max() { return heap[0]; }

  void insert(int p) {
    if (size == maxSize) {
      cout << "error" << endl;
      return;
    }

    size++;
    heap[size - 1] = p;  //?
    sift_up(size);
  }

  int extract_max() {
    int result = heap[0];
    heap[0] = heap[size - 1];  //?
    size--;
    sift_down(0);
    return result;
  }

  int remove(int i) {
    heap[i] = heap[0] + 1;
    sift_up(i);
    extract_max();
  }

  void change_priority(int i, int p) {
    int oldP = heap[i];
    heap[i] = p;
    if (p > oldP) {
      sift_up(i);
    } else {
      sift_down(i);
    }
  }

  void print() {
    for (int i = 0; i < size; i++) {
      cout << heap[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  PriorityMaxHeap heap(9);
  heap.insert(11);
  heap.insert(29);
  heap.insert(14);
  heap.insert(18);
  heap.insert(12);
  heap.insert(13);
  heap.insert(42);
  heap.insert(7);
  heap.insert(18);
  
  heap.print();

  for (int i = 0; i < 9; i++) {
    cout << heap.extract_max() << endl;
  }

  return 0;
}