#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int dsize = dots.size();
    
    int a_1, b_1 , a_2, b_2;
    double g_1 = 99999.0;
    double g_2 = 99999.0;
    
    for(int i=1; i<=dsize-1; i++){
        a_1 = dots[0][0] - dots[i][0];
        b_1 = dots[0][1] - dots[i][1];
        g_1 = (double) b_1 / a_1;
        
        
        if(i==1){
            a_2 = dots[i+1][0] - dots[i+2][0];
            b_2 = dots[i+1][1] - dots[i+2][1];
        }
        else if(i==2){
            a_2 = dots[i-1][0] - dots[i+1][0];
            b_2 = dots[i-1][1] - dots[i+1][1];
        }
        else if(i==3){
            a_2 = dots[i-1][0] - dots[i-2][0];
            b_2 = dots[i-1][1] - dots[i-2][1];
        }
        
        g_2 = (double) b_2 / a_2;
        
        if(g_1 == g_2 && (g_1 != 99999.0 || g_2 != 99999.0)){
            answer = 1;
            return answer;    
        }
    }
    
    return answer;
}