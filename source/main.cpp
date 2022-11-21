#include "library.h"

// int main(int argc, char **argv) {
//     // validate the params
//     if (argc == 5) {
//         if (strcmp(argv[1], "-a") == 0) {
//             if (strstr(argv[3], ".txt") != NULL) {
//                 doCommand1(argv[2], argv[3], argv[4]);
//             } else {
//                 doCommand3(argv[2], argv[3], argv[4]);
//             }
//         } else {
//             doCommand4(argv[2], argv[3], argv[4]);
//         }

//     } else if (argc == 6) {
//         if (strcmp(argv[1], "-a") == 0) {
//             doCommand2(argv[2], argv[3], argv[4], argv[5]);
//         } else {
//             doCommand5(argv[2], argv[3], argv[4], argv[5]);
//         }

//     } else {
//         cout << "Invalid params" << endl;
//         return 0;
//     }
//     return 225;
// }

int main()
{
    // validate the params
    int a[500000];
    int n;

    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
            cout << "Random data: " << endl;
        if (i == 1)
            cout << "Sorted data " << endl;
        if (i == 2)
            cout << "Reversed data " << endl;
        if (i == 3)
            cout << "Nearly sorted data: " << endl;

        for (int j = 0; j < 6; j++)
        {
            if (j == 0)
            {
                n = 10000;
            }
            if (j == 1)
            {
                n = 30000;
            }
            if (j == 2)
            {
                n = 50000;
            }
            if (j == 3)
            {
                n = 100000;
            }
            if (j == 4)
            {
                n = 300000;
            }
            if (j == 5)
            {
                n = 500000;
            }

            GenerateData(a, n, i);
           
            int *b = new int[n];
            
          
            for (int k = 0; k < n; k++)
            {
              
                b[k] = a[k];
            }
            cout << "n = " << n << endl;
            cout << selectionSortTime(a, n) << "ms " << selectionSortComp(b, n) << " \n";
            delete b;
        }
    
        cout << endl;
    }

    return 0;
}



