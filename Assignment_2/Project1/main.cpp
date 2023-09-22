// his file contains the 'main' function. Program execution begins and ends there.

using namespace std;

#include <iostream>

#include "io.h"
#include "main.h"
#include "TowerOfHanoi.cpp"



int main() {
    cout << endl;
    cout << endl;
    cout << " [하노이 탑]." << endl;
    cout << endl;
    cout << "안녕하세요!" << endl;

    int N;

    while (true) {
        cout << "원판의 개수를 입력해주세요 (1 ≤ N ≤ 100): ";
        cin >> N;

        if (N >= 1 && N <= 100) {
            break; // 올바른 범위의 값이 입력될 때까지 반복
        }
        else {
            cout << "입력 범위를 초과하였습니다. 다시 입력해주세요." << endl;
            cout << endl;
        }
    }

    TowerOfHanoi hanoi(N);
    hanoi.solve();

    cout << endl;
    cout << "이동 횟수 K: " << hanoi.getMoveCount() << endl;

    if (N > 20) {
        cout << "N이 20보다 큰 경우, 과정은 출력되지 않습니다." << endl;
    }
    else {
        cout << "이동 과정은 다음과 같습니다:" << endl;
        hanoi.printMoves();
    }

    return 0;
}