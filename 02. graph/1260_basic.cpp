#include <iostream>
#include <vector>
#include <queue>
#include <string.h> // memset
#include <algorithm>
using namespace std;

vector<int> e[10002];
bool visit[1002];

void dfs(int start)
{
  visit[start] = true;
  cout << start << " ";

  for (int i = 0; i < e[start].size(); i++)
  {
    int next = e[start][i];
    if (!visit[next])
      dfs(next);
  }
}

void bfs(int start)
{
  queue<int> worklist;

  worklist.push(start);
  visit[start] = true;
  cout << start << " ";

  while (!worklist.empty())
  {
    int current = worklist.front();
    worklist.pop();
    for (int i = 0; i < e[current].size(); i++)
    {
      int next = e[current][i];
      if (!visit[next])
      {
        visit[next] = true;
        cout << next << " ";
        worklist.push(e[current][i]);
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

  int n, m, v;
  cin >> n >> m >> v;
  for (int i = 1; i <= m; i++)
  {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b); // 양방향
    e[b].push_back(a); // 양방향
  }
  for (int i = 1; i <= n; i++)
  {
    sort(e[i].begin(), e[i].end());
  }

  dfs(v);
  cout << endl;
  memset(visit, false, sizeof(visit));
  bfs(v);

  // 전체 그래프를 도는 게 아니라는 걸 명심!!
  // Connected component만 돈다

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기