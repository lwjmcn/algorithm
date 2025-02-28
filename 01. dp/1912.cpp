#include <iostream>
#include <algorithm>
using namespace std;

int dp[100010] = {0, };
int arr[100010];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> arr[i];
  }

  dp[1] = arr[1];
  int result = dp[1];
  for (int i = 2; i <= n; i++){  
    if(dp[i-1] >= 0)
      dp[i] = dp[i-1] + arr[i];
    else 
      dp[i] = arr[i];

    result = max(result, dp[i]);
  }

  cout << result;
  
  // 채점 전 freopen 주석 처리 할 것
  return 0;
}