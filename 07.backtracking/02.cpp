// CodeTree
// Backtracking(simple)
// 아름다운 수

#include <iostream>
#include <vector>

using namespace std;

int n;

int count = 0;

vector<int> nums;
void backtracking(int size) {
    if (size > n) return;
    else if (size == n) {
        count ++;
        return;
    }

    for(int i = 1; i <= 4; i++) {
        for(int j = 0; j < i; j++) {
            nums.push_back(i);
        }
        backtracking(size+i);
        for(int j = 0; j < i; j++) {
            nums.pop_back();
        }
    }
    

}

int main() {
    cin >> n;

    backtracking(0);

    cout << count;
    return 0;
}
