#include <iostream>
using namespace std;

template <typename T, typename X>
void Print(T *arr, X size)
{
	for(int i=0; i<size; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}
/////////////////////////////////////////

template <typename T, typename X>
bool FindElement(T *arr, X size, T find)
{
	for(int i=0; i<size; ++i){
		if(arr[i]==find)
			return true;
	}
	return false;
}
/////////////////////////////////////////

template <typename T, typename X>
void Union(T *arr1, X size1, T *arr2, X size2)
{
	for(int i=0; i<size1; ++i){
		int check=0;
		for(int j=0; j<size2; ++j){
			if(arr1[i]==arr2[j]){
				check=1;
				break;
			}			
		}
		if(check==0)
			cout<<arr1[i]<<" ";
	}
	for(int i=0; i<size2; ++i)
		cout<<arr2[i]<<" ";
	cout<<endl;
}
/////////////////////////////////////////

template <typename T, typename X>
void Intersection(T *arr1, X size1, T *arr2, X size2)
{
	int tempSize=0;
	for(int i=0; i<size1; ++i)
		for(int j=0; j<size2; ++j){
			if(arr1[i]==arr2[j])
				++tempSize;
		}
	
	T *tempArr=new T[tempSize];		//dynamic because can also return pointer to dynamic array
	X index=0;
	for(int i=0; i<size1; ++i)
		for(int j=0; j<size2; ++j){
			if(arr1[i]==arr2[j])
				tempArr[index++]=arr1[i];
		}
	for(int i=0; i<tempSize; ++i)
		cout<<tempArr[i]<<" ";
	cout<<endl;
}
/////////////////////////////////////////

template <typename T, typename X>
bool Disjoint(T *arr1, X size_1, T *arr2, X size_2)
{
	for(int i=0; i<size_1; ++i){
		for(int j=0; j<size_2; ++j)
			if(arr1[i]==arr2[j])
				return false;
	}
	return true;
}
////////////////////////////////////////



int main()
{
	float A[9]={10.43,4.3,5.61,6.90,11.57,12.11,3.8,2.4,9.5};
	float B[13]={11.01,12.34,16.5,3.8,8.1,2.4,9.11,12.11,6.75,10.43,20.2,2.1,4.3};
	
	
	cout<<"Set A: "; Print(A,9);
	cout<<"Set B: "; Print(B,13);
	cout<<"\nSearch Status: "<<FindElement<float,int>(B,13,4.3)<<endl;
	cout<<"\nUnion: "; Union(A,9,B,13);
	cout<<"\nIntersection: "; Intersection(A,9,B,13);
	cout<<"\nDisjoint Status: "<<Disjoint(A,9,B,13)<<endl;
	
	return 0;
}
