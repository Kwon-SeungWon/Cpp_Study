#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int& n, vector<vector<int>>& computers, vector<bool>& visited, int current){
    
    if(visited[current]){
        return 0;
    }
    
    visited[current] = true;
    
    for(int next=0; next<n; next++){
        if(computers[current][next] == 1){
            dfs(n, computers, visited, next);
        }
    }
    
    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i=0; i<n; i++){
        answer += dfs(n, computers, visited, i);
    }
    
    return answer;
}