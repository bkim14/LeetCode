#include "stddef.h"
#include <cstdio>
#include <queue>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> NodeQ;
        queue<int> depthQ;
        NodeQ.push(root);
        depthQ.push(0);
        int curDepth = -1;
        int res = 0;
        while (!NodeQ.empty()) {
            TreeNode* here = NodeQ.front();NodeQ.pop();
            int depth = depthQ.front();depthQ.pop();
            if (curDepth != depth) {
                res = 0;curDepth = depth;
            }
            res += here->val;
            if (here->left) {
                NodeQ.push(here->left);
                depthQ.push(depth + 1);
            }
            if (here->right) {
                NodeQ.push(here->right);
                depthQ.push(depth + 1);
            }
        }
        return res;
    }
};

int main() {

    Solution sol;
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    int x = sol.deepestLeavesSum(node);

	return 0;
}