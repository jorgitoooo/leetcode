/* ---------------
 * Jorge L. Garcia
 * ~/~/2019
 * ---------------
 * Serialize &
 * Deserialize
 * Binary Tree
 */

#include<iostream>
#include<sstream>

#include<deque>
#include<stack>
#include<vector>

#include<string>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string    serialize(TreeNode* root);
TreeNode* deserialize(string data);

vector<TreeNode*> makeNodeVectorFrom(string s);
vector<string>    splitToVector(string s);

void printVectorOf(vector<TreeNode *> v);
void printVectorOf(vector<string> v);
void printTree(TreeNode *r);

int main(int argc, char **argv) {
/*	
	TreeNode* root = new TreeNode(1);
	TreeNode* c0   = new TreeNode(2);
	TreeNode* c1   = new TreeNode(3);
	TreeNode* c2   = new TreeNode(4);
	TreeNode* c3   = new TreeNode(5);
	root->left  = c0;
	root->right = c1;
	c1->left  = c2;
	c1->right = c3;

	cout << serialize(root) << endl;

	printTree(deserialize(serialize(root)));
	cout << endl;
*/
	//TreeNode *root = deserialize("[5,4,7,3,null,2,null,-1,null,9]");
	//cout << serialize(root) << endl;
	
	cout << 2 % 3 << endl;

	return 0;
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
        if(!root) return "[]";
        
        string serialized = "[";
        deque<TreeNode*> parents;
        stack<TreeNode*> children;
       
        serialized += to_string(root->val);

        parents.push_back(root->left);        
        parents.push_back(root->right);

        
        while(!parents.empty()) {
            for(int i = 0; i < parents.size(); i++) {
                if(parents[i]) {
                    serialized += "," + to_string(parents[i]->val);
                    children.push(parents[i]->left);
                    children.push(parents[i]->right);
                } else {
                    serialized += ",null";
                }
            }
            parents.clear();
            while(!children.empty()) {
                parents.push_front(children.top());
                children.pop();
            }
        }
        return serialized + "]";
}

TreeNode* deserialize(string data) {

	vector<TreeNode*> nodes = makeNodeVectorFrom(data);

        if(nodes.size() == 0) return nullptr;


	// Will iterate through the vector starting from the right most child
	//   of the tree the left most child of the root
        for(int i = nodes.size() - 1; i >= 1; i--) {
		TreeNode *node = nodes[i];
		
		if(node) {
			if(i % 2 == 0 && nodes[(i/2) - 1]) nodes[(i/2) - 1]->right = node;
				
			else if(nodes[(i/2)]) nodes[(i/2)]->left = node;
		}	
	}

	printTree(nodes[0]);
	cout << endl;

        return nodes[0];
}

vector<string> splitToVector(string s) {
        vector<string> elements;
        
	// Remove square backets
	s = s.substr(1, s.length() - 2);

	istringstream strm(s);
	string token;

	while(getline(strm, token, ',')) 
		elements.push_back(token);

        return elements;
}

vector<TreeNode*> makeNodeVectorFrom(string s) {
        vector<TreeNode*> nodes;
        
	// Remove square backets
	s = s.substr(1, s.length() - 2);

	istringstream strm(s);
	string token;

	while(getline(strm, token, ',')) {
		if(token == "null") nodes.push_back(nullptr);

		else nodes.push_back(new TreeNode(stoi(token)));
	}

        return nodes;
}

void printTree(TreeNode *r) {
	if(r) {
		cout << r->val << ", ";
		printTree(r->left);
		printTree(r->right);
	}
}

void printVectorOf(vector<string> v) {
	for(string el : v) cout << el << " ";
	cout << endl;
}

void printVectorOf(vector<TreeNode *> v) {
	for(TreeNode *el : v) cout << el->val << " ";
	cout << endl;
}
