#include <iostream>
#include <algorithm>
using namespace std;

int n;
// 배열을 선언하지 않고 프랙탈 풀기
void blankOrStar(int x, int y, int size) // size에 대한 재귀함수, 각 좌표가 공백인지 아닌지를 판별별
{
  if (((x / size) % 3 == 1) && ((y / size) % 3 == 1)) // 공백 최우선 출력
    cout << " ";
  else if (size == 1) // 재귀 마지막 호출
    cout << "*";
  else
    blankOrStar(x, y, size / 3); // 재귀 호출
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      blankOrStar(i, j, n); // 모든 좌표에 대해 호출한다
    }
    cout << "\n";
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기