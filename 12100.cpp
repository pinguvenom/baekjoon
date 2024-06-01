#include <bits/stdc++.h>
using namespace std;

int n;
int _arr[21][21];
int arr[21][21];

int _max = 0;

void find_max() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] > _max) {
        if (arr[i][j] == 128) {
          continue;
        }
        _max = arr[i][j];
      }
    }
  }
}

void move(int direction) {
  // 위로 이동
  if (direction == 1) {
    for (int j = 0; j < n; j++) {
      int cursor = 0;
      for (int i = 0; i < n; i++) {
        if (arr[i][j] != 0) {
          int tmp = arr[i][j];
          arr[i][j] = 0;

          if (arr[cursor][j] == 0) {
            arr[cursor][j] = tmp;
          } else if (arr[cursor][j] == tmp) {
            arr[cursor][j] *= 2;
            cursor++;
          } else {
            cursor++;
            arr[cursor][j] = tmp;
          }
        }
      }
    }
  }
  // 아래로 이동
  else if (direction == 2) {
    for (int j = 0; j < n; j++) {
      int cursor = n - 1;
      for (int i = n - 1; i >= 0; i--) {
        if (arr[i][j] != 0) {
          int tmp = arr[i][j];
          arr[i][j] = 0;

          if (arr[cursor][j] == 0) {
            arr[cursor][j] = tmp;
          } else if (arr[cursor][j] == tmp) {
            arr[cursor][j] *= 2;
            cursor--;
          } else {
            cursor--;
            arr[cursor][j] = tmp;
          }
        }
      }
    }
  }
  // 좌로 이동
  else if (direction == 3) {
    for (int i = 0; i < n; i++) {
      int cursor = 0;
      for (int j = 0; j < n; j++) {
        if (arr[i][j] != 0) {
          int tmp = arr[i][j];
          arr[i][j] = 0;

          if (arr[i][cursor] == 0) {
            arr[i][cursor] = tmp;
          } else if (arr[i][cursor] == tmp) {
            arr[i][cursor] *= 2;
            cursor++;
          } else {
            cursor++;
            arr[i][cursor] = tmp;
          }
        }
      }
    }
  }
  // 우로 이동
  else if (direction == 4) {
    for (int i = 0; i < n; i++) {
      int cursor = n - 1;
      for (int j = n - 1; j >= 0; j--) {
        if (arr[i][j] != 0) {
          int tmp = arr[i][j];
          arr[i][j] = 0;

          if (arr[i][cursor] == 0) {
            arr[i][cursor] = tmp;
          } else if (arr[i][cursor] == tmp) {
            arr[i][cursor] *= 2;
            cursor--;
          } else {
            cursor--;
            arr[i][cursor] = tmp;
          }
        }
      }
    }
  }
  return;
}

void search(vector<int> vec) {
  if (vec.size() == 5) {
    memcpy(arr, _arr, sizeof(arr));
    for (auto x : vec) {
      move(x);
    }
    find_max();
    return;
  }

  for (int i = 1; i < 5; i++) {
    vec.push_back(i);
    search(vec);
    vec.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> _arr[i][j];
    }
  }
  vector<int> vec;
  search(vec);

  cout << _max;

  return 0;
}