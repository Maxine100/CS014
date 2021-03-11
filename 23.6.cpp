#include <iostream>
#include <cstdlib>

using namespace std;
    
const int NUMBERS_SIZE = 50000;

int Partition_midpoint(int numbers[], int i, int k) {
    
    int midpoint = i + (k - i) / 2;
    int pivot = numbers[midpoint];
    int l = i;
    int h = k;
    bool done = false;
    
    while (!done) {
        while (numbers[l] < pivot) {
            // cout << "Incrementing l." << endl;
            ++l;
        }
        while (pivot < numbers[h]) {
            // cout << "Decrementing h." << endl;
            --h;
        }
        if (l >= h) {
            // cout << "Partition is done." << endl;
            done = true;
        }
        else {
            // cout << "Swapping values at l and h." << endl;
            int temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;
            ++l;
            --h;
        }
    }
    // cout << "Returning " << h << "." << endl;
    return h;
}

void Quicksort_midpoint(int numbers[], int i, int k) {
    
    int j = 0;
    if (i >= k) {
        return;
    }
    
    j = Partition_midpoint(numbers, i, k);
    // cout << "j is " << j << "." << endl;
    
    // cout << "Calling partition on upper half." << endl;
    Quicksort_midpoint(numbers, i, j);
    // cout << "Calling partition on lower half." << endl;
    Quicksort_midpoint(numbers, j + 1, k);
}

int Partition_medianOfThree(int numbers[], int i, int k) {
    
    int midpoint = i + (k - i) / 2;
    int midPivot = numbers[midpoint];
    int firstPivot = numbers[i];
    int endPivot = numbers[k];
    int temp = 0;
    
    
    int sort[] = {firstPivot, midPivot, endPivot};
    
    for (int a = 0; a < 3; ++a) {
        for (int b = a + 1; b < 3; ++b) {
            if (sort[b] < sort[a]) {
                temp = sort[b];
                sort[b] = sort[a];
                sort[a] = temp;
            }
        }
    }
    
    int pivot = sort[1];
    int l = i;
    int h = k;
    bool done = false;
    
    while (!done) {
        while (numbers[l] < pivot) {
            // cout << "Incrementing l." << endl;
            ++l;
        }
        while (pivot < numbers[h]) {
            // cout << "Decrementing h." << endl;
            --h;
        }
        if (l >= h) {
            // cout << "Partition is done." << endl;
            done = true;
        }
        else {
            // cout << "Swapping values at l and h." << endl;
            int temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;
            ++l;
            --h;
        }
    }
    // cout << "Returning " << h << "." << endl;
    return h;
}

void Quicksort_medianOfThree(int numbers[], int i, int k) {
    if (i >= k) {
        return;
    }
    
    int j = Partition_medianOfThree(numbers, i, k);
    
    Quicksort_medianOfThree(numbers, i, j);
    Quicksort_medianOfThree(numbers, j + 1, k);
}

void InsertionSort(int numbers[], int numbersSize) {
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 1; i < numbersSize; ++i) {
        j = i;
        while (j > 0 && numbers[j] < numbers[j - 1]) {
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}

int getRandInt(int low, int high) {
    return (low + rand()) & (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]) {
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = i;//getRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int main() {
    
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    fillArrays(arr1, arr2, arr3);
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    clock_t Start = clock();
    //call sort function here
    InsertionSort(arr1, NUMBERS_SIZE);
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    
    cout << elapsedTime << endl;
    
    return 0;
}