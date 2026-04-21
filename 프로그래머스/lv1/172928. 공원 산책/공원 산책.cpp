#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// 2차원 벡터 정의
// vector<vector<int>> V;

// 문자열 자르기 -> substr(시작) / substr(시작, 길이)
// 문자열 -> 정수 -> stoi (실패 시 예외 가능)
// 부분 찾기 -> find, 없으면 string::npos

// 격자 -> vector<string> (행 하나 = string, park[r][c] = 한 칸)
// 읽기만 -> const vector<T>& (복사 X, & 없이 넘김)
// 크기 -> size(), 비었음 -> empty()
// 빈 vector 반환 -> 이동 실패 / 명령 무시


vector<vector<int>> moving(const vector<string>& park, string moving_direction, int moving_count,
                           int robot_dog_row, int robot_dog_col)
{
    vector<vector<int>> result;

    if (park.empty()) {
        return result;
    }

    const int num_rows = static_cast<int>(park.size());

    for (int i = 0; i < moving_count; i++) {
        if (moving_direction == "E") {
            robot_dog_col += 1;
        } else if (moving_direction == "W") {
            robot_dog_col -= 1;
        } else if (moving_direction == "N") {
            robot_dog_row -= 1;
        } else if (moving_direction == "S") {
            robot_dog_row += 1;
        }

        if (robot_dog_row < 0 || robot_dog_row >= num_rows) {
            return result;
        }
        const int num_cols = static_cast<int>(park[robot_dog_row].size());
        if (robot_dog_col < 0 || robot_dog_col >= num_cols) {
            return result;
        }
        if (park[robot_dog_row][robot_dog_col] == 'X') {
            return result;
        }
    }

    result.push_back({robot_dog_row, robot_dog_col});
    return result;
}


vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    // 이차원 vector 메모 할 것
    // vector <vector<string>> map;
    
    int start_row = 0;
    int start_col = 0;
    
    for (int i = 0; i < park.size(); i++){
        
        size_t start_pos = park[i].find('S');
        
        if(start_pos != string::npos){
            start_row = i;
            start_col = start_pos;
            break;
        }
    }
    
    
    string direction;
    int move_count;
    int current_row = start_row;
    int current_col = start_col;
    
    for (int i=0; i<routes.size(); i++){
        
        direction = routes[i].substr(0, 1);
        move_count = stoi(routes[i].substr(2));

        vector<vector<int>> next_pos =
            moving(park, direction, move_count, current_row, current_col);
        if (!next_pos.empty()) {
            current_row = next_pos[0][0];
            current_col = next_pos[0][1];
        }
    }

    answer.push_back(current_row);
    answer.push_back(current_col);
    return answer;
}
