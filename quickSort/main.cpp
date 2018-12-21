#include "pch.h"
#include <time.h>


const int ARRSIZE{ 100000 };

/* STL(standard template library Sort functions*/
/***************************************************************/
void stableSort()
{
	int stableArr[ARRSIZE];
	for (int i = 0; i < ARRSIZE; i++)
	{
		stableArr[i] = rand() % 1000;
	}
	std::stable_sort(stableArr, stableArr + ARRSIZE);
}

void stdSort()
{
	int stdArr[ARRSIZE];
	for (int i = 0; i < ARRSIZE; i++)
	{
		stdArr[i] = rand() % 1000;
	}
	std::sort(stdArr, stdArr + ARRSIZE);
}
/****************************************************************/

/* MERGESORT*/
void Merger(int arr[], int lo, int  mi, int hi) {
	int *temp = new int[hi - lo + 1];	//temporary merger array
	int i = lo, j = mi + 1;				//i is for left-hand,j is for right-hand
	int k = 0;							//k is for the temporary array
	while (i <= mi && j <= hi) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	//rest elements of left-half
	while (i <= mi)
		temp[k++] = arr[i++];
	//rest elements of right-half
	while (j <= hi)
		temp[k++] = arr[j++];
	for (k = 0, i = lo; i <= hi; ++i, ++k)
		arr[i] = temp[k];				//copy the mergered temporary array to the original array
	delete[]temp;
}
void MergeSortHelper(int arr[], int lo, int hi) {
	int mid;
	if (lo < hi) {
		mid = (lo + hi) >> 1;
		MergeSortHelper(arr, lo, mid);
		MergeSortHelper(arr, mid + 1, hi);
		Merger(arr, lo, mid, hi);
	}
}
void MergeSort(int arr[], int arr_size) {
	MergeSortHelper(arr, 0, arr_size - 1);
}
void mergeSort()
{
	int mergwArr[ARRSIZE];
	int n = ARRSIZE;
	for (int i = 0; i < n; i++)
	{
		mergwArr[i] = (rand() % 1000);
	}
	MergeSort(mergwArr, n);
}



/*QUICKSORT*/
inline void Swap(int &a, int &b) {
	int k = a;
	a = b;
	b = k;
}
//reload rand to produce random number in a fixed range
inline int rand(int p, int q) {
	int size = q - p + 1;
	//    srand(time(NULL));
	return (p + rand() % size);
}
int Partition(int arr[], int lo, int hi) {
	//produce ramdom subscript
	int t = rand(lo, hi);
	Swap(arr[t], arr[hi]);
	int index = lo - 1;
	int key = arr[hi];
	for (int i = lo; i < hi; i++) {
		if (arr[i] <= key)
			Swap(arr[++index], arr[i]);
	}
	Swap(arr[++index], arr[hi]);
	return index;
}
void QuickSortHelper(int arr[], int lo, int hi) {
	if (lo < hi) {
		int index = Partition(arr, lo, hi);
		QuickSortHelper(arr, lo, index - 1);
		QuickSortHelper(arr, index + 1, hi);
	}
}
void QuickSort(int arr[], int arr_size) {
	QuickSortHelper(arr, 0, arr_size - 1);
}
void quickSort()
{
	int array[ARRSIZE];
	int n = ARRSIZE;
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 100;
	}	
	QuickSort(array, n);
}

int main()
{
	srand(time(NULL));

	auto start1 = std::chrono::high_resolution_clock::now();
	quickSort();
	auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
	long long microseconds1 = std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count();
	std::cout << "\nSTL Quick sort Time: " << microseconds1 << "\n";


	auto start2 = std::chrono::high_resolution_clock::now();
	mergeSort();
	auto elapsed2 = std::chrono::high_resolution_clock::now() - start2;
	long long microseconds2 = std::chrono::duration_cast<std::chrono::microseconds>(elapsed2).count();
	std::cout << "\nSTL Merge sort Time: " << microseconds2 << "\n";


	auto start3 = std::chrono::high_resolution_clock::now();
	stdSort();
	auto elapsed3 = std::chrono::high_resolution_clock::now() - start3;
	long long microseconds3 = std::chrono::duration_cast<std::chrono::microseconds>(elapsed3).count();
	std::cout << "\nSTL Std sort Time: " << microseconds3 << "\n";


	auto start4 = std::chrono::high_resolution_clock::now();
	stableSort();	
	auto elapsed4 = std::chrono::high_resolution_clock::now() - start4;
	long long microseconds4 = std::chrono::duration_cast<std::chrono::microseconds>(elapsed4).count();
	std::cout << "\nSTL Stable sort Time: " << microseconds4 << "\n";


	std::cin.get();
}
