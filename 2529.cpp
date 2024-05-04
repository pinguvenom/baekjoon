#include <bits/stdc++.h>
using namespace std;

int n;
long long _min = LONG_LONG_MAX;
long long _max = LONG_LONG_MIN;
vector<char> op;

void combi(int start, vector<int> vec) {
  if (vec.size() == n + 1) {
    do {
      bool b_meet_condition = true;
      for (int i = 0; i < op.size(); i++) {
        if (!b_meet_condition) {
          break;
        }
        if (op[i] == '<' && vec[i] > vec[i + 1]) {
          b_meet_condition = false;
        } else if (op[i] == '>' && vec[i] < vec[i + 1]) {
          b_meet_condition = false;
        }
      }
      if (b_meet_condition) {
        long long num = 0;
        for (int i = 0; i < vec.size(); i++) {
          num *= 10;
          num += vec[i];
        }

        _max = max({_max, num});
        _min = min({_min, num});
      }
    } while (next_permutation(vec.begin(), vec.end()));
    return;
  }

  for (int i = start + 1; i < 10; i++) {
    vec.push_back(i);
    combi(i, vec);
    vec.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    op.push_back(x);
  }

  vector<int> vec;
  combi(-1, vec);

  cout << setfill('0') << setw(n + 1) << _max << '\n';
  cout << setfill('0') << setw(n + 1) << _min;

  return 0;
}