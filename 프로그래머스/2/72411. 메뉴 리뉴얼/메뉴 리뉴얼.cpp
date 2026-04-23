#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// [변경점 1] current_comb에 '&'를 붙여서 모든 분신이 하나의 원본을 공유하게 만듭니다.
void dfs(const string& order, int course_len, int start, string& current_comb, map<string, int>& menu) {
    
    // 종료 조건은 똑같습니다.
    if (current_comb.length() == course_len) {
        menu[current_comb]++;
        return;
    }

    for (int i = start; i < order.size(); i++) {
        
        // --- 전진 ---
        // [변경점 2] 배낭에 이번 알파벳을 직접 집어넣습니다.
        current_comb.push_back(order[i]);
        
        // --- 재귀 (분신술) ---
        // 이미 current_comb 안에 글자를 넣었으므로, 덧셈 없이 그냥 넘깁니다.
        dfs(order, course_len, i + 1, current_comb, menu);
        
        // --- 후진 (상태 복구) ---
        // [변경점 3] 분신이 튕겨져 돌아왔으니, 방금 넣었던 알파벳을 다시 빼냅니다.
        current_comb.pop_back(); 
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }
    
    for (int course_len : course) {
        map<string, int> menu;
        
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i].length() >= course_len) {
                // [변경점 4] 빈 배낭을 하나 만들어서 참조(&)로 넘겨줍니다.
                string empty_backpack = ""; 
                dfs(orders[i], course_len, 0, empty_backpack, menu);
            }
        }
        
        int max_count = 0;
        for (auto& item : menu) {
            max_count = max(max_count, item.second);
        }
        
        if (max_count >= 2) {
            for (auto& item : menu) {
                if (item.second == max_count) {
                    answer.push_back(item.first);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}

// #include <string>
// #include <vector>
// #include <map>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// // [2단계] DFS 백트래킹 (조합 뽑기)
// // order: 손님 주문 (예: "ABC")
// // course_len: 뽑아야 할 길이
// // start: 중복 방지를 위해 앞으로만 전진하는 인덱스
// // current_comb: 지금까지 뽑은 조합
// void dfs(const string& order, int course_len, int start, string current_comb, map<string, int>& menu) {
//     // 목표 길이에 도달하면 맵에 횟수(Value)를 1 증가시키고 리턴
//     if (current_comb.length() == course_len) {
//         menu[current_comb]++;
//         return;
//     }

//     // start부터 끝까지만 탐색 (visited 배열이 필요 없는 이유!)
//     for (int i = start; i < order.size(); i++) {
//         dfs(order, course_len, i + 1, current_comb + order[i], menu);
//     }
// }

// vector<string> solution(vector<string> orders, vector<int> course) {
//     vector<string> answer;
    
//     // [1단계] 모든 주문을 알파벳 오름차순으로 정렬 ("XW" -> "WX")
//     // 이 작업을 해야 나중에 "WX"와 "XW"가 다른 조합으로 인식되는 대참사를 막습니다.
//     for (int i = 0; i < orders.size(); i++) {
//         sort(orders[i].begin(), orders[i].end());
//     }
    
//     // 코스 요리 길이(2개, 3개, 4개...)별로 하나씩 처리
//     for (int course_len : course) {
//         // [3단계] 맵 선언 (코스 길이가 바뀔 때마다 백지상태의 새로운 맵 사용)
//         map<string, int> menu;
        
//         // 모든 손님의 주문을 하나씩 꺼내서 조합 뽑기
//         for (int i = 0; i < orders.size(); i++) {
//             // 손님이 시킨 요리 개수가 우리가 만들 코스 길이보다 길거나 같을 때만 조합 가능
//             if (orders[i].length() >= course_len) {
//                 dfs(orders[i], course_len, 0, "", menu);
//             }
//         }
        
//         // [4단계] 1등만 골라내기
//         int max_count = 0;
        
//         // 4-1. 맵을 쭉 훑으며 가장 많이 주문된 횟수(최댓값) 찾기
//         for (auto& item : menu) {
//             max_count = max(max_count, item.second);
//         }
        
//         // 4-2. 최댓값이 2번 이상이라면 정답 배열에 쓸어 담기 (공동 1등 포함)
//         if (max_count >= 2) {
//             for (auto& item : menu) {
//                 if (item.second == max_count) {
//                     answer.push_back(item.first); // item.first는 문자열(Key)
//                 }
//             }
//         }
//     }
    
//     // [마무리] 문제 조건: "정답은 사전 순으로 오름차순 정렬해서 return 해주세요."
//     sort(answer.begin(), answer.end());
    
//     return answer;
// }