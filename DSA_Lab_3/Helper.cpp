#include "Helper.h"

//1. Function to implement sorting algorithms based on algo_id
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

//-----------------------------------------------------------------------------------------------


//2. Functions to convert data type of algorithm and input order
//
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

//-----------------------------------------------------------------------------------------------

// 3. Functions to print out the result
// 
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
		cout << "Running time (if required): " << fixed << run_time / 1000 << setprecision(5) << " millisecs" << endl;
	}
	else if (strcmp(output_param, "-comp") == 0)
	{
		cout << "Comparisons (if required): " << NumComp << endl;
	}
	else
	{
		cout << "Running time (if required): " << fixed << run_time / 1000 << setprecision(5) << " millisecs" << endl;
		cout << "Comparisons (if required): " << NumComp << endl;
	}
}

//-----------------------------------------------------------------------------------------------

// 4. Functions to check for valid input/file
// Check if the command line argument is a valid algorithm name

bool isAlgorithmName(char* algorithm_name)
{
	if (strcmp(algorithm_name, "selection-sort") == 0)
	{
		return true;
	}
	if (strcmp(algorithm_name, "insertion-sort") == 0)
	{
		return true;
	}
	if (strcmp(algorithm_name, "bubble-sort") == 0)
	{
		return true;
	}
	if (strcmp(algorithm_name, "heap-sort") == 0)
	{
		return true;
	}
	if (strcmp(algorithm_name, "merge-sort") == 0)
	{
		return true;
	}
	if (strcmp(algorithm_name, "quick-sort") == 0)
	{
		return true;
	}
	if (strcmp(algorithm_name, "radix-sort") == 0)
	{
		return true;
	}
	if (strcmp(algorithm_name, "shaker-sort") == 0)
	{
		return true;
	}
	if (strcmp(algorithm_name, "shell-sort") == 0)
	{
		return true;
	}
	if (strcmp(algorithm_name, "counting-sort") == 0)
	{
		return true;
	}
	if (strcmp(algorithm_name, "flash-sort") == 0)
	{
		return true;
	}

	return false;
}

bool endWithTxtSuffix(char* filename)
{
	const char* dotTxt = ".txt";
	size_t filename_length = strlen(filename);
	size_t dotTxt_length = strlen(dotTxt);

	if (filename_length >= dotTxt_length && strcmp(filename + filename_length - dotTxt_length, dotTxt) == 0)
	{
		return true;
	}

	return false;
}
bool hasNoIllegalChars(char* filename)
{
	const char* illegalCharacters = "<>:\"/\\|?*";

	for (int i = 0; i < (int)strlen(filename); i++)
	{
		if (strchr(illegalCharacters, filename[i]) != NULL)
		{
			return false;
		}
	}

	return true;
}
bool isValidFilename(char* filename)
{
	return ((endWithTxtSuffix(filename)) && (hasNoIllegalChars(filename)));
}

bool isInputSize(char* str) {
	if (str == nullptr || *str == '\0') {
		return false;
	}

	for (int i = 0; i < strlen(str); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}

	return true;
}
bool isValidInputSize(int size)
{
	if ((size >= 1) && (size <= 1000000))
	{
		return true;
	}

	return false;
}
int getSize(char* input_size)
{
	int size = 0;

	for (int i = 0; i < (int)strlen(input_size); i++)
	{
		if (input_size[i] >= '0' && input_size[i] <= '9')
		{
			size = size * 10 + (input_size[i] - '0');
		}
	}

	return size;
}

bool isOutputParam(char* output_param)
{
	if (strcmp(output_param, "-time") == 0)
	{
		return true;
	}
	if (strcmp(output_param, "-comp") == 0)
	{
		return true;
	}
	if (strcmp(output_param, "-both") == 0)
	{
		return true;
	}

	return false;
}

bool isInputOrder(char* input_order)
{
	if (strcmp(input_order, "-rand") == 0)
	{
		return true;
	}
	if (strcmp(input_order, "-nsorted") == 0)
	{
		return true;
	}
	if (strcmp(input_order, "-sorted") == 0)
	{
		return true;
	}
	if (strcmp(input_order, "-rev") == 0)
	{
		return true;
	}

	return false;
}
