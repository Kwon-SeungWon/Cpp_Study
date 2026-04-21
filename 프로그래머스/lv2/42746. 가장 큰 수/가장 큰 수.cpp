// string 형변환은 to_string

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


bool comp(int o_a, int o_b){
    string str_a = to_string(o_a);
    string str_b = to_string(o_b);
    
    // 두 숫자를 이어붙여서 비교
    return str_a + str_b > str_b + str_a;
}

string solution(vector<int> numbers) {
    string answer = "";

    // 커스텀 비교 함수를 사용해 정렬
    sort(numbers.begin(), numbers.end(), comp);
    
    // 결과 문자열 생성
    for(int i=0; i<numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    
    // 만약 모든 숫자가 0인 경우 처리 (예: [0, 0, 0]의 경우 "0" 반환)
    if(answer[0] == '0') {
        return "0";
    }
    
    return answer;
}