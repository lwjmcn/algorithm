#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt[2]; // cnt0, cnt1, cnt2;
vector<int> paper[2200];

bool checkIfAllSameNum(int startX, int startY, int size)
{
  int num = paper[startX][startY];

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (paper[startX + i][startY + j] != num)
        return false;
  return true;
}

void divideNconquer(int startX, int startY, int size)
{
  if (checkIfAllSameNum(startX, startY, size))
  {
    cnt[paper[startX][startY]]++;
    // cout << "x" << startX << " y" << startY << " size" << size << "\n";
  }
  else
  {
    // 재귀
    for (int i = 0; i < size; i += size / 3)
      for (int j = 0; j < size; j += size / 3)
        divideNconquer(startX + i, startY + j, size / 3);
  }
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;
  int k;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> k;                  // -1,0,1
      paper[i].push_back(k + 1); // 0,1,2
    }
  }

  divideNconquer(0, 0, n);

  cout << cnt[0] << "\n"
       << cnt[1] << "\n"
       << cnt[2];

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기