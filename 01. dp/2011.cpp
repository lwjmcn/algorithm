#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


// 코드를 이렇게 더럽게 쓰지 말자 ... ㅠ
// 이중배열도 안 써도 됏잖아....
int code[5001];
int dp[5001][2];

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  string n;
  cin >> n;

  // 배열로 분해
  int digit = 1; // 자릿수
  for(char c : n) {
    code[digit++] = c - 48; 
  }

  // dp[i] 뒤에서 i번째 digit까지 봤을 때 경우의 수 
  // dp[i][0] i번째 digit은 한 자리 수
  // dp[i][1] i번째 digit은 (i-1)번째 digit(앞자리수)과 묶여서 
  if(code[1] == 0) {
    cout << 0;
    exit(0);
  }
  dp[1][0] = 1;
  dp[1][1] = 0;
  for(int i = 2; i <= n.length(); i++) {
    if (code[i] == 0 && code[i-1] != 1 && code[i-1] != 2){ // 불가능한 암호
      cout << 0;
      exit(0);
    } // 00, 30, 40, ... 90
    else if (code[i] == 0) {
      dp[i][0] = 0; // 한 자리 불가능
      dp[i][1] = dp[i-1][0];
    }
    else {
      dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % 1000000; // 합

      if(code[i] <= 6 && (code[i-1] == 1 || code[i-1] == 2)) // 10~16, 20~26
        dp[i][1] = dp[i-1][0];
      else if (code[i] > 6 && code[i-1] == 1) // 17~19
        dp[i][1] = dp[i-1][0];
      else dp[i][1] = 0; // 두 자리 불가능
    }
    if (code[i-1] == 0) {
      dp[i][1] = 0;
    }
  }

  // for (int j = 1; j <=10; j++)  
  //   cout << code[j] << " ";
  // cout << endl;
  // for (int j = 1; j <=10; j++)
  //   cout << dp[j][0] << " ";
  // cout << endl;
  // for (int j = 1; j <=10; j++)
  //   cout << dp[j][1] << " ";
  // cout << endl; 
  
  cout << (dp[n.length()][0] + dp[n.length()][1]) % 1000000;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

