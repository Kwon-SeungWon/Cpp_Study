# 알고리즘 복습 루틴과 핵심 개념 정리

## 목표

이 문서는 현재 레포를 기준으로 한 번에 복습할 수 있는 통합 가이드입니다.

- 반복해서 등장한 핵심 알고리즘 개념
- 자주 쓰는 C++ 문법/구현 패턴
- 실전형 일간/주간 복습 루틴
- 재풀이할 때 쓰는 공통 풀이 템플릿

---

## 1) 복습 핵심 개념

### 1.1 BFS 최단거리

대표 파일:

- `leetcode/BFS_Shortest Path in Binary Matrix/Shortest Path in Binary Matrix.cpp`
- `프로그래머스/lv2/1844. 게임 맵 최단거리/게임 맵 최단거리.cpp`
- `프로그래머스/2/159993. 미로 탈출/미로 탈출.cpp`

핵심 포인트:

- `queue`로 레벨 순회(너비 우선 확장) 진행
- 큐에 `(x, y, dist)`를 넣거나 레벨 단위로 거리 계산
- 큐에 넣는 순간 `visited` 처리해서 중복 방문 방지
- 도착점 최초 도달 시 즉시 반환(최단거리 보장)
- 경계 조건과 벽(막힌 칸) 체크를 항상 먼저 수행

복잡도 패턴:

- 시간: `O(V + E)` (격자형 문제는 보통 `O(n*m)`)
- 공간: `O(n*m)` (큐 + 방문 배열)

---

### 1.2 DFS / 백트래킹

대표 파일:

- `프로그래머스/lv2/43165. 타겟 넘버/타겟 넘버.cpp`
- `프로그래머스/lv3/43164. 여행경로/여행경로.cpp`
- `프로그래머스/2/72411. 메뉴 리뉴얼/메뉴 리뉴얼.cpp`

핵심 포인트:

- 종료 조건(base case)을 가장 먼저 검사
- 선택 -> 재귀 -> 복구(`push_back` -> `dfs` -> `pop_back`) 패턴 유지
- `visited`/`used` 상태를 일관되게 관리
- 전역 변수 사용 시 문제 시작 전에 반드시 초기화

#### 레포 기준: "DFS로 무엇을 구하나?" 1줄 매핑

- `프로그래머스/lv2/43165. 타겟 넘버/타겟 넘버.cpp`
  - 구하는 것: **조건을 만족하는 식의 개수(경우의 수 count)**  
  - DFS 역할: `+/-` 두 갈래를 끝까지 탐색해서 `sum == target` 개수 누적

- `프로그래머스/lv3/43164. 여행경로/여행경로.cpp`
  - 구하는 것: **가능한 경로 중 사전순 우선 조건을 만족하는 실제 경로(path)**
  - DFS 역할: 티켓 사용 여부를 백트래킹하면서 경로를 구성, 유효 경로 찾으면 조기 종료

- `프로그래머스/2/72411. 메뉴 리뉴얼/메뉴 리뉴얼.cpp`
  - 구하는 것: **코스 길이별 조합 빈도(count)**
  - DFS 역할: 주문 문자열에서 조합을 생성해 맵 카운팅

- `프로그래머스/2/87946. 피로도/피로도.cpp`
  - 구하는 것: **탐험 가능한 최대 던전 수(max)**
  - DFS 역할: 방문 순서를 바꿔가며 완전탐색, `max_dungeons` 갱신

- `프로그래머스/lv2/86971. 전력망을 둘로 나누기/전력망을 둘로 나누기.cpp`
  - 구하는 것: **간선을 하나 끊었을 때 한쪽 컴포넌트 크기(size)**
  - DFS 역할: 특정 간선을 무시하고 연결된 노드 수를 세어 차이 최소화

- `프로그래머스/lv3/43162. 네트워크/네트워크.cpp`
  - 구하는 것: **연결 요소 개수(component count)**
  - DFS 역할: 아직 방문 안 한 노드에서 한 번씩 쭉 퍼져서 네트워크 묶음 개수 계산

요약:

