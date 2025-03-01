#include <iostream>
#include <algorithm>
using namespace std;

int n, c, ans;
int house[200005];
int dist[200005]; // 집 간 거리

// 첫번째 집에는 무조건 설치
// 그 후 간격을 어떻게 할지 이분탐색 하자

bool isAllInstalled(int minLength)
{
  int install_cnt = 0;
  int dist_from_prev = 0;
  for (int i = 1; i < n; i++)
  {
    dist_from_prev += dist[i];
    if (dist_from_prev >= minLength)
    { // 설치
      dist_from_prev = 0;
      install_cnt++;
    }
  }
  if (install_cnt >= c - 1)
    return true;
  return false;
}
void binarySearch(int left, int right)
{
  if (left > right)
    return;
  // cout << "left " << left << " right " << right << "\n";
  int mid = (left + right) / 2;
  if (isAllInstalled(mid))
  {
    binarySearch(mid + 1, right);
    ans = max(ans, mid);
  }
  else
    binarySearch(left, mid - 1);
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int coord;
  cin >> n >> c;
  for (int i = 0; i < n; i++)
  {
    cin >> coord;
    house[i] = coord;
  }

  sort(house, house + n);

  for (int i = 1; i < n; i++)
    dist[i] = house[i] - house[i - 1];

  binarySearch(1, house[n - 1] - house[0]);

  cout << ans;
  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기