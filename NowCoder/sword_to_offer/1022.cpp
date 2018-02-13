#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> nodeList;
        queue<TreeNode *> Q;
        TreeNode* t = root;
        if(!root)  //空树
        {
            return nodeList;
        }
        Q.push(root);
        while(!Q.empty())
        {
            t = Q.front();
            nodeList.push_back(t->val);
            Q.pop();
            //注意判断左右子树是否为NULL
            if(t->left)
                Q.push(t->left);
            if(t->right)
                Q.push(t->right);
        }
        return nodeList;
    }
};

int main()
{
    Solution s1;
    return 0;
}