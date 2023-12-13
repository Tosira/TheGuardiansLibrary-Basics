#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <iostream>
#include <vector>

//  Base 
void swap(int &a, int &b); 

//  CUADRATICOS
void selectionSort(std::vector<int> &data);
void bubbleSort(std::vector<int> &data);
void insertionSort(std::vector<int> &data); 
void shellSort(std::vector<int> &data);     

//  LOGARITMICOS

//  MergeSort
std::vector<int> sort(std::vector<int> &left, std::vector<int> &right);  
std::vector<int> mergeSort(std::vector<int> &data);

//  QuickSort
int partition(std::vector<int> &data, const int low, const int high); 
void quickSort(std::vector<int> &data, const int low, const int high); 

//  HeapSort
void heapify(std::vector<int> &data, int n, int i); 
void heapSort(std::vector<int> &data); 

#endif