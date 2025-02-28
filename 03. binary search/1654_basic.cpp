#include <iostream>
#include <algorithm>
using namespace std;

int lan[10005];
int k, n;
int ans;

int getN(int desiredLength)
{
  int cnt = 0;
  for (int i = 0; i < k; i++)
    cnt += lan[i] / desiredLength;

  return cnt;
}
void binarySearch(long long left, long long right)
{
  // cout << "left " << left << " right " << right << "\n";
  if (left > right)
    return;
  long long mid = (left + right) / 2; // MAX가 2^31-1이어도 덧셈 오버플로우 !! int, long long 항상 주의하자자
  int cur = getN((int)mid);
  if (cur >= n)
  {
    ans = max(ans, (int)mid);
    // cout << ans << "\n";
    binarySearch(mid + 1, right);
  }
  else if (cur < n)
    binarySearch(left, mid - 1);
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  cin >> k >> n;
  int l;
  long long sum = 0;
  for (int i = 0; i < k; i++)
  {
    cin >> l;
    lan[i] = l;
    sum += l;
  }

  binarySearch(1, sum / n);
  cout << ans;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기