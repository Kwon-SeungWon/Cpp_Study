#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>

using namespace std;

//1. 그래프 만들기
//2. dfs로 완전탐색해서 모든 경로 도출
//3. 알파벳 순 정렬이 우선순위

vector<string> answer;
int ticket_size;
bool found{false};

void dfs(string now, 
           vector<vector<string>>& tickets, 
           map<string, vector<string>>& graph, 
           map<string, vector<bool>>& used) 
{
    
    if(answer.size() == ticket_size + 1){
        found = true;
        return;
    }
    
    for(int i=0; i<graph[now].size(); i++){
         
        if(!used[now][i]){
            
            string next = graph[now][i];
            
            used[now][i] = true;
            answer.push_back(next);

            dfs(next, tickets, graph, used);
            
            if(found){
                return;
            }

            used[now][i] = false;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    // graph의 사이즈를 알기 위해 set으로 중복 없이 넣어보기
    set<string> S;
    
    for(auto& t : tickets){
        S.insert(t[0]);
        S.insert(t[1]);
    }
    
    int graph_size = S.size();
    
    map <string, vector<string>> graph;
    map <string, vector<bool>> used;
    
    // Graph 생성
    for(auto& t : tickets){
        string from =t[0];
        string to   =t[1];   
        
        graph[from].push_back(to);
        used[from].push_back(false);
    } 
    
    // Graph 정렬
    for(auto& a : graph){
        sort(a.second.begin(), a.second.end());
    }
    
    // DFS 적용으로 answer 도출
    ticket_size = tickets.size();
    answer.push_back("ICN");
    dfs("ICN", tickets, graph, used);        

    
    // for(auto& a : graph){
    //     cout << a.first << ": ";
    //     for(auto& dest : a.second){
    //         cout << dest << ", ";
    //     }
    //     cout << "\n";
    // }
    
    return answer;
}