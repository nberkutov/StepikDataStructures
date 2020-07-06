#include <cstring>
#include <iostream>
using namespace std;

int main() {
  
  char** book = new char*[1000001];

  int n = 0;
  cin >> n;

  int number;
  char name[15];
  char cmd[5];
  for (int i = 0; i < n; i++) {
    cin >> cmd;
    // cout << cmd << endl;
    if (strcmp(cmd, "add") == 0) {
      cin >> number;
      cin >> name;
      if (book[number] == nullptr) 
        book[number] = new char[15];
      strcpy(book[number], name);
    } else if (strcmp(cmd, "del") == 0) {
      cin >> number;
      if (book[number] != nullptr)
        strcpy(book[number], "");
    } else if (strcmp(cmd, "find") == 0) {
      cin >> number;
      if (book[number] != nullptr && strcmp(book[number], "") != 0) {
        cout << book[number] << endl;
      } else {
        cout << "not found" << endl;
      }
    }
  }

  return 0;
}