- DFS는 "경로의 가지 수만" 세는 게 아니라,
  - `count(개수)`,
  - `path(경로 자체)`,
  - `max/min(최적값)`,
  - `size/component(구조 정보)`까지 모두 구할 수 있습니다.

---

### 1.3 그리디 + 정렬

대표 파일:

- `프로그래머스/lv2/181188. 요격 시스템/요격 시스템.cpp`
- `프로그래머스/lv2/42885. 구명보트/구명보트.cpp`
- `프로그래머스/lv2/42747. H－Index/H－Index.cpp`

핵심 포인트:

- 정렬 후 로컬 최적 선택을 반복
- 최소/최대 짝짓기에는 투포인터가 매우 유용
- 기본 정렬로 부족하면 comparator를 직접 작성
- "로컬 최적이 왜 전체 최적이 되는지"를 말로 설명할 수 있어야 함

---

### 1.4 문자열 / 접두어 / 순열

대표 파일:

- `프로그래머스/lv2/42577. 전화번호 목록/전화번호 목록.cpp`
- `프로그래머스/lv2/42839. 소수 찾기/소수 찾기.cpp`

핵심 포인트:

- 정렬 후 접두어 검사(`find(prefix) == 0`)
- `substr`, `stoi`, `find`의 동작을 정확히 이해
- 순열 문제는 `sort` + `next_permutation` 조합을 우선 검토
- 중복 제거에는 `set` 활용

---

### 1.5 해시 / 맵 카운팅

대표 파일:

- `프로그래머스/lv2/42578. 의상/의상.cpp`
- `프로그래머스/lv1/42889. 실패율/실패율.cpp`

핵심 포인트:

- 빠른 빈도 집계는 `unordered_map`
- 키 정렬이 필요하면 `map`
- 카운팅 + 조합 계산(`(count + 1)` 형태)을 자주 사용

---

### 1.6 투포인터 / 슬라이딩 윈도우

대표 문제 감각:

- 정렬된 배열에서 합/차이 조건 만족 쌍 찾기
- 연속 부분 구간의 합/길이/최댓값 찾기

핵심 포인트:

- 구간 문제는 `left`, `right`의 이동 조건을 명확히 분리
- "조건 만족 시 줄일지, 늘릴지" 규칙을 먼저 문장으로 정의
- 정렬 + 양끝 포인터는 그리디와 같이 자주 등장

미니 예시:

```cpp
int left = 0, right = arr.size() - 1;
while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) return 1;
    if (sum < target) left++;
    else right--;
}
```

---

### 1.7 누적합 / 구간합

대표 문제 감각:

- "구간 [l, r]의 합을 빠르게 여러 번 구하라"
- "특정 구간 조건을 만족하는 개수 세기"

핵심 포인트:

- `prefix[i] = 0..i-1 합` 형태로 정의하면 계산 실수가 줄어듦
- 구간합은 `prefix[r + 1] - prefix[l]`
- 인덱스 기준(0-based / 1-based)을 한 번 정하면 끝까지 고정

미니 예시:

```cpp
vector<int> prefix(n + 1, 0);
for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + arr[i];
}
int range_sum = prefix[r + 1] - prefix[l];
```

---

### 1.8 이진 탐색 (결정 문제 포함)

대표 문제 감각:

- 정렬 배열에서 값 찾기
- "가능/불가능"이 단조성을 가지는 최적값 찾기

핵심 포인트:

- 경계(`lo`, `hi`)와 종료 조건(`lo <= hi`)을 일관되게 유지
- 중간값 계산은 `mid = lo + (hi - lo) / 2`
- 결정 문제는 `check(mid)`를 기준으로 구간을 줄임

미니 예시:

```cpp
int lo = 0, hi = n - 1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) lo = mid + 1;
    else hi = mid - 1;
}
return -1;
```

---

## 2) 자주 쓰는 C++ 문법 패턴

### 2.1 컨테이너 선언

자주 쓰는 선언 + 실전 예시를 함께 기억하면 훨씬 빨라집니다.

#### `vector<vector<bool>> visited(n, vector<bool>(m, false));`

