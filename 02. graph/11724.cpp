#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> e[1002];
int visit[1002];

void dfs(int start)
{
  visit[start] = true;
  // cout << start << " ";

  for (int i = 0; i < e[start].size(); i++)
  {
    int next = e[start][i];
    if (!visit[next])
      dfs(next);
  }
}

int notVisited(int n)
{
  for (int i = 1; i <= n; i++)
  {
    if (!visit[i])
      return i;
  }
  return 0;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  int next = 1;
  int answer = 0;

  while (next != 0)
  {
    dfs(next);
    answer++;
    next = notVisited(n);
  }

  cout << answer;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기