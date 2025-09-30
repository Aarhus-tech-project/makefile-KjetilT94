#include "hanoi.hpp"
#include "bst.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char** argv) {
    if (argc >= 3 && std::string(argv[1]) == "--hanoi") {
        int n = std::stoi(argv[2]);
        std::cout << hanoi_moves(n) << "\n";
        return 0;
    }
    if (argc >= 3 && std::string(argv[1]) == "--bst") {
        BST t;
        std::stringstream ss(argv[2]); // e.g. "5,2,7,3"
        for (std::string tok; std::getline(ss, tok, ','); )
            if (!tok.empty()) t.insert(std::stoi(tok));
        std::cout << (t.find(3) ? "found" : "missing") << "\n";
        return 0;
    }
    std::cerr << "usage: app --hanoi N | --bst \"5,2,7,3\"\n";
    return 2;
}