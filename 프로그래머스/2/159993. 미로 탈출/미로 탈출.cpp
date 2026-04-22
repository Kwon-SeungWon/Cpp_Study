#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct Node{
    int x;
    int y;
    int sec;
};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool isReachedVia = false;

int bfs(vector<string>& grid, int startX, int startY, int targetX, int targetY, int sec){
    
    vector<vector<bool>> visited (101, vector<bool>(101, false));

    int xsize = grid.size();
    int ysize = grid[0].size();
    
    queue<Node> q; 
    q.push({startX, startY, sec});
    visited[startX][startY] = true;
    
    while(!q.empty()){
        
        Node current = q.front();
        q.pop();
        
        int cx = current.x;
        int cy = current.y;
        int csec = current.sec;
        
        if(cx == targetX && cy == targetY){
            return csec;
        }
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
          
            if(nx >= 0 && ny>= 0 && nx < xsize && ny < ysize){
                if(!visited[nx][ny] && grid[nx][ny] != 'X'){
                    q.push({nx, ny, csec+1});
                    visited[nx][ny] = true;
                }
            }
            
        }
    }
    
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    int startX, startY, viaX, viaY, targetX, targetY;
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].size(); j++){
            if(maps[i][j] == 'S'){
                startX = i;
                startY = j;
            }
            else if(maps[i][j] == 'L'){
                viaX = i;
                viaY = j;
            }
            else if(maps[i][j] == 'E'){
                targetX = i;
                targetY = j;
            }
        }
    }
    
    answer = bfs(maps, startX, startY, viaX, viaY, answer);
    
    if(answer == -1){
        return answer;
    }
    
    answer = bfs(maps, viaX, viaY, targetX, targetY, answer);
        
    return answer;
}