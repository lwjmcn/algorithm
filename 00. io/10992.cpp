#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    if (i != n-1) {
      for (int j = 0; j < n-i-1; j++) 
        cout << " ";
      cout << "*";
      for (int j = 0; j < 2*i - 1; j++ )
        cout << " ";
      if (i != 0)
        cout << "*";
    } 
    else {
      for (int j = 1; j <= 2*i+1; j++ ) {
        cout << "*";
      }
    }
    cout << "\n";
  }

  return 0;
}