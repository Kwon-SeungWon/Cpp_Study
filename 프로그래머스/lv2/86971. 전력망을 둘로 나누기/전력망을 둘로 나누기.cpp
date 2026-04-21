#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dfs (int begin, int ignore, vector<vector<int>>& adj_nodes, vector<bool>& visited){
    
    int count = 1;
    visited[begin] = true;
    
    for(auto& next : adj_nodes[begin]){
        if(!visited[next] && next != ignore){
            count+=dfs(next, ignore, adj_nodes, visited);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    vector<vector<int>> adj(n+1);
    
    for(auto& w : wires){
        adj[w[0]].push_back(w[1]);
        adj[w[1]].push_back(w[0]);
    }
    
    // 간선 끊기
    for(auto& w : wires){
        int n1 = w[0];
        int n2 = w[1];
        
        // 방문 노드 초기화
        vector<bool> visited(n+1, false);
        
        // DFS를 통한 끊어진 간선부터의 count 세기
        int count_node1 = dfs(n1, n2, adj, visited);
        int count_node2 = n - count_node1;
        int result = abs(count_node1 - count_node2);
        
        answer = min(answer, result);
    }
    
    
    return answer;
}