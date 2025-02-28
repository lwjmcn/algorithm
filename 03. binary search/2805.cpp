#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int tree[1000006];
int ans;

long long getM(int h)
{
  long long sum = 0; // 정신차리자... 20억 테케는 꼭 한 번씩 돌려보고 제출할 것
  for (int i = 0; i < n; i++)
    if (tree[i] > h)
      sum += (tree[i] - h);

  return sum;
}
void binarySearch(int left, int right)
{
  if (left > right)
    return;
  int mid = (left + right) / 2;
  if (getM(mid) >= m)
  {                               // 나무가 충분하면
    binarySearch(mid + 1, right); // 높이를 높여도 됨
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

  int t;
  long long sum;
  int maxHeight;
  cin >> n >> m; // 100만, 20억억
  for (int i = 0; i < n; i++)
  {
    cin >> t;
    tree[i] = t;
    sum += t;
    maxHeight = max(t, maxHeight);
  }

  binarySearch(1, maxHeight);

  cout << ans;
  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기