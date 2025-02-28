#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  // dp[i] = dp[i-1]+dp[i-2]*2
  dp[1] = 1;
  dp[2] = 1+1+1;
  dp[3] = 1+1+1+1*2;
  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i-1]+dp[i-2]*2) %10007;
  }
  cout << dp[n];

  return 0;
}