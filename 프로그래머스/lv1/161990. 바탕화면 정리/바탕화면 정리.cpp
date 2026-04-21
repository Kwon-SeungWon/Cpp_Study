#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int row = wallpaper.size();          // 주어진 벡터에서 행의 개수
    int col = wallpaper[0].size();       // 첫 번째 행에서 열의 개수

    int first_file_row = -1; // 첫 번째 #의 행 인덱스
    int last_file_row = -1;  // 마지막 #의 행 인덱스
    int first_file_col = -1; // 첫 번째 #의 열 인덱스
    int last_file_col = -1;  // 마지막 #의 열 인덱스
    bool find_state = false;
    
    // 첫 번째 # 찾기 (위에서 아래로)
    for(int i = 0; i < row && !find_state; i++) {
        for(int j = 0; j < col; j++) {
            if(wallpaper[i][j] == '#') {
                first_file_row = i;
                find_state = true;
                break;
            }
        }
    }
    
    find_state = false;
    
    // 마지막 # 찾기 (아래에서 위로)
    for(int i = row - 1; i >= 0 && !find_state; i--) {
        for(int j = 0; j < col; j++) {
            if(wallpaper[i][j] == '#') {
                last_file_row = i;
                find_state = true;
                break;
            }
        }
    }

    find_state = false;
    
    // 첫 번째 # 찾기 (왼쪽에서 오른쪽으로)
    for(int i = 0; i < col && !find_state; i++) {
        for(int j = 0; j < row; j++) {
            if(wallpaper[j][i] == '#') {
                first_file_col = i;
                find_state = true;
                break;
            }
        }
    }
    
    find_state = false;
    
    // 마지막 # 찾기 (오른쪽에서 왼쪽으로)
    for(int i = col - 1; i >= 0 && !find_state; i--) {
        for(int j = 0; j < row; j++) {
            if(wallpaper[j][i] == '#') {
                last_file_col = i;
                find_state = true;
                break;
            }
        }
    }

    // 결과값 출력
    cout << first_file_row << ", " << first_file_col << ", " << last_file_row + 1 << ", " << last_file_col + 1 << endl;

    answer.push_back(first_file_row);
    answer.push_back(first_file_col);
    answer.push_back(last_file_row + 1);
    answer.push_back(last_file_col + 1);

    return answer;
}