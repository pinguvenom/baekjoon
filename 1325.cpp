#include <bits/stdc++.h>
using namespace std;

vector<int> vec[10001];
int visited[10001];
void dfs(int here, int& cnt) {
  visited[here] = 1;
  cnt++;

  for (int there : vec[here]) {
    if (visited[there] == 1) {
      continue;
    }
    dfs(there, cnt);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  while (m--) {
    int a, b;
    cin >> a >> b;

    vec[b].push_back(a);
  }

  int max_cnt = 0;
  vector<int> max_cnt_idx;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    dfs(i, cnt);

    if (cnt > max_cnt) {
      max_cnt = cnt;
      max_cnt_idx.clear();
      max_cnt_idx.push_back(i);
    } else if (cnt == max_cnt) {
      max_cnt_idx.push_back(i);
    }
  }

  for (auto i : max_cnt_idx) {
    cout << i << ' ';
  }

  return 0;
}