#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[4][4];
int max_sum;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      arr[i][j] = s[j] - '0';
    }
  }

  for (int k = 0; k < (1 << (n * m)); k++) {
    int sum = 0;
    // 가로줄 더하기
    for (int i = 0; i < n; i++) {
      int val = 0;
      for (int j = 0; j < m; j++) {
        int idx = i * m + j;
        if ((k & (1 << idx)) == 0) {
          val *= 10;
          val += arr[i][j];
        } else {
          sum += val;
          val = 0;
        }
      }
      sum += val;
    }

    // 세로줄 더하기
    for (int j = 0; j < m; j++) {
      int val = 0;
      for (int i = 0; i < n; i++) {
        int idx = i * m + j;
        if ((k & (1 << idx)) != 0) {
          val *= 10;
          val += arr[i][j];
        } else {
          sum += val;
          val = 0;
        }
      }
      sum += val;
    }

    max_sum = max({sum, max_sum});
  }

  cout << max_sum;
  return 0;
}