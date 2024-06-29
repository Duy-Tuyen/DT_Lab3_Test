#pragma once
#include <iostream>
#include <cmath>
#include "vector"

void SelectionSort(int* a, int n, unsigned long long& NumComp);

void InsertionSort(int* a, int n, unsigned long long& NumComp);

void BubbleSort(int* a, int n, unsigned long long& NumComp);
void BubbleSort_Flag(int* a, int n, unsigned long long& NumComp);

void ShakerSort(int* a, int n, unsigned long long& NumComp);

void ShellSort(int* a, int n, unsigned long long& NumComp);

void MaxHeapify(int* a, int n, int i, unsigned long long& NumComp);
void HeapSort(int* a, int n, unsigned long long& NumComp);

void Merge(int* a, int first, int mid, int last, unsigned long long& NumComp);
void SplitMS(int* a, int first, int last, unsigned long long& NumComp);
void MergeSort(int* a, int n, unsigned long long& NumComp);

int Sort_First_Middle_Last(int* a, int left, int right, unsigned long long& NumComp);
int Partition(int* a, int first, int last, unsigned long long& NumComp);
void QS_Recursion(int* a, int left, int right, unsigned long long& num_Comp);
void QuickSort(int* a, int n, unsigned long long& NumComp);

void CountingSort(int* a, int n, unsigned long long& NumComp);

int GetMax(int* a, int n, unsigned long long& NumComp);
void RadixSort(int* a, int n, unsigned long long& NumComp);

void FlashSort(int* a, int n, unsigned long long& NumComp);
