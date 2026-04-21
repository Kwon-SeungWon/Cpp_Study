#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 뒤에 k개를 가림
// 뽑기
// 883911999 5

string solution(string number, int k) {
    string answer = "";
    int index = 0;
    int n_index = 0;
    int whole_i = number.size() - k;
    int flag = 0;
    
    for(int j=0; j<whole_i; j++){
        int num = 0;
        for(int i = index;  i <= k+j; i++){
            if(num < number[i]){
                num = number[i];
                index = i+1;
            }
        }
        answer.push_back(num);
    }
    return answer;
}