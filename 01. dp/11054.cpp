#include <iostream>
#include <algorithm>
using namespace std;

int dp[1020][2];
int arr[1010];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  
  
  dp[1][0] = 1; // 증가 중
  dp[1][1] = 1; // 감소 중
  for (int i = 2; i <= n; i++)
  {
    int asc_max = 0; // 증가하는 수열의 최대
    int dsc_max = 0; // 증가하다 감소하는 수열의 최대
    for (int j = 1; j <= i; j++)
      if(arr[j] < arr[i]) // 증가
        asc_max = max(asc_max, dp[j][0]);
      else if (arr[j] > arr[i])  // 감소
        dsc_max = max(dsc_max, max(dp[j][0], dp[j][1]));
    dp[i][0] = asc_max + 1;
    dp[i][1] = dsc_max + 1;
  }

  int result = 1;
  for (int i = 1; i <=n; i++)
    cout << dp[i][0] << " ";
  cout << endl;
  for (int i = 1; i <=n; i++)
    cout << dp[i][1] << " ";
  cout << endl;

  for (int i = 1; i <= n; i++)
    // result = max(result, max(dp[i][0], dp[i][1]));
  cout << result;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}