#include "City.h"
#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

int main() {

	City beijing("BEIJING", pair<double, double>(39.9042, 116.4074));
	City dublin("DUBLIN", pair<double, double>(53.3498, 6.2603));
	City hongKong("HONG KONG", pair<double, double>(22.3964, 114.1095));
	City london("LONDON", pair<double, double>(51.5074, 0.1278));
	City losAngeles("LOS ANGELES", pair<double, double>(34.0522, 118.2437));
	City newYork("NEW YORK", pair<double, double>(40.7128, 74.0059));
	City madrid("MADRID", pair<double, double>(40.4168, 3.7038));	
	City moscow("MOSCOW", pair<double, double>(55.7558, 37.6173));

	//cout << dublin;
	//cout << newYork;
	//cout << london;
	//cout << madrid;

	BinaryTree cityTree;

	cityTree.insert(losAngeles);
	cityTree.insert(london);
	cityTree.insert(dublin);
	cityTree.insert(beijing);
	cityTree.insert(hongKong);
	cityTree.insert(moscow);
	cityTree.insert(newYork);
	cityTree.insert(madrid);

	cityTree.preOrderTraversal();

	cout << "\nNumber of children: " << cityTree.countChildren() << endl;

	system("pause");
	return 0;
}
