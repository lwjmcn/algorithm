#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int ans = 0;
vector<pair<int, int>> adj_weight[10005]; // vertex-> adjacent vertex, edge weight
map<int, int> dest_dist;                  // src -> dest vertex, dist
bool visit[10005];
// int dist[10005][10005] = {0};
// // i에서 j까지의 거리(weight의 합)를 저장한다...
// -> 128MB는 3000만개까지 가능... 얘는 1억임 ㅠ

// 풀이
// 증명에 의해 트리의 지름은
// dfs/bfs 2번을 통해 찾을 수 있다 (임의의 노드에서 가장 먼 노드 -> 해당노드에서 가장 먼 노드)

pair<int, int> bfs(int src)
{
  for (int k = 1; k <= n; k++)
    visit[k] = false;
  dest_dist.clear();

  // cout << "src " << src << "\n";
  pair<int, int> farthest; // vertex, dist

  queue<int> worklist; // to be the "src" next
  worklist.push(src);

  while (!worklist.empty())
  {
    int cur = worklist.front();
    worklist.pop();
    visit[cur] = true;

    for (int i = 0; i < adj_weight[cur].size(); i++)
    {
      int next = adj_weight[cur][i].first;
      int weight = adj_weight[cur][i].second;

      if (visit[next])
        continue;

      dest_dist[next] = dest_dist[cur] + weight;

      if (dest_dist[next] > farthest.second)
      {
        farthest.first = next;
        farthest.second = dest_dist[next];
      }

      worklist.push(next);
    }
  }
  return farthest;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  // int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++)
  {
    int parent, child, weight;
    cin >> parent >> child >> weight;
    adj_weight[parent].push_back(pair<int, int>(child, weight));
    adj_weight[child].push_back(pair<int, int>(parent, weight));
  }

  cout << bfs(bfs(1).first).second;
  // cout << ans;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기