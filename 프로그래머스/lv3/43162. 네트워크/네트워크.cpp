#include <string>
#include <vector>

using namespace std;

int dfs(int begin, const vector<vector<int>>& computers, vector<bool>& visited, int n) {
    if (visited[begin]) {
        return 0;
    }

    visited[begin] = true;

    for (int next = 0; next < n; next++) {
        if (computers[begin][next] == 1) {
            dfs(next, computers, visited, n);
        }
    }

    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        answer += dfs(i, computers, visited, n);
    }

    return answer;
}