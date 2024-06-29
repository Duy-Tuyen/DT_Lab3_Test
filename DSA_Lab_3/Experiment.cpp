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

int* CopyData(int* a, int size)
{
    int* Data = new int[size];
    for (int i = 0; i < size; i++)
        Data[i] = a[i];

    return Data;
}

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

// Command 1
// Command line arguments: <algorithm> <input_file> <output_param>
// Run the sorting algorithm with the input data from the input file
// Result: Print time or comparisons count to console and write the sorted array to "output.txt" file
void Command1(char* algo_name, char* input_filename, char* output_param)
{
	// Print out the information of cmd1 experiment
    cout << "Algorithm Mode" << endl;
    int algo_id = getAlgoId(algo_name);

    cout << "Algorithms: " << getAlgoName(algo_id) << endl;
    cout << "Input file: " << input_filename << endl;

	// Read the input file and run the sorting algorithm
    ifstream fread;
    fread.open(input_filename, ios::in);
    if (fread.is_open())
    {
        int size;
        unsigned long long NumComp;
        int* arr;
	    
        fread >> size;
        cout << "Input Size: " << size << endl;
        cout << "------------------------------" << endl;

        arr = new int[size];
        for (int count = 0;count < size;count++) 
	{
            fread >> arr[count];
        }

        clock_t start, end;
        start = clock();
        SORT_ALGO(arr, size, NumComp, algo_id);
        end = clock();
        double run_time = double(end - start) / double(CLOCKS_PER_SEC);

        // Print out the running time and number of comparisons
		printResult(run_time, NumComp, output_param);
        fread.close();

        //Write down the sorted array to "output.txt" file
		printToFile(arr, size, "output.txt");
        delete[] arr;
    }
    else
        cout << "Can not open àn read file!" << endl;
}

// Command 2
// Command line arguments: <algorithm> <size> <input_order> <output_param>
// Run the sorting algorithm with the generated data of the given size and input order
// Result: Print time or comparisons count to console and write the sorted array to "output.txt" file
void Command2(char* algo_name, int size, char* input_order, char* output_param)
{
	// Print out the information of cmd2 experiment
	cout << "Algorithm mode" << endl;
	int algo_id = getAlgoId(algo_name);
	int input_order_id = getInputOrderId(input_order);
	cout << "Algorithm: " << getAlgoName(algo_id) << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: " << getInputOrder(input_order) << endl;
	cout << "-----------------------------" << endl;

	int* arr = new int[size];
	unsigned long long NumComp;
	
	GenerateData(arr, size, input_order_id);


	// Run the sorting algorithm and measure the running time and number of comparisons
	clock_t start, end;
	start = clock();
	SORT_ALGO(arr, size, NumComp, algo_id);
	end = clock();
	double run_time = double(end - start) / double(CLOCKS_PER_SEC);

	// Print out the running time and number of comparisons
	printResult(run_time, NumComp, output_param);

	// Write down the sorted array to "output.txt" file
	printToFile(arr, size, "output.txt");
	delete[] arr;
}

// Command 3
// Command line arguments: <algorithm> <size> <output_param>
// Run the sorting algorithm with the generated data of the given size and for all 4 input orders
// Result: Print time or comparisons count to console and write the sorted array to "output.txt" file
void Command3(char* algo_name, int size, char* output_param) {
	// Print out the information of cmd3 experiment
	cout << "Algorithm mode" << endl;
	int algo_id = getAlgoId(algo_name);
	int input_order_id;
	cout << "Algorithm: " << getAlgoName(algo_id) << endl;
	cout << "Input size: " << size << endl;
	cout << "-----------------------------" << endl;

	// Run the sorting algorithm for all 4 input orders and measure the running time and comparison counts
	int* arr = new int[size];
	unsigned long long NumComp;
	for (input_order_id = 0; input_order_id < 4; input_order_id++) {
		GenerateData(arr, size, input_order_id);

		clock_t start, end;
		start = clock();
		SORT_ALGO(arr, size, NumComp, algo_id);
		end = clock();
		double run_time = double(end - start) / double(CLOCKS_PER_SEC);

	// Print out the running time and number of comparisons
		cout << "Input order: " << getInputOrder(input_order_id) << endl;
		printResult(run_time, NumComp, output_param);
		cout << "-----------------------------" << endl;
	}

	// Write down the sorted array to "output.txt" file
	printToFile(arr, size, "output.txt");
	delete[] arr;
}

