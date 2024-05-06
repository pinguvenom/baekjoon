#include <bits/stdc++.h>
using namespace std;

int n;
int population[10];
vector<int> adj[10];

int arr[10];
int visited[10];

int on_population;
int off_population;

int _min = INT_MAX;

void dfs(int here) {
  visited[here] = 1;
  if (arr[here]) {
    on_population += population[here];
  } else {
    off_population += population[here];
  }

  for (int there : adj[here]) {
    if (arr[here] != arr[there] || visited[there]) {
      continue;
    }
    dfs(there);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> population[i];
  }

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < x; j++) {
      int val;
      cin >> val;
      adj[i].push_back(val - 1);
    }
  }

  for (int i = 0; i < (1 << n); i++) {
    if (i == 0 || i == (1 << n) - 1) {
      continue;
    }
    memset(arr, 0, sizeof(arr));
    memset(visited, 0, sizeof(visited));
    on_population = 0;
    off_population = 0;

    for (int j = 0; j < n; j++) {
      // j 번째 비트가 켜져 있으면 -> on
      if (i & (1 << j)) {
        arr[j] = 1;
      }
    }
    int conn_cmp = 0;
    for (int j = 0; j < n; j++) {
      if (!visited[j]) {
        dfs(j);
        conn_cmp++;
        if (conn_cmp > 2) {
          break;
        }
      }
    }

    if (conn_cmp == 2) {
      _min = min({_min, abs(on_population - off_population)});
    }
  }

  if (_min == INT_MAX) {
    cout << -1;
  } else {
    cout << _min;
  }

  return 0;
}