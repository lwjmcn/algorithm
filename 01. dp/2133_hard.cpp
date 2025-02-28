#include <iostream>
#include <algorithm>
using namespace std;

int dp[31]; 

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;

  // 점화식
  // dp[i] = dp[i-2]*dp[2] + dp[i-4]*2 + dp[i-6]*2 + ... + dp[0]*2
  dp[0] = 1; // 특이 케이스가 2개씩 생김
  dp[2] = 3;
  for(int i = 2; i <= n; i+=2) { // 홀수는 0
    dp[i] = dp[i-2] * dp[2];
    for (int j = i-4; j >= 0; j--) {
      dp[i] += dp[j] * 2;
    }
  }

  cout << dp[n];

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}