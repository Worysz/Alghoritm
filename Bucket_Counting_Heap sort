#include <iostream>
#include <time.h>
#include "heap.h"

using namespace std;

template <typename T>
void printArray(T array[], int );
template <typename T>
void countingSort(T array[], int );
template <typename T>
void bucketSort(T array[], int );

int main() 
{

    const int size = 10;
    int* array = new int[size];
    int* array2 = new int[size];

    int* array3 = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
        array2[i] = array[i];
        array3[i] = array[i];
    }

    clock_t start = clock();
    countingSort(array, size);
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
   cout << "Counting sort " << elapsed << " s" << std::endl;
     printArray(array, size);

  

    start = clock();
    bucketSort(array2, size);
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Bucket sort " << elapsed << " s" << std::endl;
    printArray(array2, size);

    heap<int>* bh = new heap<int>;
    for (int i = 0; i < size; i++)
    {
        bh->push_h(array3[i]);
  }


    

    start = clock();

   
    bh->sort();
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Heap sort " << elapsed << " s" << std::endl;   
   bh->show();

   
}


template <typename T>
void countingSort(T array[], int size) {
    T max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    int* counters = new int[max + 1]();

    for (int i = 0; i < size; i++) {
        counters[array[i]]++;
    }

    int j = 0;
    for (int i = 0; i <= max; i++) {
        while (counters[i] > 0) {
            array[j] = i;
            j++;
            counters[i]--;
        }
    }

    delete[] counters;
}
template <typename T>
void bucketSort(T array[], int size) 
{
    T max = array[0];
    for (int i = 1; i < size; i++) {        //finding max value
        if (array[i] > max) {
            max = array[i];
        }
    }
    
    T** buckets = new T * [max + 1]; // creating buckets +1
    for (int i = 0; i <= max; i++) {
        buckets[i] = new T[size];
    }
    int* counters = new int[max + 1]();
    for (int i = 0; i < size; i++) {
        buckets[array[i]][counters[array[i]]] = array[i];
        counters[array[i]]++;
    }
    int j = 0;
    for (int i = 0; i <= max; i++) 
    {   

        for (int k = 0; k < counters[i]; k++) {
            array[j] = buckets[i][k];
            j++;
        }
    }
    for (int i = 0; i <= max; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] counters;
}
template <typename T>
void printArray(T array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
        cout << endl;
}
