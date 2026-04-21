#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    
    int h_index = 0;
    
    for (int i = 0; i < citations.size(); i++) {
        int rank = i + 1; 
        
        if (citations[i] >= rank) {
            h_index = rank; 
        } 
        else {
            break; 
        }
    }
    
    return h_index; 
}