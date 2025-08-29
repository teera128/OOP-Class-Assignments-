#include <iostream>
using namespace std;

template <class T>
T findMax(T a, T b, T c)
{
	T max = a;

	if (max < b)
		max = b;
	if (max < c)
		return c;
	else
		return max;
}

int main()
{
	int a, b, c;
	double g, h, i;

	cout << "Test Find Max 1" << endl;
	cout << "Press Number 1 : " << endl;
	cin >> a;
	cout << "Press Number 2 : " << endl;
	cin >> b;
	cout << "Press Number 3 : " << endl;
	cin >> c;
	cout << "Max of " << a << ", " << b << ", " << c << " is " << findMax(a, b, c) << endl;
	cout << endl;

	cout << "Test Find Max 2" << endl;
	cout << "Press Number 1 : " << endl;
	cin >> g;
	cout << "Press Number 2 : " << endl;
	cin >> h;
	cout << "Press Number 3 : " << endl;
	cin >> i;
	cout << "Max of " << g << ", " << h << ", " << i << " is " << findMax(g, h, i) << endl;
	cout << endl;

	return 0;
}