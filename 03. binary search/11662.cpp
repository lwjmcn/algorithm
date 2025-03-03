#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
#define PRECISION 1000
// 이분탐색: 단조증가/단조감소에서의 특정값
// 삼분탐색: 오목/볼록의 극값

double ax, ay, bx, by, cx, cy, dx, dy;
double minDist = 20000;

pair<double, double> getMinho(double t)
{
  return {ax + (bx - ax) * t, ay + (by - ay) * t};
}
pair<double, double> getKangho(double t)
{
  return {cx + (dx - cx) * t, cy + (dy - cy) * t};
}
double getDist(double t)
{
  pair<double, double> m = getMinho(t / PRECISION);
  pair<double, double> k = getKangho(t / PRECISION);

  double dist = pow(m.first - k.first, 2);
  double dist_ = pow(m.second - k.second, 2);
  dist = sqrt(dist + dist_);

  return dist;
}

void ternarySearch(double left, double right)
{
  if (right - left < 1e-6)
    return;
  double leftmid = left + (right - left) / 3;
  double rightmid = right - (right - left) / 3;
  // cout << "left " << left << " leftmid " << leftmid << " rightmid " << rightmid << " right " << right << "\n";

  double leftmidDist = getDist(leftmid);
  double rightmidDist = getDist(rightmid);
  // cout << "dist " << leftmidDist << " " << rightmidDist << "\n";

  minDist = min(leftmidDist, rightmidDist);

  if (leftmidDist < rightmidDist)
    ternarySearch(left, rightmid);
  else
    ternarySearch(leftmid, right);
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("../input.txt", "r", stdin);

  cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

  // ternarySearch(0, PRECISION);

  cout.precision(10);
  cout << minDist;

  // 채점 전 freopen 주석 처리 할 것
  return 0;
}

// https://plzrun.tistory.com/entry/알고리즘-문제풀이PS-시작하기