언제 쓰나:

- 격자 BFS/DFS에서 방문 여부 체크

예시:

```cpp
int n = grid.size();
int m = grid[0].size();
vector<vector<bool>> visited(n, vector<bool>(m, false));

visited[0][0] = true;
```

주의:

- 입력 크기 기반으로 생성해야 함 (`101x101` 고정 X)

#### `queue<pair<int, int>> q;`

언제 쓰나:

- 좌표만 필요한 BFS

예시:

```cpp
queue<pair<int, int>> q;
q.push({0, 0});

while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
}
```

#### `queue<Node> q;`

언제 쓰나:

- 좌표 + 거리 + 상태(예: 벽 부순 횟수)처럼 정보가 많을 때

예시:

```cpp
struct Node {
    int x;
    int y;
    int dist;
};

queue<Node> q;
q.push({0, 0, 1});
```

#### `unordered_map<string, int> freq;`

언제 쓰나:

- 문자열/숫자 빈도 카운팅

예시:

```cpp
unordered_map<string, int> freq;
for (const string& name : names) {
    freq[name]++;
}
```

주의:

- 키 순서가 필요하면 `map` 사용

#### `set<int> uniq;`

언제 쓰나:

- 중복 제거 + 자동 정렬이 필요할 때

예시:

```cpp
set<int> uniq;
for (int x : nums) uniq.insert(x);

int unique_count = uniq.size();
```

### 2.2 정렬

#### 오름차순

```cpp
sort(v.begin(), v.end());
```

예시:

```cpp
vector<int> v = {4, 1, 3, 2};
sort(v.begin(), v.end()); // 1 2 3 4
```

#### 내림차순

```cpp
sort(v.begin(), v.end(), greater<int>());
```

예시:

```cpp
vector<int> v = {4, 1, 3, 2};
sort(v.begin(), v.end(), greater<int>()); // 4 3 2 1
```

#### 사용자 정의 정렬

문장으로 기준을 먼저 적고 코드로 옮기면 실수가 줄어듭니다.

- 1순위: 점수(score) 내림차순
- 2순위: 이름(name) 오름차순

```cpp
struct Player {
    string name;
    int score;
};

bool cmp(const Player& a, const Player& b) {
    if (a.score == b.score) return a.name < b.name;
    return a.score > b.score;
}

sort(players.begin(), players.end(), cmp);
```

### 2.3 문자열 처리

#### 벡터 포함 여부

```cpp
auto it = find(words.begin(), words.end(), target);
bool exists = (it != words.end());
```

#### 접두어 검사

```cpp
bool is_prefix = (s2.find(s1) == 0); // s1이 s2의 prefix인지
```

예시:

```cpp
string s1 = "119";
string s2 = "1195524421";
bool is_prefix = (s2.find(s1) == 0); // true
```

#### 부분 문자열

```cpp
string part = s.substr(pos, len);
```

예시:

```cpp
string s = "ABCDE";
string part = s.substr(1, 3); // "BCD"
```

#### 문자열 -> 정수

```cpp
int x = stoi(str);
```

예시:

```cpp
string str = "2026";
int year = stoi(str); // 2026
```

주의:

- `stoi`는 숫자가 아닌 문자를 만나면 예외가 발생할 수 있음
- `substr(pos, len)`의 두 번째 인자는 "끝 인덱스"가 아니라 "길이"

### 2.4 재귀 템플릿

```cpp
void dfs(State& st, int depth) {
    if (isBaseCase(st, depth)) {
        // 정답 처리
        return;
    }

    for (auto& choice : choices(st)) {
        applyChoice(st, choice);
        dfs(st, depth + 1);
        rollbackChoice(st, choice);
    }
}
```

실전 예시(타겟 넘버 스타일):

```cpp
int answer = 0;

void dfs(const vector<int>& numbers, int target, int idx, int sum) {
    if (idx == (int)numbers.size()) {
        if (sum == target) answer++;
        return;
    }

    dfs(numbers, target, idx + 1, sum + numbers[idx]);
    dfs(numbers, target, idx + 1, sum - numbers[idx]);
}
```

