#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
//#include <chrono> we chose chrono library over time.h because it provides a high resolution clock which help measuring run time more accurate
#include <unordered_map> // use for function convert name -> id
#include "DataGenerator.h"
#include "Algorithms.h"


using namespace std;


void SORT_ALGO(int* a, int n, unsigned long long& num_Comp, int algo_id);

string getAlgoName(int algo_id);

int getAlgoId(const std::string& algo_cmd);

string getInputOrder(int input_order_id);

string getInputOrder(const std::string& input_order_cmd);

int getInputOrderId(const std::string& input_order_cmd);

int* CopyData(int* a, int size);

void printToFile(int* a, int size, const char* filename);

void Command1(char* algo_name, char* input_filename, char* output_param);

void Command2(char* algo_name, int size, char* input_order, char* output_param);

void Command3(char* algo_name, int size, char* output_param);

void Command4(char* algo_name1, char* algo_name2, char* input_filename);

void Command5(char* algo1_name, char* algo2_name, int size, char* input_order);