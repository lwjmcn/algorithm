#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> tree[100010]; // tree[v] = {adjv, dist}
pair<int, int> maxDist;              // {adjv, dist}
int visit[100010];

void dfs(int start, int cur, int distFromStart)
{
  visit[cur] = true;

  // cout << "dfs start" << start << " cur" << cur << " distFromStart" << distFromStart << "\n";
  for (int i = 0; i < tree[cur].size(); i++)
  {
    int next = tree[cur][i].first;
    int distToNext = tree[cur][i].second;

    if (visit[next])
      continue;
    int newDist = distFromStart + distToNext;

    if (newDist > maxDist.second)
      maxDist = {next, newDist};

    dfs(start, next, distFromStart + distToNext);
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
  for (int i = 0; i < n; i++)
  {
    int v, adjv, dist;
    cin >> v;
    while (1)
    {
      cin >> adjv;
      if (adjv == -1)
        break;
      cin >> dist;
      tree[v].push_back({adjv, dist}); // 입력이 양방향으로 주어짐
    }
  }

  maxDist = {0, 0};
  dfs(1, 1, 0);

  int next = maxDist.first;
  maxDist = {0, 0};
  for (int i = 0; i <= n; i++)
  {
    visit[i] = false;
  }

  dfs(next, next, 0);

  cout << maxDist.second;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기