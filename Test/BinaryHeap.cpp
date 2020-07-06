#include <iostream>
using namespace std;

class BinaryHeap {
 private:
  int* heap;
  int maxSize;
  int size;

  void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
  }

  int parent(int i) { return i / 2; }

  int left_child(int i) { return 2 * i; }

  int right_child(int i) { return 2 * i + 1; }

  void sift_up(int i) {
    while (i > 1 && heap[parent(i)] < heap[i]) {
      swap(heap[parent(i)], heap[i]);
      i = parent(i);
    }
  }

  void sift_down(int i) {
    int max_index = i;

    int l = left_child(i);
    int r = right_child(i);

    if (l <= size && heap[l] > heap[max_index]) {
      max_index = l;
    }

    if (r <= size && heap[r] > heap[max_index]) {
      max_index = r;
    }

    if (max_index != i) {
      swap(heap[i], heap[max_index]);
      sift_down(max_index);
    }
  }

 public:
  BinaryHeap(int _size) {
    maxSize = _size;
    size = 0;
    heap = new int[maxSize + 1];
  }

  int get_max() { return heap[1]; }

  void insert(int p) {
    if (size == maxSize) {
      cout << "error" << endl;
      return;
    }

    size++;
    heap[size] = p;  //?
    sift_up(size);
  }

  int extract_max() {
    int result = heap[1];
    heap[1] = heap[size];  //?
    size--;
    sift_down(1);
    return result;
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

void sift_up(int heap[], int i) {
  int parent = (i - 1) / 2;
  while (i > 0 && heap[parent] < heap[i]) {
    swap(heap[parent], heap[i]);
    i = parent;
  }
}

void sift_down(int A[], int size, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int max_index = i;

  if (left < size && A[left] > A[max_index]) {
    max_index = left;
  }

  if (right < size && A[right] > A[max_index]) {
    max_index = right;
  }

  if (max_index != i) {
    swap(A[i], A[max_index]);
    cout << i << " " << max_index << endl;
    sift_down(A, size, max_index);
  }
}

void build_heap(int A[], int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    sift_down(A, size, i);
  }
}

void heap_sort(int A[], int size) {
  int n = size;
  build_heap(A, size);
  for (int i = size - 1; i >= 0; i--) {
    swap(A[0], A[size - 1]);
    size--;
    sift_down(A, size, 0);
  }
}

int main() {
  BinaryHeap heap(9);
  heap.insert(11);
  heap.insert(29);
  heap.insert(14);
  heap.insert(18);
  heap.insert(12);
  heap.insert(13);
  heap.insert(42);
  heap.insert(7);
  heap.insert(18);

  int A[] = {5, 4, 3, 2, 1};
  build_heap(A, 5);
  for (int i = 0; i < 5; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}