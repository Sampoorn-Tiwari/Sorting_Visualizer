# SFML Sorting Visualizer - Bubble Sort VS Insertion Sort

Sorting visualizer made by using SFML in c++.

## Why Insertion Sort was faster
Both algorithms sort an identical array of randomly generated bars. Despite both having a theoretical time complexity of O(N^2), Insertion Sort finishes significantly faster. 

Here is what i realized after seeing visualization:
* Bubble Sort : It picks each bar and traverses the entire unsorted section of the array to compare and sort, executing the maximum number of operations every single time.

* Insertion Sort : It skips unecessary operations. It checks the bars to its left, and the moment it finds a smaller bar, it realizes it has found its perfect spot. It immediately skips the rest of the checks, assuming the left partition is already sorted.

By skipping these massive amounts of unnecessary swap operations, Insertion Sort vastly outperforms the brute-force nature of Bubble Sort.