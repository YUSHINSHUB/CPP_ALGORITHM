/*
commented by ChatGPT
This C++ program implements a binary search algorithm combined with Breadth-First Search (BFS) to determine the maximum permissible limit (weight or capacity) for a path from node f1 to f2 in a graph. 
The graph is represented using an adjacency list, where each edge has a limitation (capacity). 
The objective is to find the highest limit such that there is still a path from f1 to f2. 
The binary search narrows down the possible limits to find the maximum one that allows for a path between f1 and f2.
이 C++ 프로그램은 그래프에서 노드 f1에서 f2로 가는 경로에 대한 최대 허용 한계(무게 또는 용량)를 결정하기 위해 이진 탐색 알고리즘과 너비 우선 탐색(BFS)을 결합하여 구현합니다. 
그래프는 인접 리스트를 사용하여 표현되며, 각 간선에는 한계(용량)가 있습니다. 
목표는 f1에서 f2로의 경로가 여전히 존재하는 가장 높은 한계를 찾는 것입니다. 
이진 탐색은 f1과 f2 사이의 경로를 허용하는 최대 한계를 찾기 위해 가능한 한계를 좁혀 나갑니다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class route {
public:
    int to, lim; // 목적지 노드와 이동 한계(용량)를 나타내는 변수

    route(int to, int lim) {
        this->to = to;
        this->lim = lim;
    }
};

int N, M; // 노드 수(N)와 간선 수(M)
bool visited[10001]; // 방문 여부를 나타내는 배열
int f1, f2; // 시작 노드(f1)와 목적지 노드(f2)
int hig = INT_MIN; // 가능한 최대 한계값
int low = INT_MAX; // 가능한 최소 한계값
int mid = 0; // 이진 탐색을 위한 중간 값
vector<route> list[10001]; // 각 노드의 인접 리스트

static bool search(int idx) {
    // BFS를 사용하여 idx 한계값으로 f1에서 f2로 이동 가능한지 확인
    fill(visited, visited + N + 1, false);
    visited[f1] = true;
    queue<int> q;
    q.push(f1);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (t == f2) {
            return true;
        }
        for (route r : list[t]) {
            if (r.lim >= idx && !visited[r.to]) {
                q.push(r.to);
                visited[r.to] = true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int res = 0; // 결과값 (최대 한계 값)
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        list[A].push_back(route(B, C));
        list[B].push_back(route(A, C));

        hig = max(hig, C);
        low = min(low, C);
    }

    cin >> f1 >> f2;

    // 이진 탐색으로 최대 한계 값 탐색
    while (low <= hig) {
        mid = (low + hig) / 2;
        if (search(mid)) {
            low = mid + 1;
            res = mid;
        }
        else {
            hig = mid - 1;
        }
    }

    cout << res; // 결과 출력
}
