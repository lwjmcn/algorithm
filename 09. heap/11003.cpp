// 슬라이딩 윈도우, 우선순위 큐
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

struct cmp {
  bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second > b.second; // min heap, 오름차순
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("../input.txt", "r", stdin);
  
  int n, L, tmp;
  vector<int> arr;

  cin >> n >> L;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    arr.push_back(tmp);
  }

  // Ak부터 AI까지의 최솟값이 Di, Ak부터 Ai까지 개수가 L개
  // D를 구한다

  // pair = {index, value}
  priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

  for(int i = 0; i < n; i++) {
    pq.push({i, arr[i]});

    pair<int,int> min_ = pq.top();    
    while (min_.first < i-L+1 || min_.first > i)  { // index 윈도우 범위 확인
      pq.pop();
      min_ = pq.top();
    } 

    cout << min_.second << " ";
  }
  
   
  return 0;
}