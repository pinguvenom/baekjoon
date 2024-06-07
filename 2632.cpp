#include <bits/stdc++.h>
using namespace std;

int pizza_size;
int m, n;
int a[1001], b[1001];
int psum_a[2002], psum_b[2002];
map<int, int> a_pizza, b_pizza;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> pizza_size;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    psum_a[i] = psum_a[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    psum_b[i] = psum_b[i - 1] + b[i];
  }

  for (int i = m + 1; i <= 2 * m; i++) {
    psum_a[i] = psum_a[i - 1] + a[i - m];
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    psum_b[i] = psum_b[i - 1] + b[i - n];
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < m; j++) {
      int sum_a = psum_a[i + j] - psum_a[j];
      a_pizza[sum_a]++;

      if (i == m) {  // 모든 원소들을 다 더하는 경우는 한번만 실행
        break;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      int sum_b = psum_b[i + j] - psum_b[j];
      b_pizza[sum_b]++;

      if (i == n) {  // 모든 원소들을 다 더하는 경우는 한번만 실행
        break;
      }
    }
  }

  int total_case = a_pizza[pizza_size] + b_pizza[pizza_size];
  for (int i = 1; i < pizza_size; i++) {
    total_case += (a_pizza[i] * b_pizza[pizza_size - i]);
  }
  cout << total_case;
  return 0;
}