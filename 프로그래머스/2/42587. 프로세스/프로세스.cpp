#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    // 1. 일반 큐: {우선순위, 기존 위치}를 저장
    queue<pair<int, int>> q;
    // 2. 우선순위 큐: 내림차순 정렬되어 항상 가장 높은 우선순위를 O(1)로 확인 가능
    priority_queue<int> pq; 
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while (!q.empty()) {
        int current_priority = q.front().first;
        int current_index = q.front().second;
        q.pop();
        
        if (current_priority == pq.top()) {
            answer++;    
            pq.pop();   
            
            if (current_index == location) {
                return answer;
            }
            
        } 
        else {
            q.push({current_priority, current_index});
        }
    }
    
    return answer;
}