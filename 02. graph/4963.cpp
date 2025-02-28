#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int w, h;
int map[52][52]; // 1 is land
bool visit[52][52];
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1}; // 좌상부터 시계방향으로
int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

pair<int, int> getStart()
{
  for (int r = 1; r <= h; r++)
    for (int c = 1; c <= w; c++)
      if (!visit[r][c] && map[r][c] == 1)
        return pair<int, int>(r, c);
  return pair<int, int>(-1, -1);
}
void dfs(pair<int, int> current)
{
  int r = current.first;
  int c = current.second;
  visit[r][c] = true;
  // cout << r << " " << c << endl;
  for (int i = 0; i < 8; i++)
  {
    if (((r + dx[i]) >= 1) && ((r + dx[i]) <= h) && ((c + dy[i]) >= 1) && ((c + dy[i]) <= w))
    {
      // cout << "iter " << r + dx[i] << " " << c + dy[i] << endl;
      if (!visit[r + dx[i]][c + dy[i]] && map[r + dx[i]][c + dy[i]] == 1)
        dfs(pair<int, int>(r + dx[i], c + dy[i]));
    }
  }
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  while (1)
  {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    for (int r = 1; r <= h; r++)
    {
      for (int c = 1; c <= w; c++)
      {
        int p;
        cin >> p;
        map[r][c] = p;
      }
    }

    int ans = 0;
    pair<int, int> start = getStart();
    while (start.first != -1)
    {
      // cout << "Start" << endl;
      dfs(start);
      start = getStart();
      ans++;
    }

    cout << ans << endl;

    for (int a = 1; a <= h; a++)
    {
      for (int b = 1; b <= w; b++)
      {
        map[a][b] = 0;
        visit[a][b] = false;
      }
    }
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기