# 코딩테스트 직전 최종 꿀팁

## 1. 문제를 보자마자 판단하는 법

문제를 읽고 아래 키워드가 보이면 바로 유형을 의심한다.

- **최단거리 / 최소 이동 / 미로 / 지도 / 격자** -> `BFS`
- **연결 / 네트워크 / 노드 / 간선 / 덩어리 개수** -> `DFS` 또는 `BFS`
- **모든 경우 / 순서 / 조합 / 경로 / 선택** -> `DFS + 백트래킹`
- **종류 / 개수 / 중복 / 이름별 카운트** -> `unordered_map`
- **최소 개수 / 최대 효율 / 구간 / 끝점 / 무게 제한** -> `정렬 + 그리디`
- **두 개를 골라 합 비교 / 양끝에서 좁히기** -> `투포인터`
- **접두어 / 문자열 일부 / 사전순** -> `정렬 + 문자열`

가장 먼저 물어볼 것:

```text
1. 최단거리인가?
2. 연결된 덩어리인가?
3. 모든 경우를 봐야 하나?
4. 종류별로 세면 되나?
5. 정렬하면 쉬워지나?
```

---

## 2. BFS 핵심

BFS는 **가중치 없는 최단거리**에 쓴다.

```cpp
queue<pair<int, int>> q;
vector<vector<int>> dist(n, vector<int>(m, -1));

q.push({0, 0});
dist[0][0] = 1;

while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (dist[nx][ny] == -1 && grid[nx][ny] == 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}
```

주의:

- BFS는 **큐에 넣을 때 방문 처리**
- 거리 하나를 전역으로 `++` 하면 틀리기 쉽다
- 좌표마다 거리(`dist`)를 따로 관리한다

---

## 3. DFS 핵심

DFS는 **연결된 것 전부 방문**할 때 먼저 떠올린다.

```cpp
void dfs(int node) {
    visited[node] = true;

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}
```

DFS 감각:

```text
현재 노드 방문
-> 연결된 다음 노드로 깊게 들어감
-> 더 갈 곳 없으면 돌아옴
```

대표 사용:

- 네트워크 개수 세기
- 연결된 노드 수 세기
- 트리/그래프 탐색

주의:

- DFS는 보통 **함수 들어오자마자 방문 처리**
- `visited` 없으면 무한 재귀 가능
- 전역 변수 쓰면 초기화 조심

---

## 4. 백트래킹 핵심

백트래킹은 **DFS + 선택 복구**다.

```text
선택
재귀
복구
```

```cpp
used[i] = true;
path.push_back(x);

dfs(...);

path.pop_back();
used[i] = false;
```

DFS와 차이:

- DFS: 방문하고 끝
- 백트래킹: 선택했다가 다시 취소하고 다른 경우 탐색

대표 사용:

- 순열
- 조합
- 여행경로
- 피로도
- 메뉴 리뉴얼

---

## 5. 그리디 + 정렬

그리디는 **정렬 후 지금 가장 좋은 선택을 반복**하는 방식이다.

문제를 보고 이런 말이 있으면 의심:

```text
최소 개수
최대로 처리
겹치지 않게
끝나는 시간
무게 제한
```

Comparator 작성 전 문장으로 먼저 정리:

```text
1순위: 끝점 오름차순
2순위: 시작점 오름차순
```

```cpp
bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}
```

주의:

- 오름차순/내림차순 방향 확인
- tie-break 조건 확인
- 정렬 기준이 문제 목표와 맞는지 손으로 1번 검산

---

## 6. 해시 / 맵

종류별 개수, 이름별 개수, 중복 체크는 해시부터 생각한다.

```cpp
unordered_map<string, int> count_map;

for (const auto& x : arr) {
    count_map[x]++;
}
```

선택 기준:

- 빠른 조회만 필요 -> `unordered_map`
- 키 정렬 필요 -> `map`
- 중복 제거 -> `set` 또는 `unordered_set`

`의상` 같은 문제:

```text
각 종류마다 (개수 + 1)을 곱하고,
아무것도 안 입는 경우 1개를 뺀다.
```

---

## 7. 투포인터

정렬 후 양끝에서 좁히는 문제.

```cpp
sort(v.begin(), v.end());

int left = 0;
int right = v.size() - 1;

while (left <= right) {
    if (v[left] + v[right] <= limit) {
        left++;
    }
    right--;
    answer++;
}
```

대표 감각:

- 가장 작은 것 + 가장 큰 것
- 합이 조건을 만족하면 둘 다 처리
- 아니면 큰 쪽만 처리

---

## 8. 문자열

자주 쓰는 함수:

```cpp
s.substr(pos, len);
s.find(target);
stoi(s);
sort(s.begin(), s.end());
```

주의:

- `substr(pos, len)`의 두 번째 인자는 끝 인덱스가 아니라 길이
- `find`는 못 찾으면 `string::npos`
- 접두어 확인은 `s2.find(s1) == 0`

전화번호 목록 패턴:

```cpp
sort(phone_book.begin(), phone_book.end());

for (int i = 0; i + 1 < phone_book.size(); i++) {
    if (phone_book[i + 1].find(phone_book[i]) == 0) {
        return false;
    }
}
return true;
```

---

## 9. 제출 전 실수 체크리스트

진짜 제출 직전 이것만 확인한다.

```text
for문 증감식 맞나? i++ / next++ / n++ 오타
배열 범위 체크했나?
visited 초기화했나?
전역 answer 초기화했나?
디버그 cout 제거했나?
sort 방향 맞나?
return 조건 빠진 것 없나?
시작점/도착점 예외 처리했나?
빈 입력 또는 길이 1 처리했나?
```

특히 자주 터지는 실수:

```cpp
for (int next = 0; next < n; n++) // 틀림
```

정답:

```cpp
for (int next = 0; next < n; next++)
```

---

## 10. 내일 운영 전략

1. 쉬운 구현/해시 문제부터 푼다.
2. BFS/DFS는 `visited`와 종료 조건부터 설계한다.
3. 그리디는 정렬 기준부터 문장으로 적는다.
4. 15~20분 막히면 다음 문제로 넘어간다.
5. 마지막 10분은 예제 손검산 + 디버그 출력 제거에 쓴다.

---

## 11. 마지막으로 외울 문장

```text
BFS는 최단거리.
DFS는 연결된 것 색칠하기.
백트래킹은 선택하고 되돌리기.
그리디는 정렬하고 지금 최선 고르기.
해시는 종류별로 세기.
투포인터는 양끝에서 좁히기.
```

내일은 새로운 걸 떠올리기보다, 이 기본 패턴을 정확하게 적용하는 게 제일 중요하다.
