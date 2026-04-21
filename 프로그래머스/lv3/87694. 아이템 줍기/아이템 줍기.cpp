#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// 직사각형들이 포개지는 걸 어떻게 구현하지? -> 와 속을 칠하고 파낸다? 이건 어떻게 생각했지? 일단 구현해보자
// **** 좌표 2배 뻥튀기 이벤트로 갈 수 있는곳, 없는곳 구분해줘야함!!!!!!! *******
// BFS 로 시작점부터 끝점까지의 최단 경로가기 BFS는 큐에 넣을때 방문처리!

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<vector<int>> grid(101, vector<int>(101,0));
vector<vector<bool>> visited(101, vector<bool>(101, false));

int bfs(int beginX, int beginY, int endX, int endY){
    queue <pair<pair<int,int>, int>> q;
    
    q.push({{beginX, beginY}, 0});
    visited[beginX][beginY] = true;
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if(x == endX && y == endY){
            return dist;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx <= 100 && ny <= 100 
               && !visited[nx][ny] && grid[nx][ny] == 1){
                
                q.push({{nx,ny}, dist+1});
                visited[nx][ny] = true;
            }
        }
    }
    return 0;    
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    // 1. 속 채우기
    for(int i=0; i<rectangle.size(); i++){
        int min_x = rectangle[i][0] * 2;
        int max_x = rectangle[i][2] * 2;
        int min_y = rectangle[i][1] * 2;
        int max_y = rectangle[i][3] * 2;
        int sub_x, sub_y;
        // x상단 - x하단
        sub_x = rectangle[i][2] - rectangle[i][0];
        
        for(int x=min_x; x<=max_x; x++){
            for(int y=min_y; y<=max_y; y++){
                // 완전 내부인 경우 = 2
                if(min_x < x && x < max_x && min_y < y && y < max_y){
                    grid[x][y] = 2;
                }
                // 선분 테두리인 경우 = 1
                else{
                    if(grid[x][y] != 2) grid[x][y] = 1;

                }
            }
        }
    }
    
    answer = bfs(characterX*2, characterY*2, itemX*2, itemY*2) / 2;

    return answer;
}