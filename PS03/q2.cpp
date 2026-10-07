#include <iostream>
#include <vector>

int main() {
    int n;
    if (!(std::cin >> n) || n <= 0) {
        return 0;
    }

    std::vector<int> suitors;
    suitors.reserve(n);

    for (int i = 1; i <= n; ++i) {
        suitors.push_back(i);
    }

    int index = 0;

    while (suitors.size() > 1) {
        index = (index + 2) % static_cast<int>(suitors.size());
        suitors.erase(suitors.begin() + index);
    }

    std::cout << suitors[0] << '\n';
    return 0;
}
