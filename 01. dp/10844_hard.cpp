#include <iostream>
#include <algorithm>
using namespace std;

int dp_1 [105];
int pd [105];
int dp[105][11]; 

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  // 1 2 3 4 5 6 7 8 9
  // dp_1[1] = 9
  
  // 9
  // pd[1] = 1
  // 12 10 23 21 34 32.....76 78 87 89 98!!! 
  // dp_1[2] = dp_1[1]*2 - 1 = 17

  // 10 89
  // pd[2] = pd[1]*2 - 2 = 2
  // 121 123 101!!! 234 232 210 212 343 345 321 323 .... 765 767 787 789 876 878 898!!! 989 987
  // dp_1[3] = dp_1[2]*2 - 2 = 32

  // 210 789 989
  // pd[3] = pd[2]*2 - 1 = 3
  // dp_1[4] = dp_1[3]*2 - 3 = 61
  
  // 3210 1210 6789 8789 8989! ***1010
  // pd[4] = pd[3]*2 - 1 = 5
  // dp_1[5] = dp_1[4]*2 - 5

  // 43210 23210 21210! 56789 76789 98789 78789 78989 98989
  // pd[5] = pd[4]*2 - 1 = 9
  // dp_1[6] = dp_1[4]*2 - 9



  // initialize
  dp[1][0] = 0; // i번째에서 j가 마지막 자릿수인 경우의 개수
  for (int i = 1; i <= 9; i++) 
    dp[1][i] = 1;

  // dp
  for (int i = 2; i<=n; i++) {
    dp[i][0] = dp[i-1][1];
    for (int j = 1; j <= 8; j++) {
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
    }
    dp[i][9] = dp[i-1][8];
  }

  // result sum
  int result = 0;
  for (int j = 0; j < 10; j++ ){
    result += dp[n][j];
    result %= 1000000000;
  }

  cout << result;
  
  return 0;
}