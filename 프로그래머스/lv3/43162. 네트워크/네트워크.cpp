#include <string>
#include <vector>

using namespace std;

void DFS(vector<bool>& visited, vector<vector<int>> computers, int cur_point, int n){
    visited[cur_point] = true;
    
    for(int i=0; i<n; i++){
        if(!visited[i] && computers[cur_point][i] == 1){
            DFS(visited,computers,i,n);
        }
    }
}

int solution(int n, vector<vector<int>> computers){
    int answer=0;
    vector<bool> visited(n,false);
    
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            DFS(visited, computers, i, n);
            answer++;
        }
    }
    
    return answer;
}