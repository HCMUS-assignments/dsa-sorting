#include "library.h"

// supporting functions defined here


// 1. read input file
void readInputFile (char *fileIn, int *&a, int &n) {
    ifstream fin(fileIn);
    if (fin.fail()) {
        cout << "Cannot open file " << fileIn << endl;
        return;
    }
    fin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    fin.close();
}

// 2. writing file
void writingFile (char *outputFile, int a[], int n) {
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

// 5. do outputOrder for command
void doOutputOrder (char *output, double &time, int &comp, int a[], int n, char *alg) {
    if (strcmp(output, "-time") == 0) {
        time = getTimeOfAlg (alg, a, n);
    } else if (strcmp(output, "-comp") == 0) {
        comp = getCompOfAlg (alg, a, n);
    } else if (strcmp(output, "-both") == 0) {
        time = getTimeOfAlg (alg, a, n);
        comp = getCompOfAlg (alg, a, n);
    } else {
        cout << "Invalid output order" << endl;
    }
}

// 6. get type of input order
int getTypeOfInputOrder (char *inputOrder) {
    int type = -1;
    if (strcmp(inputOrder, "-rand") == 0) {
        type = 0;
    } else if (strcmp(inputOrder, "-sorted") == 0) {
        type = 1;
    } else if (strcmp(inputOrder, "-rev") == 0) {
        type = 2;
    } else if (strcmp(inputOrder, "-nsorted") == 0) {
        type = 3;
    } else {
        cout << "Invalid input order" << endl;
        type = -1;
    }
    return type;
}

// 7. display name of input order
void displayNameOfInputOrder (char *inputOrder) {
    if (strcmp(inputOrder, "-rand") == 0) {
        cout << "Randomize" << endl;
    } else if (strcmp(inputOrder, "-sorted") == 0) {
        cout << "Sorted" << endl;
    } else if (strcmp(inputOrder, "-rev") == 0) {
        cout << "Reversed" << endl;
    } else if (strcmp(inputOrder, "-nsorted") == 0) {
        cout << "Nearly sorted" << endl;
    } else {
        cout << "Invalid input order" << endl;
    }
}



//  Supporting algorithm functions

// 1. swap function
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 2. heapify function
void heapify (int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }

}

// 3. merge function
void merge (int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = a[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }

}

// 4. merge sort function
void mergeSort (int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }

}

// 5. partition function
int partition (int a[], int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);

}

// 6. quick sort function
void quickSort (int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

// 7. counting sort function
void countingSort (int a[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) {
        a[i] = output[i];
    }
}

// 8. get max value function
int getMax (int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// 9. get min value function
int getMin (int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;

}

// 10. get number of digits function
int getNumberOfDigits (int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

// 11. get digit function
int getDigit (int n, int k) {
    int digit = 0;
    for (int i = 0; i < k; i++) {
        digit = n % 10;
        n /= 10;
    }
    return digit;

}

// 12. create queue function
void createQueue(Queue* &Q)
{
	Q = new Queue;
	Q->pHead = NULL;
	Q->pTail = NULL;
}

// 13. create node function
Node* createtNode(int value)
{
	Node* p = new Node;
	p->data = value;
	p->pNext = NULL;

	return p;
}

// 14. check if queue is empty
bool isEmpty(Queue* Q)
{
	if (Q->pHead == NULL) return true;
	else return false;
}

// 15. enqueue function
void enqueue(Queue* Q,int value)
{
	if (isEmpty(Q))
		Q->pHead = Q->pTail = createNode(value);
	else {
		Node* p = createtNode(value);
		Q->pTail->pNext = p;
		Q->pTail = p;
	}
}

// 16. dequeue function
int dequeue(Queue* Q)
{
	Node* del = Q->pHead;
	int result = del->data;
	Q->pHead = del->pNext;
	delete del;
	return result;
}

// 17. get the number of digits of max number
int getNumberDigitsOfMax(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max) max = a[i];
	}

	return getNumberOfDigits(max);
}

// 18. count digits of compare function
int countDigitsOfCompare(int value,int &compare)
{
	if (++compare && value < 10) return 1;
	else return getNumberOfDigits(value / 10) + 1;
}

// 19. get number of digits of max number in compare function
int getNumberDigitsOfMaxCompare(int a[], int n,int &compare)
{
	int max = a[0];
	for (int i = 1; ++compare && i < n; i++)
	{
		if (++compare && a[i] > max) max = a[i];
	}

	return countDigitsOfCompare(max,compare);
}