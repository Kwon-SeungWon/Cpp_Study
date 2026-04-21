#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>  // INT_MAX를 사용하기 위한 헤더
#include <queue>    // BFS를 위한 큐

using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int answer = INT_MAX;  // 초기값을 매우 큰 값으로 설정 (최소값을 찾기 위함)

void bfs(vector<vector<int>> &maps, vector<vector<bool>> &visited, int row, int col) {
    queue<pair<pair<int, int>, int>> q;  // 큐에 좌표와 이동 거리를 함께 저장
    q.push({{row, col}, 1});  // 시작 좌표와 초기 거리 1
    visited[row][col] = true;  // 시작 지점 방문 처리

    while (!q.empty()) {
        int curr_row = q.front().first.first;
        int curr_col = q.front().first.second;
        int count = q.front().second;  // 현재까지 이동한 거리
        q.pop();

        // 도착 지점에 도달했을 때 최단 경로 확인
        if (curr_row == maps.size() - 1 && curr_col == maps[0].size() - 1) {
            answer = count;
            return;  // 최단 경로를 찾았으므로 즉시 종료
        }

        // 상하좌우로 이동
        for (int i = 0; i < 4; i++) {
            int new_row = curr_row + dy[i];
            int new_col = curr_col + dx[i];

            // 유효한 좌표 내에 있고, 방문하지 않았으며 길이 있는 경우
            if (new_row >= 0 && new_col >= 0 && new_row < maps.size() && new_col < maps[0].size()) {
                if (!visited[new_row][new_col] && maps[new_row][new_col] == 1) {
                    visited[new_row][new_col] = true;  // 방문 처리
                    q.push({{new_row, new_col}, count + 1});  // 다음 경로와 거리를 큐에 삽입
                }
            }
        }
    }
}

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));  // 방문 여부 체크

    bfs(maps, visited, 0, 0);  // BFS 시작

    return answer == INT_MAX ? -1 : answer;  // 경로가 없으면 -1 반환
}
