#include <iostream>

class HotDogStand {
private:
    int id;
    int numSold;
    static int totalSold;

public:
    HotDogStand(int standId, int initialSold) : id(standId), numSold(initialSold) {
        totalSold += initialSold;
    }

    void justSold() {
        ++numSold;
        ++totalSold;
    }

    int getNumSold() const {
        return numSold;
    }

    int getID() const {
        return id;
    }

    static int getTotalNumSold() {
        return totalSold;
    }
};

int HotDogStand::totalSold = 0;

int main() {
    HotDogStand stand1(1, 5);
    HotDogStand stand2(2, 2);
    HotDogStand stand3(3, 0);

    stand1.justSold();
    stand1.justSold();
    stand2.justSold();
    stand3.justSold();
    stand3.justSold();
    stand3.justSold();

    std::cout << "Stand " << stand1.getID() << " sold " << stand1.getNumSold() << " hot dogs.\n";
    std::cout << "Stand " << stand2.getID() << " sold " << stand2.getNumSold() << " hot dogs.\n";
    std::cout << "Stand " << stand3.getID() << " sold " << stand3.getNumSold() << " hot dogs.\n";
    std::cout << "Total sold by all stands: " << HotDogStand::getTotalNumSold() << '\n';

    return 0;
}
