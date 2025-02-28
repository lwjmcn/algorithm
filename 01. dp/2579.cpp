#include <iostream>
#include <algorithm>
using namespace std;

int dp[310];
int stair[310];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> stair[i];

    // 마지막은 꼭 밟아야 함
    // 연속 세 개를 밟으면 안 됨
    // dp[i]: i번째 계단을 밟았다고 했을 때 최댓값
  dp[0] = 0;
  dp[1] = stair[1]; 
  dp[2] = dp[1] + stair[2];
  for(int i = 3; i <= n; i++){
    // xo o
    dp[i] = dp[i-3] + stair[i-1] + stair[i];
    // _x o
    dp[i] = max(dp[i], dp[i-2] + stair[i]);
  }

  cout << dp[n];
    


  // 채점 전 freopen 주석 처리 할 것
  return 0;
}