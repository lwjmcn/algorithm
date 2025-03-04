#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a; // 100만 길이의 int 배열은 선언할 수 없다
vector<int> b;
vector<int> ab;

void divideAndConquer()
{
  int ai = 0;
  int bi = 0;

  while (1)
  {
    while (ai >= n)
    {
      if (bi >= m)
        return;
      ab.push_back(b[bi++]);
    }
    while (bi >= m)
    {
      if (ai >= n)
        return;
      ab.push_back(a[ai++]);
    }

    if (a[ai] < b[bi])
      ab.push_back(a[ai++]);
    else
      ab.push_back(b[bi++]);
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  cin >> n >> m;
  int k;
  for (int i = 0; i < n; i++)
  {
    cin >> k;
    a.push_back(k);
  }
  for (int i = 0; i < m; i++)
  {
    cin >> k;
    b.push_back(k);
  }

  divideAndConquer();

  for (int i = 0; i < n + m; i++)
  {
    cout << ab[i] << " ";
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기