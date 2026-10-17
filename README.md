# 📘 Page Replacement Algorithm Simulator (C++)

A C++-based **Operating Systems project** that simulates and compares three popular page replacement algorithms: FIFO, LRU, and Optimal.

The simulator demonstrates how operating systems manage memory frames, handle page faults, and improve page hit rates using different page replacement strategies.

## 📌 Project Overview

Page replacement is a memory management technique used by operating systems when a requested page is not available in physical memory and all memory frames are occupied.

This project implements three page replacement algorithms and displays their step-by-step execution, page faults, page hits, hit ratio, and fault ratio.

## ✨ Features

* ✅ Implements FIFO (First-In, First-Out).
* ✅ Implements LRU (Least Recently Used).
* ✅ Implements Optimal Page Replacement.
* ✅ Accepts a page reference string as user input.
* ✅ Accepts the number of memory frames.
* ✅ Displays step-by-step frame contents.
* ✅ Identifies page hits and page faults.
* ✅ Calculates page hit ratio and page fault ratio.
* ✅ Compares the performance of all three algorithms.
* ✅ Uses separate functions for each algorithm.
* ✅ Written in C++ using a structured programming approach.

## 🛠️ Technologies Used

* **Programming Language:** C++
* **Compiler:** GCC / G++
* **IDE:** Visual Studio Code
* **Version Control:** Git and GitHub

## 🧠 Algorithms Implemented

### 1. FIFO (First-In, First-Out)

FIFO replaces the page that entered memory first.

* Simple to implement.
* Maintains pages in arrival order.
* May suffer from Belady's anomaly.

### 2. LRU (Least Recently Used)

LRU replaces the page that has not been accessed for the longest time.

* Uses past page references to select a victim.
* Often performs better than FIFO, although not for every reference string.
* Requires tracking page usage history.

### 3. Optimal Page Replacement

Optimal replaces the page whose next use is farthest in the future, or that will not be used again.

* Produces the minimum possible number of page faults for a given reference string and frame count.
* Useful as a benchmark for comparing other algorithms.
* Requires knowledge of future page references, so it is generally not directly implementable as a real-time replacement policy.

## 📥 Sample Input

```text
Enter number of pages: 13
Enter reference string: 7 0 1 2 0 3 0 4 2 3 0 3 2
Enter number of frames: 3
```

## 📊 Sample Results

For the reference string above with 3 frames:

| Algorithm | Page Faults | Page Hits | Fault Ratio | Hit Ratio |
| --------- | ----------: | --------: | ----------: | --------: |
| FIFO      |          10 |         3 |      76.92% |    23.08% |
| LRU       |           9 |         4 |      69.23% |    30.77% |
| Optimal   |           7 |         6 |      53.85% |    46.15% |

*Note: These results correspond to the sample input shown above.*

## ⚙️ How to Run the Project

### Step 1: Clone the Repository

```bash
git clone https://github.com/sanjeetkumar989159-hub/Page-Replacement-Algorithm-Simulator-OS.git
```

### Step 2: Open the Project Folder

```bash
cd Page-Replacement-Algorithm-Simulator-OS
```

### Step 3: Compile the Program

Make sure GCC/G++ is installed.

```bash
g++ page_replacement.cpp -o page_replacement
```

### Step 4: Run the Program

**Windows:**

```powershell
.\page_replacement.exe
```

**Linux/macOS:**

```bash
./page_replacement
```

> **Note:** If your C++ source file has a different name, replace `page_replacement.cpp` with your actual filename in the compilation command.

## 📁 Project Structure

```text
Page-Replacement-Algorithm-Simulator-OS/
│
├── page_replacement.cpp
├── README.md
└── screenshots/
    ├── fifo-output.png
    ├── lru-output.png
    └── optimal-output.png
```

*The screenshot files are examples of suggested filenames. Add your actual screenshots to the `screenshots` folder.*

## 📈 Performance Analysis

* **FIFO:** Replaces the oldest loaded page without considering recent usage.
* **LRU:** Considers past usage and replaces the least recently accessed page.
* **Optimal:** Uses future references to select the best page to replace.

For the sample input, Optimal produces the fewest page faults, followed by LRU and FIFO.

The results may differ for other reference strings and frame counts.

## 🎯 Learning Outcomes

Through this project, I learned:

* Fundamentals of operating system memory management.
* How page replacement algorithms work.
* The difference between page hits and page faults.
* How to calculate hit and fault ratios.
* How to implement algorithms using separate C++ functions.
* How to compare algorithm performance.
* How to use Git, GitHub, and Visual Studio Code for project development.

## 🚀 Future Improvements

* Add a graphical user interface.
* Support larger reference strings.
* Display graphical performance comparisons.
* Allow users to save simulation results.
* Add more page replacement algorithms.

## 👨‍💻 Author

**Sumit**

GitHub: [@sanjeetkumar989159-hub](https://github.com/sanjeetkumar989159-hub)

## 📄 License

This project is intended for educational purposes and Operating Systems Lab practice.
