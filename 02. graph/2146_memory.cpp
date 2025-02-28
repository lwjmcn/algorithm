#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int map[105][105];
bool visit[105][105];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

// land 2,3,4,...으로 표시
// for each land
// bfs를 했을 때 가장 빨리 도착하는 섬으로
int markLand()
{
  int landname = 1;
  queue<pair<int, int>> worklist;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (map[i][j] == 1)
      {
        // start bfs
        landname++;
        worklist.push(pair<int, int>(i, j));
        map[i][j] = landname;

        while (!worklist.empty())
        {
          int r = worklist.front().first;
          int c = worklist.front().second;
          worklist.pop();

          for (int k = 0; k < 4; k++)
          {
            int ix = r + dx[k];
            int jy = c + dy[k];
            if (ix < 1 || jy < 1 || ix > n || jy > n)
              continue;
            if (map[ix][jy] == 1) // 여기서 무한으로 안 들어가지!!!!!!!!!!!!
            {                     // 섬
              worklist.push(pair<int, int>(ix, jy));
              map[ix][jy] = landname; // 여기서 바꿔줘야
            }
          }
        }
      }
    }
  }
  return landname; // land수+2
}

int buildNewLand(int landname)
{
  queue<pair<int, int>> worklist;

  // landname 섬을 queue에 모두 push
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (map[i][j] == landname)
      {
        visit[i][j] = true;
        worklist.push(pair<int, int>(i, j));
      }
    }
  }

  // 해안선 worklist bfs (한 칸씩 넓혀감)
  int dist = -1;
  while (!worklist.empty())
  {
    dist++;
    int level_cnt = worklist.size();
    for (int level = 0; level < level_cnt; level++)
    {
      int i = worklist.front().first;
      int j = worklist.front().second;
      worklist.pop();

      for (int k = 0; k < 4; k++)
      {
        int ix = i + dx[k];
        int jy = j + dy[k];
        if (ix < 1 || jy < 1 || ix > n || jy > n || visit[ix][jy])
          continue;

        // 간척사업, 해안선을 하나씩 늘려가면서 거리를 구하자
        if (map[ix][jy] == 0) // 바다
        {
          worklist.push(pair<int, int>(ix, jy));
          visit[ix][jy] = true;
        }
        else // 다른 섬 도착
          return dist;
      }
    }
  }
  return -1;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int c;
      cin >> c;
      map[i][j] = c;
    }
  }

  int lastLand = markLand();
  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 1; j <= n; j++)
  //   {
  //     cout << map[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  int ans = 200;
  for (int land = 2; land < lastLand; land++) // 마지막 섬은 체크 안 해도 됨
  {
    int tmp = buildNewLand(land);
    if (tmp != -1)
      ans = min(ans, tmp);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        visit[i][j] = false;
  }

  cout << ans;
  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기