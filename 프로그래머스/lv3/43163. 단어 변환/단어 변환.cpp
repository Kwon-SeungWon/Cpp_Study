#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// String 내부 탐색이 머였지?
// -> find(words.begin(), words.end(), target) == words.end()

// Vector 특정 원소 지우기
// words.erase(words.begin() + i);

bool compare(string current, string given, int words_size){
    int letter_size = current.size();
    int count = 0;
    
    for(int i = 0; i < letter_size; i++){
        string c = current.substr(i,1);
        string g = given.substr(i,1);
        
        if(c == g){
            count ++;        
        }
    }
    
    if(count == letter_size - 1){
        cout << "바꿀 수 있음!" << "\n";
        return true;
    }
    else{
        return false;
    }
}

int bfs(string begin, string target, const vector<string>& words){
    int words_size = words.size();
    // Initialize visited vector
    vector<bool> visited(words_size, false);    
    queue<pair<string, int>> q;
    
    q.push({begin, 0});
    
    while(!q.empty()){
        string current = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if(current == target)
            return depth;
        
        for(int i = 0; i < words_size; i++){
            if(!visited[i] && compare(current, words[i], words_size)){
                visited[i] = true;
                q.push({words[i], depth + 1});
            }
        }
    }
    
    return 0;
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int words_size = words.size();
    string current;
    
    // No words for Target
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    
    return bfs(begin, target, words);
}