#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <string.h>
using namespace std;

// I. Algorithms

// 1. selection sort
double selectionSortTime (int a[], int n);
int selectionSortComp (int a[], int n);

// 2. insertion sort
double insertionSortTime (int a[], int n);
int insertionSortComp (int a[], int n);

// 3. bubble sort
double bubbleSortTime (int a[], int n);
int bubbleSortComp (int a[], int n);

// 4. shaker sort
double shakerSortTime (int a[], int n);
int shakerSortComp (int a[], int n);

// 5. shell sort
double shellSortTime (int a[], int n);
int shellSortComp (int a[], int n);

// 6. heap sort
void heapify (int a[], int n, int i);
double heapSortTime (int a[], int n);
int heapSortComp (int a[], int n);

// 7. merge sort
void mergeSort (int a[], int l, int r);
void merge (int a[], int l, int m, int r);
double mergeSortTime (int a[], int n);
int mergeSortComp (int a[], int n);

// 8. quick sort
int partition (int a[], int low, int high);
void quickSort (int a[], int low, int high);
double quickSortTime (int a[], int n);
int quickSortComp (int a[], int n);

// 9. counting sort
double countingSortTime (int a[], int n);
int countingSortComp (int a[], int n);

// 10. radix sort
double radixSortTime (int a[], int n);
int radixSortComp (int a[], int n);

// 11. flash sort
double flashSortTime (int a[], int n);
int flashSortComp (int a[], int n);



// II. Command functions

// 1. command 1
void doCommand1 (char *alg, char *fileIn, char *output);

// 2. command 2
void doCommand2 (char *alg, char *inputSize, char *inputOrder, char *output);

// 3. command 3
void doCommand3 (char *alg, char *inputSize, char *output);

// 4. command 4
void doCommand4 (char *alg1, char *alg2, char *fileIn);

// 5. command 5
void doCommand5 (char *alg1, char *alg2, char *inputSize, char *inputOrder);



// III. Supporting functions

// 1. read input file
void readInputFile (char *fileIn, int a[], int &n);

// 2. writing file function
void writingFile (char *outputFile, int a[], int n);

// 3. get time in seconds of the algorithm
double getTimeOfAlg (char *alg, int a[], int n);

// 4. get number of comparisons of the algorithm
int getCompOfAlg (char *alg, int a[], int n);

// 5. doOutputOrder function
void doOutputOrder (char *output, double &time, int &comp, int a[], int n, char *alg);

// 6. get type of input order
int getTypeOfInputOrder (char *inputOrder);

// 7. display name of input order
void displayNameOfInputOrder (char *inputOrder);



// IV. Generate data functions

// 1. generate random data
void GenerateRandomData (int a[], int n);

// 2. generate sorted data
void GenerateSortedData (int a[], int n);

// 3. generate reversed data
void GenerateReversedData (int a[], int n);

// 4. generate nearly sorted data
void GenerateNearlySortedData (int a[], int n);

// 5. generate data function
void GenerateData (int a[], int n, int dataType);


// V. Supporting algorithm functions

// 1. swap function
void swap (int *a, int *b);

// 2. get max value function
int getMax (int a[], int n);

// 3. get min value function
int getMin (int a[], int n);

// 4. get number of digits function
int getNumberOfDigits (int n);

// 5. get digit function
int getDigit (int n, int k);

// struct Node
struct Node
{
    int data;
    Node *pNext;
};

// struct Queue
struct Queue {
	Node* pHead;
	Node* pTail;
};

// 6. create queue function
void createQueue (Queue *&Q);

// 7. create node function
Node* createNode (int value);

// 8. check if queue is empty
bool isEmpty(Queue* Q);

// 9. enqueue function
void enqueue(Queue* Q,int value);

// 10. dequeue function
int dequeue(Queue* Q);

// 11. get the number of digits of max number
int getNumberDigitsOfMax(int a[], int n);

// 12. count digits of compare function
int countDigitsOfCompare(int value,int &compare);

// 13. get number of digits of max number in compare function
int getNumberDigitsOfMaxCompare(int a[], int n,int &compare);