포인트:

- 종료 조건을 인덱스 끝으로 두면 상태가 명확해짐
- 재귀 파라미터는 "현재 상태를 완전히 표현"해야 함

---

### 2.4-1 백트래킹 집중 정리

재귀와 백트래킹의 차이:

- 재귀: 문제를 작은 문제로 호출하는 "구조"
- 백트래킹: 재귀 과정에서 "불필요한 경로를 가지치기"하고, 상태를 복구하는 "전략"

핵심 흐름(고정 패턴):

1. 종료 조건 확인
2. 가능한 선택지 순회
3. 선택 반영 (`push`, `mark`)
4. 재귀 호출
5. 상태 복구 (`pop`, `unmark`)

#### 조합(Combination) 템플릿

```cpp
vector<vector<int>> result;
vector<int> path;

void backtrackCombine(const vector<int>& nums, int start, int k) {
    if ((int)path.size() == k) {
        result.push_back(path);
        return;
    }

    for (int i = start; i < (int)nums.size(); i++) {
        path.push_back(nums[i]);                 // 선택
        backtrackCombine(nums, i + 1, k);       // 다음 인덱스부터
        path.pop_back();                         // 복구
    }
}
```

언제 쓰나:

- 순서가 중요하지 않은 선택 문제 (`nCk`, 메뉴 조합 등)

#### 순열(Permutation) 템플릿

```cpp
vector<vector<int>> result_perm;
vector<int> path_perm;
vector<bool> used;

void backtrackPermute(const vector<int>& nums) {
    if ((int)path_perm.size() == (int)nums.size()) {
        result_perm.push_back(path_perm);
        return;
    }

    for (int i = 0; i < (int)nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;                          // 선택
        path_perm.push_back(nums[i]);
        backtrackPermute(nums);
        path_perm.pop_back();                    // 복구
        used[i] = false;                         // 복구
    }
}
```

언제 쓰나:

- 순서가 중요한 배치/나열 문제 (`n!` 탐색)

#### 가지치기(Pruning) 예시

```cpp
void dfs(const vector<int>& nums, int idx, int sum, int target) {
    // 남은 수를 전부 더해도 target 도달 불가라면 가지치기 (예시)
    if (sum > target) return;

    if (idx == (int)nums.size()) {
        // 정답 처리
        return;
    }

    dfs(nums, idx + 1, sum + nums[idx], target);
    dfs(nums, idx + 1, sum, target);
}
```

가지치기 포인트:

- "이 경로는 더 가도 정답 불가능"을 빠르게 판단
- 조건이 강할수록 시간 단축 효과가 큼

백트래킹 실수 체크:

- `pop_back` 또는 `used[i] = false` 복구 누락
- 종료 조건보다 늦게 검증해서 불필요한 호출 증가
- 전역 결과 벡터 초기화 누락
- 중복 원소가 있는 문제에서 중복 결과 제거 로직 누락

---

### 2.5 BFS 템플릿 (격자)

```cpp
queue<pair<pair<int, int>, int>> q; // ((x, y), dist)
vector<vector<bool>> visited(n, vector<bool>(m, false));

q.push({{sx, sy}, 1});
visited[sx][sy] = true;

while (!q.empty()) {
    int x = q.front().first.first;
    int y = q.front().first.second;
    int dist = q.front().second;
    q.pop();

    if (x == tx && y == ty) return dist;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (!visited[nx][ny] && grid[nx][ny] != 'X') {
                visited[nx][ny] = true;
                q.push({{nx, ny}, dist + 1});
            }
        }
    }
}
return -1;
```

거리 배열로 푸는 변형(더 자주 쓰임):

```cpp
queue<pair<int, int>> q;
vector<vector<int>> dist(n, vector<int>(m, -1));

q.push({sx, sy});
dist[sx][sy] = 1;

while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (dist[nx][ny] == -1 && grid[nx][ny] == 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}
```

포인트:

- `dist`를 쓰면 방문 여부와 거리를 동시에 관리 가능
- `dist[nx][ny] == -1`을 방문 체크로 사용

