#include <iostream>
#include <queue>
using namespace std;

int main() {
  int size, n;
  cin >> size >> n;

  queue<int> q;
  queue<int> a;
  int arrival, duration;
  int finishTime = 0;
  int k = 0;
  for (int i = 0; i < n; i++) {
    cin >> arrival >> duration;

    while (!q.empty() && q.front() <= arrival) {
      q.pop();
    }

    if (finishTime < arrival) {
      cout << arrival << endl;
      finishTime = arrival + duration;
      q.push(finishTime);
    } else if (q.size() < size) {
      cout << finishTime << endl;
      finishTime += duration;
      q.push(finishTime);
    } else {
      cout << -1 << endl;
    }
  }

  /*while (!a.empty()) {
    cout << a.back() << endl;
    a.pop();
  }*/

  return 0;
}