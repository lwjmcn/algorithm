#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

vector<int> e[20001];      // edge
int coloring[20001] = {0}; // 0 is not visited, 1 is red, -1 is blue

bool isBipartite(int start)
{
  int currentColor = 1;

  // bfs
  queue<int> worklist;

  worklist.push(start);
  coloring[start] = currentColor;
  // cout << start << " " << currentColor << endl;

  while (!worklist.empty())
  {
    int current = worklist.front();
    worklist.pop();
    currentColor = coloring[current];

    for (int i = 0; i < e[current].size(); i++)
    {
      int next = e[current][i];
      if (coloring[next] == currentColor)
      {
        return false;
      }
      if (coloring[next] == 0)
      {
        coloring[next] = -currentColor;
        worklist.push(next);
        // cout << next << " " << -currentColor << endl;
      }
    }
  }
  return true;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int k;
  cin >> k;
  for (int test = 0; test < k; test++)
  {
    bool ans;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
      if (coloring[i] == 0)
        ans = isBipartite(i);
      if (!ans)
        break;
    }

    if (ans)
      cout << "YES";
    else
      cout << "NO";

    cout << endl;
    for (int i = 1; i <= n; i++)
      coloring[i] = 0;
    for (int i = 1; i <= n; i++)
      e[i].clear();
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기