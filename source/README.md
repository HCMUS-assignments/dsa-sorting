# :reminder_ribbon: DSA Sorting
___
# :page_facing_up: Table of Contents
## 1. [Introduction](##introduction)
## 2. [Sorting Algorithms](##sorting-algorithms)
###     2.1 [Selection Sort](###selection-sort)
###     2.2 [Insertion Sort](###insertion-sort)
###     2.3 [Bubble Sort](###bubble-sort)
###     2.4 [Shaker Sort](###shaker-sort)
###     2.5 [Shell Sort](###shell-sort)
###     2.6 [Heap Sort](###heap-sort)
###     2.7 [Merge Sort](###merge-sort)
###     2.8 [Quick Sort](###quick-sort)
###     2.9 [Counting Sort](###counting-sort)
###     2.10 [Radix Sort](###radix-sort)
###     2.11 [Flash Sort](###flash-sort)
## 3. [References](##references)

___


## :book: Introduction
### I. Algorithm mode:

    command 1: running a sorting algorithm on the given input data
    prototype: [Execution file] -a [Algorithm] [Given input] [Output params]
    Example:   a.exe -a radix-sort input.txt -both

    command 2: Run a sorting algorithm on the data generated automatically with specified size and order
    prototype; [Execution file] -a [Algorithm] [Input size] [Input order] [output params]
    Example:   a.exe -a selection-sort 50 -rand -time

    command 3:  Run a sorting algorithm on ALL data arrangements of a specified size.
    prototype: [Execution file] -a [Algorithm] [Input size] [Output params]
    Example:   a.exe -a binary-insertion-sort 7000 -comp


### II. Comparison mode:

    command 4:  Run two sorting algorithms on the given input.
    prototype: [Execution file ] -c [Algorithm 1] [Algorithm 2] [Given input]  
    Example:    a.exe -c heap-sort merge-sort input.txt

    command 5:  Run two sorting algorithms on the data generated automatically.
    prototype:  [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
    Example:    a.exe -c quick-sort merge-sort 100000 -nsorted

### III. Input order ~ Data order : 4 types
     -rand: randomized data
     -nsorted: nearly sorted data
     -sorted: sorted data
    - rev: reverse sorted data

### IV. Output params:
    -time: running time
    -comp: number of comparisons
    -both: 

### V. Given input:
    1st line : an interger n, the number of elements in the array
    2nd line: n integers, the elements of the array, separated by a single space

### VI. Output:
    -time : algorithm running time
    -comp : number of comparisons
    -both : both time and comparisons

### VII. Data size: 10 000, 30 000, 50 000, 100 000, 300 000, 500 000

## :books: Sorting Algorithms
### :one: Selection Sort
#### I. Algorithm:
    1. Find the smallest element in the array and swap it with the first element.
    2. Find the second smallest element in the array and swap it with the second element.
    3. Find the third smallest element in the array and swap it with the third element.
    4. Repeat until the array is sorted.

#### II. Complexity:
    - Time complexity: O(n^2)
    - Space complexity: O(1)

### :two: Insertion Sort
#### I. Algorithm:
    1. Insert the second element into the sorted subarray.
    2. Insert the third element into the sorted subarray.
    3. Insert the fourth element into the sorted subarray.
    4. Repeat until the array is sorted.

#### II. Complexity:
    - Time complexity: O(n^2)
    - Space complexity: O(1)

### :three: Bubble Sort
#### I. Algorithm:
    1. Compare the first element with the second element. If the first element is greater than the second element, swap them.
    2. Compare the second element with the third element. If the second element is greater than the third element, swap them.
    3. Compare the third element with the fourth element. If the third element is greater than the fourth element, swap them.
    4. Repeat until the array is sorted.

#### II. Complexity:
    - Time complexity: O(n^2)
    - Space complexity: O(1)

### :four: Shaker Sort
#### I. Algorithm:
    1. Compare the first element with the second element. If the first element is greater than the second element, swap them.
    2. Compare the second element with the third element. If the second element is greater than the third element, swap them.
    3. Compare the third element with the fourth element. If the third element is greater than the fourth element, swap them.
    4. Repeat until the array is sorted.

#### II. Complexity:
    - Time complexity: O(n^2)
    - Space complexity: O(1)

### :five: Shell Sort
#### I. Algorithm:
    1. Sort the elements with a gap of n/2.
    2. Sort the elements with a gap of n/4.
    3. Sort the elements with a gap of n/8.
    4. Repeat until the array is sorted.

#### II. Complexity:
    - Time complexity: O(n^2)
    - Space complexity: O(1)

### :six: Heap Sort
#### I. Algorithm:
    1. Build a max heap from the input data.
    2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree.
    3. Repeat step 2 while size of heap is greater than 1.

#### II. Complexity:
    - Time complexity: O(nlogn)
    - Space complexity: O(1)

### :seven: Merge Sort
#### I. Algorithm:
    1. If the list is empty or has one item, it is sorted.
    2. Divide the list recursively into two halves until it can no more be divided.
    3. Merge the smaller lists into new list in sorted order.

#### II. Complexity:
    - Time complexity: O(nlogn)
    - Space complexity: O(n)

### :eight: Quick Sort
#### I. Algorithm:
    1. Pick an element, called a pivot, from the list.
    2. Reorder the list so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
    3. Recursively apply the above steps to the sub-list of elements with smaller values and separately to the sub-list of elements with greater values.

#### II. Complexity:
    - Time complexity: O(nlogn)
    - Space complexity: O(nlogn)

### :nine: Counting Sort
#### I. Algorithm:
    1. Find the largest element in the array.
    2. Create a count array of size equal to the largest element and initialize it with all zeros.
    3. Store the count of each element at its respective index in count array.
    4. Find cumulative sum of elements in the count array.
    5. Find the index of each element of the original array in the count array. This gives the cumulative count.
    6. Place the element at the index calculated in step 5 in the output array.
    7. Reduce the count by 1 for each index calculated.

#### II. Complexity:
    - Time complexity: O(n+k)
    - Space complexity: O(n+k)

### :keycap_ten: Radix Sort
#### I. Algorithm:
    1. Find the maximum number to know number of digits.
    2. Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is current digit number.
    3. The idea of Radix Sort is to do digit by digit sort starting from least significant digit to most significant digit. Radix sort uses counting sort as a subroutine to sort.

#### II. Complexity:
    - Time complexity: O(nk)
    - Space complexity: O(n+k)

### :one: :one: Flash Sort
#### I. Algorithm:
    1. Find the minimum and maximum values in the array.
    2. Calculate the m value using the following formula: m = (n * alpha) / (max - min)
    3. Create a new array of size m and initialize it with zeros.
    4. Iterate over the array and calculate the index of each element using the following formula: index = (array[i] - min) * m / (max - min)
    5. Increment the value at the index calculated in step 4.
    6. Iterate over the new array and calculate the cumulative sum.
    7. Iterate over the array in reverse order and calculate the index of each element using the following formula: index = (array[i] - min) * m / (max - min)
    8. Place the element at the index calculated in step 7 in the output array.
    9. Reduce the count by 1 for each index calculated.

#### II. Complexity:
    - Time complexity: O(n)
    - Space complexity: O(n)

## :book: references
