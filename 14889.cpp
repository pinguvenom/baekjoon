#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[20][20];
int min_diff = INT_MAX;

void calc_diff(vector<int> t1, vector<int> t2) {
  int team1_score = 0;
  int team2_score = 0;
  for (int i = 0; i < t1.size(); i++) {
    for (int j = i + 1; j < t1.size(); j++) {
      team1_score += arr[t1[i]][t1[j]];
      team1_score += arr[t1[j]][t1[i]];
    }
  }

  for (int i = 0; i < t2.size(); i++) {
    for (int j = i + 1; j < t2.size(); j++) {
      team2_score += arr[t2[i]][t2[j]];
      team2_score += arr[t2[j]][t2[i]];
    }
  }
  min_diff = min({min_diff, abs(team2_score - team1_score)});
  if (min_diff == 0) {
    cout << 0;
    exit(0);
  }
}

void combi(int start, vector<int> b) {
  if (b.size() == k) {
    vector<int> t2;
    for (int i = 0; i < n; i++) {
      if (find(b.begin(), b.end(), i) == b.end()) {
        t2.push_back(i);
      }
    }
    calc_diff(b, t2);
    return;
  }

  for (int i = start + 1; i < n; i++) {
    b.push_back(i);
    combi(i, b);
    b.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  k = n / 2;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  vector<int> b;
  combi(-1, b);

  cout << min_diff;
  return 0;
}