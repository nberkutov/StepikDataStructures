#include <iostream>
using namespace std;

const int MAXN = 100000;

int p[MAXN];
int rank[MAXN];
int vals[MAXN];

void MakeSet(int* p, int* rank, int x) 
{
    p[x] = x;
    rank[x] = 0;
}

int Find(int x) 
{
    return ( x == p[x] ? x : p[x] = Find(p[x]) );
}

void Union(int* rank, int x, int y) 
{
    if ( (x = Find(x)) == (y = Find(y)) )
        return;
	
    if ( rank[x] <  rank[y] )
        p[x] = y;
    else {
        p[y] = x;
        if ( rank[x] == rank[y] )
            ++rank[x];
    }
}

int main() {
  int n, m;
  int destination, source;

  cin >> n >> m;
  
  for (int i = 1; i <= n; i++) {
    int r;
    cin >> r;
    p[i] = i;
  }

  for (int i = 0; i < m; i++) {
    cin >> destination >> source;
  }

  return 0;
}