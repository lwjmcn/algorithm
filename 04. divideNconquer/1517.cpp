#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int n;
pair<int, int> a[500005]; // value, index
// bubble sort의 swap 개수 -> 어떤 수열값에 대하여 오른쪽에 그보다 작은 값의 개수를 세면 됨
// segment tree 풀이 참고: https://loosie.tistory.com/328

// 작은 숫자부터 segment tree에 +1로 업데이트한다
// segment tree 노드 값은 지금까지 센 숫자의 개수임
// a[3]에 대하여 오른쪽~~~ 값을 구한다고 할 때, [4:end] 구간합 쿼리를 하면 됨!!!

ll segtree[2000005]; // a[], count of smaller nums on the right side

ll init(int cur, int start, int end)
{
  if (start == end)
    return 0;

  int mid = (start + end) / 2;
  ll left = init(cur * 2, start, mid);
  ll right = init(cur * 2 + 1, mid + 1, end);

  return segtree[cur] = left + right;
}

ll range_query(int cur, int start, int end, int left_query, int right_query)
{
  if (left_query > end || right_query < start)
    return 0;

  if (left_query <= start && right_query >= end)
    return segtree[cur];

  int mid = (start + end) / 2;
  ll left = range_query(cur * 2, start, mid, left_query, right_query);
  ll right = range_query(cur * 2 + 1, mid + 1, end, left_query, right_query);

  return left + right;
}
void update(int cur, int start, int end, int index, int diff)
{
  if (index < start || index > end)
    return;

  segtree[cur] += diff;

  if (start == end)
    return;

  int mid = (start + end) / 2;
  update(cur * 2, start, mid, index, diff);
  update(cur * 2 + 1, mid + 1, end, index, diff);
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int k;
    cin >> k;
    a[i] = {k, i}; // value, index
  }
  sort(a + 1, a + n + 1); // value기준 sort

  init(1, 1, n);

  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    // cout << a[i].first << " " << a[i].second << "\n";
    ans += range_query(1, 1, n, a[i].second + 1, n);
    update(1, 1, n, a[i].second, 1);

    // for (int i = 0; i < 4 * n; i++)
    // {
    //   cout << segtree[i] << " ";
    // }
    // cout << "\n";
  }

  cout << ans;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기