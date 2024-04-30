#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[200001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  queue<int> q;
  q.push(n);
  visited[n] = 1;

  while (q.size()) {
    int x = q.front();
    q.pop();

    if (x == k) {
      break;
    }

    for (int i = 0; i < 3; i++) {
      int nx;
      if (i == 0) {
        nx = min(x + 1, 200000);
      } else if (i == 1) {
        nx = max(x - 1, 0);
      } else {
        nx = min(x * 2, 200000);
      }
      if (visited[nx]) {
        continue;
      }

      q.push(nx);
      visited[nx] = visited[x] + 1;
    }
  }

  cout << visited[k] - 1;

  return 0;
}