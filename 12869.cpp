#include <bits/stdc++.h>
using namespace std;

int n;
int arr[3];
int dx[6] = {9, 9, 3, 3, 1, 1};
int dy[6] = {3, 1, 9, 1, 9, 3};
int dz[6] = {1, 3, 1, 9, 3, 9};

int visited[61][61][61];

struct dtype {
  int a, b, c;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  queue<dtype> q;
  visited[arr[0]][arr[1]][arr[2]] = 1;
  q.push({arr[0], arr[1], arr[2]});

  while (q.size()) {
    int a = q.front().a;
    int b = q.front().b;
    int c = q.front().c;
    q.pop();

    if (a == 0 && b == 0 && c == 0) {
      break;
    }

    for (int i = 0; i < 6; i++) {
      int na = max(0, a - dx[i]);
      int nb = max(0, b - dy[i]);
      int nc = max(0, c - dz[i]);

      if (visited[na][nb][nc]) {
        continue;
      }
      visited[na][nb][nc] = visited[a][b][c] + 1;
      q.push({na, nb, nc});
    }
  }
  cout << visited[0][0][0] - 1;
}