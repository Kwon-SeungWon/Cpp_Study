#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare (int a, int b){
    
    if(a < b) return false;
    return true;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
//     for(int i=0; i < sizes.size(); i++){
//         if(compare(sizes[i][0], sizes[i][1])){
//             int temp = sizes[i][0];
//             int temp2 = sizes[i][1];
            
//             sizes[i][0] = temp2;
//             sizes[i][1] = temp;
//         }   
//     }
    
    // Swap 사용
    for(auto& size: sizes){
        if(size[0] > size[1]){
            swap(size[0], size[1]);
        }
    }
    
    sort(sizes.begin(), sizes.end());
    
    int w = sizes[(sizes.size()-1)][0];
    
    int h = 0;
    for(int i=0; i<sizes.size(); i++){
        h = max(h, sizes[i][1]);
    }
    
    answer = w * h;
    
    return answer;
}