#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> e[1002];

int bfs_total(int n)
{
  int ans = 0;
  bool visit[1002] = {false};

  for (int i = 1; i <= n; i++)
  {
    if (!visit[i])
    {
      ans++;
      queue<int> worklist;

      int start = i;
      visit[start] = true;
      worklist.push(start);

      while (!worklist.empty())
      {
        int current = worklist.front();
        worklist.pop();
        for (int j = 0; j < e[current].size(); j++)
        {
          int next = e[current][j];
          if (!visit[next])
          {
            visit[next] = true;
            worklist.push(next);
          }
        }
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

  int t;
  cin >> t;
  for (int test = 0; test < t; test++)
  {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      int a;
      cin >> a;
      e[i].push_back(a);
    }
    cout << bfs_total(n) << endl;
    for (int i = 1; i <= n; i++)
      e[i].clear();
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기