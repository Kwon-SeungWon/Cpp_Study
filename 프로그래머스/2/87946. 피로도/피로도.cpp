#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[8] = {false,};
int max_dungeons = 0;

void dfs(int current_k, int depth, const vector<vector<int>>& dungeons) {
    max_dungeons = max(max_dungeons, depth);

    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && current_k >= dungeons[i][0]) {
            
            visited[i] = true;
            
            dfs(current_k - dungeons[i][1], depth + 1, dungeons);
            
            // BackTracking!!!
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, 0, dungeons);
    return max_dungeons;
}



//#include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int solution(int k, vector<vector<int>> dungeons) {
//     int answer = -1;

//     // sort(dungeons.begin(),dungeons.end());

//     do{
//         int tmpK = k;
//         int visited = 0;
//         for(int i = 0; i<dungeons.size(); i++){
//             if(dungeons[i][0] <= tmpK){
//                 visited++;
//                 tmpK -= dungeons[i][1];
//             }
//         }
//         answer = max(answer, visited);
//     }while(next_permutation(dungeons.begin(),dungeons.end()));

//     return answer;
// }