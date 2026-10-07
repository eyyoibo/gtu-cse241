#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void aaronTurn(bool& bobAlive, bool& charlieAlive) {
    int r = rand() % 100;
    if (charlieAlive) {
        if (r <= 33) charlieAlive = false;
    } else if (bobAlive) {
        if (r <= 33) bobAlive = false;
    }
}

void bobTurn(bool& aaronAlive, bool& charlieAlive) {
    int r = rand() % 100;
    if (charlieAlive) {
        if (r <= 50) charlieAlive = false;
    } else if (aaronAlive) {
        if (r <= 50) aaronAlive = false;
    }
}

void charlieTurn(bool& aaronAlive, bool& bobAlive) {
    if (bobAlive) {
        bobAlive = false;
    } else if (aaronAlive) {
        aaronAlive = false;
    }
}

int simulateDuel() {
    bool aaronAlive = true;
    bool bobAlive = true;
    bool charlieAlive = true;

    while (true) {
        if (aaronAlive) aaronTurn(bobAlive, charlieAlive);
        if (aaronAlive && !bobAlive && !charlieAlive) return 1;

        if (bobAlive) bobTurn(aaronAlive, charlieAlive);
        if (bobAlive && !aaronAlive && !charlieAlive) return 2;

        if (charlieAlive) charlieTurn(aaronAlive, bobAlive);
        if (charlieAlive && !aaronAlive && !bobAlive) return 3;
    }
}

void printResults(int aaronWins, int bobWins, int charlieWins, int totalDuels) {
    cout << "Aaron won " << aaronWins << "/" << totalDuels
         << " duels or " << (100.0 * aaronWins / totalDuels) << " %" << endl;
    cout << "Bob won " << bobWins << "/" << totalDuels
         << " duels or " << (100.0 * bobWins / totalDuels) << " %" << endl;
    cout << "Charlie won " << charlieWins << "/" << totalDuels
         << " duels or " << (100.0 * charlieWins / totalDuels) << " %" << endl;
}

int main() {
    srand(time(0));

    int aaronWins = 0, bobWins = 0, charlieWins = 0;
    const int NUM_DUELS = 10000;

    for (int i = 0; i < NUM_DUELS; i++) {
        int winner = simulateDuel();
        if (winner == 1) aaronWins++;
        else if (winner == 2) bobWins++;
        else charlieWins++;
    }

    printResults(aaronWins, bobWins, charlieWins, NUM_DUELS);

    return 0;
}
