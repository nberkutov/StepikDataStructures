#include <iostream>
#include <string>
using namespace std;

struct node {
  string str;
  node* next;
  node() {}
  node(string s, node* _next) {
    str = s;
    next = _next;
  }
};
typedef node* link;

class HashTable {
  link* T;
  int size;

  int Hash(string s) {
    long p = 1000000007;
    int len = s.length();
    long long* x = new long long[len];
    long long h = 0;

    x[0] = 1;
    for (int i = 1; i < len; i++) {
      x[i] = ((x[i - 1] % p) * (263 % p)) % p;
    }

    for (int i = 0; i < len; i++) {
      h += s[i] * x[i];
      h %= p;
    }
    return h % size;
  }

 public:
  HashTable(int _size) {
    size = _size;
    T = new link[size + 1];
    for (size_t i = 0; i <= size; i++) {
      T[i] = new node("", 0);
    }
  }

  void add(string s) {
    if (find(s)) return;

    int pos = Hash(s);
    link t = new node(s, T[pos]->next);
    T[pos]->next = t;
  }

  bool find(string s) {
    int pos = Hash(s);
    link t;
    for (t = T[pos]->next; t != 0; t = t->next) {
      if (s.compare(t->str) == 0) {
        return true;
      }
    }
    return false;
  }

  void check(int i) {
    link t;
    for (t = T[i]->next; t != 0; t = t->next) {
      cout << t->str << " ";
    }
    cout << endl;
  }

  void del(string s) {
    int pos = Hash(s);
    for (link t = T[pos]; t->next != 0; t = t->next) {
      if (s.compare(t->next->str) == 0) {
        link d = t->next;
        t->next = d->next;
        delete d;
        return;
      }
    }
  }
};

int main() {
  string cmd;
  string str;
  int arg;

  int m, n;
  cin >> m;
  cin >> n;

  HashTable ht(m);
  for (int i = 0; i < n; i++) {
    cin >> cmd;
    if (cmd.compare("add") == 0) {
      cin >> str;
      ht.add(str);
    }
    if (cmd.compare("del") == 0) {
      cin >> str;
      ht.del(str);
    }
    if (cmd.compare("find") == 0) {
      cin >> str;
      if (ht.find(str)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
    if (cmd.compare("check") == 0) {
      cin >> arg;
      ht.check(arg);
    }
  }
}