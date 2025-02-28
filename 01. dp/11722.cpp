#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010];
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
  
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    int bigger_max = 0;
    for (int j = 1; j < i; j++) {
      if (arr[j] > arr[i] && dp[j] > bigger_max){
        bigger_max = dp[j];
      }
    }
    dp[i] = bigger_max + 1;
  }

  int result = 0;
  for(int i = 1; i <= n; i++)
    result = max(result, dp[i]);
  cout << result;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}
