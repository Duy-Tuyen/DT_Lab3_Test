#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
//#include <chrono> we chose chrono library over time.h because it provides a high resolution clock which help measuring run time more accurate
#include <unordered_map> // use for function convert name -> id

#include "Algorithms.h"
#include "DataGenerator.h"

using namespace std;

//1. Function to implement sorting algorithms based on algo_id
void SORT_ALGO(int* a, int n, unsigned long long& num_Comp, int algo_id);

//-----------------------------------------------------------------------------------------------


//2. Functions to convert data type of algorithm and input order
//
// Convert algo_id to algorithm name (to print out the result)
string getAlgoName(int algo_id);

// Convert algorithm name from command prompt to algo_id
int getAlgoId(const std::string& algo_cmd);

// Convert input order id to input order name (to print out the result)
string getInputOrder(int input_order_id);

// Convert input order name from command prompt to input order name (to print out the result)
string getInputOrder(const std::string& input_order_cmd);

// Convert input order name from command prompt to input order id
int getInputOrderId(const std::string& input_order_cmd);

// Copy data of one array to another array
int* CopyData(int* a, int size);

//-----------------------------------------------------------------------------------------------

// 3. Functions to print out the result
// 
// Print the sorted array to "output.txt" file
void printToFile(int* a, int size, const char* filename);

// Print the result (runtime or comparisons) to console
void printResult(double run_time, unsigned long long NumComp, const char* output_param);

//-----------------------------------------------------------------------------------------------

// 4. Functions to check for valid input/file
bool isAlgorithmName(char* algorithm_name);

bool endWithTxtSuffix(char* filename);
bool hasNoIllegalChars(char* filename);
bool isValidFilename(char* filename);

bool isInputSize(char* str);
bool isValidInputSize(int size);
int getSize(char* input_size);

bool isOutputParam(char* output_param);

bool isInputOrder(char* input_order);