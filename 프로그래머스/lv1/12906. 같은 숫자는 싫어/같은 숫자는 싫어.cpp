#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> s;
    
    for(int i=0; i<arr.size(); i++){
        if(i!=0 && answer.back() == arr[i]){
            continue;
        }
        answer.push_back(arr[i]);
    }
    
    return answer;
}