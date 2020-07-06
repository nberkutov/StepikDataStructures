#include <iostream>
#include <cstring>
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

int main() {
  int n;
  cin >> n;

  char cmd[4];
  int arg;

  Stack<int> st(n);

  for (int i = 0; i < n; i++) {
    cin >> cmd;
    if(strcmp(cmd, "push") == 0) {
      cin >> arg;
      st.push(arg);
    }
    
    if(strcmp(cmd, "pop") == 0) {
      if(!st.empty()) {
        st.pop();
      }
    }

    if(strcmp(cmd, "max") == 0) {
      if(!st.empty()) {
        cout << st.Max() << endl;
      }
    }
  }

  return 0;
}