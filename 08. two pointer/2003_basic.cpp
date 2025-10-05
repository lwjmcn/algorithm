#include <iostream>
#include <algorithm>
#include <vector>

#define DEBUG true

#if DEBUG
#define DEBUG_MSG(x) cout << x << endl
#else
#define DEBUG_MSG(x)
#endif

using namespace std;


int countCases(vector<int> arr, int m) {
  int count = 0;
  int i = 0;
  int j = 0;
  int sum = arr[i];

  while(j < arr.size()) {
    if(sum > m) {
      sum -= arr[i];
      i++;
      if(i > j) {
        j++;
        if (j < arr.size()) sum += arr[j];
      }
    }
    else if(sum < m){ 
      j++;
      if (j < arr.size()) sum += arr[j];

    }
    else {
      count ++;
      sum -= arr[i];
      i++;
      j++;
      if (j < arr.size()) sum += arr[j];

    }
  }
  return count;

}

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  int n, m;
  cin >> n >> m;

  vector<int> arr;
  int tmp;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    arr.push_back(tmp); 
  }

  cout << countCases(arr, m);

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}