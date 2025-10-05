// CodeTree
// 투포인터, 완전탐색
// 2020 카카오 인턴십 - 보석 쇼핑
// 모든 종류를 포함하는 최소 구간 찾기

#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

set<string> getKinds(vector<string>& gems) { // 참조
    set<string> kinds;
    
    for(string gem : gems)
        kinds.insert(gem);
    
    return kinds;
}


vector<int> getSection(vector<string>& gems) {
    set<string> allKinds = getKinds(gems); // 모두 가질 때의 종류
    int min_len = gems.size() + 1;
    int min_start = 0;
    int min_end = 0;
    
    int start = 0;
    int end = 0;
    unordered_map<string, int> kindCount;
    kindCount[gems[start]] = 1;
    
    while(start <= end && end < gems.size()) {

        while(kindCount.size() != allKinds.size()) { // unordered_map처럼 큰 거는 함수 분리해서 인자로 넘길 때 참조(&)로 줄 것, 함수 호출 시마다 copy됨 O(n)
            end++;
            if(end == gems.size()) break;
            kindCount[gems[end]]++;
        }
        if(end == gems.size()) break;
        
        while (kindCount[gems[start]] >= 2) {
            kindCount[gems[start]]--;
            start ++;
        }
    
        int len = end - start + 1;
        if(len < min_len) {
            min_len = len;
            min_end = end;
            min_start = start;
        }
        
        kindCount[gems[start]]--;
        if (kindCount[gems[start]] == 0)
            kindCount.erase(gems[start]); // 0이면 size로 남아있으니 erase 해줘야 함
        start++;
        end++;
        if(end == gems.size()) break;
        kindCount[gems[end]]++;
    }
    
    return {min_start + 1, min_end + 1};
}

vector<int> solution(vector<string> gems) {
     
    return getSection(gems);    
}