#include <bits/stdc++.h>
using namespace std;

int n;
int _min = INT_MAX;
int _max = INT_MIN;
vector<int> num;
vector<int> operand;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    num.push_back(x);
  }

  for (int i = 0; i < 4; i++) {
    int j;
    cin >> j;
    while (j--) {
      operand.push_back(i);
    }
  }

  do {
    int val = num[0];
    for (int i = 0; i < n - 1; i++) {
      if (operand[i] == 0) {
        val = val + num[i + 1];
      } else if (operand[i] == 1) {
        val = val - num[i + 1];
      } else if (operand[i] == 2) {
        val = val * num[i + 1];
      } else if (operand[i] == 3) {
        val = val / num[i + 1];
      }
    }
    if (val > _max) {
      _max = val;
    }
    if (val < _min) {
      _min = val;
    }
  } while (next_permutation(operand.begin(), operand.end()));

  cout << _max << '\n';
  cout << _min;
  return 0;
}