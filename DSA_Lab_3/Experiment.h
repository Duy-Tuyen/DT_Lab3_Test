#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <unordered_map> // use for function convert name -> id

#include "Helper.h"
#include "DataGenerator.h"
#include "Algorithms.h"


using namespace std;
const int SIZE[6] = { 10000,30000,50000,100000, 300000, 500000 };

// Command 1
// Command line arguments: <algorithm> <input_file> <output_param>
// Run the sorting algorithm with the input data from the input file
// Result: Print time or comparisons count to console and write the sorted array to "output.txt" file
void Command1(char* algo_name, char* input_filename, char* output_param);

// Command 2
// Command line arguments: <algorithm> <size> <input_order> <output_param>
// Run the sorting algorithm with the generated data of the given size and input order
// Result: Print time or comparisons count to console and write the sorted array to "output.txt" file
void Command2(char* algo_name, int size, char* input_order, char* output_param);

// Command 3
// Command line arguments: <algorithm> <size> <output_param>
// Run the sorting algorithm with the generated data of the given size and for all 4 input orders
// Result: Print time or comparisons count to console and write the sorted array to "output.txt" file
void Command3(char* algo_name, int size, char* output_param);

// Command 4
// Command line arguments: <algorithm1> <algorithm2> <input_file>
// Run 2 sorting algorithms with the input data from the input file to compare their performance
// Result: Print both time and comparisons count of 2 algo to console and write the sorted array to "output.txt" file
void Command4(char* algo_name1, char* algo_name2, char* input_filename);

// Command 5
// Command line arguments: <algorithm1> <algorithm2> <size> <input_order>
// Run 2 sorting algorithms with the generated data of the given size and input order to compare their performance
// Result: Print both time and comparisons count of 2 algo to console and write the sorted array to "output.txt" file
void Command5(char* algo1_name, char* algo2_name, int size, char* input_order);

void Experiment(char* input_order);
