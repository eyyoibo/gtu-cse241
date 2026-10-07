#include <iostream>

int main() {
    std::cout << "Prime numbers between 3 and 100:\n";

    for (int n = 3; n <= 100; ++n) {
        bool isPrime = true;

        for (int d = 2; d < n; ++d) {
            if (n % d == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            std::cout << n << ' ';
        }
    }
    std::cout << std::endl;
    return 0;
}
