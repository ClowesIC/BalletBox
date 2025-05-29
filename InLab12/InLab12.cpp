// Academic Integrity Affidavit:
// I certify that this program code is my work.  Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: Ian Clowes
// Section: 002-Lab CMPSCI 122
// Assignment: InLab12 (binary tree)
//


#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef int Type;
/////////////////////////////////////////////////////////////////////
// Declaration for the BinNode class
/////////////////////////////////////////////////////////////////////
class BinNode {
public:
	Type data;
	BinNode* left;
	BinNode* right;
};
/////////////////////////////////////////////////////////////////////
// NOTE: Place your 3 functions below here
/////////////////////////////////////////////////////////////////////

int CountLeaves(BinNode* root) {

	if (root == nullptr) {
		return 0;
	}
	if (root->left == nullptr && root->right == nullptr) {
	return 1;
	}
	return CountLeaves(root->left) + CountLeaves(root->right);
	
}

int CountSmaller5(BinNode* root) {
	int count = 0;

	if (root == nullptr) {
		return 0;
	}

	if (root->data <= 5) {
		count = 1;
	}

	int leftCount = CountSmaller5(root->left);
	int rightCount = CountSmaller5(root->right);

	return count + leftCount + rightCount;

}



int FindMin(BinNode* root) {
	if (root == nullptr) {
		return INT_MIN;
	}

	int leftMin = FindMin(root->left);
	int rightMin = FindMin(root->right);

	int minValue = root->data;

	if (leftMin < minValue) {
		minValue = leftMin;
	}

	if (rightMin < minValue) {
		minValue = rightMin;
	}

	return minValue;
}