// Command 4
// Command line arguments: <algorithm1> <algorithm2> <input_file>
// Run 2 sorting algorithms with the input data from the input file to compare their performance
// Result: Print time or comparisons count of 2 algo to console and write the sorted array to "output.txt" file
void Command4(char* algo_name1, char* algo_name2, char* input_filename)
{
    cout << "COMPARE MODE" << endl;
    int algo_id1 = getAlgoId(algo_name1);
    int algo_id2 = getAlgoId(algo_name2);

    cout << "Algorithm: " << getAlgoName(algo_id1) << " | " << getAlgoName(algo_id2)<<endl;
    cout << "Input file" << input_filename << endl;

    ifstream fread;
    fread.open(input_filename, ios::in);
    if (fread.is_open())
    {
        int size, * arr1, * arr2;
        unsigned long long NumComp1, NumComp2;

        fread >> size;
        cout << "Input size: " << size << endl;
        cout << "-----------------------------" << endl;

        arr1 = new int[size];
        arr2 = new int[size];
        for (int count = 0; count < size; count++)
        {
            fread >> arr1[count];
        }
        arr2 = CopyData(arr2, size);

        clock_t start1, end1, start2, end2;

        start1 = clock();
        SORT_ALGO(arr1, size, NumComp1, algo_id1);
        end1 = clock();
        double run_time1 = double(end1 - start1) / double(CLOCKS_PER_SEC);

        start2 = clock();
        SORT_ALGO(arr2, size, NumComp2, algo_id2);
        end2 = clock();
        double run_time2 = double(end2 -start2)  / double(CLOCKS_PER_SEC);

		// Print out the running time and number of comparisons
        cout << "Running time: " << fixed << run_time1 / 1000000 << setprecision(5) << "ms" << " | "
			 << fixed << run_time2 / 1000000 << setprecision(5) << "ms" << endl;
        cout << "Comparisons: " << NumComp1 << " | " << NumComp2 << endl;

		// Write down the sorted array to "output.txt" file
		printToFile(arr1, size, "output.txt");

        delete[] arr1;
        delete[] arr2;
    }
    else
    {
        cout << "Can not open and read file! " << endl;
    }
}


// Command 5
// Command line arguments: <algorithm1> <algorithm2> <size> <input_order>
// Run 2 sorting algorithms with the generated data of the given size and input order to compare their performance
// Result: Print time or comparisons count of 2 algo to console and write the sorted array to "output.txt" file
void Command5(char* algo1_name, char* algo2_name, int size, char* input_order)
{
	cout << "COMPARE MODE" << endl;
	int algo_id1 = getAlgoId(algo1_name);
	int algo_id2 = getAlgoId(algo2_name);
	int input_order_id = getInputOrderId(input_order);

	cout << "Algorithm: " << getAlgoName(algo_id1) << " | " << getAlgoName(algo_id2) << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: " << getInputOrder(input_order) << endl;
	cout << "-----------------------------" << endl;

	int* arr1 = new int[size];
	int* arr2 = new int[size];
	unsigned long long NumComp1, NumComp2;

	// Generate data
	GenerateData(arr1, size, input_order_id);
	arr2 = CopyData(arr1, size);

	clock_t start1, end1, start2, end2;

	start1 = clock();
	SORT_ALGO(arr1, size, NumComp1, algo_id1);
	end1 = clock();
	double run_time1 = double(end1 - start1) / double(CLOCKS_PER_SEC);

	start2 = clock();
	SORT_ALGO(arr2, size, NumComp2, algo_id2);
	end2 = clock();
	double run_time2 = double(end2 - start2) / double(CLOCKS_PER_SEC);


	// Print out the running time and number of comparisons
	cout << "Running time: " << fixed << run_time1 / 1000000 << setprecision(5) << "ms" << " | "
		 << fixed << run_time2 / 1000000 << setprecision(5) << "ms" << endl;

	cout << "Comparisons: " << NumComp1 << " | " << NumComp2 << endl;

	// Write down the sorted array to "output.txt" file
	printToFile(arr1, size, "output.txt");

	delete[] arr1;
	delete[] arr2;
}