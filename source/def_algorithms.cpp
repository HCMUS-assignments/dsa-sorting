#include "library.h"

// algorithms functions are defined here

// 1. selection sort (done)
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
    return (double) 1000 * (end - start) / CLOCKS_PER_SEC;
}
int selectionSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons
    for (int i = 0; ++comp && i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; ++comp && j < n; j++) {
            if (++comp && a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }

    
    return comp;
}

// 2. insertion sort  * (done)
double insertionSortTime (int a[], int n) {
    clock_t start = clock();

    // insertion sort
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = a[i];

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    clock_t end = clock();
    return (double) 1000 * (end - start) / CLOCKS_PER_SEC;

}
int insertionSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons
    for (int i = 1; ++comp && i < n; i++) {
        int j = i - 1;
        int key = a[i];

        while (++comp && j >= 0 && ++comp && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
    
    return comp;

}

// 3. bubble sort (done)
double bubbleSortTime (int a[], int n) {
    clock_t start = clock();

    for (int i = 0; i < n-1 ; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }

    clock_t end = clock();
    return (double) 1000 * (end - start) / CLOCKS_PER_SEC;
}

int bubbleSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons
    for (int i = 0; ++comp &&  i < n-1; i++)
    {
        for (int j = 0; ++comp && j < n-i-1; j++)
        {
            if (++comp && a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
    return comp;
}

// 4. shaker sort (done)
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
    return (double) 1000 * (end - start) / CLOCKS_PER_SEC;


}
int shakerSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons
    int left = 0;
    int right = n - 1;
    while (++comp && left < right) {
        for (int i = right;++comp &&  i > left; i--) {
            if (++comp && a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
            }
        }
        left++;
        for (int i = left;++comp && i < right; i++) {
            if (++comp && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
        right--;
    }

    return comp;
}

// 5. shell sort (done)
double shellSortTime (int a[], int n) {
    clock_t start = clock();

    // shell sort
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }

    clock_t end = clock();
    return (double) 1000 * (end - start) / CLOCKS_PER_SEC;

}
int shellSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons
     for (int gap = n / 2; ++comp && gap > 0; gap /= 2) {
        for (int i = gap; ++comp && i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; ++comp && j >= gap && ++comp && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }

    return comp;
    
}

// 6. heap sort
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
    return (double) 1000 * (end - start) / CLOCKS_PER_SEC;
}

void heapifyComp(int a[], int n, int i, int &comp) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if ((++comp && l < n) && (++comp && a[l] > a[largest])) {
        largest = l;
    }
    if ((++comp && r < n) && (++comp && a[r] > a[largest])) {
        largest = r;
    }
    if (++comp && largest != i) {
        swap(a[i], a[largest]);
        heapifyComp(a, n, largest,comp);
    }
}

int heapSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons
    for (int i = n / 2 - 1;++comp && i >= 0; i--) {
        heapifyComp(a, n, i,comp);
    }
    for (int i = n - 1;++comp && i >= 0; i--) {
        swap(a[0], a[i]);
        heapifyComp(a, i, 0,comp);
    }

    return comp;
}

// 7. merge sort (done)

void merge(int* arr, int *leftArr, int* rightArr, int n){
	int nL = n/2;
	int nR = n - nL;
	int iL = 0, iR = 0, i = 0;

	while (iL < nL && iR < nR) {
		if(leftArr[iL] <= rightArr[iR])
			arr[i++] = leftArr[iL++];
		else arr[i++] = rightArr[iR++];
    }

	while (iL < nL) {
		arr[i++] = leftArr[iL++];
    }

	while(iR < nR) {
		arr[i++] = rightArr[iR++];
}

}
void mergeSort(int a[], int n) {
	if (n == 1) return;

	int nL = n/2;
	int nR = n - nL;
	int* arrLeft = new int[nL];
	int* arrRight = new int[nR];

	for(int i = 0; i < nL; i++)
		arrLeft[i] = a[i];

	for(int i = nL; i < n; i++)
		arrRight[i - nL] = a[i];

	mergeSort(arrLeft, nL);
	mergeSort(arrRight, nR);

	merge(a, arrLeft, arrRight, n);

    delete[] arrLeft;
    delete[] arrRight;
}

double mergeSortTime (int a[], int n) {
    clock_t start = clock();

    // merge sort
    mergeSort(a, n);

    clock_t end = clock();
    return (double) 1000 * (end - start) / CLOCKS_PER_SEC;
}


void merge(int* arr, int *leftArr, int* rightArr, int n, int &comp){
	int nL = n/2;
	int nR = n - nL;
	int iL = 0, iR = 0, i = 0;

	while((++comp && iL < nL) && (++comp && iR < nR)) {
		if(++comp && leftArr[iL] <= rightArr[iR])
			arr[i++] = leftArr[iL++];
		else arr[i++] = rightArr[iR++];
    }

	while (++comp && iL < nL) {
		arr[i++] = leftArr[iL++];
    }

	while(++comp && iR < nR) {
		arr[i++] = rightArr[iR++];
    }

}
void mergeSort(int a[], int n, int &comp){
	if (++comp && n == 1) return;

	int nL = n/2;
	int nR = n - nL;
	int* arrLeft = new int[nL];
	int* arrRight = new int[nR];

	for(int i = 0; ++comp && i < nL; i++)
		arrLeft[i] = a[i];
        
	for(int i = nL; ++comp && i < n; i++)
		arrRight[i - nL] = a[i];

	mergeSort(arrLeft, nL);
	mergeSort(arrRight, nR);

	merge(a, arrLeft, arrRight, n,comp);

    delete[] arrLeft;
    delete[] arrRight;
}

int mergeSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons
    mergeSort(a, n, comp);

    
    return comp;
}

// 8. quick sort  ** (done)
void quickSort(int a[], int left, int right) {
    int i = left, j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(a, left, j);
    }
    if (i < right) {
        quickSort(a, i, right);
    }
}
double quickSortTime (int a[], int n) {
    clock_t start = clock();

    // quick sort
    quickSort(a, 0, n - 1);

    clock_t end = clock();
    return (double) 1000 * (end - start) / CLOCKS_PER_SEC;


}

void quickSortComp (int a[], int left, int right, int &comp) {
    int i = left, j = right;
    int pivot = a[(left + right) / 2];

    while (++comp && i <= j) {
        while (++comp && a[i] < pivot) {
            i++;
        }
        while (++comp && a[j] > pivot) {
            j--;
        }
        if (++comp && i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (++comp && left < j) {
        quickSortComp(a, left, j, comp);
    }
    if (++comp && i < right) {
        quickSortComp(a, i, right, comp);
    }
}
int quickSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons
    quickSortComp(a, 0, n - 1, comp);
    
    return comp;


}

// 9. counting sort  *** (done)
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
    return (double) 1000 * (end - start) / CLOCKS_PER_SEC;

}
int countingSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons
    int max = a[0];
    for (int i = 1; ++comp && i < n; i++) {
        if (++comp && a[i] > max) {
            max = a[i];
        }
    }
    int* count = new int[max + 1];
    for (int i = 0;++comp && i < max + 1; i++) {
        count[i] = 0;
    }
    for (int i = 0;++comp && i < n; i++) {
        count[a[i]]++;
    }
    int i = 0;
    int j = 0;
    while (++comp && i < max + 1) {
        if (++comp && count[i] > 0) {
            a[j++] = i;
            count[i]--;
        }
        else {
            i++;
        }
    }

    
    return comp;

}

// 10. radix sort (done)

double radixSortTime (int a[], int n) {
    clock_t start = clock();

    // radix sort
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
    return (double) 1000 * (end - start) / CLOCKS_PER_SEC;
}

int radixSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons
    int max = getNumberDigitsOfMaxCompare(a, n, comp);
	Queue** table = new Queue*[10];

	for (int i = 0; ++comp && i < 10; i++)
	{
		createQueue(table[i]);
	}

	for (int k = 0; ++comp && k < max; k++)
	{
		for (int i = 0; ++comp && i < n; i++)
		{
			int unit =int(a[i] / pow(10, k)) % 10;
			enqueue(table[unit], a[i]);    // enqueue has 1 comparison
            ++comp;
		}
		int j = 0;
		int i = 0;
		while (++comp && j < 10)
		{
			while (++comp && !isEmpty(table[j]) && ++comp) // isEmpty has 1 comparison
			{
				a[i++] = dequeue(table[j]);
			}
			j++;
		}
	}

	delete[] table;
    return comp;
}

// 11. flash sort  (done)
double flashSortTime (int a[], int n) {
    clock_t start = clock();

    // flash sort
    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);   

	int* Class = new int[m];   // create class array to store the number of elements in each class

	for (int i = 0; i < m; i++)
		Class[i] = 0;

    // find min and max
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}

	if (a[max] == minVal)
		return 0;
        
    // c1 used to calculate the class index
	double c1 = (double)(m - 1) / (a[max] - minVal);

    // calculate the number of elements in each class
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++Class[k];
	}

    // calculate the starting position of each class
	for (int i = 1; i < m; i++)
		Class[i] += Class[i - 1];

    // swap the elements in the array to the correct position
	swap(a[max], a[0]);

	int nmove = 0;   // number of elements moved
	int j = 0;
	int k = m - 1;
	while (nmove < n - 1)
	{
        // j used to calculate the class index
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

	// insertionSort(a, n);
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while (j >= 0 && a[j] > x)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}

    clock_t end = clock();
    return (double) 1000 * (end - start) / CLOCKS_PER_SEC;
}

int flashSortComp (int a[], int n) {
    int comp = 0;

    // counting comparisons
    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);

	int* Class = new int[m];

	for (int i = 0; ++comp && i < m; i++)
		Class[i] = 0;

	for (int i = 1; ++comp && i < n; i++)
	{
		if ( ++comp && a[i] < minVal)
			minVal = a[i];
		if ( ++comp && a[i] > a[max])
			max = i;
	}

	if ( ++comp && a[max] == minVal)
		return comp;

	double c1 = (double)(m - 1) / (a[max] - minVal);

	for (int i = 0; ++comp &&  i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++Class[k];
	}

	for (int i = 1; ++comp &&  i < m; i++)
		Class[i] += Class[i - 1];

	swap(a[max], a[0]);

	int nmove = 0;
	int j = 0;
	int k = m - 1;
	while ( ++comp && nmove < n - 1)
	{
		while ( ++comp && j > Class[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		
		if ( ++comp && k < 0) break;
		while ( ++comp && j != Class[k])
		{
			k = int(c1 * (a[j] - minVal));
			int pos = --Class[k];
			swap(a[j], a[pos]);

            ++nmove;
		}
	}
	delete[] Class;

	//insertionSort(a, n);
	for (int i = 1; ++comp &&  i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while ( ++comp && j >= 0 && ++comp && a[j]>x)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
    
    return comp; 
}

