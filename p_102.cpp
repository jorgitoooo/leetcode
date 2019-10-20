/* ---------------
 * Jorge L. Garcia
 * //2019
 * ---------------
 * BTree Level
 * Order Reversal
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include "treenode.h"

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root)
{
	if(!root) return vector<vector<int>>();

	vector<vector<int>> tl_order;
	vector<int> level;

	queue<TreeNode*> parents;
	queue<TreeNode*> children;

	parents.push(root);
	while(!parents.empty()) {
		level.emplace_back(parents.front()->val);

		if(parents.front()->left)
	  	children.push(parents.front()->left);
		if(parents.front()->right)
			children.push(parents.front()->right);
		
		parents.pop();
		if(parents.empty()) {
			while(!children.empty()) {
				parents.push(children.front());
				children.pop();
			}
			tl_order.emplace_back(level);
			level.clear();
		}
	}	
	return tl_order;
}

int main(int argc, char **argv)
{
	TreeNode *r  = new TreeNode(0);
	TreeNode *l1 = new TreeNode(1);
	TreeNode *r1 = new TreeNode(2);
	TreeNode *l2 = new TreeNode(3);
	TreeNode *r2 = new TreeNode(4);

	r->left = l1;
	r->right = r1;
	r1->left = l2;
	r1->right = r2;

	vector<vector<int>> lo_v = levelOrder(r);

	for(auto const & level : lo_v) {
		for(auto const & node : level)
			printf("%d ", node);
		printf("\n");
	}

	return 0;
}
