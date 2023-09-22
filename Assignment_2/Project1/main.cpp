// his file contains the 'main' function. Program execution begins and ends there.

using namespace std;

#include <iostream>

#include "io.h"
#include "main.h"
#include "TowerOfHanoi.cpp"



int main() {
    cout << " [�ϳ��� ž]." << endl;
    cout << "�ȳ��ϼ���!" << endl;

    int N;
    while (true) {
        cout << "������ ������ �Է����ּ��� (1 �� N �� 100): ";
        cin >> N;

        if (N >= 1 && N <= 100) {
            break; // �ùٸ� ������ ���� �Էµ� ������ �ݺ�
        }
        else {
            cout << "�Է� ������ �ʰ��Ͽ����ϴ�. �ٽ� �Է����ּ���." << endl;
            cout << endl;
        }
    }

    TowerOfHanoi hanoi(N);
    hanoi.solve();

    cout << "�̵� Ƚ�� K: " << hanoi.getMoveCount() << endl;

    if (N <= 20) {
        cout << "�̵� ������ ������ �����ϴ�:" << endl;
        hanoi.printMoves();
    }
    else {
        cout << "N�� 20���� ū ���, ������ ��µ��� �ʽ��ϴ�." << endl;
    }

    return 0;
}