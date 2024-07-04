#include "Algorithms.h"

using namespace std;
//1. SelectionSort
//2. InsertionSort
//3. BubbleSort
//4. ShakerSort
//5. ShellSort
//6. HeapSort
//7. MergeSort
//8. QuickSort
//9. CountingSort
//10. RadixSort
//11. FlashSort

//1.Selection Sort------------------------------------------------------------------------------------------------//
void SelectionSort(int* a, int n, unsigned long long& NumComp)
{
	NumComp = 0;
	for (int i = 0; (++NumComp) && (i < n - 1);i++)
	{
		int min = i;
		for (int j = i + 1; (++NumComp) && (j < n);j++)
		{
			if ((++NumComp) && (a[min] > a[j]))
				min = j;
		}
		swap(a[min], a[i]);
	}
}

//2.Insertion Sort------------------------------------------------------------------------------------------------//
void InsertionSort(int* a, int n,unsigned long long& NumComp)
{
	NumComp = 0;
	for (int i = 1;(++NumComp) && (i < n); i++)
	{
		int key = a[i];
		int j = i - 1;
		while ((++NumComp) && (i >= 0) && (++NumComp) && (a[j] > key))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

//3.Bubble Sort--------------------------------------------------------------------------------------------------//
void BubbleSort(int* a, int n, unsigned long long& NumComp)
{
	NumComp = 0;
	for (int i = 0; (++NumComp) && (i < n - 1); i++)
	{
		for (int j = 0; (++NumComp) && j < (n - i - 1); j++)
		{
			if ((++NumComp) && (a[j] > a[j + 1]))
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void BubbleSort_Flag(int* a, int n, unsigned long long& NumComp)
{
	NumComp = 0;
	bool flag;

	for (int i = 0; (++NumComp) && (i < n - 1); i++)
	{
		flag = true;
		for (int j = 0; (++NumComp) && j < (n - i - 1); j++)
		{
			if ((++NumComp) && (a[j] > a[j + 1]))
			{
				swap(a[j], a[j + 1]);
				flag = false;
			}
		}
		if ((++NumComp) && (flag == true))
			break;
	}
}

//4.Shaker Sort------------------------------------------------------------------------------------------------//
//This implementation is refered from: https://www.geeksforgeeks.org/cocktail-sort/
void ShakerSort(int* a, int n, unsigned long long& NumComp)
{
	NumComp = 0;
	int left = 0;
	int right = n - 1;
	int temp = 0;
	bool sorted = true;

	while ((++NumComp) && (left < right))
	{
		for (int i = left;(++NumComp) && (i < right); i++)
		{
			if ((++NumComp) && (a[i] > a[i + 1]))
			{
				swap(a[i], a[i + 1]);
				temp = i;
				sorted = false;
			}
		}
		if ((++NumComp) && (sorted))
			break;

		sorted = true;
		--right;

		for (int i = right - 1; (++NumComp) && (i >= left); i--)
		{
			if ((++NumComp) && (a[i] < a[i - 1]))
			{
				swap(a[i], a[i - 1]);
				temp = i;
				sorted = false;
			}
		}
		++left;
		if ((++NumComp) && (sorted))
			break;
	}
}

//5.Shell Sort------------------------------------------------------------------------------------------------//
//This implementation is refered from: https://www.geeksforgeeks.org/shellsort/
void ShellSort(int* a, int n, unsigned long long& NumComp)
{
	NumComp = 0;
	for (int gap = n / 2;(++NumComp) && (gap > 0); gap /= 2)
	{
		for (int i = gap;(++NumComp) && (i < n); i += 1)
		{
			int temp = a[i];
			int j;
			for (j = i;(++NumComp) && (j >= gap) && (++NumComp) && (a[j - gap] > temp); j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}

//6.Heap Sort-------------------------------------------------------------------------------------------------//
//This implementation of Heap Sort is refered in content 6 of "Introduction to the design and analysis of Algorithms" by Anany Levitin
void MaxHeapify(int *a, int n, int i, unsigned long long& NumComp)
{
	
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest;

	if ((++NumComp) && (left < n) && (++NumComp) && (a[i] < a[left]))
		largest = left;
	else
		largest = i;

	if ((++NumComp) && (right < n) && (++NumComp)&& (a[largest] < a[right]))
		largest = right;

	if ((++NumComp) && largest != i)
	{
		swap(a[largest], a[i]);
		MaxHeapify(a, n, largest, NumComp);
	}
}

void HeapSort(int *a, int n, unsigned long long& NumComp)
{
	NumComp = 0;
	for (int i = (n / 2) - 1; (++NumComp) && (i >= 0); i--)
	{
		MaxHeapify(a, n, i, NumComp);
	}

	for (int i = n - 1;(++NumComp) && (i > 0); i--)
	{
		swap(a[0], a[i]);
		MaxHeapify(a, i, 0, NumComp);
	}
}

//7.Merge Sort-------------------------------------------------------------------------------------------------//
//This implementation of Heap Sort is refered in content 5 of "Introduction to the design and analysis of Algorithms" by Anany Levitin
void Merge(int* a, int* temp, int left, int mid, int right, unsigned long long& NumComp) {
	int leftEnd = mid - 1;
	int tempPos = left;
	int numElements = right - left + 1;

	int i = left;
	int j = mid;

	// Merge the two halves into temp array
	while ((++NumComp) && i <= leftEnd && (++NumComp) && j <= right) {
		if (a[i] <= a[j]) {
			temp[tempPos++] = a[i++];
		}
		else {
			temp[tempPos++] = a[j++];
		}
		NumComp++;
	}

	// Copy the rest of the left half
	while ((++NumComp) && i <= leftEnd) {
		temp[tempPos++] = a[i++];
		NumComp++;
	}

	// Copy the rest of the right half
	while ((++NumComp) && j <= right) {
		temp[tempPos++] = a[j++];
		NumComp++;
	}

	// Copy the merged result back to the original array
	for (int i = 0; (++NumComp) && i < numElements; i++, right--) {
		a[right] = temp[right];
		NumComp++;
	}
}

void SplitMS(int* a, int* temp, int left, int right, unsigned long long& NumComp) {
	if ((++NumComp) && left < right) {
		int mid = (left + right) / 2;
		SplitMS(a, temp, left, mid, NumComp);
		SplitMS(a, temp, mid + 1, right, NumComp);
		Merge(a, temp, left, mid + 1, right, NumComp);
	}
}

void MergeSort(int* a, int n, unsigned long long& NumComp) {
	NumComp = 0;
	int* temp = new int[n];
	SplitMS(a, temp, 0, n - 1, NumComp);
	delete[] temp;
}


//8.Quick Sort-------------------------------------------------------------------------------------------------//
///This implementation of Quick sort was referred in "Algorithms in a Nutshell: A Practical Guide" by George T. Heinemanitin
int Sort_First_Middle_Last(int* a, int left, int right, unsigned long long& NumComp)
{
	int mid = left + (right - left) / 2;
	if ((++NumComp) && (a[left] > a[mid]))
	{
		swap(a[left], a[mid]);
	}
	if ((++NumComp) && (a[mid] > a[right]))
	{
		swap(a[mid], a[right]);
	}
	if ((++NumComp) && (a[left] > a[right]))
	{
		swap(a[left], a[right]);
	}
	return mid;
}

int Partition(int* a, int left, int right, unsigned long long& NumComp) 
{
	int pivot = Sort_First_Middle_Last(a, left, right, NumComp);
	swap(a[pivot], a[right - 1]);
	pivot = right - 1;

	left++;
	right = right - 2;

	int i = left;
	while ((++NumComp) && (left <= right))
	{
		while ((++NumComp) && (a[pivot] < a[right]) && (++NumComp) && (left <= right))
		{
			right--;
		}

		while ((++NumComp) && (a[pivot] > a[left]) && (++NumComp) && (left <= right))
		{
			left++;
		}

		if ((++NumComp) && (left <= right))
		{
			swap(a[right], a[left]);
			left++;
			right--;
		}
	}
	swap(a[pivot], a[left]);
	return left;
}

void QS_Recursion(int* a, int left, int right, unsigned long long& NumComp)
{
	if ((++NumComp) && (right - left + 1 >= 10))
	{
		int pivot = Partition(a, left, right, NumComp);
		QS_Recursion(a, left, pivot - 1, NumComp);
		QS_Recursion(a, pivot + 1, right, NumComp);
	}
	else
	{
		for (int i = left + 1;(++NumComp) && (i < (right - left + 1)); i++)
		{
			int key = a[i];
			int j = i - 1;
			while ((++NumComp) && (i >= left) && (++NumComp) && (a[j] > key))
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = key;
		}
	}
}

void QuickSort(int* a, int n, unsigned long long& NumComp)
{
	NumComp = 0;
	QS_Recursion(a, 0, n - 1, NumComp);
}

//9.Counting Sort------------------------------------------------------------------------------------------------//
//This implementation is refered from: https://www.geeksforgeeks.org/counting-sort/
void CountingSort(int* a, int n, unsigned long long& NumComp)
{
	NumComp = 0;
	int length = 0;

	vector <int> temp(n, 0);

	for (int i = 1;(++NumComp) && (i < n); i++)
	{
		if ((++NumComp) && (a[i] > a[length]))
		{
			length = i;
		}
	}
	vector <int> frequency(a[length] + 1, 0);
	for (int i = 0;(++NumComp) && (i < n); i++)
	{
		frequency[(a[i]) % 10]++;
	}

	for (int i = 1;(++NumComp) && (i <= a[length]); i++)
	{
		frequency[i] += frequency[i - 1];
	}

	for (int i = n - 1;(++NumComp) && (i >= 0); i--)
	{
		temp[frequency[(a[i]) % 10] - 1] = a[i];
		frequency[a[i]]--;
	}

	for (int i = 0;(++NumComp) && (i < n); i++)
	{
		a[i] = temp[i];
	}
}

//10.Radix Sort------------------------------------------------------------------------------------------------//
//This implementation is refered from: https://www.geeksforgeeks.org/radix-sort/
int GetMax(int* a, int n, unsigned long long& NumComp)
{
	int max = 0;

	for (int i = 1;(++NumComp) && (i < n); i++)
		if ((++NumComp) && (a[i] > a[max]))
			max = i;
	return a[max];
}

void RadixSort(int* a, int n, unsigned long long& NumComp)
{
	NumComp = 0;
	int m = GetMax(a, n, NumComp);

	for (int exp = 1;(++NumComp) && (m / exp > 0);exp *= 10)
	{
		int count = 10;
		vector <int> frequency(count, 0);
		vector <int> temp(n, 0);

		for (int i = 0;(++NumComp) && (i < n); i++)
		{
			frequency[(a[i] / exp) % 10]++;
		}

		for (int i = 1;(++NumComp) && (i < count); i++)
		{
			frequency[i] += frequency[i - 1];
		}

		for (int i = n - 1;(++NumComp) && (i >= 0); i--)
		{
			temp[frequency[(a[i] / exp) % 10] - 1] = a[i];
			frequency[(a[i] / exp % 10)]--;
		}

		for (int i = 0;(++NumComp) && (i < n); i++)
		{
			a[i] = temp[i];
		}
	}
}

//11.Flash Sort------------------------------------------------------------------------------------------------//
//This implementation is refered from:https://javascript.algorithmexamples.com/web/Sorts/flashSort.html
void FlashSort(int* a, int n, unsigned long long& NumComp) {
	NumComp = 0;
	int minVal = a[0], maxVal = a[0];
	int m = n / 10;

	for (int i = 1; ++NumComp && (i < n); i++) {
		if (++NumComp && (a[i] < minVal)) {
			minVal = a[i];
		}
		else if (++NumComp && (a[i] > maxVal)) {
			maxVal = a[i];
		}
	}

	if (++NumComp && (maxVal == minVal)) return;

	if (++NumComp && (m <= 2)) m = 2;

	int* classFreq = new int[m]();
	for (int i = 0; ++NumComp && (i < n); i++) {
		int k = 1ll * (m - 1) * (a[i] - minVal) / (maxVal - minVal);
		classFreq[k]++;
	}

	for (int k = 1; ++NumComp && (k < m); k++) classFreq[k] += classFreq[k - 1];

	int i = 0, count = 0, k = m - 1;
	while (++NumComp && (count < n)) {
		while (++NumComp && (i >= classFreq[k])) {
			i++;
			k = 1ll * (m - 1) * (a[i] - minVal) / (maxVal - minVal);
		}

		int flash = a[i];
		while (++NumComp && (i != classFreq[k])) {
			k = 1ll * (m - 1) * (flash - minVal) / (maxVal - minVal);
			swap(a[classFreq[k] - 1], flash);
			classFreq[k]--;
			count++;
		}
	}

	for (int k = 1; ++NumComp && (k < m); k++) {
		int selected = 0, j = 0;
		for (int i = classFreq[k - 1] + 1; ++NumComp && (i < classFreq[k]); i++) {
			selected = a[i];
			j = i - 1;
			while (++NumComp && (j >= 0) && ++NumComp && (a[j] > selected)) {
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = selected;
		}
	}

	delete[] classFreq;
	return;
}
