#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int arr[101][101];
vector<pair<int, char>> move_cmd;
vector<pair<int, int>> snake;

int move_dir = 0;
int dir_change_idx = 0;
vector<pair<int, int>> dxy = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool move_snake() {
  bool b_meet_apple = false;
  vector<pair<int, int>> tmp;

  int new_y = snake[0].first + dxy[move_dir].first;
  int new_x = snake[0].second + dxy[move_dir].second;

  // 벽이나 뱀을 마주친 경우
  if (new_x >= n || new_x < 0 || new_y >= n || new_y < 0 ||
      arr[new_y][new_x] == 2) {
    return false;
  } else if (arr[new_y][new_x] == 1) {
    b_meet_apple = true;
  }

  tmp.push_back({new_y, new_x});
  if (b_meet_apple) {
    for (int i = 0; i < snake.size(); i++) {
      tmp.push_back(snake[i]);
    }
  } else {
    for (int i = 0; i < snake.size() - 1; i++) {
      tmp.push_back(snake[i]);
    }
    arr[snake[snake.size() - 1].first][snake[snake.size() - 1].second] = 0;
  }

  snake = tmp;
  for (int i = 0; i < snake.size(); i++) {
    arr[snake[i].first][snake[i].second] = 2;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int y, x;
    cin >> y >> x;
    arr[y - 1][x - 1] = 1;
  }
  arr[0][0] = 2;
  snake.push_back({0, 0});

  cin >> l;
  for (int i = 0; i < l; i++) {
    int x;
    char c;
    cin >> x >> c;
    move_cmd.push_back({x, c});
  }
  int turn_idx = 0;
  while (true) {
    if (move_cmd[dir_change_idx].first == turn_idx) {
      if (move_cmd[dir_change_idx].second == 'L') {
        move_dir = (move_dir + 3) % 4;
      } else if (move_cmd[dir_change_idx].second == 'D') {
        move_dir = (move_dir + 1) % 4;
      }
      dir_change_idx++;
    }
    if (move_snake() == false) {
      cout << turn_idx + 1;
      break;
    }

    turn_idx++;
  }

  return 0;
}