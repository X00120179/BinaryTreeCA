#include "City.h"
#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

int main() {

	City dublin("DUBLIN", pair<double, double>(53.3498, 6.2603));
	City newYork("NEW YORK", pair<double, double>(40.7128, 74.0059));
	City london("LONDON", pair<double, double>(51.5074, 0.1278));
	City madrid("MADRID", pair<double, double>(40.4168, 3.7038));

	//cout << dublin;
	//cout << newYork;
	//cout << london;
	//cout << madrid;

	BinaryTree cityTree;

	cityTree.insert(dublin);
	cityTree.insert(newYork);
	cityTree.insert(london);
	cityTree.insert(madrid);

	cityTree.preOrderTraversal();

	system("pause");
	return 0;
}
