#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// + - only, no order change
// 9 7 3 2 2 1 = 14

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int i){
    if(i == numbers.size()){
        if (sum == target){
            answer++;
        }
        return;
    }
    dfs(numbers, target, sum+numbers[i], i+1);
    dfs(numbers, target, sum-numbers[i], i+1);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);
    
    return answer;
}