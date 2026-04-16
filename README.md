Sorting Algorithm Performance Analysis
📌 Overview

This project analyzes and compares the performance of three fundamental sorting algorithms:

Merge Sort
Quick Sort
Heap Sort

The comparison is based on execution time (in microseconds) for sorting arrays of increasing sizes.

🎯 Objective

The goal of this experiment is to:

Evaluate how each algorithm performs on different input sizes
Observe practical differences despite similar theoretical complexities
Understand which algorithm is more efficient in real-world scenarios
⚙️ Algorithms Implemented
🔹 Merge Sort
Divide-and-conquer algorithm
Time Complexity: O(n log n) (all cases)
Requires extra memory
🔹 Quick Sort
Divide-and-conquer with partitioning
Time Complexity:
Average: O(n log n)
Worst: O(n²)
Very fast in practice
🔹 Heap Sort
Based on binary heap structure
Time Complexity: O(n log n)
In-place (no extra memory required)
🧪 Experiment Setup
Data Type: Product (id, price)
Sorting Key: price
Input Sizes Tested:
100
1,000
10,000
100,000
Data Generation: Random values using rand()
Time Measurement: chrono library (microseconds)
📈 Sample Results
Input Size	Merge Sort (µs)	Quick Sort (µs)	Heap Sort (µs)
100	        0	              0	                0
1,000	      0	              0	                0
10,000	   6000	            4040	            4970
100,000	   89700	          85200	            174000
📊 Observations
Quick Sort performed the fastest in most cases due to better cache efficiency
Merge Sort showed stable and consistent performance
Heap Sort was slower for large datasets despite having the same theoretical complexity
🧠 Conclusion
Quick Sort is best for large datasets in memory
Heap Sort is suitable for memory-constrained systems
Merge Sort is ideal when stability is required
▶️ How to Run
Compile the program:
g++ Untitled1.cpp -o sort
Run the executable:
./sort
📁 File Structure
Untitled1.cpp   # Main source code
README.md       # Project documentation
