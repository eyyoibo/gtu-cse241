#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int rollDie() {
    return rand() % 6 + 1;
}

int humanTurn(int humanTotalScore) {
    int turn = 0;
    char choice;

    while (1) {
        int roll = rollDie();
        cout << "You rolled: " << roll << "\n";

        if (roll == 1) {
            cout << "You rolled 1. Turn score is 0.\n";
            return 0;
        }

        turn += roll;
        cout << "Turn score: " << turn
             << " | If you hold, total becomes: " << (humanTotalScore + turn) << "\n";

        while (1) {
            cout << "Enter r to roll again or h to hold: ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please type r or h.\n";
                continue;
            }

            cin.ignore(10000, '\n');

            if (choice == 'h' || choice == 'H') {
                return turn;
            }
            if (choice == 'r' || choice == 'R') {
                break;
            }

            cout << "Invalid input. Please type r or h.\n";
        }
    }
}

int computerTurn(int computerTotalScore) {
    int turn = 0;

    while (turn < 20 && computerTotalScore + turn < 100) {
        int roll = rollDie();
        cout << "Computer rolled: " << roll << "\n";

        if (roll == 1) {
            cout << "Computer rolled 1. Turn score is 0.\n";
            return 0;
        }

        turn += roll;
    }

    cout << "Computer holds. Turn score: " << turn << "\n";
    return turn;
}

int main() {
    srand((unsigned)time(NULL));

    int humanTotal = 0;
    int computerTotal = 0;
    int turn = 0;  // 0: human, 1: computer

    cout << "Pig Game - First to 100 wins.\n\n";

    while (humanTotal < 100 && computerTotal < 100) {
        if (turn == 0) {
            humanTotal += humanTurn(humanTotal);
            cout << "Your total score: " << humanTotal << "\n\n";
            turn = 1;
        } else {
            computerTotal += computerTurn(computerTotal);
            cout << "Computer total score: " << computerTotal << "\n\n";
            turn = 0;
        }
    }

    if (humanTotal >= 100) {
        cout << "You win!\n";
    } else {
        cout << "Computer wins.\n";
    }

    return 0;
}
