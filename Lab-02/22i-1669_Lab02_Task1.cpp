#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n = 5;

	for (int a = 1; a < n; ++a) {
		for (int b = 1; b < n; ++b) {
			for (int c = 1; b < n; ++b) {
				int d = cbrt(pow(a, 3) + pow(b, 3) - pow(c, 3));
				if(d>0 && a>0 && b>0 && c>0)
					cout << a << "," << b << "," << c << "," << d << endl;
			}
		}
	}

	return 0;
}

