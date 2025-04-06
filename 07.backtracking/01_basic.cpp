// CodeTree
// Backtracking(simple)
// K개 중에 1개를 N번 뽑기

#include <iostream>
#include <vector>
using namespace std;

int K, N;

vector<int> comb;
void backtracking(int size)
{
  if (size == N)
  {
    for (int i = 0; i < N; i++)
      cout << comb[i] << " ";
    cout << "\n";
    return;
  }

  for (int i = 1; i <= K; i++)
  {
    comb.push_back(i);
    backtracking(size + 1);
    comb.pop_back();
  }
}
int main()
{
  cin >> K >> N;
  backtracking(0);
  // Please write your code here.

  return 0;
}
