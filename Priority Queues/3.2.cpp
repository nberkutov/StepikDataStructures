#include <iostream>
#include <queue>
using namespace std;

class PriorityQueue {
 private:
  pair<long, long>* heap;
  int size;
  int maxSize;

  int parent(long i) { return (i - 1) / 2; }
  int left_child(long i) { return 2 * i + 1; }
  int right_child(long i) { return 2 * i + 2; }

  void sift_up(long i) {
    while (i > 0 && heap[i] < heap[parent(i)]) {
      swap(heap[i], heap[parent(i)]);
      i = parent(i);
    }
  }

  void sift_down(int i) {
    int left = left_child(i);
    int right = right_child(i);
    int min_index = i;

    if (left < size && heap[left] < heap[min_index]) min_index = left;
    if (right < size && heap[right] < heap[min_index]) min_index = right;

    if (i != min_index) {
      swap(heap[i], heap[min_index]);
      sift_down(min_index);
    }
  }

 public:
  PriorityQueue(int _size) {
    maxSize = _size;
    size = 0;
    heap = new pair<long, long>[maxSize];
  }

  int count() { return size; }

  pair<long, long> get_max() { return heap[0]; }

  void insert(pair<long, long> p) {
    if (size == maxSize) return;
    heap[size++] = p;
    sift_up(size - 1);
  }

  pair<long, long> extract_min() {
    pair<long, long> result = heap[0];
    heap[0] = heap[size - 1];
    size--;
    sift_down(0);
    return result;
  }

  void change_priority(long i, long p) {
    long oldP = heap[i].first;
    heap[i].first = p;
    if (p < oldP) {
      sift_up(i);
    } else {
      sift_down(i);
    }
  }

};

int main() {
  long n, m;

  cin >> n >> m;
  PriorityQueue q(n);

  for (int i = 0; i < n; i++) {
    q.insert(pair<int, int>(0, i));
  }

  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    pair<long, long> p = q.get_max();
    cout << p.second << " " << p.first << endl;
    q.change_priority(0, p.first + t);
  }

  return 0;
}