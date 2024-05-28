#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100];

vector<int> multab;
int visited[101];

int cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < k; i++) {
    if (visited[arr[i]]) {
      continue;
    }

    if (multab.size() == n) {
      int last_idx = 0, last_val = 0;
      for (int x : multab) {
        int idx = INT_MAX;
        for (int j = i + 1; j < k; j++) {
          if (x == arr[j]) {
            idx = j;
            break;
          }
        }
        if (last_idx < idx) {
          last_idx = idx;
          last_val = x;
        }
      }
      visited[last_val] = 0;
      multab.erase(find(multab.begin(), multab.end(), last_val));
      cnt++;
    }
    multab.push_back(arr[i]);
    visited[arr[i]] = 1;
  }

  cout << cnt;
  return 0;
}