#include <iostream>
#include <algorithm>
using namespace std;

int n;
int image[64][64];

bool checkIfAllSame(int startX, int startY, int size)
{
  int num = image[startX][startY];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (image[startX + i][startY + j] != num)
        return false;
  return true;
}
void divideNconquer(int startX, int startY, int size)
{
  // cout << "\nstartX" << startX << " startY" << startY << " size" << size << "\n";
  if (checkIfAllSame(startX, startY, size))
    cout << image[startX][startY];
  else
  {
    size = size / 2;

    cout << "(";
    divideNconquer(startX, startY, size);
    divideNconquer(startX, startY + size, size);
    divideNconquer(startX + size, startY, size);
    divideNconquer(startX + size, startY + size, size);
    cout << ")";
  }
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  cin >> n;
  char k[70]; // 띄어쓰기 없는 int 입력받기 -> char[]로, char* 쓰면 안 됨
  for (int i = 0; i < n; i++)
  {
    cin >> k;
    for (int j = 0; j < n; j++)
    {
      image[i][j] = k[j] - '0';
      // cout << image[i][j];
    }
    // cout << "\n";
  }

  divideNconquer(0, 0, n);

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기