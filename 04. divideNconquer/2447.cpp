#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 프랙탈 문제
// 좌표에 대하여
// (x/n) % 3 == 1 && (j/n) % 3 == 1 일 때 빈 좌표이다
// 라는 방식으로 프린트 할 수 있다
// 내가 쓴 방법은 너무 원시적,,, 메모리 낭비,,,
vector<bool> paper[2200];

void pattern3(int x, int y)
{
  for (int i = 0; i < 3; i++)
    paper[x + i][y] = true;

  paper[x][y + 1] = true;
  paper[x + 1][y + 1] = false;
  paper[x + 2][y + 1] = true;

  for (int i = 0; i < 3; i++)
    paper[x + i][y + 2] = true;
}
void draw(int x, int y, int size)
{
  if (size == 3)
    return pattern3(x, y);
  for (int i = 0; i < 3; i++)
    draw(x + size / 3 * i, y, size / 3);
  draw(x, y + size / 3, size / 3);
  draw(x + size / 3 * 2, y + size / 3, size / 3);
  for (int i = 0; i < 3; i++)
    draw(x + size / 3 * i, y + size / 3 * 2, size / 3);
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      paper[i].push_back(false);

  draw(0, 0, n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (paper[i][j])
        cout << "*";
      else
        cout << " ";
    }
    cout << "\n";
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기