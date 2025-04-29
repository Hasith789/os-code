# Real-Time Process Synchronization Simulator with Deadlock Detection

This is a simple, interactive web application designed to demonstrate how multiple processes can safely access a shared resource using synchronization mechanisms. It also visually illustrates race conditions and how deadlocks can be detected and resolved in real time.

## What This Project Does

This simulator allows users to:

- Choose how many processes to run (up to 20).
- Toggle synchronization ON or OFF.
- Watch each process as it moves through different states: waiting, running, done, or deadlocked.
- See a shared counter being incremented in a controlled or uncontrolled environment.
- View a live log of all events and download it as a text file.

## Why This Project Was Created

The goal of this project is to help students and enthusiasts understand the concept of process synchronization in operating systems. Concepts like critical sections, mutual exclusion, and deadlock are much easier to grasp when you can see them in action.

## How It Works

- In **synchronized mode**, a simple software-based lock ensures that only one process enters the critical section at a time. If a process waits too long for the lock (more than 5 seconds), the simulator assumes a deadlock has occurred and resets the lock.
- In **unsynchronized mode**, all processes run simultaneously without any restriction, which may lead to unpredictable results due to race conditions.

## How to Use It

1. Open the `index.html` file in your browser.
2. Select the number of processes.
3. Choose whether to enable synchronization.
4. Click "Start Simulation" to begin.
5. Watch the process states change and observe the shared counter.
6. You can also download the event log for later review.

## Technologies Used

- HTML for structure
- CSS for styling
- JavaScript for behavior and logic

No frameworks or libraries are required. Just a browser is enough to run this simulation.

## Educational Value

This tool is especially useful for:

- Operating Systems courses
- Demonstrating synchronization issues in class
- Self-study for understanding concurrency

## Future Improvements

Some ideas for enhancements include:

- Visual timelines for each process
- Graphical representation of the lock status
- More advanced synchronization techniques (e.g., semaphores or monitors)

## License

This project is open-source and available under the MIT License. Feel free to modify and use it for educational or personal purposes.
