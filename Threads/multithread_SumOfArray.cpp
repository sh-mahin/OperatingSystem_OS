/**
 * Program: Calculate sum of array elements using two threads
 * 
 * - Divide array into two halves
 * - Thread 1 calculates sum of the first half
 * - Thread 2 calculates sum of the second half
 * - Combine results to get total sum
 */

#include <iostream>
#include <thread>
#include <vector>

using namespace std;



// Step 1: Thread function to calculate partial sum
void partial_sum(const vector<int>& arr, int start, int end, int &result) {
    result = 0;

    for (int i = start; i < end; i++) {
        result += arr[i];   // Add each element in the range
    }
}



int main() {

    // Step 2: Create array of 100 elements (1 to 100)
    vector<int> array(100);
    for (int i = 0; i < 100; i++) {
        array[i] = i + 1;
    }



    // Step 3: Variables to store partial sums
    int sum_first_half  = 0;
    int sum_second_half = 0;



    // Step 4: Create two threads
    // t1 → sums first half (indices 0 to 49)
    // t2 → sums second half (indices 50 to 99)
    thread t1(partial_sum, cref(array), 0, array.size() / 2, ref(sum_first_half));
    thread t2(partial_sum, cref(array), array.size() / 2, array.size(), ref(sum_second_half));



    // Step 5: Wait for both threads to finish
    t1.join();
    t2.join();



    // Step 6: Print results
    cout << "Sum of first half: " << sum_first_half << endl;
    cout << "Sum of second half: " << sum_second_half << endl;
    cout << "Total sum: " << sum_first_half + sum_second_half << endl;



    // Step 7: End of program
    return 0;
}



/*
---------------------------------------------------------------
Notes:

1. `cref(array)` → Passes the array by constant reference to threads.
2. `ref(sum_first_half)` → Allows thread to modify the sum variable.
3. Threads allow parallel computation; in larger arrays, this improves performance.
4. Output for this program:
   Sum of first half: 1275
   Sum of second half: 3775
   Total sum: 5050
---------------------------------------------------------------
*/
