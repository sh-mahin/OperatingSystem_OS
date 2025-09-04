/**
 * Problem Statement:
 * ------------------
 * Write a C++ program to calculate the sum of an array using three threads:
 * - Thread 1 calculates the sum of the first half of the array.
 * - Thread 2 calculates the sum of the second half of the array.
 * - Thread 3 calculates the total sum (optional, could sum all elements directly).
 * - Finally, print the sum of each part and the total sum.
 */

#include <iostream>
#include <thread>
#include <vector>
using namespace std;

// Function to calculate sum of a subarray
void partial_sum(const vector<int>& arr, int start, int end, int &result) {
    result = 0;
    for (int i = start; i < end; i++) {
        result += arr[i];
    }
}

int main() {
    // Step 1: Input 10 array elements
    vector<int> array(10);
    cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    // Step 2: Variables to store results
    int sum_first_half = 0;
    int sum_second_half = 0;
    int sum_total = 0;

    int mid = array.size() / 2;

    // Step 3: Create threads
    thread t1(partial_sum, cref(array), 0, mid, ref(sum_first_half));       // First half
    thread t2(partial_sum, cref(array), mid, array.size(), ref(sum_second_half)); // Second half
    thread t3(partial_sum, cref(array), 0, array.size(), ref(sum_total));    // Total sum

    // Step 4: Wait for threads to finish
    t1.join();
    t2.join();
    t3.join();

    // Step 5: Display results
    cout << "Sum of first half: " << sum_first_half << endl;
    cout << "Sum of second half: " << sum_second_half << endl;
    cout << "Total sum (calculated by third thread): " << sum_total << endl;

    return 0;
}
