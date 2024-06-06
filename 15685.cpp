#include <bits/stdc++.h>
using namespace std;

int n;
int arr[101][101];

struct DragonCurve {
  int x, y, d, g;
  vector<int> dir;
};
vector<DragonCurve> vec;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, d, g;
    cin >> x >> y >> d >> g;
    vec.push_back({x, y, d, g});
  }

  for (int i = 0; i < vec.size(); i++) {
    vec[i].dir.push_back(vec[i].d);
    for (int j = 0; j < vec[i].g; j++) {
      vector<int> tmp = vec[i].dir;
      for (auto it = tmp.rbegin(); it < tmp.rend(); it++) {
        vec[i].dir.push_back(((*it) + 1) % 4);
      }
    }

    int _x = vec[i].x;
    int _y = vec[i].y;
    arr[_y][_x] = 1;
    for (int j = 0; j < vec[i].dir.size(); j++) {
      if (vec[i].dir[j] == 0) {
        _x++;
      } else if (vec[i].dir[j] == 1) {
        _y--;
      } else if (vec[i].dir[j] == 2) {
        _x--;
      } else if (vec[i].dir[j] == 3) {
        _y++;
      }
      arr[_y][_x] = 1;
    }
  }

  int cnt = 0;
  for (int i = 1; i < 101; i++) {
    for (int j = 1; j < 101; j++) {
      if (arr[i - 1][j] && arr[i - 1][j - 1] && arr[i][j] && arr[i][j - 1]) {
        cnt++;
      }
    }
  }

  cout << cnt;
  return 0;
}