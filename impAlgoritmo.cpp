#include "Algoritmo.h"

void swap(int &a, int &b) {
    int temp = a; 
    a = b; 
    b = temp; 
}

void selectionSort(std::vector<int> &data) {
    size_t size = data.size(); 

    for (int i = 0; i < size; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (data[j] < data[i]) 
                swap(data[j], data[i]);             
        }   //  j
    }   //  i
}

void bubbleSort(std::vector<int> &data) {    
    size_t size = data.size(); 

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size - i; ++j) {
            if (data[j] > data[j+1])
                swap(data[j], data[j+1]);            
        }   //  j
    }   //  i
}

void insertionSort(std::vector<int> &data) {    
    size_t size = data.size(); 

    for (int i = 0; i < size; ++i) {
        int j = i; 
        while (j > 0 && data[j-1] > data[j]) {
            swap(data[j-1], data[j]); 
            --j; 
        }
    }   //  i    
}
  
void shellSort(std::vector<int> &data) {
    size_t n = data.size(); 
    
    for (int gap = n/2; gap > 0; gap /= 2) {        
        for (int i = gap; i < n; ++i) {
            int temp = data[i];
            int j;
        
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {                 
                data[j] = data[j-gap]; 
            } 

            data[j] = temp; 
        }   //  i
    }   //  gap
}

//  mergeSort
std::vector<int> sort(std::vector<int> &left, std::vector<int> &right) {    
    std::vector<int> merge; 
    size_t j = 0, i = 0; 
    
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merge.push_back(left[i]);
            i++;
        } else {
            merge.push_back(right[j]);
            j++;
        }
    }

    // Agregar los elementos restantes de left (si hay alguno)
    while (i < left.size()) {
        merge.push_back(left[i]);
        i++;
    }

    // Agregar los elementos restantes de right (si hay alguno)
    while (j < right.size()) {
        merge.push_back(right[j]);
        j++;
    }

    return merge;
}

std::vector<int> mergeSort(std::vector<int> &data) {
    if (data.size() <= 1) {
        return data; 
    }     

    int mid = data.size()/2;

    std::vector<int> left(data.begin(), data.begin() + mid);
    std::vector<int> right(data.begin() + mid, data.end());
         
    //  Aqui ya se reciben los lados ordenados por sort     
    left = mergeSort(left);
    right = mergeSort(right);

    return sort(left, right);  
}

//  QuickSort
int partition(std::vector<int> &data, const int low, const int high) {
    int pivot = data[high]; 
    int i = low - 1; 

    for (int j = low; j < high-1; ++j) {
        if (data[j] <= pivot) {
            i++; 
            swap(data[i], data[j]);
        }
    }

    swap(data[i+1], data[high]);    
    return i + 1; 
}

void quickSort(std::vector<int> &data, const int low, const int high) {
    if (low < high) {
        int pivot = partition(data, low, high); 
        quickSort(data, low, pivot - 1); 
        quickSort(data, pivot + 1, high);
    }
} 

//  HeapSort
void heapify(std::vector<int> &data, int n, int i) {
    int largest = i; 
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && data[left] > data[largest]) {
        largest = left; 
    }

    if (right < n && data[right] > data[largest]) {
        largest = right; 
    }

    if (largest != i) {
        swap(data[i], data[largest]); 
        heapify(data, n, largest);
    }
}

void heapSort(std::vector<int> &data) {
    size_t n = data.size(); 

    for (int i = n/2-1; i >= 0; --i) {
        heapify(data, n, i);        
    } 

    for (int i = n-1; i >= 1; --i) {
        swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}