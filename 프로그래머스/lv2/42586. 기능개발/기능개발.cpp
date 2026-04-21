#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    while (!progresses.empty()) {   
        
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        
        int count = 0;
        
        while (!progresses.empty() && progresses.front() >= 100) {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            count++;
        }
        
        if (count > 0) {
            answer.push_back(count);
        }
    }
    
    return answer;
}