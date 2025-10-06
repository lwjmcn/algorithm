#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> testPairs(vector<int>& liqs) {
  int start = 0;
  int end = liqs.size() - 1;
  int sum = liqs[start] + liqs[end];

  int zero_sum = sum;
  int zero_start = start;
  int zero_end = end;
  int prev_sum;

 while(start < end){  
    sum = liqs[start] + liqs[end];
    // cout << liqs[start] << " " << liqs[end] << " " << sum << endl;


    if(abs(sum) < abs(zero_sum)) {
        zero_sum = sum;
        zero_start = start;
        zero_end = end;

        if (sum == 0) break;
    }

    if (sum < 0) start++; // 작은 수를 큰 수로 대체
    if (sum > 0) end--; // 큰 수를 작은 수로 대체
  }

  return {liqs[zero_start], liqs[zero_end]};
}

int main (void) {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;

  vector<int> liqs;
  for(int i = 0; i < n; i ++) {
    int tmp;
    cin >> tmp;
    liqs.push_back(tmp);
  }

  sort(liqs.begin(), liqs.end());

  pair<int, int> answer = testPairs(liqs);

  cout << answer.first << " " << answer.second;

  return 0;
}