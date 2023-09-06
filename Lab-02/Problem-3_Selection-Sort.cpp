#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size){
	
	for(int i=0; i<size-1; ++i){
		for(int j=i+1; j<size; ++j){
			if(arr[j]<arr[i]){		//checking for next smaller value in non-sorted part
				int temp=arr[i];
				arr[i]=arr[j];		//putting smaller value at ith index in sorted part
				arr[j]=temp;		//previous ith value at jth index in non-sorted part
			}
		}
	}	
}

int main()
{
	int size=0;
	cout<<"Enter Array Size: ";
	cin>>size;
	int *arr=new int[size];		//Allocating 2d Array
	cout<<"Array Inputs: ";
	for(int i=0; i<size; ++i)	//array input
		cin>>arr[i];
	
	SelectionSort(arr,size);		//Sorting function
	
	cout<<"Sorted Array: ";
	for(int i=0; i<size; ++i)
		cout<<arr[i]<<" ";
		
	delete[] arr;		//Deallocating
	arr=nullptr;
	
	return 0;
}
