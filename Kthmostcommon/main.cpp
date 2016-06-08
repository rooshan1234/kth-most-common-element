#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

struct DataType {
	int number;
	int sizepernumber;
	DataType() {
		number = 0;
		sizepernumber = 0;
	}
	DataType(int num, int occurances) {
		number = num;
		sizepernumber = occurances;
	}
};
bool greater(DataType i, DataType j) {
	return (i.sizepernumber > j.sizepernumber);
}

void getkthcommon(int a[], int size ,int k) {
	vector <DataType> numbers;
	bool uniqueElement = true;

	for (int i = 0; i < size; i++) {
		uniqueElement = true;
		for (int x = 0; x < numbers.size(); x++) {
			if (a[i] == numbers.at(x).number) {
				numbers.at(x).sizepernumber++;
				sort(numbers.begin(), numbers.end(), greater);
				uniqueElement = false;
				break;
			}
		}
		if (uniqueElement) {
			DataType newNumber(a[i], 1);
			numbers.push_back(newNumber);
		}
	}
	cout << "NUMBER: " << numbers.at(k).number << " OCCURNACES: " << numbers.at(k).sizepernumber << endl;
}
int main() {
	int number[] = {1,1,2,2,2,3,3,4,4,4,2,2,4,4,5,5,5,5,5,5,3,3,4,4,4,4,4,4,4};
	getkthcommon(number, 29, 2);
}