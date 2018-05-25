#include "PointOctree.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	qoaed::PointOctree<int> po;
	
	po.insert(3, 2, 4, 1);
	po.insert(3, -2, 5, 2);
	po.insert(-1, -2, -5, 3);
	po.insert(12, 1, 2, 4);
	po.insert(3, 2, 1, 5);
	po.insert(10, 1, 3, 6);
	po.insert(6, 6, 6, 7);
	po.insert(1, 1, 1, 8);
	po.insert(1, 2, 3, 9);
	po.insert(1, 4, 3, 9);
	po.insert(1, 5, 3, 9);
	po.insert(1, 1, 3, 9);
	po.insert(1, 6, 3, 9);
	po.insert(1, 2, 2, 9);
	po.insert(1, 8, 3, 9);
	po.insert(1, 2, 4, 9);
	po.insert(1, 2, 5, 9);
	po.insert(1, 2, 7, 9);
	po.insert(1, 2, 8, 9);
	
	//Point3D p(1,1,1);
	//po.delete_(Point(1,1,1),0,0);
	
	cout << "PointOctree, BFS: \n";
	po.visit_dfs([](auto& n){ cout << " " << n.get_x() << " " << n.get_y() << " " << n.get_z() << "\tValor: " << *n << '\n'; });
		
	/*
	fstream arch;	
	arch.open("puntos.data", fstream::out);
	po.visit_dfs([](auto& n){ arch  << n.get_x() << "\t" << n.get_y() << "\t" << n.get_z() << '\n'; });
	arch.close();
	cout <<  "puntos.txt\n";
	*/


	return 0;
}
