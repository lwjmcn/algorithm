#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll nums[1000005];
ll segment_tree[4000005];

// 세그먼트트리 구축
ll init(int cur, int start, int end)
{
  if (start == end)
  {
    return (segment_tree[cur] = nums[start]);
  }
  int mid = (start + end) / 2;
  ll left = init(cur * 2, start, mid);
  ll right = init(cur * 2 + 1, mid + 1, end);

  return (segment_tree[cur] = left + right);
}

void print(int n)
{

  for (int i = 1; i < n * 4; i++)
  {
    cout << segment_tree[i] << " ";
  }

  cout << "\n";
}

// left~right 구간 합
ll range_query(int cur, int start, int end, int left_query, int right_query)
{
  if (left_query > end || right_query < start)
    return 0;
  if (left_query <= start && right_query >= end)
    return segment_tree[cur];

  int mid = (start + end) / 2;
  ll left = range_query(cur * 2, start, mid, left_query, right_query);
  ll right = range_query(cur * 2 + 1, mid + 1, end, left_query, right_query);

  return left + right;
}

// 값 변화
void update(int cur, int start, int end, int index, ll diff)
{
  if (index < start || index > end)
    return;

  segment_tree[cur] += diff;

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

  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
  {
    ll a;
    cin >> a;
    nums[i] = a;
  }

  init(1, 1, n);

  // print(n);

  for (int i = 0; i < m + k; i++)
  {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    if (a == 1)
    {
      // cout << "update\n";
      update(1, 1, n, b, c - nums[b]);
      nums[b] = c;
    }
    else if (a == 2)
    {
      // cout << "query\n";
      cout << range_query(1, 1, n, b, c) << "\n";
    }
    // print(n);
  }

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기