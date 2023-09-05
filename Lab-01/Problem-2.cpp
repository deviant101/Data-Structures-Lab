#include <iostream>
#include <string>
using namespace std;

template <typename T, typename X>
class Numbers{
	private:
		T A;
		X B;
	public:
		Numbers(T A1, X B1){
			A=A1;
			B=B1;
		}
		T Asquare(){
			T result=A*A;
			return result;
		}
		T division(){
			if(B!=0)
				return A/B ;
			else
				return 0;
		}
};
int main()
{
	Numbers <float,int>num(10.9,3);
	cout <<" A square : "<< num.Asquare()<<endl;
	cout <<" A/B : "<< num.division()<<endl;
}
