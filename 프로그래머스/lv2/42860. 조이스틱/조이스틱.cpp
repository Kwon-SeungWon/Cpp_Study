#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// 총 알파벳은 26개
// A
// BCDEFGHIJKLM(앞에서 12번) N(정가운데)
// O(뒤에서 12번) PQRSTYVWXYZ
// 알파벳이 13번 이상 이동해야하면 뒤에서부터 이동하기
// AAA부터 시작
// AAAZABAAAAAAX -> 00010100000010000 ZAAAABAAAAAAAAXAA ZOOM

int solution(string name) {
    int answer = 0;
    int alphabet_size = 26;
    int size = name.size();
    
    // 알파벳 변경 횟수 계산 (위아래 조작)
    for (int i = 0; i < size; ++i) {
        // 'A'에서 목표 문자까지 위쪽 또는 아래쪽으로 가는 최소 횟수 계산
        answer += min(name[i] - 'A', alphabet_size - (name[i] - 'A'));
    }
    
    // 커서 이동 최적화
    int min_move = size - 1;  // 처음엔 일직선으로 끝까지 가는 경우를 기본으로 설정
    
    for (int i = 0; i < size; ++i) {
        int next_idx = i + 1;
        // 연속된 'A' 구간 찾기
        while (next_idx < size && name[next_idx] == 'A') {
            next_idx++;
        }
        // 왼쪽으로 돌아가는 경우와 오른쪽으로 가는 경우를 비교하여 최소 이동 계산
        min_move = min(min_move, i + size - next_idx + min(i, size - next_idx));
    }
    
    answer += min_move;  // 알파벳 변환 횟수에 커서 이동 최적화 결과 더하기
    
    return answer;
}

