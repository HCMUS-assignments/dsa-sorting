#include "library.h"

// algorithms functions are defined here

// 1. selection sort
double selectionSortTime (int a[], int n) {
    clock_t start = clock();

    // selection sort
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
    
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}
int selectionSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons

    
    return comp;

}

// 2. insertion sort  *
double insertionSortTime (int a[], int n) {
    clock_t start = clock();

    // insertion sort
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int x = a[i];
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;


}
int insertionSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons

    
    return comp;

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
    return (double)(end - start) / CLOCKS_PER_SEC;
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
    clock_t start = clock();

    // shaker sort
    int left = 0;
    int right = n - 1;
    while (left < right) {
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
            }
        }
        left++;
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
        right--;
    }

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;


}
int shakerSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons

    
    return comp;


}

// 5. shell sort
double shellSortTime (int a[], int n) {
    clock_t start = clock();

    // shell sort
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h) {
                swap(a[j], a[j - h]);
            }
        }
        h = h / 3;
    }

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;


}
int shellSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons

    
    return comp;


}

// 6. heap sort
double heapSortTime (int a[], int n) {
    clock_t start = clock();

    // heap sort
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;

}
int heapSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons

    
    return comp;


}

// 7. merge sort
double mergeSortTime (int a[], int n) {
    clock_t start = clock();

    // merge sort
    mergeSort(a, 0, n - 1);

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;


}
int mergeSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons

    
    return comp;

}

// 8. quick sort  **
double quickSortTime (int a[], int n) {
    clock_t start = clock();

    // quick sort
    quickSort(a, 0, n - 1);

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;


}
int quickSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons

    
    return comp;


}

// 9. counting sort  ***
double countingSortTime (int a[], int n) {
    clock_t start = clock();

    // counting sort
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    int* count = new int[max + 1];
    for (int i = 0; i < max + 1; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    int i = 0;
    int j = 0;
    while (i < max + 1) {
        if (count[i] > 0) {
            a[j++] = i;
            count[i]--;
        }
        else {
            i++;
        }
    }

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;

}
int countingSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons

    
    return comp;

}

// 10. radix sort

double radixSortTime (int a[], int n) {
    clock_t start = clock();

    int max = getNumberDigitsOfMax(a, n);
	Queue** table = new Queue*[10];

	for (int i = 0; i < 10; i++)
	{
		createQueue(table[i]);
	}

	for (int k = 0; k < max; k++)
	{
		for (int i = 0; i < n; i++)
		{
			int unit =int(a[i] / pow(10, k)) % 10;
			enqueue(table[unit], a[i]);
		}
		int j = 0;
		int i = 0;
		while (j < 10)
		{
			while (!isEmpty(table[j]))
			{
				a[i++] = dequeue(table[j]);
			}
			j++;
		}
	}

	delete[] table;    

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int radixSortComp (int a[], int n) {
    int compare = 0;
    int max = getNumberDigitsOfMaxCompare(a, n, compare);
	Queue** table = new Queue*[10];

	for (int i = 0; ++compare && i < 10; i++)
	{
		createQueue(table[i]);
	}

	for (int k = 0; ++compare && k < max; k++)
	{
		for (int i = 0; ++compare && i < n; i++)
		{
			int unit =int(a[i] / pow(10, k)) % 10;
			enqueue(table[unit], a[i]);
		}
		int j = 0;
		int i = 0;
		while (++compare && j < 10)
		{
			while (++compare && !isEmpty(table[j]))
			{
				a[i++] = dequeue(table[j]);
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
    return (double)(end - start) / CLOCKS_PER_SEC;
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
    
    return compare; 
}