/////////////////////////////////////////////////////////////////////
// Below are functions that I implemented for binary trees
// Used by the testing program
/////////////////////////////////////////////////////////////////////
class NodePrinter {
public:
	BinNode* node;
	int rLeft;
	int rRight;
	int level;
	NodePrinter(BinNode* n, int l, int r, int lv) {
		node = n;
		rLeft = l;
		rRight = r;
		level = lv;
	}
};
void insert(BinNode*& root, Type data) {
	if (root == NULL) {
		root = new BinNode;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else if (data > root->data) {
		insert(root->right, data);
	}
	else if (data < root->data) {
		insert(root->left, data);
	}
}
void ShowTree(BinNode* root) {
	if (root == NULL) {
		return;
	}
	NodePrinter initP(root, 0, 79, 0);
	char lineBuffer0[80];
	char lineBuffer1[80];
	char lineBuffer2[80];
	char lineBuffer3[80];
	int curlevel = 0;
	queue<NodePrinter> pQueue;
	pQueue.push(initP);
	while (!pQueue.empty()) {
		for (int i = 0; i < 80; i++) {
			lineBuffer0[i] = ' ';
			lineBuffer1[i] = ' ';
			lineBuffer2[i] = ' ';
			lineBuffer3[i] = ' ';
		}
		while (!pQueue.empty() && pQueue.front().level == curlevel) {
			NodePrinter cur = pQueue.front();
			pQueue.pop();
			int mid = (cur.rLeft + cur.rRight) / 2;
			int lpos = (mid + cur.rLeft) / 2;
			int rpos = (mid + cur.rRight) / 2;
			if (cur.node->data >= 0 && cur.node->data <= 9) {
				lineBuffer0[mid] = cur.node->data + '0';
			}
			else if (cur.node->data >= 10 && cur.node->data <= 99) {
				int ldigit = cur.node->data % 10;
				int rdigit = cur.node->data / 10;
				lineBuffer0[mid] = ldigit + '0';
				lineBuffer0[mid - 1] = rdigit + '0';
			}
			else {
				lineBuffer0[mid] = '?';
			}
			//Line 1
			if (cur.node->left != NULL || cur.node->right != NULL) {
				lineBuffer1[mid] = '|';
			}
			//Line 2 & Line 3
			int ln = -1, rn = -1;
			if (cur.node->left != NULL && cur.node->right != NULL) {
				ln = lpos;
				rn = rpos;
				lineBuffer3[ln] = '|';
				lineBuffer3[rn] = '|';
				NodePrinter lp(cur.node->left, cur.rLeft, mid, curlevel + 1);
				NodePrinter rp(cur.node->right, mid, cur.rRight, curlevel + 1);
				pQueue.push(lp);
				pQueue.push(rp);
			}
			else if (cur.node->left != NULL) {
				ln = lpos;
				rn = mid;
				lineBuffer3[ln] = '|';
				NodePrinter lp(cur.node->left, cur.rLeft, mid, curlevel + 1);
				pQueue.push(lp);
			}
			else if (cur.node->right != NULL) {
				ln = mid;
				rn = rpos;
				lineBuffer3[rn] = '|';
				NodePrinter rp(cur.node->right, mid, cur.rRight, curlevel + 1);
				pQueue.push(rp);
			}
			if (ln >= 0) {
				for (int i = ln; i <= rn; i++) {
					lineBuffer2[i] = '-';
				}
			}
		}
		// Print lines
		for (int i = 0; i < 80; i++) {
			cout << lineBuffer0[i];
		}
		cout << endl;
		for (int i = 0; i < 80; i++) {
			cout << lineBuffer1[i];
		}
		cout << endl;
		for (int i = 0; i < 80; i++) {
			cout << lineBuffer2[i];
		}
		cout << endl;
		for (int i = 0; i < 80; i++) {
			cout << lineBuffer3[i];
		}
		cout << endl;
		curlevel++;
	}
}
void DeleteTree(BinNode*& root)
{
	if (root == nullptr)
		return;
	DeleteTree(root->left);
	DeleteTree(root->right);
	if (root->left != nullptr && root->left->left == nullptr && root->left->right
		== nullptr)
	{
		delete root->left;
		root->left = nullptr;
	}
	if (root->right != nullptr && root->right->left == nullptr && root->right -> right == nullptr)
	{
		delete root->right;
		root->right = nullptr;
	}
}
void inorder(BinNode* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void postorder(BinNode* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}
/////////////////////////////////////////////////////////////////////
// Below is the main function for the testing program
/////////////////////////////////////////////////////////////////////
int main() {
	cout << "Inserting 4,10,8,5,2,7,3,1,9 to empty BST." << endl;
	BinNode* root = NULL; // Empty BST
	insert(root, 4);
	insert(root, 10);
	insert(root, 8);
	insert(root, 5);
	insert(root, 2);
	insert(root, 7);
	insert(root, 3);
	insert(root, 1);
	insert(root, 9);
	cout << "Inorder Traversal: ";
	inorder(root);
	cout << endl;
	cout << "Postorder Traversal: ";
	postorder(root);
	cout << endl;
	cout << endl;
	ShowTree(root);
	// Uncomment the following to test your function
	 cout << "Total Number of leaves: " << CountLeaves(root) << endl;
	// Uncomment the following to test your function
	cout << "Total Number of Nodes with Value <= 5: " << CountSmaller5(root) << endl; if (root->right != nullptr && root->right->left == nullptr && root->right -> right == nullptr)
	{
		delete root->right;
		root->right = nullptr;
	}
}


//OUTPUT:
/*
Inserting 4, 10, 8, 5, 2, 7, 3, 1, 9 to empty BST.
Inorder Traversal : 1 2 3 4 5 7 8 9 10
Postorder Traversal : 1 3 2 7 5 9 8 10 4

4
|
---------------------------------------- -
|                                       |
2                                      10
|                                       |
-------------------- - ---------- -
|                   |                   |
1                   3                   8
|
---------- -
|         |
5         9
|
-- -
|
7



Total Number of leaves : 4
Total Number of Nodes with Value <= 5 : 5

*/
