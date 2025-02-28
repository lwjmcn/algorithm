#include <iostream>
#include <algorithm>
using namespace std;

long long dp[100][2];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  // 1로 시작
  // 1나오면 다음은 무조건 0

  dp[1][0] = 0;
  dp[1][1] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][0] = dp[i-1][0]+dp[i-1][1]; // dp[i-2][0]
      dp[i][1] = dp[i-1][0];
      // 피보나치로 풀 수 있다
     }
  }

  cout << dp[n][0] + dp[n][1];

  return 0;
}