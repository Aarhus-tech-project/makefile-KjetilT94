#pragma once
#include <memory>

struct Node {
    int key;
    std::unique_ptr<Node> l, r;
    explicit Node(int k) : key(k) {}
};

class BST {
public:
    void insert(int k);

    bool find(int k) const;

private:
    std::unique_ptr<Node> root;
};