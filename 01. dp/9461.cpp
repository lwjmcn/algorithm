#include <iostream>
#include <algorithm>
using namespace std;

long long dp[101]; // 주의!

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  int t;
  cin >> t;

  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 2;

  for (int test = 0; test < t; test++)
  {
    int n;
    cin >> n;

    for(int i = 6; i <= n; i++)
      if (dp[i] == 0)
        dp[i] = dp[i-1]+dp[i-5];

    cout << dp[n] << endl;
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}