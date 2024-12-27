# Comprehensive Comparison of Sorting Algorithms

| **Aspect**                  | **Bubble Sort**                          | **Selection Sort**                      | **Insertion Sort**                    | **Merge Sort**                           | **Quick Sort**                             |
|-----------------------------|-------------------------------------------|------------------------------------------|---------------------------------------|------------------------------------------|---------------------------------------------|
| **Time Complexity (Best)**  | O(n) *(already sorted)*                  | O(n²)                                   | O(n) *(already sorted)*               | O(n log n)                               | O(n log n) *(partition balanced)*          |
| **Time Complexity (Worst)** | O(n²)                                    | O(n²)                                   | O(n²)                                  | O(n log n)                               | O(n²) *(partition unbalanced)*             |
| **Time Complexity (Avg)**   | O(n²)                                    | O(n²)                                   | O(n²)                                  | O(n log n)                               | O(n log n)                                 |
| **Space Complexity**        | O(1) *(in-place)*                        | O(1) *(in-place)*                       | O(1) *(in-place)*                     | O(n) *(extra arrays)*                    | O(log n) *(recursive stack for partitions)*|
| **Stability**               | Stable                                   | Not Stable                              | Stable                                | Stable                                   | Not Stable *(depends on implementation)*   |
| **Method**                  | Swapping adjacent elements               | Selecting the minimum and swapping      | Shifting and inserting elements       | Divide and conquer                       | Divide and conquer                          |
| **Number of Comparisons**   | O(n²)                                    | O(n²)                                   | O(n²)                                  | O(n log n)                               | O(n log n)                                 |
| **Number of Swaps**         | O(n²)                                    | O(n)                                    | O(n²) *(in worst case)*               | Depends on merging                       | Depends on partitioning                     |
| **Number of Writes**        | High (due to repeated swaps, O(n²))       | Low (only O(3n))                        | Low (shifts instead of swaps)         | High (due to copying in merge steps)     | Moderate (partition-based writes)          |
| **Recursive/Iterative**     | Iterative                                | Iterative                               | Iterative                              | Recursive/Iterative                      | Recursive                                  |
| **Use Case**                | Educational purposes                     | Simple datasets; teaching               | Small or nearly sorted datasets       | Large datasets; stable sort needed       | General-purpose; large datasets            |
| **Practicality**            | Rarely used                              | Rarely used                             | Useful for small datasets              | Commonly used for external sorting       | Widely used; efficient in practice          |

---

## Key Observations

### Bubble Sort

- Inefficient and primarily used for teaching purposes.
- Stable due to adjacent swapping.
- Comparisons and swaps are proportional to O(n²).

### Selection Sort

- Simpler than Bubble Sort but still inefficient for large datasets.
- Not stable because minimum elements are moved to the beginning.
- Performs fewer writes (O(3n)), making it advantageous when writes are costly.

### Insertion Sort

- Very efficient for small or nearly sorted datasets.
- Stable due to its nature of shifting instead of swapping.
- Used as a subroutine in hybrid algorithms like Timsort.

### Merge Sort

- Excellent for large datasets or when stability is required.
- Space complexity is O(n) due to additional arrays.
- Divide-and-conquer strategy ensures O(n log n) performance in all cases.

### Quick Sort

- Fast and efficient in practice due to its in-place nature.
- Not stable as elements are swapped based on partitioning.
- Worst-case performance of O(n²) can be mitigated with randomized pivot selection.

This document provides a detailed breakdown of each algorithm’s characteristics, making it a reliable reference for understanding and choosing the appropriate sorting algorithm based on specific requirements.
