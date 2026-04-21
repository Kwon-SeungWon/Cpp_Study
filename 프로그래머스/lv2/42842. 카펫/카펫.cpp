#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total_area = brown + yellow;
    
    // 전체 카펫의 세로(h)는 최소 3부터 시작
    for (int h = 3; h * h <= total_area; ++h) {
        
        // 전체 면적이 세로 길이로 나누어 떨어질 때만 (사각 형태가 성립할 때)
        if (total_area % h == 0) {
            int w = total_area / h; // 전체 가로 길이
            
            // 핵심 검증: 내부의 노란색 면적이 일치하는가?
            if ((w - 2) * (h - 2) == yellow) {
                answer.push_back(w);
                answer.push_back(h);
                break; // 정답을 찾으면 즉시 종료
            }
        }
    }
    return answer;
}

// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// vector<int> solution(int brown, int yellow) {
//     vector<int> answer;
//     int min_sub = 9999999;
//     int point;
    
//     for (int i=1; i<=yellow; i++){
//         int a = i;
//         int b;
//         int sub = 0;
        
//         if(yellow % a == 0){
//             b = yellow / a;
//             sub = abs(a-b);
            
//             if(sub < min_sub){
//                 min_sub = sub;
//                 continue;
//             }
//             if(sub == min_sub && a>=b){
//                 point = b;
//                 cout << point << "\n" ;
//                 break;
//             }
//         }
//     }
//     answer.push_back((brown+yellow) / (point+2));
//     answer.push_back(point+2);
//     return answer;
// }













// #include <string>
// #include <vector>
// #include <iostream>

// using namespace std;

// // 6,4 8 4 8 4
// // 8,3 10 3 10 3
// // 4,1 6 6 1 1
// // 소수 판별 및 소인수 분해
// // y는 23 이면 b는 25+25+1+1 = 52 이다
// //2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 

// vector<int> solution(int brown, int yellow) {
//     vector<int> answer;
    
    
    
//     return answer;
// }