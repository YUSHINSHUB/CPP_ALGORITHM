/*
commented by ChatGPT
This C++ code implements the Union-Find algorithm to track the formation of social networks through friendships.
Each time a new friendship is declared, it updates the network sizes dynamically, ensuring that each person is part of a unique group.
The main function reads the number of test cases and processes each set of friendships, outputting the size of the social network after each connection is made.
It uses a map to associate each person with a unique index, facilitating the use of Union-Find on string inputs.
이 C++ 코드는 우정을 통한 소셜 네트워크 형성을 추적하기 위해 Union-Find 알고리즘을 구현합니다.
새로운 우정이 선언될 때마다 동적으로 네트워크 크기를 업데이트하여 각 사람이 고유한 그룹에 속하도록 합니다.
main 함수는 테스트 케이스의 수를 읽고 각 우정 세트를 처리한 후 각 연결이 만들어진 후의 소셜 네트워크 크기를 출력합니다.
문자열 입력에 Union-Find를 사용할 수 있도록 각 사람을 고유 인덱스와 연결하는 맵을 사용합니다.
*/

#include <iostream>
#include <map>

using namespace std;

int parent[200000]; // Stores the parent of each node
int groupcnt[200000]; // Stores the size of the group each node belongs to

// Finds the representative of a node's group, applying path compression
int find_parent(int no) {
    if (parent[no] == no) {
        return no;
    }
    return parent[no] = find_parent(parent[no]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int c = 0; c < T; c++) {
        fill(parent, parent + 200000, 0);
        fill(groupcnt, groupcnt + 200000, 0);
        map<string, int> hm; // Maps each person to a unique index
        int F;
        cin >> F;
        int cnt = 0; // Counter for unique indices
        for (int i = 0; i < F; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            // Assign unique indices to new names
            if (hm.find(s1) == hm.end()) {
                hm[s1] = cnt;
                parent[cnt] = cnt;
                groupcnt[cnt] = 1;
                cnt++;
            }
            int a = hm[s1];
            if (hm.find(s2) == hm.end()) {
                hm[s2] = cnt;
                parent[cnt] = cnt;
                groupcnt[cnt] = 1;
                cnt++;
            }
            int b = hm[s2];
            // Union operation: merge two groups if they are different
            if (find_parent(a) != find_parent(b)) {
                groupcnt[find_parent(a)] += groupcnt[find_parent(b)];
                groupcnt[find_parent(b)] = 0;
                parent[find_parent(b)] = find_parent(a);
            }
            // Output the size of the merged group
            cout << groupcnt[find_parent(a)] << "\n";
        }
    }
}
