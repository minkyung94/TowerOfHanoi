#include <iostream>
#include <stack>
#include "io.h"

#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    // ������ �ű� �� ����� �� ���� ��븦 �������� ǥ���մϴ�.
    stack<int> tower[3];

    // �ʱ� ���¿��� ù ��° ��뿡 ������ �׽��ϴ�.
    for (int i = N; i >= 1; i--) {
        tower[0].push(i);
    }

    // �̵� Ƚ���� �����ϴ� ������ �ʱ�ȭ�մϴ�.
    int moveCount = 0;

    // N�� ¦���� ��, ��ǥ ����� ��ġ�� 1�� �ʱ�ȭ�ϰ�, Ȧ���� ���� 2�� �ʱ�ȭ�մϴ�.
    int targetTower = (N % 2 == 0) ? 1 : 2;

    // �̵� ������ ����ϱ� ���� ���͸� �غ��մϴ�.
    vector<pair<int, int>> moves;

    // �ϳ��� ž ������ �ذ��ϴ� ������ �ݺ������� �����մϴ�.
    while (tower[2].size() != N) {
        int from = -1, to = -1;

        // ���� ������ �ű� ��ġ�� �����մϴ�.
        for (int i = 0; i < 3; i++) {
            if (tower[i].empty()) continue;

            int topDisk = tower[i].top();

            // ������ �ű� �� �ִ� ��ġ�� ã���ϴ�.
            if (from == -1 || topDisk < tower[from].top()) {
                from = i;
            }
        }

        // �ű� ��ġ�� �����մϴ�.
        for (int i = 0; i < 3; i++) {
            if (i != from && (tower[i].empty() || tower[from].top() < tower[i].top())) {
                to = i;
            }
        }

        // ������ �ű�ϴ�.
        int disk = tower[from].top();
        tower[from].pop();
        tower[to].push(disk);

        // �̵� Ƚ���� ������Ű�� �̵� ������ �����մϴ�.
        moveCount++;
        moves.push_back({ from + 1, to + 1 });
    }

    // �̵� Ƚ�� ���
    cout << moveCount << endl;

    // �̵� ���� ���
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}
