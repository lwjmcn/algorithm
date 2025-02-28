#include <iostream>
#include <algorithm>
using namespace std;

int dp[20];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  for (int t=0; t< T; t++ ){
    int n;
    cin >> n;

    dp[1] = 1; // 1
    dp[2] = 2; // 11 2
    dp[3] = 4; // 111 12 21 3
    // dp[10] = dp[7] + dp[8] + dp[9];
    // dp[6]은 dp[7]에 포함이지

    for (int i = 4; i <=n; i++) {
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cout << dp[n] << "\n";
  }

  return 0;
}