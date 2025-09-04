/**
 * Problem Statement:
 * ------------------
 * Write a C++ program to calculate the minimum, maximum, and average of an array 
 * using three separate threads. Each thread computes one of the values.
 */

#include <iostream>
#include <thread>
using namespace std;


// Global variables for results

int minValue, maxValue;
double avgValue;

// Thread function to find minimum

void findMin(int arr[], int n) {
    minValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minValue)
            minValue = arr[i];
    }
}

// Thread function to find maximum

void findMax(int arr[], int n) {
    maxValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }
}


// Thread function to compute average

void findAverage(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    avgValue = static_cast<double>(sum) / n;
}


// Main function

int main() {
    const int n = 10;
    int arr[n];

    // Step 1: Input array elements
    cout << "Enter 10 integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 2: Create threads for min, max, and average
    thread t1(findMin, arr, n);
    thread t2(findMax, arr, n);
    thread t3(findAverage, arr, n);

    // Step 3: Wait for all threads to finish
    t1.join();
    t2.join();
    t3.join();

    // Step 4: Display results
    cout << "Minimum Value: " << minValue << endl;
    cout << "Maximum Value: " << maxValue << endl;
    cout << "Average Value: " << avgValue << endl;

    return 0;
}
