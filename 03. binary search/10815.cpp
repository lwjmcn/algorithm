#include <iostream>
#include <algorithm>
using namespace std;

// easyyyy
// 50만개에 대해 50만개 서치하기 -> 이분탐색
// 라는 아이디어를 도출하는 게 중요
int n;
int card[500005];

bool isExist(int num)
{
  int left_idx = 0;
  int right_idx = n - 1;
  while (left_idx <= right_idx)
  {
    int mid = (left_idx + right_idx) / 2;
    if (card[mid] == num)
      return true;
    else if (card[mid] > num)
    {
      right_idx = mid - 1;
    }
    else
    {
      left_idx = mid + 1;
    }
  }
  return false;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

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
    cout << isExist(num) << " ";
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기
