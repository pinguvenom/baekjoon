#include <bits/stdc++.h>
using namespace std;

char* compare(char* a, char* b) {
  for (int i = 0; i < strlen(a); i++) {
    if (a[i] < b[i]) {
      return b;
    } else if (a[i] > b[i]) {
      return a;
    }
  }
  return a;
}

void subtract(char* a, char* b) {
  for (int i = 0; i < strlen(b); i++) {
    a[i] = a[i] - b[i] + '0';
  }
  // 음수에 대해서는 carry 연산을 수행
  for (int i = strlen(b) - 1; i >= 0; i--) {
    if (a[i] < '0') {
      a[i] += 10;
      a[i - 1]--;
    }
  }
  return;
}

void dividesubtract(char* a, char* b, char* q, int idx) {
  q[idx] = '0';
  while (a[idx - 1] > '0' || compare(a + idx, b) == a + idx) {
    subtract(a + idx, b);
    ++q[idx];
  }
  return;
}

void divide(char* a, char* b, char* q) {
  int idx = 0;
  int digit = strlen(a) - strlen(b);

  while (idx <= digit) {
    dividesubtract(a, b, q, idx++);
  }
  q[idx] = '\0';
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char a[1001];
  char b[1001];
  char q[1001];

  cin >> a >> b;
  divide(a, b, q);

  // 몫이 0인 경우에 대한 처리
  if (q[0] == '\0') {
    q[0] = '0';
    q[1] = '\0';
  }

  // 문자열 처리
  int ai = 0, qi = 0;
  while (a[ai] == '0') {
    ai++;
  }
  if (a[ai] == '\0') {
    ai--;
  }
  while (q[qi] == '0') {
    qi++;
  }
  if (q[qi] == '\0') {
    qi--;
  }

  cout << q + qi << '\n';
  cout << a + ai;

  return 0;
}