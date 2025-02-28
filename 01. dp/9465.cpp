#include <iostream>
#include <algorithm>
using namespace std;

int sticker [100010][3];
int dp [100010][3];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  int t;
  cin >> t;

  for (int tn = 0; tn < t; tn++)
  {
    int n;    
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> sticker[i][1];
    for (int i = 1; i <= n; i++)
      cin >> sticker[i][2];

    // dp[i][j] i번째 열에서 j행을 선택했을 때의 스티커 값의 합
    dp[1][1] = sticker[1][1];
    dp[1][2] = sticker[1][2];
    dp[2][1] = dp[1][2]+sticker[2][1];
    dp[2][2] = dp[1][1]+sticker[2][2];

    for (int i = 3; i <= n; i++) {
      dp[i][1] = max (dp[i-1][2], dp[i-2][2]) + sticker[i][1];
      dp[i][2] = max (dp[i-1][1], dp[i-2][1]) + sticker[i][2]; 
    }

    cout << max(dp[n][1], dp[n][2]) << endl;
  }
  return 0;
}