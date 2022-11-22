#include "library.h"

void takeCountingAndTime(int* arr, int n, int type, unsigned long long& comp, double& time){
    int* arrComp = new int[n];
    int* arrTime = new int[n];

    memmove(arrComp, arr, sizeof(int)*n);
    memmove(arrTime, arr, sizeof(int)*n);

    switch (type)
    {
    case 0:
        cout << "Selection sort with size " << n <<endl;
        comp = selectionSortComp(arrComp, n);
        time = selectionSortTime(arrTime, n);
        break;
    case 1:
        cout << "Insertion sort with size " << n <<endl;
        comp = insertionSortComp(arrComp, n);
        time = insertionSortTime(arrTime, n);
        
        break;
    case 2:
        cout << "Bubble sort with size " << n  <<endl;
        comp = bubbleSortComp(arrComp, n);
        time = bubbleSortTime(arrTime, n);
        
        break;
    case 3:
         cout << "Shaker sort with size " << n <<endl; 
        comp = shakerSortComp(arrComp, n);
        time = shakerSortTime(arrTime, n);
        break;
    case 4:
        cout << "Shell sort with size " << n <<endl;
        comp = shellSortComp(arrComp, n);
        time = shellSortTime(arrTime, n);
        break;
    case 5:
        cout << "Heap sort with size " << n <<endl;
        comp = heapSortComp(arrComp, n);
        time = heapSortTime(arrTime, n);
        break;
    case 6:
        cout << "Merge sort with size " << n <<endl;
        comp = mergeSortComp(arrComp, n);
        time = mergeSortTime(arrTime, n);
        break;
    case 7:
        cout << "Quick sort with size " << n <<endl;
        comp = quickSortComp(arrComp, n);
        time = quickSortTime(arrTime, n);
        break;
    case 8:
        cout << "Counting sort with size " << n <<endl;
        comp = countingSortComp(arrComp, n);
        time = countingSortTime(arrTime, n);
        break;
    case 9:
        cout << "Radix sort with size " << n <<endl;
        comp = radixSortComp(arrComp, n);
        time = radixSortTime(arrTime, n);
        break;
    case 10:
        cout << "Flash sort with size " << n <<endl;
        comp = flashSortComp(arrComp, n);
        time = flashSortTime(arrTime, n);
        break;
    default:
        break;
    }

    cout << "  + Comp: " << comp << endl;
    cout << "  + Time: " << time << endl;

    delete[] arrComp;
    delete[] arrTime;
}

int main(int argc, char const *argv[])
{
    // Data Order S1
    //vector<int> dataOrders = {0, 1, 2, 3};
    vector<int> dataOrders = {1};
    vector<int> dataSizes = {10000, 30000, 50000, 100000, 300000, 500000};
    //vector<int> algorithms = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> algorithms = {3};
    vector<string> fileNames = {"RandomData.csv", "SortedData.csv", "ReverseData.csv", "NearlySortedData.csv"};

    for(int order: dataOrders){
        cout << fileNames[order] << endl;
        fstream fin(fileNames[order], ios::out);
        vector<vector<double>> table(11);
        for(int size: dataSizes){
            int* arr = new int[size];
            GenerateData(arr, size, order);
            for(int algorithm: algorithms){
                unsigned long long comp;
                double time;
                takeCountingAndTime(arr, size, algorithm, comp, time);
                table[algorithm].push_back(time);
                table[algorithm].push_back((double)comp);
            }
            delete[] arr;
        }
        for(vector<double> row: table){
            for(double val: row){
                fin << val << ",";
            }
            fin << endl;
        }
        fin.close();
    }
    return 0;
}
