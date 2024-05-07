#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  struct tm *t;
  time_t timer;

  timer = time(NULL);
  t = localtime(&timer);

  std::printf("%d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

  return 0;
}