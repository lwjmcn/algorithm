#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int tomato[1005][1005];

int bfs(int n, int m)
{
  int ans = 0;
  queue<pair<int, int>> worklist;

  // 익은 토마토를 큐에 추가해두고 시작... 아 ...
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (tomato[i][j] == 1)
        worklist.push(pair<int, int>(i, j));

  while (!worklist.empty())
  {
    int r = worklist.front().first;
    int c = worklist.front().second;
    worklist.pop();
    // cout << "Visit " << r << " " << c << endl;

    for (int i = 0; i < 4; i++)
    {
      int r_ = r + dx[i];
      int c_ = c + dy[i];
      if (r_ >= 1 && r_ <= n && c_ >= 1 && c_ <= m && tomato[r_][c_] == 0)
      {
        ans = max(ans, tomato[r][c]);
        tomato[r_][c_] = tomato[r][c] + 1;
        worklist.push(pair<int, int>(r_, c_));
        // cout << "Add " << r_ << " " << c_ << endl;
      }
    }
  }
  return ans;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      int c;
      cin >> c;
      tomato[i][j] = c;
    }
  }

  int ans = bfs(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (tomato[i][j] == 0)
      {
        cout << -1;
        return 0;
      }
  cout << ans;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기