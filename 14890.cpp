#include <bits/stdc++.h>
using namespace std;

int n, l;
int arr[100][100];
int cnt;

bool check_row_road(int i) {
  int prev = arr[i][0];
  int slope[100];  // 1: up_slope,  2: down_slope, 0: no_slope
  memset(slope, 0, sizeof(slope));

  for (int j = 1; j < n; j++) {
    if (arr[i][j] == prev) {
      continue;
    } else if (abs(arr[i][j] - prev) >= 2) {
      return false;
    } else if (arr[i][j] > prev) {
      if (j < l) {
        return false;
      }
      for (int k = 1; k <= l; k++) {
        if (slope[j - k]) {
          return false;
        }
        slope[j - k] = 1;
      }
    } else if (arr[i][j] < prev) {
      if (j + l > n) {
        return false;
      }
      for (int k = 0; k < l; k++) {
        if (slope[j + k]) {
          return false;
        }
        slope[j + k] = 2;
      }
    }
    prev = arr[i][j];
  }
  return true;
}

bool check_col_road(int i) {
  int prev = arr[0][i];
  int slope[100];  // 1: up_slope,  2: down_slope, 0: no_slope
  memset(slope, 0, sizeof(slope));

  for (int j = 1; j < n; j++) {
    if (arr[j][i] == prev) {
      continue;
    } else if (abs(arr[j][i] - prev) >= 2) {
      return false;
    } else if (arr[j][i] > prev) {
      if (j < l) {
        return false;
      }
      for (int k = 1; k <= l; k++) {
        if (slope[j - k]) {
          return false;
        }
        slope[j - k] = 1;
      }
    } else if (arr[j][i] < prev) {
      if (j + l > n) {
        return false;
      }
      for (int k = 0; k < l; k++) {
        if (slope[j + k]) {
          return false;
        }
        slope[j + k] = 2;
      }
    }
    prev = arr[j][i];
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (check_row_road(i)) {
      cnt++;
    }
    if (check_col_road(i)) {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}