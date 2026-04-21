#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int n){
    
    if(n<=1) return false;
    
    for(int i=2; i*i<=n; i++){
        if(n % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    
    set <int> s;
    
    do{
        for(int i=0; i<numbers.size(); i++){
            if(isPrime(stoi(numbers.substr(0, i+1)))){
                s.insert(stoi(numbers.substr(0, i+1)));
            }
        }
    }while (next_permutation(numbers.begin(), numbers.end()));
    
    return s.size();
}