#include "library.h"

// command functions are defined here

// 1. command 1
void doCommand1 (char *alg, char *fileIn, char *output) {
    // read the input file
    int n;
    int *a;
    readInputFile(fileIn, a, n);

    // declare the variables
    double time = -1;
    int comp = -1;

    // solve the problem
    doOutputOrder(output, time, comp, a, n, alg);

    // display the result in the console
    cout <<"\nALGORITHM MODE\n";
    cout << "Algorithm: " << alg << endl;
    cout << "Input file: " << fileIn << endl;
    cout << "Input size: " << n << endl;
    cout << "----------------------------------------" << endl;
    cout << "Running time (if required): " ;
    if (time != -1) {
        cout <<  time << "s" << endl;
    } else {
        cout << endl;
    }
    cout << "Comparisons (if required): " ;
    if (comp != -1) {
        cout << comp << endl << endl;
    } else {
        cout << endl << endl;
    }

    // writing file
    writingFile("output.txt", a, n);

    // free the memory
    delete[] a;
}

// 2. command 2
void doCommand2 (char *alg, char *inputSize, char *inputOrder, char *output) {
    int n = atoi(inputSize);
    int *a = new int[n];

    // get type of input order
    int type = getTypeOfInputOrder(inputOrder);

    // generate data
    GenerateData(a, n, type);

    // writing file
    writingFile("output.txt", a, n);

    // declare the variables
    double time = -1;
    int comp = -1;

    // solve the problem
    doOutputOrder(output, time, comp, a, n, alg);

    // display the result in the console
    cout <<"\nALGORITHM MODE\n";
    cout << "Algorithm: " << alg << endl;
    cout << "Input size: " << n << endl;
    cout << "Input order: " ;
    displayNameOfInputOrder(inputOrder);
    cout << "----------------------------------------" << endl;
    cout << "Running time (if required): " ;
    if (time != -1) {
        cout <<  time << "s" << endl;
    } else {
        cout << endl;
    }
    cout << "Comparisons (if required): " ;
    if (comp != -1) {
        cout << comp << endl << endl;
    } else {
        cout << endl << endl;
    }

    // free the memory
    delete[] a;
    
}

// 3. command 3
void doCommand3 (char *alg, char *inputSize, char *output) {
    int n = atoi(inputSize);
    int *a = new int[n];

    // display the result in the console
    cout <<"\nALGORITHM MODE\n";
    cout << "Algorithm: " << alg << endl;
    cout << "Input size: " << n << endl << endl;

    // case 1: input order is random

    // declare the variables
    double time = -1;
    int comp = -1;
    GenerateData(a, n, 0);
    
    // writing file
    writingFile("input_1.txt", a, n);

    // solve the problem
    doOutputOrder(output, time, comp, a, n, alg);

    // display the result in the console
    cout << "Input order: " << "Randomize" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Running time (if required): " ;
    if (time != -1) {
        cout <<  time << "s" << endl;
    } else {
        cout << endl;
    }
    cout << "Comparisons (if required): " ;
    if (comp != -1) {
        cout << comp << endl << endl;
    } else {
        cout << endl << endl;
    }

    // case 2: input order is Nearly sorted
    time = -1;
    comp = -1;
    GenerateData(a, n, 3);

    // writing file
    writingFile("input_2.txt", a, n);

    // solve the problem
    doOutputOrder(output, time, comp, a, n, alg);

    // display the result in the console
    cout << "Input order: " << "Nearly sorted" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Running time (if required): " ;
    if (time != -1) {
        cout <<  time << "s" << endl;
    } else {
        cout << endl;
    }
    cout << "Comparisons (if required): " ;
    if (comp != -1) {
        cout << comp << endl << endl;
    } else {
        cout << endl << endl;
    }

    // case 3: input order is Sorted
    time = -1;
    comp = -1;
    GenerateData(a, n, 1);
    
    // writing file
    writingFile("input_3.txt", a, n);

    // solve the problem
    doOutputOrder(output, time, comp, a, n, alg);

    // display the result in the console
    cout << "Input order: " << "Sorted" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Running time (if required): " ;
    if (time != -1) {
        cout <<  time << "s" << endl;
    } else {
        cout << endl;
    }
    cout << "Comparisons (if required): " ;
    if (comp != -1) {
        cout << comp << endl << endl;
    } else {
        cout << endl << endl;
    }

    // case 4: input order is Reversed
    time = -1;
    comp = -1;
    GenerateData(a, n, 2);

    // writing file
    writingFile("input_4.txt", a, n);

    // solve the problem
    doOutputOrder(output, time, comp, a, n, alg);

    // display the result in the console
    cout << "Input order: " << "Reversed" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Running time (if required): " ;
    if (time != -1) {
        cout <<  time << "s" << endl;
    } else {
        cout << endl;
    }
    cout << "Comparisons (if required): " ;
    if (comp != -1) {
        cout << comp << endl << endl;
    } else {
        cout << endl << endl;
    }

    // free the memory
    delete[] a;
    
}

// 4. command 4
void doCommand4 (char *alg1, char *alg2, char *fileIn) {
    int n = 0;
    int *a = new int[n];

    // read file
    readInputFile(fileIn, a, n);

    // create an copy of array
    int *b = new int[n];
    memmove(b, a, n * sizeof(int)); 

    // declare the variables
    double time1 = -1;
    int comp1 = -1;
    double time2 = -1;
    int comp2 = -1;

    // solve the problem
    doOutputOrder("-both", time1, comp1, a, n, alg1);
    doOutputOrder("-both", time2, comp2, b, n, alg2);

    // display the result in the console
    cout << "\nCOMPARE MODE\n";
    cout << "Algorithm: " << alg1 << " | " << alg2 << endl;
    cout << "Input file: " << fileIn << endl;
    cout << "Input size: " << n << endl;
    cout << "----------------------------------------" << endl;
    cout << "Running time: " << time1 << "s | " << time2 << "s" << endl;
    cout << "Comparisons: " << comp1 << " | " << comp2 << endl << endl;

    // writing file
    writingFile("output.txt", a, n);

    // free the memory
    delete[] a;
    
}

// 5. command 5
void doCommand5 (char *alg1, char *alg2, char *inputSize, char *inputOrder) {
    int n = atoi(inputSize);
    int *a = new int[n];

    // display the result in the console
    cout <<"\nCOMPARE MODE\n";
    cout << "Algorithm: " << alg1 << " | " << alg2 << endl;
    cout << "Input size: " << n << endl;
    cout << "Input order: " ;
    displayNameOfInputOrder(inputOrder);
    cout << "----------------------------------------" << endl;

    // declare the variables
    double time1 = -1;
    int comp1 = -1;
    double time2 = -1;
    int comp2 = -1;

    // generate data
    GenerateData(a, n, getTypeOfInputOrder(inputOrder));

    // create an copy of array
    int *b = new int[n];
    memmove(b, a, n * sizeof(int));

    // writing file : 
    writingFile("input.txt", a, n);

    // solve the problem
    doOutputOrder("-both", time1, comp1, a, n, alg1);
    doOutputOrder("-both", time2, comp2, b, n, alg2);

    // display the result in the console
    cout << "Running time: " << time1 << "s | " << time2 << "s" << endl;
    cout << "Comparisons: " << comp1 << " | " << comp2 << endl << endl;

    // free the memory
    delete[] a;
    
    
}