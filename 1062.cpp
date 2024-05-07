#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[50];

int alp[26];
int _max;

// 26Ck의 조합 찾기
void combi(int start, vector<int>& b) {
  if (b.size() == k - 5) {
    int alp = 0;
    alp |= (1 << 0);   // a
    alp |= (1 << 2);   // c
    alp |= (1 << 8);   // i
    alp |= (1 << 13);  // n
    alp |= (1 << 19);  // t
    for (int i = 0; i < k - 5; i++) {
      alp |= (1 << b[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if ((alp | arr[i]) == alp) {
        cnt++;
      }
    }
    _max = max({_max, cnt});
    return;
  }
  for (int i = start + 1; i < 26; i++) {
    b.push_back(i);
    combi(i, b);
    b.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 4; j < s.size() - 4; j++) {
      arr[i] |= (1 << (s[j] - 'a'));
    }
  }

  if (k < 5) {
    cout << 0;
    return 0;
  }

  vector<int> b;
  combi(-1, b);

  cout << _max;
  return 0;
}