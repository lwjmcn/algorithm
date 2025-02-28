#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[100010];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;

  for(int i = 1; i <= n; i++) {
    if (floor(sqrt(i))==sqrt(i))
      dp[i] = 1;
    else {
      dp[i] = dp[1] + dp[i-1];
      for(int j = 1; j <= i/2; j++)
        dp[i] = min(dp[i], dp[j] + dp[i-j]);
    }
  }
  cout << dp[n];

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}