#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

// int dx[4] = {-1,1,0,0};
// int dy[4] = {0,0,-1,1};
// 의 형태로 풀 수 있다

int map[30][30];
bool visit[30][30];
int danji_num[320]; // 최대 25*25/2개

pair<int, int> getStart(int n)
{
  for (int r = 1; r <= n; r++)
    for (int c = 1; c <= n; c++)
      if (!visit[r][c] && map[r][c] == 1)
        return pair<int, int>(r, c);
  return pair<int, int>(-1, -1);
}

void dfs(pair<int, int> cur, int danji, int n)
{
  if (visit[cur.first][cur.second])
    return;
  visit[cur.first][cur.second] = true;

  if (map[cur.first][cur.second] == 1)
  {
    danji_num[danji]++;
    // cout << "[" << cur.first << "][" << cur.second << "]\n";

    if (cur.first > 1)
      dfs(pair<int, int>(cur.first - 1, cur.second), danji, n);
    if (cur.first < n)
      dfs(pair<int, int>(cur.first + 1, cur.second), danji, n);
    if (cur.second > 1)
      dfs(pair<int, int>(cur.first, cur.second - 1), danji, n);
    if (cur.second < n)
      dfs(pair<int, int>(cur.first, cur.second + 1), danji, n);
  }
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;
  for (int r = 1; r <= n; r++)
  {
    char k[30];
    cin >> k;
    for (int c = 1; c <= n; c++)
      map[r][c] = k[c - 1] - '0';
  }

  int danji = 0;
  while (getStart(n).first != -1)
  {
    // cout << "start " << getStart(n).first << getStart(n).second << endl;
    // cout << "danji " << danji;
    dfs(getStart(n), danji++, n);
  }

  cout << danji << endl;
  sort(danji_num, danji_num + danji);
  for (int i = 0; i < danji; i++)
  {
    cout << danji_num[i] << endl;
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기