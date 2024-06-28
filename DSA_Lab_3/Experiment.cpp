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

int* CopyData(int* a, int size)
{
    int* Data = new int[size];
    for (int i = 0; i < size; i++)
        Data[i] = a[i];

    return Data;
}

void Command1(char* algo_name, char* input_filename, char* output_param)
{
    cout << "Algorithm Mode" << endl;
    int algo_id = getAlgoId(algo_name);
    cout << "Algorithms: " << getAlgoName(algo_id) << endl;
    cout << "Input file: " << input_filename << endl;

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
        fread.close();

        //Write down the sorted array to to "output.txt" file
        ofstream fwrite;
        fwrite.open("output.txt", ios::out);
        if (fwrite.is_open())
        {
            fwrite << size << endl;
            for (int count = 0; count < size; count++)
            {
                fwrite << arr[count] << " ";
            }
            fwrite.close();
        }
        else
        {
            cout << "Can not open and write file!" << endl;
        }
        delete[] arr;
    }
    else
        cout << "Can not open àn read file!" << endl;
}

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

        cout << "Running time: " << fixed << run_time1 / 1000000 << setprecision(5) << "ms" << " | " << fixed << run_time2 / 1000000 << setprecision(5) << "ms" << endl;
        cout << "Comparisons: " << NumComp1 << " | " << NumComp2 << endl;
        delete[] arr1;
        delete[] arr2;
    }
    else
    {
        cout << "Can not open and read file! " << endl;
    }
}
