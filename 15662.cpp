#include <bits/stdc++.h>
using namespace std;

int t, k;

vector<deque<int>> gear;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    deque<int> dq;
    for (int j = 0; j < s.size(); j++) {
      dq.push_back(s[j] - '0');
    }
    gear.push_back(dq);
  }

  cin >> k;
  for (int i = 0; i < k; i++) {
    int gear_idx, rot;
    cin >> gear_idx >> rot;
    gear_idx--;

    // rotate left gear
    int idx = gear_idx;
    int rot_tmp = -rot;
    while (true) {
      if (idx - 1 < 0 || gear[idx][6] == gear[idx - 1][2]) {
        break;
      } else {
        idx--;
      }
    }

    for (int j = gear_idx; j > idx; j--) {
      if (rot_tmp == 1) {  // rotate clockwise
        gear[j - 1].push_front(gear[j - 1].back());
        gear[j - 1].pop_back();
      } else {  // rotate counter-clockwise
        gear[j - 1].push_back(gear[j - 1].front());
        gear[j - 1].pop_front();
      }
      rot_tmp = -rot_tmp;
    }

    // rotate right gear
    idx = gear_idx;
    rot_tmp = -rot;
    while (true) {
      if (idx + 1 >= t || gear[idx][2] == gear[idx + 1][6]) {
        break;
      } else {
        idx++;
      }
    }

    for (int j = gear_idx; j < idx; j++) {
      if (rot_tmp == 1) {  // rotate clockwise
        gear[j + 1].push_front(gear[j + 1].back());
        gear[j + 1].pop_back();
      } else {  // rotate counter-clockwise
        gear[j + 1].push_back(gear[j + 1].front());
        gear[j + 1].pop_front();
      }
      rot_tmp = -rot_tmp;
    }

    // rotate idx gear itself
    if (rot == 1) {  // rotate clockwise
      gear[gear_idx].push_front(gear[gear_idx].back());
      gear[gear_idx].pop_back();
    } else {  // rotate counter-clockwise
      gear[gear_idx].push_back(gear[gear_idx].front());
      gear[gear_idx].pop_front();
    }
  }

  int cnt = 0;
  for (auto x : gear) {
    if (x[0] == 1) {
      cnt++;
    }
  }
  cout << cnt;

  return 0;
}