#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// 가장 짧은 것들을 찾아서 그 그룹에 속한 애들 다 무찌르기

bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    // queue<int,int> Q;
    
    sort(targets.begin(), targets.end(), cmp);
    
    int last_shot = -1;
    
    for(auto& target : targets){
        // cout << target[0] << ", " << target[1] << "\n";
        
        int start = target[0];
        int end = target[1];
        
        // 현재 폭격기의 시작점이, 마지막 미사일이 커버할 수 있는 범위 밖에 있다면
        // (문제 조건에서 미사일 x는 s < x < e 에서만 요격하므로 >= 이면 요격 불가)
        if (start >= last_shot) {
            answer++;          
            last_shot = end;   // 새 미사일은 현재 폭격기의 끝점(end)에 최대한 가깝게 쏜 것으로 취급
        }
    }
    
   
    return answer;
}