#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// endl 함수는 개행 글자를 찍고 출력 버퍼까지 flush 해주기 때문에
// 버퍼 flush가 필요없다면 "\n"을 사용하자

vector<int> tree[100010];
bool visit[100010];
int parent[100010];

// 각각 구하지 말고, dfs를 한 번만 해서 parent 배열에 저장하기
void findPrevfromRoot(int prev, int cur)
{
  // cout << "visit " << cur << endl;
  visit[cur] = true;
  // cout << "parent of " << cur << " is " << prev << endl;
  parent[cur] = prev;
  for (int i = 0; i < tree[cur].size(); i++)
  {
    int next = tree[cur][i];
    // cout << "cur" << cur << " i" << i << " tree[cur][i]" << tree[cur][i] << endl;
    if (!visit[next])
    {
      // cout << "prev" << cur << " next" << next << endl;
      findPrevfromRoot(cur, next);
    }
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
  for (int i = 1; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  findPrevfromRoot(-1, 1);

  for (int i = 2; i <= n; i++)
    cout << parent[i] << "\n";

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기