#include <bits/stdc++.h>
using namespace std;

int score_map[33];
int moving_map[33][5];
int dice[10];
int horse_loc[4];
int max_score = 0;

void initialize_map() {
  score_map[0] = 0, score_map[1] = 2, score_map[2] = 4, score_map[3] = 6,
  score_map[4] = 8, score_map[5] = 10, score_map[6] = 12, score_map[7] = 14,
  score_map[8] = 16, score_map[9] = 18, score_map[10] = 20, score_map[11] = 22,
  score_map[12] = 24, score_map[13] = 26, score_map[14] = 28,
  score_map[15] = 30, score_map[16] = 32, score_map[17] = 34,
  score_map[18] = 36, score_map[19] = 38, score_map[20] = 40,
  score_map[21] = 13, score_map[22] = 16, score_map[23] = 19,
  score_map[24] = 22, score_map[25] = 24, score_map[26] = 28,
  score_map[27] = 27, score_map[28] = 26, score_map[29] = 25,
  score_map[30] = 30, score_map[31] = 35, score_map[32] = 0;
  moving_map[0][0] = 1, moving_map[0][1] = 2, moving_map[0][2] = 3,
  moving_map[0][3] = 4, moving_map[0][4] = 5;
  moving_map[1][0] = 2, moving_map[1][1] = 3, moving_map[1][2] = 4,
  moving_map[1][3] = 5, moving_map[1][4] = 6;
  moving_map[2][0] = 3, moving_map[2][1] = 4, moving_map[2][2] = 5,
  moving_map[2][3] = 6, moving_map[2][4] = 7;
  moving_map[3][0] = 4, moving_map[3][1] = 5, moving_map[3][2] = 6,
  moving_map[3][3] = 7, moving_map[3][4] = 8;
  moving_map[4][0] = 5, moving_map[4][1] = 6, moving_map[4][2] = 7,
  moving_map[4][3] = 8, moving_map[4][4] = 9;
  moving_map[5][0] = 21, moving_map[5][1] = 22, moving_map[5][2] = 23,
  moving_map[5][3] = 29, moving_map[5][4] = 30;
  moving_map[6][0] = 7, moving_map[6][1] = 8, moving_map[6][2] = 9,
  moving_map[6][3] = 10, moving_map[6][4] = 11;
  moving_map[7][0] = 8, moving_map[7][1] = 9, moving_map[7][2] = 10,
  moving_map[7][3] = 11, moving_map[7][4] = 12;
  moving_map[8][0] = 9, moving_map[8][1] = 10, moving_map[8][2] = 11,
  moving_map[8][3] = 12, moving_map[8][4] = 13;
  moving_map[9][0] = 10, moving_map[9][1] = 11, moving_map[9][2] = 12,
  moving_map[9][3] = 13, moving_map[9][4] = 14;
  moving_map[10][0] = 24, moving_map[10][1] = 25, moving_map[10][2] = 29,
  moving_map[10][3] = 30, moving_map[10][4] = 31;
  moving_map[11][0] = 12, moving_map[11][1] = 13, moving_map[11][2] = 14,
  moving_map[11][3] = 15, moving_map[11][4] = 16;
  moving_map[12][0] = 13, moving_map[12][1] = 14, moving_map[12][2] = 15,
  moving_map[12][3] = 16, moving_map[12][4] = 17;
  moving_map[13][0] = 14, moving_map[13][1] = 15, moving_map[13][2] = 16,
  moving_map[13][3] = 17, moving_map[13][4] = 18;
  moving_map[14][0] = 15, moving_map[14][1] = 16, moving_map[14][2] = 17,
  moving_map[14][3] = 18, moving_map[14][4] = 19;
  moving_map[15][0] = 26, moving_map[15][1] = 27, moving_map[15][2] = 28,
  moving_map[15][3] = 29, moving_map[15][4] = 30;
  moving_map[16][0] = 17, moving_map[16][1] = 18, moving_map[16][2] = 19,
  moving_map[16][3] = 20, moving_map[16][4] = 32;
  moving_map[17][0] = 18, moving_map[17][1] = 19, moving_map[17][2] = 20,
  moving_map[17][3] = 32, moving_map[17][4] = 32;
  moving_map[18][0] = 19, moving_map[18][1] = 20, moving_map[18][2] = 32,
  moving_map[18][3] = 32, moving_map[18][4] = 32;
  moving_map[19][0] = 20, moving_map[19][1] = 32, moving_map[19][2] = 32,
  moving_map[19][3] = 32, moving_map[19][4] = 32;
  moving_map[20][0] = 32, moving_map[20][1] = 32, moving_map[20][2] = 32,
  moving_map[20][3] = 32, moving_map[20][4] = 32;
  moving_map[21][0] = 22, moving_map[21][1] = 23, moving_map[21][2] = 29,
  moving_map[21][3] = 30, moving_map[21][4] = 31;
  moving_map[22][0] = 23, moving_map[22][1] = 29, moving_map[22][2] = 30,
  moving_map[22][3] = 31, moving_map[22][4] = 20;
  moving_map[23][0] = 29, moving_map[23][1] = 30, moving_map[23][2] = 31,
  moving_map[23][3] = 20, moving_map[23][4] = 32;
  moving_map[24][0] = 25, moving_map[24][1] = 29, moving_map[24][2] = 30,
  moving_map[24][3] = 31, moving_map[24][4] = 20;
  moving_map[25][0] = 29, moving_map[25][1] = 30, moving_map[25][2] = 31,
  moving_map[25][3] = 20, moving_map[25][4] = 32;
  moving_map[26][0] = 27, moving_map[26][1] = 28, moving_map[26][2] = 29,
  moving_map[26][3] = 30, moving_map[26][4] = 31;
  moving_map[27][0] = 28, moving_map[27][1] = 29, moving_map[27][2] = 30,
  moving_map[27][3] = 31, moving_map[27][4] = 20;
  moving_map[28][0] = 29, moving_map[28][1] = 30, moving_map[28][2] = 31,
  moving_map[28][3] = 20, moving_map[28][4] = 32;
  moving_map[29][0] = 30, moving_map[29][1] = 31, moving_map[29][2] = 20,
  moving_map[29][3] = 32, moving_map[29][4] = 32;
  moving_map[30][0] = 31, moving_map[30][1] = 20, moving_map[30][2] = 32,
  moving_map[30][3] = 32, moving_map[30][4] = 32;
  moving_map[31][0] = 20, moving_map[31][1] = 32, moving_map[31][2] = 32,
  moving_map[31][3] = 32, moving_map[31][4] = 32;
  moving_map[32][0] = 32, moving_map[32][1] = 32, moving_map[32][2] = 32,
  moving_map[32][3] = 32, moving_map[32][4] = 32;
}

void solve(vector<int> vec) {
  int score = 0;
  memset(horse_loc, 0, sizeof(horse_loc));
  for (int i = 0; i < vec.size(); i++) {
    int moving_horse = vec[i];

    int start_idx = horse_loc[moving_horse];
    if (start_idx == 32) {
      continue;
    }

    int end_idx = moving_map[start_idx][dice[i] - 1];
    // 도착하려는 자리에 말이 있는 경우는 불가능한 case이므로 바로 종료
    if (end_idx != 32 && (horse_loc[0] == end_idx || horse_loc[1] == end_idx ||
                          horse_loc[2] == end_idx || horse_loc[3] == end_idx)) {
      break;
    }

    horse_loc[moving_horse] = end_idx;
    score += score_map[end_idx];
  }
  if (score > max_score) {
    max_score = score;
  }
}

void search(vector<int> vec) {
  if (vec.size() == 10) {
    solve(vec);
    return;
  }

  for (int i = 0; i < 4; i++) {
    vec.push_back(i);
    search(vec);
    vec.pop_back();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  initialize_map();
  for (int i = 0; i < 10; i++) {
    cin >> dice[i];
  }

  vector<int> horse_vec;
  search(horse_vec);

  cout << max_score;

  return 0;
}