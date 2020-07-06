#include <iostream>
#include <vector>
using namespace std;

void sift_down(int a[], int n, int i, vector<std::pair<int, int>>& v) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int min_index = i;

  if (left < n && a[left] < a[min_index]) min_index = left;

  if (right < n && a[right] < a[min_index]) min_index = right;

  if (i != min_index) {
    swap(a[i], a[min_index]);
    v.push_back(std::pair<int, int>(i, min_index));
    sift_down(a, n, min_index, v);
  }
}

void build_heap(int a[], int n, vector<std::pair<int, int>>& v) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    sift_down(a, n, i, v);
  }
}

int main() {
  int n;
  cin >> n;

  int* a = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<std::pair<int, int>> v;
  build_heap(a, n, v);
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }

  return 0;
}