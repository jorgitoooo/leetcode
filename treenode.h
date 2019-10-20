#ifndef __TREENODE__
#define __TREENODE__
typedef struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;
#endif
