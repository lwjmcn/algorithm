// CodeTree
// Backtracking(simple)
// 강력한 폭발

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n;
int grid[20][20];
int max_cnt = 0;

vector<pair<int,int>> bombCell;
set<pair<int,int>> bombedCell; 

void checAndInsertCell (int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y <n) {
        bombedCell.insert({x, y});
    }
}
void backtracking(int cnt) {
    if (cnt == bombCell.size()) {
        bombedCell.clear();
        for (int i = 0; i < bombCell.size(); i++) {
            int x = bombCell[i].first;
            int y = bombCell[i].second;
            if (grid[x][y] == 1) {
                bombedCell.insert({x,y});
                checAndInsertCell(x-1, y);
                checAndInsertCell(x-2, y);
                checAndInsertCell(x+1, y);
                checAndInsertCell(x+2, y);           
            } else if (grid[x][y] == 2) {
                bombedCell.insert({x,y});
                checAndInsertCell(x-1, y);
                checAndInsertCell(x+1, y);
                checAndInsertCell(x, y+1);
                checAndInsertCell(x, y-1); 
            } else if (grid[x][y] == 3){
                bombedCell.insert({x,y});
                checAndInsertCell(x-1, y+1);
                checAndInsertCell(x+1, y+1);
                checAndInsertCell(x-1, y-1);
                checAndInsertCell(x+1, y-1); 
            }
        }
        max_cnt = max(max_cnt, (int)bombedCell.size());
        return;
    } 

    // for (int i = 0; i < bombCell.size(); i++) {
        int x = bombCell[cnt].first;
        int y = bombCell[cnt].second;
        for (int k = 1; k <= 3; k++){
            grid[x][y] = k;  
            backtracking(cnt+1);
            grid[x][y] = -1;  
        }
    // }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k;
            cin >> k;
            if(k == 1) {
                grid[i][j] = -1;
                bombCell.push_back({i,j});
            } else {
                grid[i][j] = 0;
            }
        }
    }
    backtracking(0);

    cout << max_cnt;

    return 0;
}
