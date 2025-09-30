#include "hanoi.hpp"

std::uint64_t hanoi_moves(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return 2 * hanoi_moves(n - 1) + 1;
}