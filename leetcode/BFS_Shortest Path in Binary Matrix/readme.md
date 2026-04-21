# 1091. Shortest Path in Binary Matrix

- Difficulty: `Medium`
- Link: [LeetCode 1091](https://leetcode.com/problems/shortest-path-in-binary-matrix/description/)

## Problem

`n x n` 이진 행렬 `grid`가 주어질 때, 좌상단 `(0, 0)`에서 우하단 `(n - 1, n - 1)`까지 가는 **최단 clear path 길이**를 구하라.  
경로가 없으면 `-1`을 반환한다.

### Clear Path 조건

1. 경로에 포함된 모든 칸의 값은 `0`이어야 한다.
2. 이동은 8방향(상, 하, 좌, 우, 대각선 4방향)으로 가능하다.
3. 경로 길이는 방문한 칸의 수이다.

## Examples

### Example 1

```text
Input:  grid = [[0,1],[1,0]]
Output: 2
```

### Example 2

```text
Input:  grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
```

### Example 3

```text
Input:  grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
```

## Visual Examples

아래 그림은 링크의 예시를 격자 형태로 다시 표현한 것이다.  
(`S`: 시작, `E`: 도착, `P`: 최단 경로, `1`: blocked)

### Example 1 Grid

|     | col0 | col1 |
|-----|------|------|
| row0 | `S/P` | `1` |
| row1 | `1` | `E/P` |

최단 경로: `(0,0) -> (1,1)` (대각선 이동), 길이 `2`

### Example 2 Grid

|     | col0 | col1 | col2 |
|-----|------|------|------|
| row0 | `S/P` | `P` | `P` |
| row1 | `1` | `1` | `P` |
| row2 | `1` | `1` | `E/P` |

최단 경로 예시: `(0,0) -> (0,1) -> (1,2) -> (2,2)`, 길이 `4`

## Constraints

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 100`
- `grid[i][j]`는 `0` 또는 `1`

## Idea

최단 경로 문제이므로 **BFS**가 정석이다.

- 시작점 또는 도착점이 `1`이면 바로 `-1`
- 큐에 `(row, col, distance)`를 넣고 레벨 순회
- 8방향으로 확장하면서 범위 안이고 값이 `0`인 칸만 방문
- 방문 처리는 `visited` 배열 또는 `grid` 값을 변경해서 중복 방문 방지
- 처음으로 도착점에 도달했을 때의 거리(`distance`)가 최단 경로

## Complexity

- Time: `O(n^2)`  
  각 칸을 최대 한 번 방문
- Space: `O(n^2)`  
  큐 + 방문 배열