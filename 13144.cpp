#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int visited[100001];
int pt1, pt2;
long long ret;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  while (pt2 < n) {
    if (!visited[arr[pt2]]) {
      visited[arr[pt2]]++;
      pt2++;
    } else {
      ret += (pt2 - pt1);
      visited[arr[pt1]]--;
      pt1++;
    }
  }
  ret += (long long)(pt2 - pt1) * (pt2 - pt1 + 1) / 2;
  cout << ret;
  return 0;
}