#include <iostream>
#include <exception>
using namespace std;

class PriorityMaxHeap {
 private:
  int* heap;
  int maxSize;
  int size;

  int parent(int i) { return i / 2; }

  int left_child(int i) { return 2 * i; }

  int right_child(int i) { return 2 * i + 1; }

  void sift_up(int i) {
    while (i > 1 && parent(i) < heap[i]) {
      swap(heap[parent(i)], heap[i]);
      i = parent(i);
    }
  }

  void sift_down(int i) {
    int left = left_child(i);
    int right = right_child(i);
    int max_index = i;
    
    if (left <= size && heap[left] > heap[max_index]) {
      max_index = left;
    }

    if (right <= size && heap[right] > heap[max_index]) {
      max_index = left;
    }

    if (i != max_index) {
      swap(heap[i], heap[max_index]);
      sift_down(max_index);
    }
  }

 public:
  PriorityMaxHeap(int _size) {
    maxSize = _size;
    size = 0;
    heap = new int[_size + 1];
  }

  void insert(int p) {
    if (size == maxSize) {
      throw new exception();
    }
    
    heap[size++] = p;
    sift_up(size);
  }

  int extract_max() {
    int result = heap[1];
    heap[1] = heap[size--];
    sift_down(0);
  }

  int remove(int i) {
    heap[i] = heap[1] + 1;
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
    for (int i = 1; i <= size; i++) {
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