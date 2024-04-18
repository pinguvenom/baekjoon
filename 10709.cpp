#include <bits/stdc++.h>
using namespace std;

char arr[100][100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w;
  cin >> h >> w;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    bool b_meet_cloud = false;
    int cloud_cnt = 0;
    for (int j = 0; j < w; j++) {
      cloud_cnt++;
      if (arr[i][j] == 'c') {
        b_meet_cloud = true;
        cloud_cnt = 0;
      }
      if (b_meet_cloud == false) {
        cout << "-1 ";
      } else {
        cout << cloud_cnt << " ";
      }
    }
    cout << '\n';
  }

  return 0;
}