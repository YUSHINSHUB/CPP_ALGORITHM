/*
commented by ChatGPT
This C++ code is designed to optimize surveillance camera placements in a grid. 
It aims to reduce blind spots by determining the best orientations for each camera. 
The grid cells can be empty, a wall, or contain a camera. 
Different camera types have distinct viewing patterns. 
The code uses backtracking to explore all possible orientations for each camera and calculates the minimum number of blind spots in the grid.
이 C++ 코드는 그리드 내에서 감시 카메라 배치를 최적화하기 위해 설계되었습니다. 
각 카메라의 최적 방향을 결정함으로써 사각지대를 줄이는 것을 목표로 합니다. 
그리드 셀은 빈 공간, 벽, 또는 카메라를 포함할 수 있습니다. 
서로 다른 카메라 유형들은 각기 다른 시야 패턴을 가지고 있습니다. 
코드는 백트래킹을 사용하여 각 카메라에 대한 모든 가능한 방향을 탐색하고 그리드 내의 최소 사각지대 수를 계산합니다.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M; // 그리드의 세로(N) 및 가로(M) 크기를 저장하는 변수
int res = 65; // 최소 사각지대 개수를 저장하는 변수, 초기값은 65로 설정
int grid[8][8]; // 8x8 그리드를 나타내는 2차원 배열
vector<int> ylist; // 카메라의 y좌표를 저장하는 벡터
vector<int> xlist; // 카메라의 x좌표를 저장하는 벡터

// 카메라가 위쪽 방향으로 감시할 때 감시 범위를 증가시키는 함수
void up(int yt, int xt) {
    for (int i = yt + 1; i < N; i++) {
        if (grid[i][xt] == 6) // 벽을 만나면 반복 중단
            break;
        else if (grid[i][xt] < 10) // 카메라 또는 벽이 아니면 계속 진행
            continue;
        grid[i][xt]++; // 감시 범위 내 칸의 값을 증가
    }
}

// 카메라가 아래쪽 방향으로 감시할 때 감시 범위를 증가시키는 함수
void dp(int yt, int xt) {
    for (int i = yt - 1; i >= 0; i--) {
        if (grid[i][xt] == 6)
            break;
        else if (grid[i][xt] < 10)
            continue;
        grid[i][xt]++;
    }
}

// 카메라가 왼쪽 방향으로 감시할 때 감시 범위를 증가시키는 함수
void lp(int yt, int xt) {
    for (int i = xt - 1; i >= 0; i--) {
        if (grid[yt][i] == 6)
            break;
        else if (grid[yt][i] < 10)
            continue;
        grid[yt][i]++;
    }
}

// 카메라가 오른쪽 방향으로 감시할 때 감시 범위를 증가시키는 함수
void rp(int yt, int xt) {
    for (int i = xt + 1; i < M; i++) {
        if (grid[yt][i] == 6)
            break;
        else if (grid[yt][i] < 10)
            continue;
        grid[yt][i]++;
    }
}

// 카메라가 위쪽 방향으로 감시 범위를 줄이는 함수
void um(int yt, int xt) {
    for (int i = yt + 1; i < N; i++) {
        if (grid[i][xt] == 6)
            break;
        else if (grid[i][xt] < 10)
            continue;
        grid[i][xt]--;
    }
}

// 카메라가 아래쪽 방향으로 감시 범위를 줄이는 함수
void dm(int yt, int xt) {
    for (int i = yt - 1; i >= 0; i--) {
        if (grid[i][xt] == 6)
            break;
        else if (grid[i][xt] < 10)
            continue;
        grid[i][xt]--;
    }
}

// 카메라가 왼쪽 방향으로 감시 범위를 줄이는 함수
void lm(int yt, int xt) {
    for (int i = xt - 1; i >= 0; i--) {
        if (grid[yt][i] == 6)
            break;
        else if (grid[yt][i] < 10)
            continue;
        grid[yt][i]--;
    }
}

// 카메라가 오른쪽 방향으로 감시 범위를 줄이는 함수
void rm(int yt, int xt) {
    for (int i = xt + 1; i < M; i++) {
        if (grid[yt][i] == 6)
            break;
        else if (grid[yt][i] < 10)
            continue;
        grid[yt][i]--;
    }
}

// 백트래킹을 통해 카메라의 모든 방향 조합을 시도하고 사각지대의 최소 개수를 찾는 함수
void bt(int idx) {
    if (idx == ylist.size()) { // 모든 카메라를 배치했을 경우
        int r = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 10) // 사각지대 카운트
                    r++;
            }
        }
        res = min(res, r); // 최소 사각지대 개수 갱신
        return;
    }
    else {
        int yt = ylist[idx]; // 현재 카메라의 y좌표
        int xt = xlist[idx]; // 현재 카메라의 x좌표

        switch (grid[yt][xt]) {
        case 1: // 카메라 유형 1의 로직
            up(yt, xt);
            bt(idx + 1);
            um(yt, xt);

            dp(yt, xt);
            bt(idx + 1);
            dm(yt, xt);

            lp(yt, xt);
            bt(idx + 1);
            lm(yt, xt);

            rp(yt, xt);
            bt(idx + 1);
            rm(yt, xt);
            break;
        case 2: // 카메라 유형 2의 로직
            up(yt, xt);
            dp(yt, xt);
            bt(idx + 1);
            um(yt, xt);
            dm(yt, xt);

            lp(yt, xt);
            rp(yt, xt);
            bt(idx + 1);
            lm(yt, xt);
            rm(yt, xt);
            break;
        case 3: // 카메라 유형 3의 로직
            up(yt, xt);
            rp(yt, xt);
            bt(idx + 1);
            um(yt, xt);
            rm(yt, xt);

            rp(yt, xt);
            dp(yt, xt);
            bt(idx + 1);
            rm(yt, xt);
            dm(yt, xt);

            dp(yt, xt);
            lp(yt, xt);
            bt(idx + 1);
            dm(yt, xt);
            lm(yt, xt);

            up(yt, xt);
            lp(yt, xt);
            bt(idx + 1);
            um(yt, xt);
            lm(yt, xt);
            break;
        case 4: // 카메라 유형 4의 로직
            up(yt, xt);
            lp(yt, xt);
            rp(yt, xt);
            bt(idx + 1);
            um(yt, xt);
            lm(yt, xt);
            rm(yt, xt);

            rp(yt, xt);
            up(yt, xt);
            dp(yt, xt);
            bt(idx + 1);
            rm(yt, xt);
            um(yt, xt);
            dm(yt, xt);

            dp(yt, xt);
            lp(yt, xt);
            rp(yt, xt);
            bt(idx + 1);
            dm(yt, xt);
            lm(yt, xt);
            rm(yt, xt);

            lp(yt, xt);
            up(yt, xt);
            dp(yt, xt);
            bt(idx + 1);
            lm(yt, xt);
            um(yt, xt);
            dm(yt, xt);
            break;
        default: // 다른 카메라 유형의 경우
            bt(idx + 1);
            break;
        }
    }
}

int main()
{
    cin >> N >> M; // 그리드 크기 입력 받기

    // 그리드 정보 입력 및 카메라 위치 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] >= 1 && grid[i][j] <= 5) { // 카메라 유형이면 좌표 저장
                ylist.push_back(i);
                xlist.push_back(j);
            }
            else if (grid[i][j] == 0)
                grid[i][j] = 10; // 빈 공간은 사각지대로 설정
        }
    }

    // 유형 5 카메라의 경우, 모든 방향으로 감시 범위 설정
    for (int i = 0; i < ylist.size(); i++) {
        if (grid[ylist[i]][xlist[i]] == 5) {
            int yt = ylist[i];
            int xt = xlist[i];
            up(yt, xt);
            dp(yt, xt);
            lp(yt, xt);
            rp(yt, xt);
        }
    }

    bt(0); // 백트래킹 함수 호출
    cout << res; // 결과 출력
}
