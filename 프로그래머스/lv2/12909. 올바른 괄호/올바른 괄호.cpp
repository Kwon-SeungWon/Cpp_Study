#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    
    queue <char> q;
    
    for(int i=0; i<s.size(); i++){
        if(i == 0 && s[i] == ')'){
            return answer;
        }
        if(s[i] == '('){
            q.push(s[i]);
        }
        if(q.front() == '(' && s[i] == ')'){
            q.pop();
        }
    }
    
    if(q.empty()) answer = true;

    return answer;
}