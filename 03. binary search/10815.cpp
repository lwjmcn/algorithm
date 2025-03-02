#include <iostream>
#include <algorithm>
using namespace std;

// easyyyy
// 50만개에 대해 50만개 서치하기 -> 이분탐색
// 라는 아이디어를 도출하는 게 중요

// C++ <algorithm>에 binary_search 함수가 있다
// 참고하자...
// binary_search(arr, arr+N, numToFind);

int n;
int card[500005];

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input/.txt", "r", stdin);

  int m, num;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> num;
    card[i] = num;
  }
  sort(card, card + n);

  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> num;
    // cout << isExist(num) << " ";
    cout << binary_search(card, card + n, num) << " ";
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기
