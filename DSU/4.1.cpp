#include <iostream>
using namespace std;

class UnionFind {
 private:
  int* parent;
  int* rank;
  int* values;
  int size;

 public:
  UnionFind(int _size) {
    size = _size + 1;
    parent = new int[size];
    rank = new int[size];
    values = new int[size];
    parent[0] = 0;
  }

  void make_set(int i, int r) {
    parent[i] = i;
    rank[i] = 0;
    values[i] = r;
    if (r > parent[0]) parent[0] = r;
  }

  int find(int i) {
    if (i != parent[i]) {
      parent[i] = find(parent[i]);
    }
    return parent[i];
  }

  void Union(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return;

    if (rank[x] > rank[y]) {
      parent[x] = y;
      values[y] += values[x];
      if (values[y] > parent[0]) parent[0] = values[y];
    } else {
      parent[y] = x;
      values[x] += values[y];
      if (values[x] > parent[0]) parent[0] = values[x];
      if (rank[x] == rank[y]) ++rank[x];
    }
  }

  int get_val() { return parent[0]; }
};

int main() {
  int n, m;
  int destination, source;

  cin >> n >> m;
  UnionFind uf(n);
  for (int i = 1; i <= n; i++) {
    int r;
    cin >> r;
    uf.make_set(i, r);
  }

  for (int i = 0; i < m; i++) {
    cin >> destination >> source;

    uf.Union(destination, source);
    cout << uf.get_val() << endl;
  }

  return 0;
}