#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    // sort(dungeons.begin(),dungeons.end());

    do{
        int tmpK = k;
        int visited = 0;
        for(int i = 0; i<dungeons.size(); i++){
            if(dungeons[i][0] <= tmpK){
                visited++;
                tmpK -= dungeons[i][1];
            }
        }
        answer = max(answer, visited);
    }while(next_permutation(dungeons.begin(),dungeons.end()));

    return answer;
}