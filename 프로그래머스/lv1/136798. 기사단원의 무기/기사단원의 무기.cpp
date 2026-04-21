#include <string>
#include <vector>
#include <cmath>

using namespace std;

int counting(int num){
    int count = 0;
    
    for(int i=1; i<=sqrt(num); i++){
        if(num%i == 0){
            count += 2;
            if(i == num/i) count --;
        } 
    }
    
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i=1; i<=number; i++){
        if(counting(i) <= limit){
            answer += counting(i);   
        }
        else answer += power;
    }
    
    return answer;
}