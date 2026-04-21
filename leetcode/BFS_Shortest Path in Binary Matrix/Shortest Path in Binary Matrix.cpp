#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    struct Node {
        int x;
        int y;
        int dist;
    };

    int dx[8] = {-1,1,0,0,-1,1,1,-1};
    int dy[8] = {0,0,-1,1,1,-1,1,-1};
    vector<vector<bool>> visited{101, vector<bool>(101,false)};

    int bfs(vector<vector<int>>& graph, int startX, int startY, int endX, int endY){
        if(graph[startX][startY] != 0 ||
           graph[endX][endY] != 0 ){
            return -1;
        }

        queue<Node> q;
        q.push({startX, startY, 1});
        visited[startX][startY] = true;

        while(!q.empty()){
            Node current = q.front();
            q.pop();

            int cx = current.x;
            int cy = current.y;
            int cdist = current.dist;

            if(cx == endX && cy == endY){
                return cdist;
            }

            for(int i=0; i<8; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx >= 0 && ny >= 0 && nx < graph.size() && ny < graph.size()){
                    if(!visited[nx][ny] && graph[nx][ny] == 0){
                        visited[nx][ny] = true;
                        q.push({nx, ny, cdist + 1});
                    }
                }
            }
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int answer;
        int startX, startY;
        int targetX, targetY;

        startX = 0;
        startY = 0;
        targetX = grid.size() - 1;
        targetY = grid.size() - 1;

        answer = bfs(grid, startX, startY, targetX, targetY);

        return answer;
    }
};