---

### 2.6 Comparator 자주 쓰는 형태

```cpp
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first; // tie-break
    }
    return a.second > b.second;   // primary key
}
```

정렬 기준을 문장으로 먼저 적고 comparator를 작성하면 실수를 줄일 수 있습니다.

실전 예시 1 (실패율 유형):

- 1순위: 실패율 내림차순
- 2순위: 스테이지 번호 오름차순

```cpp
bool cmpFailure(const pair<int, double>& a, const pair<int, double>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
```

실전 예시 2 (구간 끝점 기준 그리디):

- 1순위: 끝점 오름차순
- 2순위: 시작점 오름차순

```cpp
bool cmpInterval(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}
```

Comparator 체크리스트:

- `a`가 `b`보다 앞에 와야 하면 `true`를 반환하는가?
- tie-break 기준이 정확히 들어갔는가?
- 오름/내림 방향이 문제 조건과 일치하는가?

---

### 2.7 스택 / 우선순위 큐 템플릿

코테에서 스택/힙은 체감 빈도가 높습니다.  
특히 **괄호 검사, 단조 스택, 작업 스케줄링** 유형이 자주 나옵니다.

#### A) 스택 기본 (괄호 유효성 검사)

언제 쓰나:

- `"()"`, `"[]{}"` 같은 짝 맞추기 문제
- 최근 원소와 현재 원소의 관계를 즉시 확인할 때

```cpp
bool isValid(const string& s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else { // c == ')'
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}
```

실수 포인트:

- `st.top()` 호출 전에 `st.empty()` 확인 누락
- 마지막에 스택이 비었는지 체크 안 해서 오답

#### B) 단조 스택 (오큰수/주식가격/히스토그램 계열)

핵심 아이디어:

- 스택 내부를 "단조 증가/감소"로 유지
- 조건 깨지는 순간 `while`로 연쇄 pop

오큰수 형태 예시:

```cpp
vector<int> nextGreater(const vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st; // index 저장

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            ans[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
```

실수 포인트:

- 값이 아닌 인덱스를 저장해야 하는데 값만 저장해서 위치 정보를 잃음
- `while` 대신 `if`를 써서 연쇄 pop이 안 됨

#### C) 우선순위 큐 기본 (최대/최소 힙)

최대 힙(기본):

```cpp
priority_queue<int> max_heap;
max_heap.push(3);
max_heap.push(10);
max_heap.push(5);
int top1 = max_heap.top(); // 10
```

최소 힙:

```cpp
priority_queue<int, vector<int>, greater<int>> min_heap;
min_heap.push(3);
min_heap.push(10);
min_heap.push(5);
int top2 = min_heap.top(); // 3
```

언제 쓰나:

- "가장 큰/작은 값"을 반복해서 꺼내야 할 때
- 작업 스케줄링, K번째 원소, 다익스트라

#### D) 우선순위 큐 + pair (정렬 우선순위 커스터마이즈)

예시: `(우선순위, 작업번호)`를 최소 우선순위부터 처리

```cpp
using pii = pair<int, int>;
priority_queue<pii, vector<pii>, greater<pii>> pq;

pq.push({2, 101});
pq.push({1, 300});
pq.push({1, 200});

while (!pq.empty()) {
    int priority = pq.top().first;
    int job_id = pq.top().second;
    pq.pop();
    // priority가 작은 작업부터 처리, 같으면 job_id 작은 순
}
```

#### E) 실전 선택 기준 (스택 vs 큐 vs 힙)

- 최근 상태를 되돌리거나 짝을 맞춘다 -> `stack`
- 먼저 들어온 순서대로 처리한다 -> `queue`
- 매번 최댓값/최솟값을 뽑아야 한다 -> `priority_queue`

---

## 3) 자주 나오는 실수 체크리스트

- 입력 크기와 무관하게 `visited`를 고정 크기(예: `101x101`)로 선언
- 전역 상태(`answer`, `found`) 초기화 누락
- `q.empty()` 확인 없이 `q.front()` 접근
- 제출 코드에 디버깅 `cout` 남김
- 엣지 케이스 누락:
  - 시작점이 막힌 경우
  - 도착점이 막힌 경우
  - 목표 값이 후보 집합에 없는 경우

