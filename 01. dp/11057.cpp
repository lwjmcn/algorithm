#include <iostream>
#include <algorithm>
using namespace std;

int dp[1011][10];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  int result = 0;

  for (int j = 0; j < 10; j++) {
    dp[1][j]= 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = j; k < 10; k++) {
        dp[i][j] += dp[i-1][k] % 10007;
      }
    }
  }

  for (int j = 0; j < 10; j++) {
    result += dp[n][j]  % 10007;
  }

  cout << result % 10007;
  


  return 0;
}