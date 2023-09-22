#include "io.h"

#include <vector>
#include <iostream>

using namespace std;

class TowerOfHanoi {
public:
    TowerOfHanoi(int n) : n(n) {
        towers.resize(3);
        for (int i = n; i >= 1; i--) {
            towers[0].push_back(i);
        }
        moveCount = 0;
    }

    void solve() {
        moveDisks(n, 0, 2, 1);
    }

    void printMoves() {
        cout << moveCount << endl;
        for (const auto& move : moves) {
            cout << move.first + 1 << " " << move.second + 1 << endl;
        }
    }

    int getMoveCount() const { // moveCount를 반환하는 함수 추가
        return moveCount;
    }

private:
    int n;
    vector<vector<int>> towers;
    vector<pair<int, int>> moves;
    int moveCount;

    void moveDisks(int numDisks, int source, int target, int auxiliary) {
        if (numDisks == 0) return;

        moveDisks(numDisks - 1, source, auxiliary, target);
        moveDisk(source, target);
        moveCount++;
        moves.push_back({ source, target });

        moveDisks(numDisks - 1, auxiliary, target, source);
    }

    void moveDisk(int source, int target) {
        int disk = towers[source].back();
        towers[source].pop_back();
        towers[target].push_back(disk);
    }
};
