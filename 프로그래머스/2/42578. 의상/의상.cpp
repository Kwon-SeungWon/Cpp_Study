#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int dfsCount(const vector<int>& counts, int idx) {
    if (idx == (int)counts.size()) {
        return 1; // 현재 선택 조합 1개
    }

    int total = 0;

    // 이 종류에서 아무것도 안 입는 경우 1개
    total += dfsCount(counts, idx + 1);

    // 이 종류에서 옷 하나를 입는 경우 counts[idx]개
    for (int i = 0; i < counts[idx]; i++) {
        total += dfsCount(counts, idx + 1);
    }

    return total;
}

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> category_count;
    for (const auto& cloth : clothes) {
        category_count[cloth[1]]++;
    }

    vector<int> counts;
    for (const auto& item : category_count) {
        counts.push_back(item.second);
    }

    int all_cases = dfsCount(counts, 0);
    return all_cases - 1; // 아무것도 안 입는 경우 제외
}