#include <iostream>
#include "time.h"
#include "Array.h"
using namespace std;

int main() {
	srand(time(0));
	Array A;
	A.Init();
	A.Show();
	A.PrintMinMax();
	cout << endl;
	A.SetSizeArr(5);
	A.Show();
	A.Sort(1);
	A.Show();
	cout << endl;
	A.SetSizeArr(10);
	A.Show();
	A.Sort(0);
	A.Show();
}