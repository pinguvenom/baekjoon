#include <bits/stdc++.h>
using namespace std;
int t1_score[2880];
int t2_score[2880];

int cvt_time(string s) {
  int min = atoi(s.substr(0, 2).c_str());
  int sec = atoi(s.substr(3).c_str());
  return min * 60 + sec;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  while (n--) {
    int team, time;
    string s_time;
    cin >> team >> s_time;
    time = cvt_time(s_time);

    if (team == 1) {
      for (int i = time; i < 2880; i++) {
        t1_score[i]++;
      }
    } else if (team == 2) {
      for (int i = time; i < 2880; i++) {
        t2_score[i]++;
      }
    }
  }

  int t1_wintime = 0, t2_wintime = 0;
  for (int i = 0; i < 2880; i++) {
    if (t1_score[i] > t2_score[i]) {
      t1_wintime++;
    } else if (t1_score[i] < t2_score[i]) {
      t2_wintime++;
    }
  }

  printf("%02d:%02d\n", t1_wintime / 60, t1_wintime % 60);
  printf("%02d:%02d", t2_wintime / 60, t2_wintime % 60);

  return 0;
}