#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Node {
    int r;
    int c;
    int dist;
};

int bfs(const vector<vector<int>>& maps, vector<vector<bool>>& visited, int row_size, int col_size) {
    queue<Node> move;
    
    move.push({0, 0, 1}); 
    visited[0][0] = true;
    
    while (!move.empty()) {
        int cur_row = move.front().r;
        int cur_col = move.front().c;
        int cur_dist = move.front().dist; 
        move.pop();
        
        if (cur_row == row_size - 1 && cur_col == col_size - 1) {
            return cur_dist;
        }
        
        for (int i = 0; i < 4; i++) {
            int next_row = cur_row + dx[i];
            int next_col = cur_col + dy[i];
            
            if (next_row >= 0 && next_col >= 0 && next_row < row_size && next_col < col_size) {
                if (!visited[next_row][next_col] && maps[next_row][next_col] == 1) {
                    visited[next_row][next_col] = true;
                    
                    move.push({next_row, next_col, cur_dist + 1}); 
                }
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    return bfs(maps, visited, n, m);
}