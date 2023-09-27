#include <iostream>
#include <stack>
#include "io.h"

#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    // 원판을 옮길 때 사용할 세 개의 장대를 스택으로 표현합니다.
    stack<int> tower[3];

    // 초기 상태에서 첫 번째 장대에 원판을 쌓습니다.
    for (int i = N; i >= 1; i--) {
        tower[0].push(i);
    }

    // 이동 횟수를 저장하는 변수를 초기화합니다.
    int moveCount = 0;

    // N이 짝수일 때, 목표 장대의 위치를 1로 초기화하고, 홀수일 때는 2로 초기화합니다.
    int targetTower = (N % 2 == 0) ? 1 : 2;

    // 이동 과정을 출력하기 위한 벡터를 준비합니다.
    vector<pair<int, int>> moves;

    // 하노이 탑 문제를 해결하는 과정을 반복문으로 수행합니다.
    while (tower[2].size() != N) {
        int from = -1, to = -1;

        // 다음 원판을 옮길 위치를 결정합니다.
        for (int i = 0; i < 3; i++) {
            if (tower[i].empty()) continue;

            int topDisk = tower[i].top();

            // 원판을 옮길 수 있는 위치를 찾습니다.
            if (from == -1 || topDisk < tower[from].top()) {
                from = i;
            }
        }

        // 옮길 위치를 결정합니다.
        for (int i = 0; i < 3; i++) {
            if (i != from && (tower[i].empty() || tower[from].top() < tower[i].top())) {
                to = i;
            }
        }

        // 원판을 옮깁니다.
        int disk = tower[from].top();
        tower[from].pop();
        tower[to].push(disk);

        // 이동 횟수를 증가시키고 이동 과정을 저장합니다.
        moveCount++;
        moves.push_back({ from + 1, to + 1 });
    }

    // 이동 횟수 출력
    cout << moveCount << endl;

    // 이동 과정 출력
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}
