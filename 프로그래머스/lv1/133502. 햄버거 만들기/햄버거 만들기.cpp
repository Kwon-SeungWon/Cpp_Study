#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> stk; // 스택 사용

    for (int i = 0; i < ingredient.size(); i++) {
        stk.push(ingredient[i]); // 재료를 스택에 추가

        // 스택의 상단 4개 요소가 패턴과 일치하는지 확인
        if (stk.size() >= 4) {
            // 스택의 상단 4개 요소 확인
            if (stk.top() == 1) {
                int d = stk.top(); stk.pop();
                int c = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();

                // 패턴 확인
                if (a == 1 && b == 2 && c == 3 && d == 1) {
                    answer++; // 햄버거 개수 증가
                } else {
                    // 패턴이 아니면 원래 순서대로 다시 추가
                    stk.push(a);
                    stk.push(b);
                    stk.push(c);
                    stk.push(d);
                }
            }
        }
    }

    return answer;
}