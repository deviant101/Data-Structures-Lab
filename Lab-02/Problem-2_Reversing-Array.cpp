#include <iostream>
using namespace std;

void Reverse(int arr[], int size){
	
	int half=size/2;
	for(int i=0; i<half; ++i){
		int temp=arr[i];
		arr[i]=arr[--size];
		arr[size]=temp;
	}
}

int main(){
	
	int size=19;
	int arr[size]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	Reverse(arr,size);
	
	for(int i=0; i<size; ++i)
		cout<<arr[i]<<" ";
	
	return 0;
}
