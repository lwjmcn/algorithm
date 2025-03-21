#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
pair<int, int> a[500005];
// bubble sort의 swap 개수 -> 어떤 수열값에 대하여 오른쪽에 그보다 작은 값의 개수를 세면 됨
// segment tree 풀이 참고: https://loosie.tistory.com/328
// vector<int> 중복값 처리
pair<int, vector<int>> segtree; // a[], count of smaller nums on the right side

// void dividenconquer()
// {
//   int i = n - 1;

//   while (1)
//   {
//     for (int j = i + 1; j < n; j++)
//     {
//       if (a[j] >= a[i])
//       {
//         segtree[j + n] =
//       }
//     }

//     segtree[i + n] = {a[i], 0};
//     i--;
//   }

//   for (int i = n - 2; i >= 0; i--) // from the right side
//   {
//     cout << "a[i] " << a[i] << "\n";
//     for (int j = i + 1; j < n; j++) // nums on the right side of i
//     {
//       cout << "a[j] " << a[j] << "\n";
//       if (dp.find(j) == dp.end())
//       {
//         if (a[j] < a[i])
//         {
//           cout << "dp[a[i]]++" << "\n";
//           dp[i]++;
//         }
//       }
//       else
//       {
//         if (a[j] < a[i])
//         {
//           cout << "dp[a[i]] = dp[a[j]]+1" << "\n";
//           dp[i] += (dp[j] + 1);
//         }
//       }
//     }
//     cout << "\n";
//   }
// }

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    a[i] = {i, k}; // index, value
  }
  sort(a, a + n);

  // dividenconquer();

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    //
  }
  cout << ans;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기