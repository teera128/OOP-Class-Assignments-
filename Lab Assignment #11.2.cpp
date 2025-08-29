#include <iostream>
using namespace std;

template <class T>
class Array
{
	T box[6];
public:
	Array()
	{
	}

	Array(T* setNum)
	{
		setArray(setNum);
	}
	
	~Array() 
	{
		cout << "Delete Array" << endl;
		cout << endl;
	}

	void setArray (T* setNum)
	{
		for (int i = 0; i < 6; i++)
		{
			box[i] = setNum[i];
		}
	}

	void showArray()
	{
		for (int i = 0; i < 6; i++)
		{
			cout << box[i];
			cout << ", ";
		}
		cout << endl << endl;
	}

	T findMax()
	{
		T max = box[0];
		for (int i = 0; i < 6; i++)
		{
			if (box[i] > max)
			{
				max = box[i];
			}
		}
		return max;
	}

	T findMin()
	{
		T min = box[0];
		for (int i = 0; i < 6; i++)
		{
			if (box[i] < min)
			{
				min = box[i];
			}
		}
		return min;
	}
};


int main()
{
	cout << "---Test Array 1---" << endl;
	Array<int> a1;
	int numSet1[6];
	int maxA1, minA1;
	for (int i = 0; i < 6; i++)
	{
		cout << "Press Number " << i + 1 << endl;
		cin >> numSet1[i];
	}
	a1.setArray(numSet1);
	a1.showArray();
	maxA1 = a1.findMax();
	minA1 = a1.findMin();
	cout << "Max of this array is " << maxA1 << endl;
	cout << "Min of this array is " << minA1 << endl;
	cout << endl;

	cout << "---Test Array 2---" << endl;
	double numSet2[6] = { 18.7, 11.9, 7.4, 22.3, 24.5, 9.9 };
	double maxA2, minA2;
	Array<double> a2(numSet2);
	a2.showArray();
	maxA2 = a2.findMax();
	minA2 = a2.findMin();
	cout << "Max of this array is " << maxA2 << endl;
	cout << "Min of this array is " << minA2 << endl;
	cout << endl;

	return 0;
}