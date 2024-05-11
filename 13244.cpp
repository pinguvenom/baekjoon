#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int visited[1001];

void dfs(int here) {
  visited[here] = 1;
  for (auto there : adj[here]) {
    if (visited[there]) {
      continue;
    }
    dfs(there);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
      adj[i].clear();
    }
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    dfs(1);

    bool b_connected = true;
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        b_connected = false;
        break;
      }
    }

    if (b_connected && m == n - 1) {
      cout << "tree\n";
    } else {
      cout << "graph\n";
    }
  }

  return 0;
}