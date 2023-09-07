#include <iostream>
#include "List.cpp"
using namespace std;

int main() {

	List obj;
	obj.print();
	cout << "Inserting at start: ";
	obj.insert_start(1);
	obj.print();

	cout << "Inserting at end: ";
	obj.insert_end(5);
	obj.print();

	cout << "Inserting 10 at 2 index: ";
	obj.insert_at(2,10);
	obj.print();

	cout << "Removing from start: ";
	obj.remove_start();
	obj.print();

	cout << "Removing from end: ";
	obj.remove_end();
	obj.print();

	cout << "Removing element at 2 index: ";
	obj.remove_at(2);
	obj.print();

	cout << "Next to 3rd value : " << obj.Next(3) << "\n\n";

	cout<<"Previous to 3rd value : "<<obj.Previous(3) << "\n\n";

	cout << "Empty Status: "<<obj.is_empty() << "\n\n";

	cout << "Selection Sort: ";
	obj.sort();
	obj.print();

	cout << "Replacing 99 at 4th index: ";
	obj.replace_by_index_value(4, 99);
	obj.print();
	
	obj.sort();
	cout<<"Index of 4: "<<obj.search(4) << "\n\n";
	
	cout<<"Duplicate 5 Status: "<<obj.search_duplicate(1) << "\n\n";
	return 0;
}
