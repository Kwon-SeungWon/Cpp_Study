#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, double>& a, pair<int, double>& b){
    if (a.second == b.second) {
        return a.first < b.first; // 실패율이 같으면 번호가 작은 것이 먼저
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int,double> mTry;
    
    for(int i=1; i<=N; i++){
        int failure_count=0;
        int reached_count=0;
        double failure;
        
        for(int& s: stages){    
            if(i <= s){ // 각 도전자들의 스테이지가 해당 스테이지 번호보다 높을 때 count ++
                reached_count++; 
                
                if(i == s){ // 그 와중에 같으면 실패 count++
                    failure_count++;
                }
            }
        }
        if(reached_count == 0){
            failure = 0.0;
        }
        else failure = (double) failure_count / reached_count;
        // cout << failure << "\n";
        
        mTry[i]=failure;
    }
    
    vector<pair<int, double>> vTry (mTry.begin(), mTry.end());
            
    sort(vTry.begin(), vTry.end(), compare);

    for(auto& v : vTry){
        cout << v.first << ", " << v.second << "\n";
        answer.push_back(v.first);
    }
        
    return answer;
}















// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// bool desc(pair<int,double> &v1, pair<int,double>  &v2){
//     if(v1.second == v2.second){
//         return v1.first < v1.first;
//     }
//     else return v1.second > v2.second;
// }

// vector<int> solution(int N, vector<int> stages) {
    
//     vector<pair<int,double>> V_failure;
//     vector<int> answer;
    
//     sort(stages.begin(), stages.end());
 	
// //  	for(int i=0; i<stages.size(); i++){
        
// //         cout << stages[i] << "\t";
// //     }
// //    cout << "\n";
    
//     for(int stage_number =1; stage_number <= N; stage_number++){
//         int count = 0;
//         int whole_person = stages.size();
        
//         // if(stage_number == N){
//         //     if(stage_number < stages[i])
//         // }
        
//         for(int i=0; i<stages.size(); i++){
//             if(stage_number == stages[i]){
//                 stages.erase(stages.begin());
//                 i--;
//                 count += 1;
//             }    
//         }
        
//         double fail_percent = (double)count / whole_person;
//         // for(int i=0; i<stages.size(); i++){
//         //     cout << stages[i] << "\t";
//         // }
//         // cout << "\n";
//         // cout << count << "\t"<< whole_person << "\t" <<fail_percent << "\n";
//         V_failure.push_back({stage_number, fail_percent});
//     }
    
    
//     sort(V_failure.begin(), V_failure.end(), desc);
    
//     for(int i=0; i<N; i++){
//     	auto p = V_failure[i];
//     	answer.push_back(p.first);
//     }
    
    
    
//     return answer;
// }