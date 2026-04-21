#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long consume = 0;
    
    for(int itr=1; itr <= count; itr++){
        consume += price*itr;
    }
    
    if(consume >= money) answer = consume - money;
    else answer = 0;
    
    return answer;
}

int main(){
    
    int p,m,c;
    cin >> p >> m >> c;
    
    solution(p,m,c);
    
    return 0;
}