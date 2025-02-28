#include <iostream>
#include <algorithm>
using namespace std;

int dp[1020];
int arr[1010];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  
  
  dp[1] = arr[1];
  for (int i = 2; i <= n; i++)
  {
    int lower_max = 0;
    for (int j = 1; j <= i; j++)
      if(dp[j] > lower_max && arr[j] < arr[i])
        lower_max = dp[j];
    dp[i] = lower_max + arr[i];
  }

  int result = 1;
  for (int i = 1; i <=n; i++)
    result = max(result, dp[i]);
  cout << result;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}