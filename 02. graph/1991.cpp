#include <iostream>
#include <algorithm>
using namespace std;

// 이진 트리 배열로 구현
pair<int, int> tree_list[26]; // (left, right) in a form of (char)(ALPHABET - 'A')

void preorder(int cur)
{
  cout << (char)(cur + 'A');
  if (tree_list[cur].first)
    preorder(tree_list[cur].first);
  if (tree_list[cur].second)
    preorder(tree_list[cur].second);
}
void inorder(int cur)
{
  if (tree_list[cur].first)
    inorder(tree_list[cur].first);
  cout << (char)(cur + 'A');
  if (tree_list[cur].second)
    inorder(tree_list[cur].second);
}
void postorder(int cur)
{
  if (tree_list[cur].first)
    postorder(tree_list[cur].first);
  if (tree_list[cur].second)
    postorder(tree_list[cur].second);
  cout << (char)(cur + 'A');
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("../input.txt", "r", stdin);

  int n;
  cin >> n;

  int root;
  for (int i = 0; i < n; i++)
  {
    char h, l, r;
    cin >> h >> l >> r;

    if (i == 0)
      root = h - 'A';

    if (l != '.')
      tree_list[h - 'A'].first = l - 'A';
    if (r != '.')
      tree_list[h - 'A'].second = r - 'A';
  }

  // for (int i = 0; i < 26; i++)
  // {
  //   cout << (char)(i + 'A') << endl;
  //   if (tree_list[i].first)
  //     cout << "left " << (char)(tree_list[i].first + 'A') << endl;
  //   if (tree_list[i].second)
  //     cout << "right " << (char)(tree_list[i].second + 'A') << endl;
  //   cout << endl;
  // }

  preorder(root);
  cout << endl;
  inorder(root);
  cout << endl;
  postorder(root);

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기