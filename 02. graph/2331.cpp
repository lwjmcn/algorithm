#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[240000];

int getNext(int current, int p)
{
  int next = 0;
  int leftover = current;

  while (leftover > 0)
  {
    int digit = leftover % 10;

    int mul = 1;
    for (int i = 0; i < p; i++)
      mul *= digit;
    next += mul;

    leftover /= 10;
  }
  return next;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int a, p;
  cin >> a >> p;

  int current = a;
  while (!d[current])
  {
    int next = getNext(current, p);
    d[current] = (next);
    current = next;
  }

  int ans = 0;
  int test = a;
  while (test != current)
  {
    // cout << d[test][0] << endl;
    ans++;
    test = d[test];
  }
  cout << ans;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기