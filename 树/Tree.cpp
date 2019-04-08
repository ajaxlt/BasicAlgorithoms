#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val) :
            val(_val), left(nullptr), right(nullptr) {}
};
inline int parent(int i) {
    return (i - 1) / 2;
}
inline int left(int i) {
    return i * 2 + 1;
}
inline int right(int i) {
    return i * 2 + 2;
}
// f0. 由 层次遍历 生成 二叉树
TreeNode* generateTree(const vector<string>& a, int i) {
    TreeNode* root = new TreeNode(atoi(a[i].c_str()));
    int lchd = left(i), rchd = right(i);
    if (lchd < a.size() && a[lchd] != "#") root->left = generateTree(a, lchd);
    if (rchd < a.size() && a[rchd] != "#") root->right = generateTree(a, rchd);
    return root;
}
// f1. 二叉树的层次遍历
void levelorder(TreeNode* root, vector<int>& tmp) {
    if (!root) return;
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        TreeNode* cur = Q.front();
        Q.pop();
        tmp.push_back(cur->val);
        if (cur->left) Q.push(cur->left);
        if (cur->right) Q.push(cur->right);
    }
}
// f2. 二叉树的前序遍历(递归)
void preorder1(TreeNode* root, vector<int>& tmp) {
    if (!root) return;
    tmp.push_back(root->val);
    preorder1(root->left, tmp);
    preorder1(root->right, tmp);

}
// f3. 二叉树的前序遍历(循环)
void preorder2(TreeNode* root, vector<int>& tmp) {
    if (!root) return;

    stack<TreeNode*> stk;

    while (root || !stk.empty()) {
        if (root) {
            tmp.push_back(root->val); // 先打印根
            stk.push(root->right); // 存储右儿子
            root = root->left; // 访问左儿子
        }
        else {
            root = stk.top();
            stk.pop();
        }
    }
}
// f4. 二叉树的中序遍历(递归)
void inorder1(TreeNode* root, vector<int>& tmp) {
    if (!root) return;
    inorder1(root->left, tmp);
    tmp.push_back(root->val);
    inorder1(root->right, tmp);
}
// f5. 二叉树的中序遍历(循环)
void inorder2(TreeNode* root, vector<int>& tmp) {
    if (!root) return;

    stack<TreeNode*> stk;

    while (root || !stk.empty()) {
        if (root) {
            stk.push(root);
            root = root->left;
        }
        else {
            TreeNode* par = stk.top();
            stk.pop();

            tmp.push_back(par->val);
            root = par->right;
        }
    }
}
// f6. 二叉树的后序遍历(递归)
void postorder1(TreeNode* root, vector<int>& tmp) {
    if (!root) return;
    postorder1(root->left, tmp);
    postorder1(root->right, tmp);
    tmp.push_back(root->val);
}
// f7. 二叉树的后序遍历(循环)
void postorder2(TreeNode* root, vector<int>& tmp) {
    if (!root) return;

    stack<TreeNode*> stk;

    while (root || !stk.empty()) {
        if (root) {
            tmp.push_back(root->val); // 先打印根
            stk.push(root->left); // 存储左儿子
            root = root->right; // 访问右儿子
        }
        else {
            root = stk.top();
            stk.pop();
        }
    }
    reverse(tmp.begin(), tmp.end());
}
inline void printArray(const vector<int> tmp) {
    for (int n : tmp) cout << n << " ";
    cout << endl;
}
int main() {
    vector<string> a = {"6", "12", "4", "1", "2", "5", "7", "#", "#", "#", "10"};
    TreeNode* root = generateTree(a, 0);

    vector<int> tmp;

    cout << "层次遍历: ";
    levelorder(root, tmp);
    printArray(tmp);

    cout << "前序遍历(递归): ";
    tmp.clear();
    preorder1(root, tmp);
    printArray(tmp);

    cout << "前序遍历(循环): ";
    tmp.clear();
    preorder2(root, tmp);
    printArray(tmp);

    cout << "中序遍历(递归): ";
    tmp.clear();
    inorder1(root, tmp);
    printArray(tmp);

    cout << "中序遍历(循环): ";
    tmp.clear();
    inorder2(root, tmp);
    printArray(tmp);

    cout << "后序遍历(递归): ";
    tmp.clear();
    postorder1(root, tmp);
    printArray(tmp);

    cout << "后序遍历(循环): ";
    tmp.clear();
    postorder2(root, tmp);
    printArray(tmp);

    return 0;
}