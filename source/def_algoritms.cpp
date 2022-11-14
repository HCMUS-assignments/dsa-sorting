#include "library.h"

// algorithms functions are defined here

// 1. selection sort
double selectionSortTime (int a[], int n) {

}
int selectionSortComp (int a[], int n) {

}

// 2. insertion sort
double insertionSortTime (int a[], int n) {

}
int insertionSortComp (int a[], int n) {

}

// 3. bubble sort
double bubbleSortTime (int a[], int n) {
    clock_t start = clock();

    for(int i = 0; i < n-1; i++)
    {
        for(int j = n-1; j > i; j--)
        {
            if(a[j] < a[j-1]) swap(a[j], a[j-1]);
        }
    }

    clock_t end = clock();
    return (double)(end - start);
}

int bubbleSortComp (int a[], int n) {
    int compare = 0;
    for(int i = 0; ++compare &&  i < n-1; i++)
    {
        for(int j = n-1; ++compare &&  j > i; j--)
        {
            if(++compare && a[j] < a[j-1]) swap(a[j], a[j-1]);
        }
    }
}

// 4. shaker sort
double shakerSortTime (int a[], int n) {

}
int shakerSortComp (int a[], int n) {

}

// 5. shell sort
double shellSortTime (int a[], int n) {

}
int shellSortComp (int a[], int n) {

}

// 6. heap sort
double heapSortTime (int a[], int n) {

}
int heapSortComp (int a[], int n) {

}

// 7. merge sort
double mergeSortTime (int a[], int n) {

}
int mergeSortComp (int a[], int n) {

}

// 8. quick sort
double quickSortTime (int a[], int n) {

}
int quickSortComp (int a[], int n) {

}

// 9. counting sort
double countingSortTime (int a[], int n) {

}
int countingSortComp (int a[], int n) {

}

// 10. radix sort
struct Node {
	int data;
	Node* pNext;
};

struct Queue {
	Node* pHead;
	Node* pTail;
};

void CreatQueue(Queue* &Q)
{
	Q = new Queue;
	Q->pHead = NULL;
	Q->pTail = NULL;
}

Node* CreatNode(int value)
{
	Node* p = new Node;
	p->data = value;
	p->pNext = NULL;

	return p;
}

bool isEmpty(Queue* Q)
{
	if (Q->pHead == NULL) return true;
	else return false;
}

void _push(Queue* Q,int value)
{
	if (isEmpty(Q))
		Q->pHead = Q->pTail = CreatNode(value);
	else {
		Node* p = CreatNode(value);
		Q->pTail->pNext = p;
		Q->pTail = p;
	}
}

int _pop(Queue* Q)
{
	Node* del = Q->pHead;
	int result = del->data;
	Q->pHead = del->pNext;
	delete del;
	return result;
}

int CountDigit(int value)
{
	if (value < 10) return 1;
	else return CountDigit(value / 10) + 1;
}

int MaxNumberofDigits(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max) max = a[i];
	}

	return CountDigit(max);
}

double radixSortTime (int a[], int n) {
    clock_t start = clock();

    int max = MaxNumberofDigits(a, n);
	Queue** table = new Queue*[10];

	for (int i = 0; i < 10; i++)
	{
		CreatQueue(table[i]);
	}

	for (int k = 0; k < max; k++)
	{
		for (int i = 0; i < n; i++)
		{
			int unit =int(a[i] / pow(10, k)) % 10;
			_push(table[unit], a[i]);
		}
		int j = 0;
		int i = 0;
		while (j < 10)
		{
			while (!isEmpty(table[j]))
			{
				a[i++] = _pop(table[j]);
			}
			j++;
		}
	}

	delete[] table;    

    clock_t end = clock();
    return (double)(end - start);    
}

int CountDigit_Compare(int value,int &compare)
{
	if (++compare && value < 10) return 1;
	else return CountDigit(value / 10) + 1;
}

int MaxNumberofDigits_Compare(int a[], int n,int &compare)
{
	int max = a[0];
	for (int i = 1; ++compare && i < n; i++)
	{
		if (++compare && a[i] > max) max = a[i];
	}

	return CountDigit_Compare(max,compare);
}

int radixSortComp (int a[], int n) {
    int compare = 0;
    int max = MaxNumberofDigits_Compare(a, n, compare);
	Queue** table = new Queue*[10];

	for (int i = 0; ++compare && i < 10; i++)
	{
		CreatQueue(table[i]);
	}

	for (int k = 0; ++compare && k < max; k++)
	{
		for (int i = 0; ++compare && i < n; i++)
		{
			int unit =int(a[i] / pow(10, k)) % 10;
			_push(table[unit], a[i]);
		}
		int j = 0;
		int i = 0;
		while (++compare && j < 10)
		{
			while (++compare && !isEmpty(table[j]))
			{
				a[i++] = _pop(table[j]);
			}
			j++;
		}
	}

	delete[] table;
    return compare;
}

// 11. flash sort
double flashSortTime (int a[], int n) {
    clock_t start = clock();

    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);

	int* Class = new int[m];
	for (int i = 0; i < m; i++)
		Class[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}

	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++Class[k];
	}

	for (int i = 1; i < m; i++)
		Class[i] += Class[i - 1];

	swap(a[max], a[0]);

	int nmove = 0;
	int j = 0;
	int k = m - 1;
	while (nmove < n - 1)
	{
		while (j > Class[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		
		if (k < 0) break;
		while (j != Class[k])
		{
			k = int(c1 * (a[j] - minVal));
			int pos = --Class[k];
			swap(a[j], a[pos]);
			
			++nmove;
		}
	}
	delete[] Class;

	//insertionSort(a, n);
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while (j >= 0&&a[j]>x)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}

    clock_t end = clock();
    return (double)(end - start);
}

int flashSortComp (int a[], int n) {
    int compare = 0;
    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);

	int* Class = new int[m];
	for (int i = 0; ++compare && i < m; i++)
		Class[i] = 0;
	for (int i = 1; ++compare && i < n; i++)
	{
		if ( ++compare && a[i] < minVal)
			minVal = a[i];
		if ( ++compare && a[i] > a[max])
			max = i;
	}

	if ( ++compare && a[max] == minVal)
		return compare;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++compare &&  i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++Class[k];
	}

	for (int i = 1; ++compare &&  i < m; i++)
		Class[i] += Class[i - 1];

	swap(a[max], a[0]);

	int nmove = 0;
	int j = 0;
	int k = m - 1;
	while ( ++compare && nmove < n - 1)
	{
		while ( ++compare && j > Class[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		
		if ( ++compare && k < 0) break;
		while ( ++compare && j != Class[k])
		{
			k = int(c1 * (a[j] - minVal));
			int pos = --Class[k];
			swap(a[j], a[pos]);

            ++nmove;
		}
	}
	delete[] Class;

	//insertionSort(a, n);
	for (int i = 1; ++compare &&  i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while ( ++compare && j >= 0 && ++compare && a[j]>x)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}
