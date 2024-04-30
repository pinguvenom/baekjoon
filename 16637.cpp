#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> num_vec;
vector<char> oper_vec;

int max_val = INT_MIN;

int calc(int a, int b, char op) {
  if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else if (op == '*') {
    return a * b;
  }
}

void go(int idx, int _num) {
  if (idx == num_vec.size() - 1) {
    max_val = max(max_val, _num);
    return;
  }

  go(idx + 1, calc(_num, num_vec[idx + 1], oper_vec[idx]));
  if (idx + 2 <= num_vec.size() - 1) {
    int tmp = calc(num_vec[idx + 1], num_vec[idx + 2], oper_vec[idx + 1]);
    go(idx + 2, calc(_num, tmp, oper_vec[idx]));
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      num_vec.push_back(s[i] - '0');
    } else {
      oper_vec.push_back(s[i]);
    }
  }

  go(0, num_vec[0]);
  cout << max_val;

  return 0;
}