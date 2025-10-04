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

vector<int> arr;


int countPairs(vector<int> arr, int x) {
  int count = 0;
  for(int i = 0; i < arr.size() - 1; i++) {
    int aj = x - arr[i];
    bool isExistAj = binary_search(arr.begin()+i+1, arr.end(), aj);
    if (isExistAj) count ++; 
  }

  return count;
}


int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;

  int tmp;
  for(int i =0; i < n; i++){
    cin >> tmp;
    arr.push_back(tmp);
  }

  int x;
  cin >> x;

  sort(arr.begin(), arr.end());

  cout << countPairs(arr, x);

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

//https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기