#include "Experiment.h"

// Command 1
// Command line arguments: <algorithm> <input_file> <output_param>
// Run the sorting algorithm with the input data from the input file
// Result: Print time or comparisons count to console and write the sorted array to "output.txt" file
void Command1(char* algo_name, char* input_filename, char* output_param)
{
	// Print out the information of cmd1 experiment
    cout << "Command 1" << endl;

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

        // Run and calculate the running time and/or the number of comparisons
        auto start = std::chrono::high_resolution_clock::now();
        SORT_ALGO(arr, size, NumComp, algo_id);
        auto end = std::chrono::high_resolution_clock::now();
        double run_time = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();

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
    cout << "Command 2" << endl;

	int algo_id = getAlgoId(algo_name);
	int input_order_id = getInputOrderId(input_order);
	cout << "Algorithm: " << getAlgoName(algo_id) << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: " << getInputOrder(input_order) << endl;
	cout << "-----------------------------" << endl;

	int* arr = new int[size];
	unsigned long long NumComp;
	
	GenerateData(arr, size, input_order_id);


    // Run and calculate the running time and/or the number of comparisons
    auto start = std::chrono::high_resolution_clock::now();
    SORT_ALGO(arr, size, NumComp, algo_id);
    auto end = std::chrono::high_resolution_clock::now();
    double run_time = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();

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
    cout << "Command 3" << endl;

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

        // Run and calculate the running time and/or the number of comparisons
        auto start = std::chrono::high_resolution_clock::now();
        SORT_ALGO(arr, size, NumComp, algo_id);
        auto end = std::chrono::high_resolution_clock::now();
        double run_time = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();

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
// Result: Print both time and comparisons count of 2 algo to console and write the sorted array to "output.txt" file
void Command4(char* algo_name1, char* algo_name2, char* input_filename)
{
    cout << "Command 4" << endl;

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

        // Run and calculate the running time and/or the number of comparisons
        auto start1 = std::chrono::high_resolution_clock::now();
        SORT_ALGO(arr1, size, NumComp1, algo_id1);
        auto end1 = std::chrono::high_resolution_clock::now();
        double run_time1 = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end1 - start1).count();

        auto start2 = std::chrono::high_resolution_clock::now();
        SORT_ALGO(arr2, size, NumComp2, algo_id2);
        auto end2 = std::chrono::high_resolution_clock::now();
        double run_time2 = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end2 - start2).count();

		// Print out the running time and number of comparisons
        cout << "Running time: " << fixed << run_time1 << setprecision(5) << " millisecs" << " | "
			 << fixed << run_time2 << setprecision(5) << " millisecs" << endl;
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
// Result: Print both time and comparisons count of 2 algo to console and write the sorted array to "output.txt" file
void Command5(char* algo1_name, char* algo2_name, int size, char* input_order)
{
    cout << "Command 5" << endl;

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

    // Run and calculate the running time and/or the number of comparisons
    auto start1 = std::chrono::high_resolution_clock::now();
    SORT_ALGO(arr1, size, NumComp1, algo_id1);
    auto end1 = std::chrono::high_resolution_clock::now();
    double run_time1 = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end1 - start1).count();

    auto start2 = std::chrono::high_resolution_clock::now();
    SORT_ALGO(arr2, size, NumComp2, algo_id2);
    auto end2 = std::chrono::high_resolution_clock::now();
    double run_time2 = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end2 - start2).count();


	// Print out the running time and number of comparisons
	cout << "Running time: " << fixed << run_time1 << setprecision(5) << " millisecs" << " | "
		 << fixed << run_time2 << setprecision(5) << " millisecs" << endl;

	cout << "Comparisons: " << NumComp1 << " | " << NumComp2 << endl;

	// Write down the sorted array to "output.txt" file
	printToFile(arr1, size, "output.txt");

	delete[] arr1;
	delete[] arr2;
}

void Experiment(char* input_order)
{
    ofstream expiriment_fout;
    expiriment_fout.open("ExperimentResult.txt");
    if (expiriment_fout.is_open())
    {
        int Data_Order = getInputOrderId(input_order);

        cout << "----DATA ORDER: " << getInputOrder(Data_Order) << endl << endl;
        expiriment_fout << endl << "DATA ORDER : " << getInputOrder(Data_Order) << endl;

        for (int Data_Size = 0; Data_Size < 6; Data_Size++)
        {
            cout << "----DATA SIZE: " << SIZE[Data_Size] << endl << endl;

            expiriment_fout << "----DATA SIZE: " << SIZE[Data_Size] << endl;

            int* data = new int[SIZE[Data_Size]];
            GenerateData(data, SIZE[Data_Size], Data_Order);

            for (int Sorting_Algorithms_ID = 0; Sorting_Algorithms_ID < 11; Sorting_Algorithms_ID++)
            {
                int* a = CopyData(data, SIZE[Data_Size]);
                unsigned long long NumComp = 0;

                auto start = std::chrono::high_resolution_clock::now();
                SORT_ALGO(a, SIZE[Data_Size], NumComp, Sorting_Algorithms_ID);
                auto end = std::chrono::high_resolution_clock::now();

                double run_time = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();

                cout << "----Algorithm: " << getAlgoName(Sorting_Algorithms_ID) << endl;
                printResult(run_time, NumComp, "both");
                cout << endl;

                expiriment_fout << "----Algorithm: " << getAlgoName(Sorting_Algorithms_ID) << endl;
                expiriment_fout << "       Runtime : " << fixed << setprecision(5) << run_time << " millisecs" << endl;
                expiriment_fout << "       Comparisons: " << NumComp << endl;

                expiriment_fout.flush();
                delete[] a;
            }

            cout << endl;
            delete[] data;
        }
        expiriment_fout << "------------------------------------------------------" << endl;

        expiriment_fout.close();
    }
    else
        cout << "Unsuccessfully open file." << endl;
    cout << "Complete the experiment!" << endl;
}
