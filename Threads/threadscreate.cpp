/**
 * Program: Simple thread demonstration
 * 
 * - A thread prints numbers 0 to 4 with a delay.
 * - Main process waits for the thread to finish using join().
 * - Demonstrates basic thread creation, join, and concurrent execution.
 */

#include <iostream>
#include <thread>
#include <unistd.h>  // for sleep()

using namespace std;



// Step 1: Thread function
void thread_fun() {

    cout << "[THREAD] Started execution." << endl;

    for (int j = 0; j < 5; j++) {
        cout << "[THREAD] j = " << j << endl;
        sleep(1);   // Simulate work (1 second delay)
    }

    cout << "[THREAD] Finished execution." << endl;
}



int main() {

    // Step 2: Create a thread
    thread t1(thread_fun);

    // Step 3: Wait for the thread to finish (like pthread_join)
    t1.join();
    // Note: t1.detach() could be used if we want thread to run independently

    
    // Step 4: Main process continues
    cout << "[MAIN] Back to main process." << endl;

    for (int i = 15; i < 20; i++) {
        cout << "[MAIN] i = " << i << endl;
        sleep(1);  // Simulate work in main process
    }



    // Step 5: End of program
    return 0;
}



/*
---------------------------------------------------------------
📌 Notes:

1. `thread t1(thread_fun)` → creates a new thread executing `thread_fun`.
2. `t1.join()` → main process waits until thread finishes.
3. `t1.detach()` → would allow thread to run independently (main doesn't wait).
4. `sleep(1)` → simulates processing time, helps visualize thread execution.

5. Output behavior:
   - Thread prints numbers 0-4 with delays.
   - After thread finishes, main prints numbers 15-19 with delays.
---------------------------------------------------------------
*/
