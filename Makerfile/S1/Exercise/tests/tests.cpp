#include "hanoi.hpp"
#include "bst.hpp"
#include <cassert>
#include <vector>

int main() {
    assert(hanoi_moves(0) == 0);
    assert(hanoi_moves(1) == 1);
    assert(hanoi_moves(2) == 3);
    assert(hanoi_moves(10) == 1023);

    BST t; for (int v : std::vector<int>{5,2,7,3}) t.insert(v);
    assert(t.find(3) == true);
    assert(t.find(6) == false);
    return 0;
}