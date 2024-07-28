class Node {
public:
    Node* left = nullptr;
    Node* right = nullptr;
    int l = 0, r = 0, mid = 0;
    int v = 0, add = 0;

    Node(int l, int r) { this->l = l, this->r = r, this->mid = l + (r - l) / 2; }
};

class SegmentTree {
private:
    Node* root;

    void push_up(Node* node) { node->v = max(node->left->v, node->right->v); }

    void push_down(Node* node) {}

    void update(int l, int r, int v, Node* node) {
        if (l > r) {
            return;
        }
        if (node->l >= l && node->r <= r) {
            node->v = node->add = v;
            return;
        }
        push_down(node);
        if (l <= node->mid) {
            update(l, r, v, node->left);
        }
        if (r > node->mid) {
            update(l, r, v, node->right);
        }
        push_up(node);
    }

    int query(int l, int r, Node* node) {}

public:
    SegmentTree() { root = new Node(1, 1e9); }

    void update(int l, int r, int v) { update(l, r, v, root); }

    int query(int l, int r) { query(l, r, root); }
};