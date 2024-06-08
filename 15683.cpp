#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8][8];
int tmp[8][8];
struct cctv {
  int y, x, n;
};
vector<cctv> vec;
vector<int> vec2;
int cctv_case[6] = {0, 4, 2, 4, 4, 1};

int _min = INT_MAX;

void solve(int idx) {
  if (idx == vec.size()) {
    memcpy(tmp, arr, sizeof(arr));
    for (int i = 0; i < idx; i++) {
      tmp[vec[i].y][vec[i].x] == 1;
      if (vec[i].n == 1) {
        if (vec2[i] == 0) {
          int loc = vec[i].x;
          while (true) {
            if (loc >= m || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc++;
          }
        } else if (vec2[i] == 1) {
          int loc = vec[i].y;
          while (true) {
            if (loc < 0 || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc--;
          }
        } else if (vec2[i] == 2) {
          int loc = vec[i].x;
          while (true) {
            if (loc < 0 || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc--;
          }
        } else if (vec2[i] == 3) {
          int loc = vec[i].y;
          while (true) {
            if (loc >= n || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc++;
          }
        }
      } else if (vec[i].n == 2) {
        if (vec2[i] == 0) {
          int loc = vec[i].x;
          while (true) {
            if (loc >= m || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc++;
          }

          loc = vec[i].x;
          while (true) {
            if (loc < 0 || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc--;
          }
        } else if (vec2[i] == 1) {
          int loc = vec[i].y;
          while (true) {
            if (loc < 0 || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc--;
          }

          loc = vec[i].y;
          while (true) {
            if (loc >= n || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc++;
          }
        }
      } else if (vec[i].n == 3) {
        if (vec2[i] == 0) {
          int loc = vec[i].x;
          while (true) {
            if (loc >= m || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc++;
          }
          loc = vec[i].y;
          while (true) {
            if (loc < 0 || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc--;
          }
        } else if (vec2[i] == 1) {
          int loc = vec[i].y;
          while (true) {
            if (loc < 0 || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc--;
          }
          loc = vec[i].x;
          while (true) {
            if (loc < 0 || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc--;
          }
        } else if (vec2[i] == 2) {
          int loc = vec[i].x;
          while (true) {
            if (loc < 0 || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc--;
          }
          loc = vec[i].y;
          while (true) {
            if (loc >= n || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc++;
          }
        } else if (vec2[i] == 3) {
          int loc = vec[i].y;
          while (true) {
            if (loc >= n || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc++;
          }
          loc = vec[i].x;
          while (true) {
            if (loc >= m || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc++;
          }
        }
      } else if (vec[i].n == 4) {
        if (vec2[i] == 0) {
          int loc = vec[i].x;
          while (true) {
            if (loc >= m || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc++;
          }
          loc = vec[i].y;
          while (true) {
            if (loc < 0 || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc--;
          }
          loc = vec[i].x;
          while (true) {
            if (loc < 0 || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc--;
          }
        } else if (vec2[i] == 1) {
          int loc = vec[i].y;
          while (true) {
            if (loc < 0 || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc--;
          }
          loc = vec[i].x;
          while (true) {
            if (loc < 0 || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc--;
          }
          loc = vec[i].y;
          while (true) {
            if (loc >= n || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc++;
          }
        } else if (vec2[i] == 2) {
          int loc = vec[i].x;
          while (true) {
            if (loc < 0 || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc--;
          }
          loc = vec[i].y;
          while (true) {
            if (loc >= n || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc++;
          }
          loc = vec[i].x;
          while (true) {
            if (loc >= m || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc++;
          }
        } else if (vec2[i] == 3) {
          int loc = vec[i].y;
          while (true) {
            if (loc >= n || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc++;
          }
          loc = vec[i].x;
          while (true) {
            if (loc >= m || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc++;
          }
          loc = vec[i].y;
          while (true) {
            if (loc < 0 || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc--;
          }
        }
      } else if (vec[i].n == 5) {
        if (vec2[i] == 0) {
          int loc = vec[i].x;
          while (true) {
            if (loc >= m || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc++;
          }
          loc = vec[i].y;
          while (true) {
            if (loc < 0 || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc--;
          }
          loc = vec[i].x;
          while (true) {
            if (loc < 0 || arr[vec[i].y][loc] == 6) {
              break;
            }
            tmp[vec[i].y][loc] = 1;
            loc--;
          }
          loc = vec[i].y;
          while (true) {
            if (loc >= n || arr[loc][vec[i].x] == 6) {
              break;
            }
            tmp[loc][vec[i].x] = 1;
            loc++;
          }
        }
      }
    }

    int cnt = m * n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (tmp[i][j]) {
          cnt--;
        }
      }
    }
    if (cnt < _min) {
      _min = cnt;
    }
    return;
  }
  for (int i = 0; i < cctv_case[vec[idx].n]; i++) {
    vec2.push_back(i);
    solve(idx + 1);
    vec2.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] >= 1 && arr[i][j] <= 5) {
        vec.push_back({i, j, arr[i][j]});
      }
    }
  }

  solve(0);
  cout << _min;

  return 0;
}