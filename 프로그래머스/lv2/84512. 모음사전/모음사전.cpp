#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// A, E, I, O, U 
// 가중치
// A 고정시 -> 1글자 1, 2글자 5 , 3글자 5*5=25, 4글자 5*5*5 = 125, 5글자 625 -> 781
// "AAAAE"	6
// "AAAE"	10
// "I"	1563
// "EIO"	1189

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<int> weights={781, 156, 31, 6, 1};
    vector<char> alphabet={'A', 'E', 'I', 'O', 'U'};

    for(int i=0; i<word.size(); i++){
        int num = find(alphabet.begin(), alphabet.end(), word[i]) - alphabet.begin();
        answer += num * weights[i] + 1;
    }


    return answer;
}