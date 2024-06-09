#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int arr[50][50];

void move_circle(int x, int d, int k) {
  int tmp[50][50];
  memcpy(tmp, arr, sizeof(arr));

  for (int i = 0; i < n; i++) {
    if ((i + 1) % x != 0) {
      continue;
    }

    for (int j = 0; j < m; j++) {
      if (d == 0) {  // cw
        tmp[i][(j + k) % m] = arr[i][j];
      } else {  // ccw
        tmp[i][j] = arr[i][(j + k) % m];
      }
    }
  }
  memcpy(arr, tmp, sizeof(tmp));
}

void modify_circle() {
  int sum = 0;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j]) {
        sum += arr[i][j];
        cnt++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!arr[i][j]) {
        continue;
      }
      if (arr[i][j] < (float)sum / cnt) {
        arr[i][j]++;
      } else if (arr[i][j] > (float)sum / cnt) {
        arr[i][j]--;
      }
    }
  }
}

void remove_adj() {
  int tmp[50][50];
  memcpy(tmp, arr, sizeof(arr));

  bool removed = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!arr[i][j]) {
        continue;
      }

      if (arr[i][j] == arr[i][(j + 1) % m]) {
        removed = true;
        tmp[i][j] = 0;
        tmp[i][(j + 1) % m] = 0;
      }
    }
  }

  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (!arr[i][j]) {
        continue;
      }

      if (arr[i][j] == arr[i + 1][j]) {
        removed = true;
        tmp[i][j] = 0;
        tmp[i + 1][j] = 0;
      }
    }
  }
  memcpy(arr, tmp, sizeof(tmp));

  if (!removed) {
    modify_circle();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> t;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  while (t--) {
    int x, d, k;
    cin >> x >> d >> k;
    move_circle(x, d, k);
    remove_adj();
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j]) {
        sum += arr[i][j];
      }
    }
  }

  cout << sum;
  return 0;
}