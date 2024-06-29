#include "Helper.h"

// Function to implement sorting algorithms based on algo_id
void SORT_ALGO(int* a, int n, unsigned long long& num_Comp, int algo_id)
{
	switch (algo_id)
	{
	case 0:
		SelectionSort(a, n, num_Comp);
		break;
	case 1:
		InsertionSort(a, n, num_Comp);
		break;
	case 2:
		BubbleSort(a, n, num_Comp);
		break;
	case 3:
		ShakerSort(a, n, num_Comp);
		break;
	case 4:
		ShellSort(a, n, num_Comp);
		break;
	case 5:
		HeapSort(a, n, num_Comp);
		break;
	case 6:
		MergeSort(a, n, num_Comp);
		break;
	case 7:
		QuickSort(a, n, num_Comp);
		break;
	case 8:
		CountingSort(a, n, num_Comp);
		break;
	case 9:
		RadixSort(a, n, num_Comp);
		break;
	case 10:
		FlashSort(a, n, num_Comp);
		break;
	default:
		break;
	}
}

// Convert algo_id to algorithm name (to print out the result)
string getAlgoName(int algo_id) {
	switch (algo_id)
	{
	case 0:
		return "Selection Sort";
		break;
	case 1:
		return "Insertion Sort";
		break;
	case 2:
		return "Bubble Sort";
		break;
	case 3:
		return "Shaker Sort";
		break;
	case 4:
		return "Shell Sort";
		break;
	case 5:
		return "Heap Sort";
		break;
	case 6:
		return "Merge Sort";
		break;
	case 7:
		return "Quick Sort";
		break;
	case 8:
		return "Counting Sort";
		break;
	case 9:
		return "Radix Sort";
		break;
	case 10:
		return "Flash Sort";
		break;
	default:
		return "Invalid algorithm id";
		break;
	}
}

// Convert algorithm name from command prompt to algo_id
int getAlgoId(const std::string& algo_cmd) {
	static const std::unordered_map<std::string, int> algo_map = {
		{"selection-sort", 0},
		{"insertion-sort", 1},
		{"bubble-sort", 2},
		{"shaker-sort", 3},
		{"shell-sort", 4},
		{"heap-sort", 5},
		{"merge-sort", 6},
		{"quick-sort", 7},
		{"counting-sort", 8},
		{"radix-sort", 9},
		{"flash-sort", 10}
	};

	auto it = algo_map.find(algo_cmd);
	if (it != algo_map.end()) {
		return it->second;
	}
	else return -1;
}

// Convert input order id to input order name (to print out the result)
string getInputOrder(int input_order_id) {
	switch (input_order_id)
	{
	case 0:
		return "Random";
	case 1:
		return "Sorted";
	case 2:
		return "Reverse";
	case 3:
		return "Nearly Sorted";
	default:
		return "Invalid input order id";
	}
}

// Convert input order name from command prompt to input order name (to print out the result)
string getInputOrder(const std::string& input_order_cmd) {
	static const std::unordered_map<std::string, std::string> input_order_map = {
		{"-rand", "Random"},
		{"-sorted", "Sorted"},
		{"-rev", "Reverse"},
		{"-nsorted", "Nearly Sorted"}
	};

	auto it = input_order_map.find(input_order_cmd);
	if (it != input_order_map.end()) {
		return it->second;
	}
	else {
		return "Invalid input order cmd name";
	}
}

// Convert input order name from command prompt to input order id
int getInputOrderId(const std::string& input_order_cmd) {
	static const std::unordered_map<std::string, int> input_order_map = {
		{"-rand", 0},
		{"-sorted", 1},
		{"-rev", 2},
		{"-nsorted", 3}
	};

	auto it = input_order_map.find(input_order_cmd);
	if (it != input_order_map.end()) {
		return it->second;
	}
	else {
		return -1;
	}
}

// Copy data of one array to another array
int* CopyData(int* a, int size)
{
	int* Data = new int[size];
	for (int i = 0; i < size; i++)
		Data[i] = a[i];

	return Data;
}

// Print the sorted array to "output.txt" file
void printToFile(int* a, int size, const char* filename)
{
	ofstream fwrite;
	fwrite.open(filename, ios::out);
	if (fwrite.is_open())
	{
		fwrite << size << endl;
		for (int i = 0; i < size; i++)
		{
			fwrite << a[i] << " ";
		}
		fwrite.close();
	}
	else
	{
		cout << "Can not open and write file!" << endl;
	}

}

// Print the result (runtime or comparisons) to console
void printResult(double run_time, unsigned long long NumComp, const char* output_param)
{
	if (strcmp(output_param, "-time") == 0)
	{
		cout << "Running time (if required): " << fixed << run_time / 1000000 << setprecision(5) << "ms" << endl;
	}
	else if (strcmp(output_param, "-comp") == 0)
	{
		cout << "Comparisons (if required): " << NumComp << endl;
	}
	else
	{
		cout << "Running time (if required): " << fixed << run_time / 1000000 << setprecision(5) << "ms" << endl;
		cout << "Comparisons (if required): " << NumComp << endl;
	}
}