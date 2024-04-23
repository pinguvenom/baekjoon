#include <bits/stdc++.h>
using namespace std;

int cnt;
int removed_node;
vector<int> vec[50];

void get_leaf_cnt(int n) {
  if (n == removed_node) {
    return;
  }
  if (vec[n].empty()) {
    cnt++;
    return;
  }
  for (int i : vec[n]) {
    if (i == removed_node) {
      if (vec[n].size() == 1) {
        cnt++;
      }
      continue;
    }
    get_leaf_cnt(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int root_node;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == -1) {
      root_node = i;
    } else {
      vec[x].push_back(i);
    }
  }
  cin >> removed_node;

  get_leaf_cnt(root_node);
  cout << cnt;
  return 0;
}