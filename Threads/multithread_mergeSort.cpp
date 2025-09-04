/**
 * A program to demonstrate Multithreaded Merge Sort in C++.
 * 
 * - Divide array into two halves.
 * - Sort left half in one thread.
 * - Sort right half in another thread.
 * - Finally merge the two sorted halves.
 */

#include <iostream>
#include <thread>
#include <vector>

using namespace std;



// Step 1: Merge two sorted subarrays arr[l..m] and arr[m+1..r]
void merge(vector<int>& arr, int l, int m, int r) {

    int n1 = m - l + 1;   // size of left subarray
    int n2 = r - m;       // size of right subarray

    vector<int> L(n1), R(n2);

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Merge temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}



// Step 2: Normal merge sort (recursive, single-threaded)
void mergeSort(vector<int>& arr, int l, int r) {

    if (l < r) {
        int m = (l + r) / 2;

        // Recursive sorting of two halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}



// Step 3: Thread function (wrapper for mergeSort)
void threadedMergeSort(vector<int>& arr, int l, int r) {
    mergeSort(arr, l, r);
}



// Step 4: Main function
int main() {

    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;



    // Step 5: Divide array into two halves
    int mid = (0 + n - 1) / 2;



    // Step 6: Create 2 threads (one for each half)
    thread t1(threadedMergeSort, ref(arr), 0, mid);
    thread t2(threadedMergeSort, ref(arr), mid + 1, n - 1);



    // Step 7: Wait for both threads to finish
    t1.join();
    t2.join();



    // Step 8: Merge the two sorted halves
    merge(arr, 0, mid, n - 1);



    // Step 9: Print sorted array
    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;



    // Step 10: End of program
    return 0;
}
