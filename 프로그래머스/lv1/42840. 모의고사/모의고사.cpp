#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

// 21212 1번은 0 2번은 4 3번은 2
// 수1은 5번마다 반복, 수2는 8, 수3은 10
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> result;
    
    vector<int> n1 = {1, 2, 3, 4, 5}; // 5번마다 반복
    vector<int> n2 = {2, 1, 2, 3, 2, 4, 2, 5}; // 8번마다 반복
    vector<int> n3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 10번마다 반복
    
    int count1 = 0, count2 = 0, count3 = 0; // 각각의 정답 개수를 셀 변수
    
    // 정답과 비교하며 각 사람의 정답 개수를 카운팅
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == n1[i % n1.size()]) count1++;
        if(answers[i] == n2[i % n2.size()]) count2++;
        if(answers[i] == n3[i % n3.size()]) count3++;
    }
    
    // 가장 많이 맞춘 사람 찾기
    int max_correct = max({count1, count2, count3});
    
    // 가장 많이 맞춘 사람을 결과에 추가
    if(count1 == max_correct) result.push_back(1);
    if(count2 == max_correct) result.push_back(2);
    if(count3 == max_correct) result.push_back(3);
    
    return result;
}