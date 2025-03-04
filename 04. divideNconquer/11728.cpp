#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[1000005];
int b[1000005];
int ab[2000005];

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
      ab[ai + bi] = b[bi++];
    }
    while (bi >= m)
    {
      if (ai >= n)
        return;
      ab[ai + bi] = a[ai++];
    }

    if (a[ai] < b[bi])
      ab[ai + bi] = a[ai++];
    else
      ab[ai + bi] = b[bi++];
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  cin >> n >> m;
  int k;
  for (int i = 0; i < n; i++)
  {
    cin >> k;
    a[i] = k;
  }
  for (int i = 0; i < m; i++)
  {
    cin >> k;
    b[i] = k;
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