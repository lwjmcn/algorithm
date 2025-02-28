#include <iostream>
#include <algorithm>
using namespace std;

int dp[210][210];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  // dp[k][n]: k개를 더해서 합이 n가 되는 경우의 수
  // 경험적으로 알아낼 것 ,,,,,,,
  
  for (int n = 1; n <= N; n++)
    dp[1][n] = 1;
  for (int k = 1; k <= K; k++)
    dp[k][1] = k;

  for (int n = 2; n <= N; n++)
    for (int k = 2; k <= K; k++)
      dp[k][n] = (dp[k-1][n]+dp[k][n-1]) % 1000000000;

  cout << dp[K][N] % 1000000000;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}