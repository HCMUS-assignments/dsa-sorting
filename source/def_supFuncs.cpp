#include "library.h"

// supporting functions defined here


// 1. read input file
void readInputFile (char *fileIn, int a[], int &n) {
    ifstream fin(fileIn);
    if (fin.fail()) {
        cout << "Cannot open file " << fileIn << endl;
        return;
    }
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    fin.close();
}

// 2. writing file
void writeOutputFile (char *outputFile, int a[], int n) {
    ofstream fout(outputFile);
    if (fout.fail()) {
        cout << "Cannot open file " << outputFile << endl;
        return;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }

    fout.close();
}

// 3. get time in seconds of the algorithm
double getTimeOfAlg (char *alg, int a[], int n) {
    double time = 0;
    if (strcmp(alg, "selection-sort") == 0) {
        time = selectionSortTime(a, n);
    } else if (strcmp(alg, "insertion-sort") == 0) {
        time = insertionSortTime(a, n);
    } else if (strcmp(alg, "bubble-sort") == 0) {
        time = bubbleSortTime(a, n);
    } else if (strcmp(alg, "shaker-sort") == 0) {
        time = shakerSortTime(a, n);
    } else if (strcmp(alg, "shell-sort") == 0) {
        time = shellSortTime(a, n);
    } else if (strcmp(alg, "heap-sort") == 0) {
        time = heapSortTime(a, n);
    } else if (strcmp(alg, "merge-sort") == 0) {
        time = mergeSortTime(a, n);
    } else if (strcmp(alg, "quick-sort") == 0) {
        time = quickSortTime(a, n);
    } else if (strcmp(alg, "counting-sort") == 0) {
        time = countingSortTime(a, n);
    } else if (strcmp(alg, "radix-sort") == 0) {
        time = radixSortTime(a, n);
    } else if (strcmp(alg, "flash-sort") == 0) {
        time = flashSortTime(a, n);
    } else {
        cout << "Invalid algorithm" << endl;
        return -1;
    }
    return time;
    
}

// 4. get number of comparisons of the algorithm
int getCompOfAlg (char *alg, int a[], int n) {
    int comp = 0;
    if (strcmp(alg, "selection-sort") == 0) {
        comp = selectionSortComp(a, n);
    } else if (strcmp(alg, "insertion-sort") == 0) {
        comp = insertionSortComp(a, n);
    } else if (strcmp(alg, "bubble-sort") == 0) {
        comp = bubbleSortComp(a, n);
    } else if (strcmp(alg, "shaker-sort") == 0) {
        comp = shakerSortComp(a, n);
    } else if (strcmp(alg, "shell-sort") == 0) {
        comp = shellSortComp(a, n);
    } else if (strcmp(alg, "heap-sort") == 0) {
        comp = heapSortComp(a, n);
    } else if (strcmp(alg, "merge-sort") == 0) {
        comp = mergeSortComp(a, n);
    } else if (strcmp(alg, "quick-sort") == 0) {
        comp = quickSortComp(a, n);
    } else if (strcmp(alg, "counting-sort") == 0) {
        comp = countingSortComp(a, n);
    } else if (strcmp(alg, "radix-sort") == 0) {
        comp = radixSortComp(a, n);
    } else if (strcmp(alg, "flash-sort") == 0) {
        comp = flashSortComp(a, n);
    } else {
        cout << "Invalid algorithm" << endl;
        return -1;
    }
    return comp;
    
}