---

## 3-1) 특히 실수하기 쉬운 유형

### A. BFS/DFS 상태 관리 문제

- 실수:
  - 방문 처리를 큐에서 꺼낼 때 해서 중복 삽입 발생
  - 전역 `answer` 초기화 누락
- 해결 습관:
  - 큐에 넣는 순간 방문 처리
  - `solution()` 시작부에서 전역 변수 초기화

### B. 정렬 + comparator 문제

- 실수:
  - tie-break 누락으로 오답
  - 오름/내림 방향 반대로 작성
- 해결 습관:
  - 기준을 "1순위, 2순위"로 한국어 문장 먼저 작성
  - 샘플 3개 만들어 손으로 comparator 결과 확인

### C. 문자열/인덱스 문제

- 실수:
  - `substr(pos, len)`의 두 번째 인자를 끝 인덱스로 착각
  - `find` 결과 비교 실수 (`npos` 체크 누락)
- 해결 습관:
  - 문자열 함수 사용 전 반환형/의미 5초 확인
  - 접두어 판별은 `find(prefix) == 0` 형태로 고정

### D. 구현형 시뮬레이션 문제

- 실수:
  - 조건 분기가 많아 누락 케이스 발생
  - 상태 변수 업데이트 순서 꼬임
- 해결 습관:
  - 상태 전이 순서를 번호로 적고 구현
  - 매 루프 종료 시 불변식 1개를 점검

---

## 3-2) 코테 빈출 유형 모음

아래 유형은 기업 코테/플랫폼에서 매우 자주 등장합니다.

### 그래프/탐색

- 격자 최단거리(BFS)
- 연결 요소 개수(DFS/BFS)
- 최단 경로 변형(가중치가 있으면 다익스트라)

### 정렬/그리디

- 인터벌 겹침 최소화, 회의실 배정, 요격류
- 최소/최대 짝짓기(투포인터)
- 우선순위 기반 선택

### 자료구조

- 스택 괄호/문자열 폭발/단조 스택
- 큐 시뮬레이션, 우선순위 큐 스케줄링
- 해시맵 카운팅, 중복 제거(set)

### 문자열

- 접두어/접미어
- 파싱 및 토큰화
- 순열/조합 생성과 중복 처리

### DP

- 1차원 점화식(계단, 동전, 배낭 기초)
- 2차원 DP(LCS, 격자 경로)
- 상태 정의를 먼저 하고 전이식 작성

### 이진 탐색/파라메트릭 서치

- 정답 범위가 크고 단조성이 있는 경우
- `check(mid)`로 가능 여부 판별

---

## 3-3) 유형별 빠른 선택 가이드

- "최단" + "가중치 없음" -> BFS
- "모든 경우 탐색" + "정답 개수/가능성" -> DFS/백트래킹
- "정렬 후 규칙적으로 선택 가능" -> 그리디
- "구간 여러 번 질의" -> 누적합
- "정답 범위를 줄여가며 찾기" -> 이진 탐색

---

## 4) 주간 복습 루틴 (권장)

## 요일별 구성

- **월**: BFS/그래프 최단거리
- **화**: DFS/백트래킹
- **수**: 그리디 + 정렬
- **목**: 문자열/해시
- **금**: 혼합 재풀이(타임어택)
- **토**: 약점 유형 집중
- **일**: 가벼운 복습 + 노트 정리

### 일일 세션 (90분)

- **10분**: 기존 풀이를 읽고 핵심 아이디어를 한 줄로 요약
- **35분**: 코드 안 보고 재풀이
- **15분**: 기존 풀이와 비교
- **20분**: 더 깔끔한 최종 버전으로 다시 작성
- **10분**: 미니 회고 기록(실수 + 원인 + 재발 방지 패턴)

추가 권장:

