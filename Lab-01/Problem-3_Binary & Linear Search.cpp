#include <iostream>
using namespace std;

template <typename T>
bool Linear_Search(T Array[][4], T rows, T cols, T find)
{
	for(int i=0; i<rows; ++i)
		for(int j=0; j<cols; ++j){
			if(Array[i][j]==find)
				return true;
		}
	return false;
}

template <typename T>
void SelectionSort(T arr[][4], T R, T C){
	
	T tempArr[R*C], tempIndex=0, tempSize=R*C;
	for(int i=0; i<R; ++i)
		for(int j=0; j<C; ++j)
			tempArr[tempIndex++]=arr[i][j];

	for(int i=0; i<tempSize-1; ++i){
		for(int j=i+1; j<tempSize; ++j){
			if(tempArr[j]<tempArr[i]){
				int temp=tempArr[i];
				tempArr[i]=tempArr[j];
				tempArr[j]=temp;
			}
		}
	}
	int index=0;
	for(int i=0; i<R; ++i)
		for(int j=0; j<C; ++j)
			arr[i][j]=tempArr[index++];
}

template <typename T>
bool Binary_Search(T Array[][4], T rows, T cols, T target)
{
    int low=0, high=(rows*cols-1);
    while(low<=high){
    	
        int mid=(low+high)/2;
        int x=mid/cols;
        int y=mid%cols;
        if(Array[x][y]==target)
            return true;
        else if(Array[x][y]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    return false;
}

int main()
{
	int Arr[3][4] = {{12,43,66,78}, {34,21,72,81}, {7,13,2,59}};
	int Find=2;
	cout<<"Linear Search: "<<Linear_Search<int>(Arr,3,4,Find)<<endl;
	
	int Arr2[4][4] = {{10,20,30,40}, {15,25,35,45}, {27,29,37,48}, {32,33,39,50}};
	int Find_2=29;
	SelectionSort(Arr2,4,4);
	cout<<"Binary Search: "<<Binary_Search(Arr2,4,4,Find_2)<<endl;
		
	return 0;
}
