#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// O(n)이라 함은,
// 한 번 방문한 노드는 다시 방문하지 않는 것을 목표로 한다

// https://wooono.tistory.com/409 DFS 깔끔 풀이

int choice[100010];
bool visit[100010]; // 한 번의 bfs/dfs에서 방문함, cycle 판단을 위함
bool done[100010];  // 팀 매칭이 됐는지 안 됐는지 여부를 이미 판단함함, bfs/dfs하다가 done을 만나면 다 done임
bool cycle[100010]; // cycle의 멤버인지 여부

void getCycle(int n)
{
  for (int i = 1; i <= n; i++)
  {
    // cout << "start " << i << endl;
    int cur = i;
    while (!done[cur]) // find cycle
    {
      if (visit[cur])
      {
        while (!done[cur])
        {
          done[cur] = true;
          cycle[cur] = true;
          // cout << "done " << cur << endl;
          // cout << "cycle " << cur << endl;
          cur = choice[cur];
        }
      }
      else
      {
        visit[cur] = true;
        cur = choice[cur];
        // cout << "visit " << cur << endl;
      }
    }

    cur = i;
    while (visit[cur] && !done[cur])
    {
      visit[cur] = false;
      done[cur] = true;
      // cout << "done " << cur << endl;
      cur = choice[cur];
    }
  }
}

int countNonCycle(int n)
{
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!cycle[i])
      cnt++;
  return cnt;
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
      int num;
      cin >> num;
      choice[i] = num;
    }

    getCycle(n);

    cout << countNonCycle(n) << endl;

    memset(choice, 0, sizeof(choice));
    memset(visit, false, sizeof(visit));
    memset(done, false, sizeof(done));
    memset(cycle, false, sizeof(cycle));
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기