- **10분(선택)**: 오늘 푼 문제를 "다른 방식"으로 한 번 더 설계
  - 예: BFS로 푼 문제를 DFS로 가능한지 검토
  - 예: 브루트포스 풀이를 그리디/정렬로 줄일 수 있는지 검토

### 운영 규칙

- 35분 내 막히면 즉시 힌트/기존 코드 확인
- 같은 문제를 3일 뒤 다시 재풀이
- 유형별 실수 로그를 따로 유지

---

## 5) 4주 회전 복습 플랜

### 1주차 (기초 안정화)

- BFS 최단거리(격자)
- DFS 기본 분기
- 정렬 + comparator 기초
- 접두어/해시 카운팅

### 2주차 (패턴 속도화)

- 동일 유형 반복, 제한 시간 더 타이트하게 적용
- 첫 제출에서 버그 없는 초안을 목표로 진행

### 3주차 (혼합 난이도)

- 쉬운 문제 + 중간 난이도 문제를 섞어서 한 세션에 풀이
- 모의 세션 1회(연속 3문제) 추가

### 4주차 (약점 보완)

- 이전 실패 문제만 골라 재풀이
- 재사용 템플릿/체크리스트 확정

---

## 5-1) 실전 코테 직전 30분 루틴

1. BFS 템플릿, DFS 템플릿 1회씩 눈으로 점검
2. comparator 예시 1개 손코딩
3. `unordered_map`, `set`, `priority_queue` 기본 선언 재확인
4. 엣지 케이스 체크 순서 암기:
   - 입력 비어 있음
   - 시작/도착 불가능
   - 최소 크기 입력(길이 1 등)
5. 디버그 출력 제거 습관 마지막 확인

---

## 6) 빠른 문제 해결 템플릿

문제마다 아래 순서로 진행:

1. **유형 분류**: BFS / DFS / 그리디 / 문자열 / 해시?
2. **문제 상태 정리**:
   - 입력 크기 제한
   - 요구 출력 형태
   - 엣지 케이스
3. **자료구조 선택**:
   - queue / stack / map / set / vector
4. **불변식(invariant) 설정**:
   - 반복/재귀 동안 항상 참이어야 하는 조건은 무엇인가?
5. **구현**
6. **작은 예제로 드라이런**
7. **복잡도 점검**
8. **최종 정리(디버그 출력 제거)**

실전 질문 3개:

- 이 문제는 "탐색/BFS"인가 "정렬/그리디"인가?
- 지금 상태 정의로 반례를 커버할 수 있는가?
- 내 코드에서 가장 깨지기 쉬운 조건문은 어디인가?

---

## 7) 현재 레포 기준 재풀이 우선순위

### 우선순위 A (반복 빈도 높게)

- `leetcode/BFS_Shortest Path in Binary Matrix/Shortest Path in Binary Matrix.cpp`
- `프로그래머스/lv2/1844. 게임 맵 최단거리/게임 맵 최단거리.cpp`
- `프로그래머스/lv2/43165. 타겟 넘버/타겟 넘버.cpp`
- `프로그래머스/lv2/42885. 구명보트/구명보트.cpp`

### 우선순위 B (A 안정화 후)

- `프로그래머스/lv3/43164. 여행경로/여행경로.cpp`
- `프로그래머스/2/72411. 메뉴 리뉴얼/메뉴 리뉴얼.cpp`
- `프로그래머스/lv2/181188. 요격 시스템/요격 시스템.cpp`
- `프로그래머스/lv2/42577. 전화번호 목록/전화번호 목록.cpp`

---

## 8) 간단 자기평가 로그 양식

아래 형식을 복붙해서 사용:

```text
[날짜]
문제:
유형:
소요 시간:
결과: 성공 / 실패
핵심 버그:
버그 원인:
재발 방지 패턴:
재풀이 예정일:
```

---

## 9) 마무리

실력은 아래 3가지를 반복할수록 가장 빨리 올라갑니다.

- 문제 유형을 빠르게 분류하고,
- 맞는 자료구조를 빠르게 선택하고,
- 같은 구현 실수를 반복하지 않는 것.

이 파일을 복습 대시보드처럼 계속 업데이트하면서 사용하세요.
