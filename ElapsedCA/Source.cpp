#include "timer.h"
#include "City.h"
#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

// Lee Healy X00120179

int main() {



	// Start Timers.
	double wallStart = get_wall_time();
	double cpuStart = get_cpu_time();



	// Creating cities to be used in the binary tree later.
	City beijing("BEIJING", 39.9042, 116.4074);
	City dublin("DUBLIN", 53.3498, 6.2603);
	City hongKong("HONG KONG", 22.3964, 114.1095);
	City london("LONDON", 51.5074, 0.1278);
	City losAngeles("LOS ANGELES", 34.0522, 118.2437);
	City newYork("NEW YORK", 40.7128, 74.0059);
	City madrid("MADRID", 40.4168, 3.7038);
	City moscow("MOSCOW", 55.7558, 37.6173);



	// Creating the binary tree for cities and naming it cityTree.
	BinaryTree cityTree;



	// Inserting the multiple cities previously created.
	cityTree.insert(losAngeles);
	cityTree.insert(london);
	cityTree.insert(dublin);
	cityTree.insert(beijing);
	cityTree.insert(hongKong);
	cityTree.insert(moscow);
	cityTree.insert(newYork);
	cityTree.insert(madrid);



	// Message at top of terminal.
	cout << "ADS 2 C++ Elapsed CA.\nLee Healy - X00120179.\n" << endl;



	// 1. DISPLAY THE TREE.
	cout << "\n\n\n### DISPLAYING TREE ###" << endl;
	cityTree.preOrderTraversal();



	// 2. SEARCH FOR A TREE BY ITS OBJECT NAME.
	cout << "\n\n\n### SEARCHING TREE FOR DUBLIN ###" << endl;
	cityTree.search(dublin); // Should return Dublin.



	// 3. SEARCH FOR A CITY BY ITS NAME.
	cout << "\n\n\n### SEARCHING TREE FOR DUBLIN ###" << endl;
	cityTree.searchName("DUBLIN"); // Should return Dublin + Co-ordinates.
	cout << "\n\n\n### SEARCHING TREE FOR HONG KONG ###" << endl;
	cityTree.searchName("HONG KONG"); // Should return Hong Kong + Co-ordinates.
	cout << "\n\n\n### SEARCHING TREE FOR NEW YORK ###" << endl;
	cityTree.searchName("NEW YORK"); // Should return New York + Co-ordinates.



	// 4. SEARCH FOR A CITY BY ITS GPS CO-ORDINATES.
	cout << "\n\n\n### SEARCHING TREE FOR CO-ORDINATES 34.0522, 118.2437 ###" << endl;
	cityTree.searchGPS(34.0522, 118.2437); // Should return Los Angeles + Co-ordinates.



	// 5. GET THE SMALLEST CITY IN THE TREE.
	cout << "\n\n\n### FINDING SMALLEST TREE### " << endl;
	cout << "\nSmallest city (by name) in the tree is: " << cityTree.findSmallest() << endl;



	// 6. REMOVE A CITY FROM THE TREE.
	cout << "\n\n\n### REMOVING MADRID ###" << endl;
	cityTree.removeCity(madrid); // Should remove Madrid object from the tree, shouldn't be in the next display call.



	// 7. DISPLAY THE TREE AFTER REMOVING A CITY.
	cout << "\n\n### DISPLAYING TREE ###" << endl;
	cityTree.preOrderTraversal();



	// 8. LIST THE CITIES CLOSEST TO LONDON WITHIN 1000 KILOMETRES.
	cout << "\n\n\n### DISPLAYING CITIES WITHIN 1000 KM FROM LONDON ###" << endl;
	cityTree.compareCities(london, 1000);



	// 9. LIST THE CITIES CLOESEST TO DUBLIN WITHIN 8000 KILOMETRES.
	cout << "\n\n\n### DISPLAYING CITIES WITHIN 8000 KM FROM DUBLIN ###" << endl;
	cityTree.compareCities(dublin, 8000);



	// 10. GET THE MAX HEIGHT OF THE BINARY TREE.
	cout << "\n\n\n### FINDING MAX HEIGHT OF TREE ###" << endl;
	cout << "The Binary Search Tree has a max height of: " << cityTree.maxHeight() << "\n" << endl;



	//  Stop timers
	double wallEnd = get_wall_time();
	double cpuEnd = get_cpu_time();



	// Print out running time results.
	cout << "\n\n######### RUN TIMES ###########" << endl;
	cout << "\tWall Time = " << wallEnd - wallStart << endl;
	cout << "\tCPU Time  = " << cpuEnd - cpuStart << endl;
	cout << "###############################\n\n" << endl;



	system("pause");
	return 0;
}
