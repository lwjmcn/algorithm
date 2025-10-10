// Code tree
// 도넛과 막대 그래프, 2024 카카오


#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


// 생성된 정점
// 아웃엣지가 2개 이상이고 인엣지가 없으면 생성된 정점

// 생성 정점에서부터 dfs로 지나간 정점을 visit함
// 도넛
// 새로운 정점이 visit했던 정점이고 아웃엣지가 1개, 거기부터 다 done함
// 8자
// 새로운 정점이 visit했던 정점이고 아웃엣지가 2개
// 막대
// 새로운 정점이 없으면 막대의 마지막임

vector<int> countGraphs (int c, unordered_map<int, vector<int>>& nextNodes) {
    int cntDonut = 0; // 도넛모양그래프
    int cntBar = 0; // 막대모양그래프
    int cntEight = 0; // 8자모양그래프
    bool visit[1000005] = {false, };
    
    for(int start : nextNodes[c]) { // 각 그래프의 한 점
        int cur = start;
        visit[cur] = true;
        if(nextNodes[cur].size() > 1) { // 8자
            cntEight++;
            continue;
        } 
        if (nextNodes[cur].size() == 0){ // 막대
            cntBar++;
            continue;
        }
        
        while(nextNodes[cur].size() > 0) {
            cur = nextNodes[cur][0];
            if(nextNodes[cur].size() > 1) { // 8자, 무조건 먼저 분기
                cntEight++;
                break;
            } 
            else if (visit[cur]) {
                cntDonut++; // 도넛
                break;
            }
            else if(nextNodes[cur].size() == 0) { // 막대
                cntBar++;
                break;
            }
            
            visit[cur] = true;
        }       
        
    }
    return {c, cntDonut, cntBar, cntEight};
}

vector<int> solution(vector<vector<int>> edges) {
    unordered_map<int, vector<int>> nextNodes; // 정점, 정점의 next 배열 (out-degree)
    unordered_map<int, vector<int>> prevNodes; // 정점, 정점의 prev 배열 (in-degree)
    int c; // 생성된 정점
    
    for(vector<int> edge : edges) {
        int src = edge[0];
        int dst = edge[1];
        nextNodes[src].push_back(dst); // edge map 생성
        prevNodes[dst].push_back(src);
        
        // 아웃엣지 기준 생성된 정점 찾기
        if (nextNodes[src].size() >= 2 && prevNodes[src].size() == 0) {
            c = src;
        }
    }

    return countGraphs (c, nextNodes);
 
}