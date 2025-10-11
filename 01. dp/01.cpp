// Code tree
// 산 모양 타일링, 2024 카카오

#include <string>
#include <vector>
#include <iostream>

using namespace std;


// 산 모양이 있는 n번에는 각각 |마름모, /마름모, 역마름모, 혹은 삼각형 2개를 놓을 수 있다
// /마름모를 놓았다면 그다음에 역마름모는 놓을 수 없다 // 이거아님
// 역마름모를 놓았다면 그다음에 /마름모는 놓을 수 없다
// 산 모양이 없으면 삼각형2개, /마름모, 역마름모를 놓을 수 있다 (|마름모를 놓을 수 없다)

// int countCases(int curIndex, int prevShape, vector<int>& tops) {    
//     // cout << "index " <<curIndex-1 << " shape "<<prevShape << endl; 
//     if(curIndex >= tops.size()) {
//         return 1; // done
//     }
//     else if(tops[curIndex] == 1) { // 산 모양
//         if(prevShape == 0 || prevShape == 1 || prevShape == 2) // 삼각형, |, / -> 세모, /, |, 역
//             return countCases(curIndex+1,0,tops) + countCases(curIndex+1,1,tops) + countCases(curIndex+1,2,tops) + countCases(curIndex+1,3,tops);
//         else // 역마름모 -> 세모, |, 역
//             return countCases(curIndex+1,0,tops) + countCases(curIndex+1,1,tops) + countCases(curIndex+1,3,tops);
//     } else { // 산 모양 아님
//         if(prevShape == 0 || prevShape == 1 || prevShape == 2) // 삼각형 -> 세모, /, 역
//             return countCases(curIndex+1,0,tops) + countCases(curIndex+1,2,tops) + countCases(curIndex+1,3,tops);
//         else // 역마름모 -> 세모, 역
//             return countCases(curIndex+1,0,tops) + countCases(curIndex+1,3,tops);
//     }
// }
// 재귀함수는 시간 초과, dp로 하자

int solution(int n, vector<int> tops) {
    // dp[i][j] : i번째 index, i번쨰 shape가 마름모인지 여부 0,1
    
    vector<vector<int>> dp(n+1, vector<int>(2,0));
    dp[0][0] = 1; // 첫번째 산의 이전 shape는 세모라고 하자
    dp[0][1] = 0;
    for(int i = 1; i <= n; i++) { 
        if(tops[i-1] == 1) { // 1-based 이기 때문~~
            dp[i][0] = (3*dp[i-1][0] + 2*dp[i-1][1]) % 10007; // 세모(1,1) 또는 /마름모(1,0) 또는 |마름모(1,1)가 될 수 있는 경우의 수
            dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % 10007; // 역마름모가 될 수 있는 경우의 수
        } else {
            dp[i][0] = (2*dp[i-1][0] + dp[i-1][1]) % 10007; // 세모(1,1) 또는 /마름모(1,0)가 될 수 있는 경우의 수
            dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % 10007; // 역마름모가 될 수 있는 경우의 수
        }
    }
    
    return (dp[n][0]+dp[n][1]) % 10007;
}