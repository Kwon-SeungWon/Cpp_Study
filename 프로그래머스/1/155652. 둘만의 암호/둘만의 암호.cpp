#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++){
        int count = 0;
        
        for(int j = 1; j <= index + count; j++){
            int a = (int) s[i] + j;
            
            while(a > 122) a -= 26; 
            
            for(int k = 0; k < skip.size(); k++){
                int b = (int) skip[k];
                
                if(a == b){
                    count++;
                    break; 
                }
            }
        }
        
        int final_val = (int) s[i] + index + count;
        while(final_val > 122) final_val -= 26;
        
        char last_word = (char) final_val;
        answer.push_back(last_word);
    }
    
    return answer;
}