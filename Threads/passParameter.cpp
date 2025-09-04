/**
 * Program: Sum elements of an array using a thread
 * 
 * - A separate thread calculates the sum of array elements.
 * - Main process waits for thread to finish using join().
 * - Demonstrates thread creation, passing arguments, and thread synchronization.
 */

#include <iostream>
#include <thread>
#include <unistd.h> // for sleep()

using namespace std;



// Step 1: Thread function to calculate sum
void thread_fun(int arr[], int size, int &sum) {

    cout << "[THREAD] Started calculation..." << endl;

    sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];   // Add element to sum
        cout << "[THREAD] Element " << i 
             << " summed. Current sum: " << sum << endl;

        sleep(1);        // Sleep for 1 second to simulate work
    }

    cout << "[THREAD] Finished calculation." << endl;
}



int main() {

    // Step 2: Define array and sum variable
    int ara[3] = {1, 2, 3};
    int sum = 0;



    // Step 3: Create a thread
    // Pass array, its size, and reference to sum variable
    thread t1(thread_fun, ara, 3, ref(sum));



    // Step 4: Wait for thread to finish
    t1.join();



    // Step 5: Back to main process
    cout << "[MAIN] Thread has finished." << endl;
    cout << "[MAIN] Sum of elements: " << sum << endl;



    // Step 6: End of program
    return 0;
}



/*
---------------------------------------------------------------
📌 Notes:

1. `ref(sum)` → Passes the sum variable by reference, so the thread
   can modify it and main process can access the result.

2. `sleep(1)` → Simulates delay in thread processing; useful for 
   observing step-by-step execution.

3. Output will show:
   - Thread starts
   - Each element being summed
   - Main process resumes after join() with total sum

---------------------------------------------------------------
*/
