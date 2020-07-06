#include <iostream>
#include <queue>
using namespace std;

int main() {
  
  priority_queue<int, vector<int>, greater<int>> q;
  for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);
  
  
  return 0;
}