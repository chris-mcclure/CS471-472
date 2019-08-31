// Chris McClure
// 8/31/2019
// CS471 Senior Capstone 1
// HW1

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::vector;
using std::endl;

// function print displays the structure in current order from beginning to end.
template <typename A>
void print(A & data) {
	for (int i = 0; i < std::size(data) ; i++) {
		cout << " " << data[i];
	}
	cout << endl;
}

// function test compares the current element of the data structure to the following one, 
// if the following value is less than the previous, the data strucutre isn't sorted and the test fails. 
// Otherwise the test passes.
template <typename A>
void test(A & data) {
	double lo = 0;
	double hi = 0;
	for (int i = 0; i < std::size(data)-1; i++) {
		lo = data[i];
		hi = data[i + 1];
		if (lo > hi) {
			cout << "Test failed..." << endl;
			cout << hi << " < " << lo << endl;
		}
	}
	cout << "All tests passed!" << endl;;
}

// function quicksort recurisvely calls itself with a new partition value each time until the structure has been sorted.
template <typename A>
void quicksort(A & data, int lo, int hi) {
	if (lo < hi) {
		int p = partition(data, lo, hi);
		quicksort(data, lo, p - 1);
		quicksort(data, p + 1, hi);
	}
}

// function partition chooses a new pivot point in the structure to sort around
template <typename A>
int partition(A & data, int lo, int hi) {
	int pivot = data[hi];
	int i = lo;
	for (int j = lo; j < hi; j++) {
		if (data[j] < pivot) {
			std::swap(data[i], data[j]);
			i = i + 1;
		}
	}
	std::swap(data[i], data[hi]);
	return i;
}

int main() {
	//testing array
	int bar[6] = { 5, -42, 100, 17, 2, -1000 };
	print(bar);
	quicksort(bar, 0, std::size(bar) - 1);
	print(bar);
	test(bar);
	cout << endl;
	
	//testing vector
	vector<double> myvec;
	myvec.push_back(4.2);
	myvec.push_back(6.09);
	myvec.push_back(-3.12);
	myvec.push_back(3.867);
	myvec.push_back(100.111);
	print(myvec);
	quicksort(myvec, 0, std::size(myvec) - 1);
	print(myvec);
	test(myvec);
	return 0;
}

