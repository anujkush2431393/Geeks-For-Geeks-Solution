/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    unordered_map<int, int> mp;
    int idx = 0;

    Node* build(vector<int> &pre, vector<int> &preMirror, int l, int r) {
        if (idx >= pre.size() || l > r)
            return nullptr;

        Node* root = new Node(pre[idx++]);

        if (l == r || idx >= pre.size())
            return root;

        int p = mp[pre[idx]];

        root->left = build(pre, preMirror, p, r);
        root->right = build(pre, preMirror, l + 1, p - 1);

        return root;
    }

  public:
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        int n = preMirror.size();

        for (int i = 0; i < n; i++)
            mp[preMirror[i]] = i;

        idx = 0;
        return build(pre, preMirror, 0, n - 1);
    }
};