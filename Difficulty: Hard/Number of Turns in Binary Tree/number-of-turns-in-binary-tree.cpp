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
}; */

class Solution {
    bool findPath(Node* root, int target, vector<char>& path) {
        if (!root) return false;

        if (root->data == target) return true;

        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, target, path))
            return true;
        path.pop_back();

        return false;
    }

  public:
    int numberOfTurns(Node* root, int p, int q) {
        vector<char> pathP, pathQ;

        findPath(root, p, pathP);
        findPath(root, q, pathQ);

        // Find common path => path till LCA
        int i = 0;
        while (i < pathP.size() && i < pathQ.size() &&
               pathP[i] == pathQ[i]) {
            i++;
        }

        // Build path from p -> LCA -> q
        vector<char> directions;

        // Moving from p to LCA: reverse directions
        for (int j = (int)pathP.size() - 1; j >= i; j--) {
            directions.push_back(pathP[j]);
        }

        // Moving from LCA to q
        for (int j = i; j < pathQ.size(); j++) {
            directions.push_back(pathQ[j]);
        }

        int turns = 0;

        for (int j = 1; j < directions.size(); j++) {
            if (directions[j] != directions[j - 1])
                turns++;
        }

        return turns == 0 ? -1 : turns;
    }
};