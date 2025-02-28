#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010];
int p[1010];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  
  // i들의 합이 n일 때 p[i] 합의 최댓값
  // i들의 합이 (n-1)일 때, 1을 p[1]을 더함
  // i들의 합이 (n-2)일 때, n=2
  // dp[n] = dp[n-1] + p[1] or dp[n-2] + dp[2] or ... dp[n/2] dp[n/2]
  dp[1] = p[1];
  for (int i = 2; i <= n; i++)
  {
    dp[i] = p[i];
    for (int j = 1; j <= i/2; j++)
      dp[i] = max(dp[i], dp[i-j]+dp[j]);
  }

  cout << dp[n];

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}