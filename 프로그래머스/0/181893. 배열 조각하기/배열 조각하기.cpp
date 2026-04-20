#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    
    for(int i = 0; i < query.size(); i++){
        int sub = query[i];
        // // 짝수
        // if(sub % 2 == 0){
        //     for(int j = sub; j < arr.size(); j++){
        //         arr.erase(arr.begin() + sub + 1);
        //     }
        // }
        // else{
        //     for(int j = 0; j < sub; j++){
        //         arr.erase(arr.begin());
        //     }
        // }
        
        if(i % 2 == 0){
            arr.erase(arr.begin() + sub + 1, arr.end());
        }
        else{
            arr.erase(arr.begin(), arr.begin() + sub);
        }
    }
        
    return arr;
}