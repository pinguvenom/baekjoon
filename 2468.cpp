#include <bits/stdc++.h>
using namespace std;

int n;
int adj[100][100];
bool b_adj[100][100];
bool visited[100][100];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
  visited[y][x] = true;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
      continue;
    }
    if (b_adj[ny][nx] == false || visited[ny][nx] == true) {
      continue;
    }
    dfs(ny, nx);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  int max_n = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> adj[i][j];
      if (adj[i][j] > max_n) {
        max_n = adj[i][j];
      }
    }
  }

  int max_safety_area_cnt = 1;
  for (int k = 1; k < max_n; k++) {
    int safety_area_cnt = 0;

    // initialize variable
    memset(b_adj, 0, sizeof(b_adj));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (adj[i][j] > k) {
          b_adj[i][j] = 1;
        }
      }
    }

    // calculate safety area
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (b_adj[i][j] == true && visited[i][j] == false) {
          safety_area_cnt++;
          dfs(i, j);
        }
      }
    }

    if (safety_area_cnt > max_safety_area_cnt) {
      max_safety_area_cnt = safety_area_cnt;
    }
  }

  cout << max_safety_area_cnt;

  return 0;
}