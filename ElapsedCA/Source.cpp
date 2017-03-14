#include "City.h"
#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

int main() {

	City beijing("BEIJING", 39.9042, 116.4074);
	City dublin("DUBLIN", 53.3498, 6.2603);
	City hongKong("HONG KONG", 22.3964, 114.1095);
	City london("LONDON", 51.5074, 0.1278);
	City losAngeles("LOS ANGELES", 34.0522, 118.2437);
	City newYork("NEW YORK", 40.7128, 74.0059);
	City madrid("MADRID", 40.4168, 3.7038);	
	City moscow("MOSCOW", 55.7558, 37.6173);

	BinaryTree cityTree;

	cityTree.insert(losAngeles);
	cityTree.insert(london);
	cityTree.insert(dublin);
	cityTree.insert(beijing);
	cityTree.insert(hongKong);
	cityTree.insert(moscow);
	cityTree.insert(newYork);
	cityTree.insert(madrid);

	cout << "ADS 2 C++ Elapsed CA.\nLee Healy - X00120179.\n\n\n\n\n";

	cityTree.preOrderTraversal();

	cout << "\nNumber of cities: " << cityTree.countChildren() << ".\n" << endl;

	cout << "Smallest city (by name) in the tree is: " << cityTree.findSmallest() << endl;

	//cityTree.removeCity(dublin);
	cityTree.preOrderTraversal();

	cout << "\nNumber of cities: " << cityTree.countChildren() << ".\n" << endl;


	cout << "CALCULATING DISTANCE FUNCTION NOW" << endl;
	cityTree.compareCities(dublin);





	system("pause");
	return 0;
}
