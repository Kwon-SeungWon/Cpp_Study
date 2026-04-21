#include <vector>
#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    // Definition
    int answer = 0;
    unordered_set <int> us;

    // Insert to Unordered Set
    for (int i=0; i<nums.size(); i++){
        us.insert(nums[i]);
    }
    
    // Judge
    if(us.size() <= nums.size() / 2){
        answer = us.size();
    }
    else{
        answer = nums.size() / 2;
    }
    
    return answer;
}