#include <iostream>
#include <algorithm>
using namespace std;

int grape[10010];
int dp[10010];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> grape[i];

  // dp[i][j] 
  // i번째 와인을 j = 0 마시지 않음 / j = 1 마셨을 떄의 최댓값
  dp[1] = grape[1];
  dp[2] = dp[1]+grape[2];

  for (int i = 3; i <= n; i++){
    
    dp[i] = max (max(dp[i-3]+grape[i-1]+grape[i] ,dp[i-2]+grape[i]), dp[i-1]);
    // dp[i-3]+grape[i-1]+grape[i]     X O O    
    // dp[i-2]+grape[i]                  X O 
    // dp[i-1]                             X
    // 중의 최댓값
  }

  cout << dp[n];
  
  

  return 0;
}