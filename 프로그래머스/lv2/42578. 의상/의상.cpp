#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// 종류 + 1 * 개수 - 1
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, vector<string>> C;
    
    for(auto& c : clothes){
        // cout << c[0] << "," << c[1] << "\n";
        C[c[1]].push_back(c[0]);
    }
    
    for(auto& a : C){
        answer *= (a.second.size() + 1);  
        // cout << "개수: " << a.second.size() << "\n";
    }
    
    answer--;
    
    return answer;
}   