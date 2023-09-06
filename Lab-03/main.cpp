#include <iostream>
#include "List.cpp"
using namespace std;

int main() {

	List obj;
	obj.print();
	cout<<endl;
	obj.insert_start(1);
	obj.insert_end(5);
	obj.insert_at(2,10);
	obj.print();
	cout<<endl;
	obj.remove_start();
	obj.remove_end();
	obj.remove_at(2);
	obj.print();
	cout << "Empty Status: "<<obj.is_empty() << endl;
	return 0;
}
