#include "List.h"
#include <iostream>
using namespace std;

List::List(){

	cout << "Enter Array Size: ";
	cin >> size;
	arr = new int[size];
	cout << "Enter " << size << " values:\n";
	for (int i = 0; i < size; ++i)
		cin >> arr[i];

}
//----------------------------------------//
void List::insert_start(int val){
	
	int* tempArr = new int[size + 1];
	tempArr[0] = val;
	for (int i = 0,j = 1; i < size; ++i,++j)
		tempArr[j] = arr[i];
	++size;
	delete[] arr;
	arr = tempArr;
}
//----------------------------------------//
void List::insert_end(int val) {
	int* tempArr = new int[size + 1];
	tempArr[size] = val;
	for (int i = 0; i < size; ++i)
		tempArr[i] = arr[i];
	++size;
	delete[] arr;
	arr = tempArr;
}
//----------------------------------------//
void List::insert_at(int index, int val){

	int* tempArr = new int[size + 1];
	for (int i = 0, j = 0; i < size + 1; ++i) {
		if (i == index)
			tempArr[index] = val;
		else
			tempArr[i] = arr[j++];
	}
	++size;
	delete[] arr;
	arr = tempArr;
}
//----------------------------------------//
void List::remove_start() {
	int* tempArr = new int[size - 1];
	for (int i = 1, j = 0; i < size; ++i, ++j)
		tempArr[j] = arr[i];
	--size;
	delete[] arr;
	arr = tempArr;
}
//----------------------------------------//
void List::remove_end() {
	int* tempArr = new int[size - 1];
	for (int i = 0; i < size - 1; ++i)
		tempArr[i] = arr[i];
	--size;
	delete[] arr;
	arr = tempArr;
}
//----------------------------------------//
void List::remove_at(int index) {
	int* tempArr = new int[size - 1];
	for (int i = 0,j=0; i < size; ++i) {
		if (i == index)
			continue;
		else
			tempArr[j++] = arr[i];
	}
	--size;
	delete[] arr;
	arr=tempArr;
}
//----------------------------------------//
bool List::is_empty() {
	if (size == 0)
		return true;
	else
		return false;
}
//----------------------------------------//
void List::print(){

	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
	cout << "Size: " << size << endl;

}


