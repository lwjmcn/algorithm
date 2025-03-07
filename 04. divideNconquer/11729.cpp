#include <iostream>
#include <algorithm>
using namespace std;

// dp로 횟수 구하기 풀었었다...

// DP와 분할정복
// 공통점: 작은 문제 단위로 쪼개면서 해결
// 차이점: 분할정복은 작은 문제끼리 서로 겹치지 않는다 (memoization X)

void hanoi(int n, int src, int mid, int dst)
{
  if (n == 1)
  {
    cout << src << " " << dst << "\n";
    return;
  }
  hanoi(n - 1, src, dst, mid);
  cout << src << " " << dst << "\n";
  hanoi(n - 1, mid, src, dst);
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;

  // 횟수
  // dp[1] = 1;
  // dp[n] = dp[n-1] + 1 + dp[n-1];
  // dp[n] = 2*dp[n-1] + 1;
  //       = 2* (2*dp[n-2]+1) + 1;
  //       = 4*dp[n-2]+3
  //       = 2^n -1
  int cnt = 1;
  for (int i = 0; i < n; i++)
    cnt *= 2;
  cnt -= 1;
  cout << cnt << "\n";

  // 경로
  hanoi(n, 1, 2, 3);

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기