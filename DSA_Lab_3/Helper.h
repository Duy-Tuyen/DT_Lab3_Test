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

void SORT_ALGO(int* a, int n, unsigned long long& num_Comp, int algo_id);

string getAlgoName(int algo_id);

int getAlgoId(const std::string& algo_cmd);

string getInputOrder(int input_order_id);

string getInputOrder(const std::string& input_order_cmd);

int getInputOrderId(const std::string& input_order_cmd);

int* CopyData(int* a, int size);

// Print the sorted array to "output.txt" file
void printToFile(int* a, int size, const char* filename);

// Print the result (runtime or comparisons) to console
void printResult(double run_time, unsigned long long NumComp, const char* output_param);