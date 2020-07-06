#include <iostream>
using namespace std;

class UnionFind {
  int* parents;
  int* ranks;
  int size;

 public:
  UnionFind(int _size) {
    size = _size + 1;
    parents = new int[size];
    ranks = new int[size];
  }

  void make_set(int i) { parents[i] = i; }

  int find(int i) {
    if (i != parents[i]) {
      parents[i] = find(parents[i]);
    }
    return parents[i];
  }

  void unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return;

    if (ranks[x] > ranks[y]) {
      parents[x] = y;
    } else {
      parents[y] = x;
      if (ranks[x] == ranks[y]) {
        ranks[x]++;
      }
    }
  }

  int inequality(int x, int y) { return find(x) == find(y) ? 0 : 1; }
};

int main() {
  int n, e, d;
  cin >> n >> e >> d;

  UnionFind uf(n);
  for (int i = 0; i < n; i++) {
    uf.make_set(i);
  }

  for (int k = 0; k < e; k++) {
    int i, j;
    cin >> i >> j;
    uf.unite(i, j);
  }

  int t = 1;
  for (int k = 0; k < d; k++) {
    int i, j;
    cin >> i >> j;
    t *= uf.inequality(i, j);
  }

  cout << t << endl;

  return 0;
}