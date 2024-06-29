// DSA_Lab_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Algorithms.h"
#include "DataGenerator.h"
#include "Experiment.h"
#include "Helper.h"

using namespace std;

int main(int argc, char** argv) {
    
	if (argc < 2) {
		cout << "Invalid input" << endl;
		return 0;
	}

	string mode = argv[1];

	if (mode == "-a") {
		// Mode = -a -> ALGORITHM MODE -> Command 1, 2, 3
		// Command 1: <algorithm> <input_file> <output_param>
		// Command 2: <algorithm> <size> <input_order> <output_param>
		// Command 3: <algorithm> <size> <output_param>
		cout << "ALGORITHM MODE\n";

		if (argc < 5) {
			cout << "Parameters missing or formatted incorrectly.\n" << endl;
			return -1;
		}

		string algo_name = argv[2];
		if (!isValidAlgorithmName(argv[2])) {
			cout << "Invalid algorithm name.\n" << endl;
			return -1;
		}

		if (isMeantToBeGivenInputFile(argv[3])) {
			// If argv[3] = input file -> command 1
			if (argc > 5 || !isMeantToBeOutputParam(argv[4])) {
				cout << "Unrecognized or incorrectly formatted arguments for command 1.\n"
					<< "Expected format : <algorithm> <input_file> <output_param>\n" << endl;
				return -1;
			}

			Command1(argv[2], argv[3], argv[4]);

		}
		else if (isMeantToBeInputSize(argv[3])) {
			// If argv[3] = input size -> command 2 or 3
			if (isMeantToBeOutputParam(argv[4])) {
				// If argv[4] = output param -> command 3; If not -> command 2
				if (argc > 5) {
					cout << "Unrecognized or incorrectly formatted arguments for command 3.\n"
						<< "Expected format : <algorithm> <input_file> <output_param>\n" << endl;
					return -1;
				}

				Command3(argv[2], getSize(argv[3]), argv[4]);
			}
			else {
				if (argc > 6 || !isMeantToBeInputOrder(argv[4]) || !isMeantToBeOutputParam(argv[5])) {
					cout << "Unrecognized or incorrectly formatted arguments for command 2.\n"
						<< "Expected format : <algorithm> <size> <input_order> <output_param>\n" << endl;
					return -1;
				}

				Command2(argv[2], getSize(argv[3]), argv[4], argv[5]);
			}
		}
		else {
			cout << "Invalid input.\n" << endl;
			return -1;
		}

	}
	else if (mode == "-c") {
		// Mode = -c -> EXPERIMENT MODE -> Command 4 or 5
		// Command 4: <algorithm1> <algorithm2> <input_file>
		// Command 5: <algorithm1> <algorithm2> <size> <input_order>
		cout << "EXPERIMENT MODE\n";

		if (argc < 5) {
			cout << "Parameters missing or formatted incorrectly.\n" << endl;
			return -1;
		}

		if (!isMeantToBeAlgorithmName(argv[2])) {
			cout << "Invalid algorithm name for the 1st algorithm.\n" << endl;
			return -1;
		}

		if (!isMeantToBeAlgorithmName(argv[3])) {
			cout << "Invalid algorithm name for the 2nd algorithm.\n" << endl;
			return -1;
		}

		if (isMeantToBeGivenInputFile(argv[4])) {
			// If argv[4] = input file -> command 4
			if (argc > 5) {
				cout << "Unrecognized or incorrectly formatted arguments for command 4.\n"
					<< "Expected format : <algorithm1> <algorithm2> <input_file>\n" << endl;
				return -1;
			}

			Command4(argv[2], argv[3], argv[4]);
		}
		else {
			if (argc > 6 || !isMeantToBeInputSize(argv[4]) && !isMeantToBeInputOrder(argv[5])) {
				cout << "Unrecognized or incorrectly formatted arguments for command 5.\n"
					<< "Expected format : <algorithm1> <algorithm2> <size> <input_order>\n" << endl;
				return -1;
			}

			Command5(argv[2], argv[3], getSize(argv[4]), argv[5]);
		}

	}
	else if (mode == "-e") {
		// Mode = -e -> EXPERIMENT MODE -> command -e
		// Experiment command: Only -e
		cout << "EXPERIMENT MODE\n";

		if (argc > 2) {
			cout << "Unrecognized or incorrectly formatted arguments for experiment mode command.\n"
				<< "Expected format : -e\n" << endl;
			return -1;
		}

		Experiment();
	}
	else {
		cout << "Invalid mode.\n" << endl;
		return -1;
	}

	return 0;
}
