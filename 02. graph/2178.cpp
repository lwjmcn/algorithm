#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int miro[105][105];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int r, int c) // (1,1로 시작)
{
  for (int i = 0; i < 4; i++)
  {
    int r_ = r + dx[i];
    int c_ = c + dy[i];
    if (r_ >= 1 && r_ <= n && c_ >= 1 && c <= m && miro[r_][c_] > 0)
    {
      if ((r_ == 1 && c_ == 1) || miro[r_][c_] > 1) // visited before
      {
        if (miro[r_][c_] > miro[r][c] + 1)
        {
          miro[r_][c_] = miro[r][c] + 1;
          dfs(r_, c_);
        }
      }
      else
      {
        miro[r_][c_] = miro[r][c] + 1;
        dfs(r_, c_);
      }
    }
  }
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++)
      miro[i][j] = s[j - 1] - '0';
  }

  dfs(1, 1);

  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 1; j <= m; j++)
  //     cout << miro[i][j] << " ";
  //   cout << endl;
  // }
  cout << miro[n][m];

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기