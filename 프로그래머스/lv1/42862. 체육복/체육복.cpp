#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i = 0; i < lost.size(); i++) {
        for(int j = 0; j < reserve.size(); j++) {
            if(lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                break;
            }
        }
    }
    
    answer = n - lost.size();

    
    for(int i=0; i<lost.size(); i++){
        int rsize = reserve.size();
        if(rsize == 0){
            break;
        }
        for(int j=0; j<rsize; j++){
            if(reserve[j] + 1 == lost[i] ||
               reserve[j] - 1 == lost[i]){
                reserve.erase(reserve.begin() + j);
                answer++;
                break;
            }
        }
    }
    
    return answer;
}