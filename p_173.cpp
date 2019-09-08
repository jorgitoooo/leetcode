/* ---------------
 * Jorge L. Garcia
 * 9/8/2019
 * ---------------
 * Binary Search
 * Tree Iterator
 */

#include <iostream>
#include <stack>

using namespace std;

typedef struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class BSTIterator
{
    stack<TreeNode*> stk;
    void get_leftmost_child(TreeNode *root)
    {
        stk.push(root);
        TreeNode *tmp_node = root;

        while(tmp_node->left)
        {
            stk.push(tmp_node->left);
            tmp_node = tmp_node->left;
        }
    }
public:
    BSTIterator(TreeNode* root)
    {
        if(root)
        {
            get_leftmost_child(root);
        }
    }
    
    int next()
    {
	if(this->hasNext())
	{
		TreeNode *node_to_return  = stk.top();
		stk.pop();
		
		if(node_to_return->right)
		{
		    get_leftmost_child(node_to_return->right);
		}
		return node_to_return->val;
	}
	return -1;
    }
    
    bool hasNext()
    {
        return stk.size() > 0;
    }
};

int main(int argc, char **argv)
{
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(3);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(1);
	root->right->right = new TreeNode(7);

	BSTIterator *iter = new BSTIterator(root);

	printf("next() => %d\n", iter->next());
	printf("hasNext() => %d\n", iter->hasNext());
	printf("next() => %d\n", iter->next());
	printf("next() => %d\n", iter->next());
	printf("hasNext() => %d\n", iter->hasNext());
	printf("next() => %d\n", iter->next());
	printf("hasNext() => %d\n", iter->hasNext());
	printf("next() => %d\n", iter->next());
	printf("hasNext() => %d\n", iter->hasNext());
	printf("next() => %d\n", iter->next());
	printf("hasNext() => %d\n", iter->hasNext());
	printf("next() => %d\n", iter->next());
	printf("hasNext() => %d\n", iter->hasNext());


	return 0;
}
