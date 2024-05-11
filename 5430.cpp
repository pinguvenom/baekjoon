#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    string p, arr_str;
    int n;
    deque<int> arr;
    cin >> p >> n >> arr_str;

    // 문자열 입력받기
    int x = 0;
    for (char c : arr_str) {
      if (c == '[' || c == ']') {
        continue;
      }
      if (c >= '0' && c <= '9') {
        x *= 10;
        x += c - '0';
      } else {
        if (x > 0) {
          arr.push_back(x);
        }
        x = 0;
      }
    }
    if (x > 0) {
      arr.push_back(x);
    }

    // 함수 실행
    bool b_error = false, b_reverse = false;
    for (char c : p) {
      if (c == 'R') {
        b_reverse = !b_reverse;
      } else {
        if (arr.empty()) {
          b_error = true;
          break;
        }

        if (b_reverse) {
          arr.pop_back();
        } else {
          arr.pop_front();
        }
      }
    }

    // 결과 출력
    if (b_error) {
      cout << "error\n";
    } else {
      cout << "[";
      if (arr.empty()) {
        cout << "]\n";
        continue;
      }

      if (b_reverse) {
        for (int i = arr.size() - 1; i > 0; i--) {
          cout << arr[i] << ",";
        }
        cout << arr[0];
      } else {
        for (int i = 0; i < arr.size() - 1; i++) {
          cout << arr[i] << ",";
        }
        cout << arr[arr.size() - 1];
      }
      cout << "]\n";
    }
  }
  return 0;
}