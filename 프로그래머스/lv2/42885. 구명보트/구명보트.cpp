#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// first, align and limit calculation
// 30 40 50 50 90 100 (100) 4
// 70 90 95 100 100 (100) 5
// 120 100 100 90 80 80 40 40 20 10(140) -> 6

bool opposite_sort(int &a,int &b){
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // Sort people in descending order
    sort(people.begin(), people.end(), opposite_sort);
    
    int i = 0;                 // Pointer for the heaviest person (from the start)
    int j = people.size() - 1;  // Pointer for the lightest person (from the end)
    
    while (i <= j) {
        // If the heaviest and lightest person together can fit in one boat
        if (people[i] + people[j] <= limit) {
            j--; // Pair the lightest person with the heaviest
        }
        // In either case, the heaviest person gets a boat
        i++;
        answer++;
    }
    
    return answer;
}