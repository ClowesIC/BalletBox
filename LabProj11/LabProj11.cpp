#include <iostream>
#include<fstream>

using namespace std;

// Node type:
struct TreeNode {
	string studentName;
	float averageGrade;
	int numCourses;
	TreeNode* left;
	TreeNode* right;
};

void Insert(TreeNode*& root, string studentName, float grade) {
	if (root == NULL) {
		root = new TreeNode;
		root->left = NULL;
		root->right = NULL;
		root->averageGrade = grade;
		root->studentName = studentName;
		return;
	}
	if (studentName < root->studentName) {
		Insert(root->left, studentName, grade);
	}
	else if (studentName > root->studentName) {
		Insert(root->right, studentName, grade);
	}
	else if (studentName == root->studentName) {
		return;
	}
	return;
}

void PrintTree(TreeNode* root, ofstream& out) {
	if (root == NULL) {
		return;
	}
	//in order traversal
	PrintTree(root->left, out);
	out << root->studentName << " " << root->averageGrade << endl;
	PrintTree(root->right, out);
}


int main() {
	string fileName;
	string outputFile;


	cout << "Please type the text file name: ";
	cin >> fileName;
	ifstream infile(fileName);

	cout << endl << "Please give the output text file name: ";
	cin >> outputFile;
	
	if (!infile) {
		cout << "Error! " << fileName << " failed to open.";
	}

	//create Binary Search Tree
	TreeNode* root = NULL;
	string studentName, courseName;
	float grade = 0;

	//read lines from input file
	while (infile >> studentName >> courseName >> grade) {
		//insert into BST
		Insert(root, studentName, grade);
	}

	infile.close();

	//open an outputfile
	ofstream outfile(outputFile);
	if (!outfile) {
		cout << "Error opening " << outputFile << " file";
	}

	PrintTree(root, outfile);

	outfile.close();

	cout << "You are done! You can open the file " << outputFile << " to check." << endl;

	return 0;
	


}

//OUTPUT in console:
/*
Please type the text file name: input.txt

Please give the output text file name: sorted.txt
You are done! You can open the file sorted.txt to check.*/

///OUTPUT in sorted.txt
/*
Alex 60
Ben 70
Bob 70
Bruce 85
Carte 60
Charles 90
Eddy 35
Luke 90
Mike 80
Patric 30
Peter 95
Pique 50
*/