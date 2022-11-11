#include "library.h"

int main(int argc, char **argv) {
    // validate the params
    


    
}


    // Data Order: 1. sorted data, 2. nearly sorted data, 3. reverse sorted data, 4. randomized data

    // Data size: 10 000, 30 000, 50 000, 100 000, 300 000, 500 000

    // I. Algorithm mode:

    //  command 1: running a sorting algorithm on the given input data
    //  prototype: [Execution file] -a [Algorithm] [Given input] [Output params]
    //  Example:   a.exe -a radix-sort input.txt -both

    // command 2: Run a sorting algorithm on the data generated automatically with specified size and order
    // prototype; [Execution file] -a [Algorithm] [Input size] [Input order] [output params]
    // Example:   a.exe -a selection-sort 50 -rand -time

    // command 3:  Run a sorting algorithm on ALL data arrangements of a specified size.
    // prototype: [Execution file] -a [Algorithm] [Input size] [Output params]
    // Example:   a.exe -a binary-insertion-sort 7000 -comp


    // II. Comparison mode:

    // command 4:  Run two sorting algorithms on the given input.
    // prototype: [Execution file ] -c [Algorithm 1] [Algorithm 2] [Given input]  
    // Example:    a.exe -c heap-sort merge-sort input.txt

    // command 5:  Run two sorting algorithms on the data generated automatically.
    // prototype:  [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
    // Example:    a.exe -c quick-sort merge-sort 100000 -nsorted

    // III. Input order:
    //  -rand: randomized data
    //  -nsorted: nearly sorted data
    //  -sorted: sorted data
    // - rev: reverse sorted data

    // IV. Output params:
    // -time: running time
    // -comp: number of comparisons
    // -both: 