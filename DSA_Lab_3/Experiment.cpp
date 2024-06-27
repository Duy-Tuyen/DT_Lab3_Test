#include "Experiment.h"

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

string getAlgoName(int algo_id) {
	switch (algo_id)
	{
	case 0:
		return "Selection Sort";
	case 1:
		return "Insertion Sort";
	case 2:
		return "Bubble Sort";
	case 3:
		return "Shaker Sort";
	case 4:
		return "Shell Sort";
	case 5:
		return "Heap Sort";
	case 6:
		return "Merge Sort";
	case 7:
		return "Quick Sort";
	case 8:
		return "Counting Sort";
	case 9:
		return "Radix Sort";
	case 10:
		return "Flash Sort";
	default:
		return "Invalid algorithm id";
	}
}

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