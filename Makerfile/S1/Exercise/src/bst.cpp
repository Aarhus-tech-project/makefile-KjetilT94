#include "bst.hpp"

static void insert_rec(std::unique_ptr<Node>& n, int k) {
    if (!n) {
        n = std::make_unique<Node>(k);
        return;
    }

    if (k < n->key) {
        insert_rec(n->l, k);
    } else if (k > n->key) {
        insert_rec(n->r, k);
    }
}

static bool find_rec(const Node* n, int k) {
    if (!n) {
        return false;
    }

    if (k == n->key) {
        return true;
    } else if (k < n->key) {
        return find_rec(n->l.get(), k);
    } else {
        return find_rec(n->r.get(), k);
    }
}

void BST::insert(int k) { insert_rec(root, k); }
bool BST::find(int k) const { return find_rec(root.get(), k); }