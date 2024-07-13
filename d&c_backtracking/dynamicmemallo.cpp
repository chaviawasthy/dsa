#include<bits/stdc++.h>

using namespace std;

void print(iny **v, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<v[i][j]<<" ";
        }
        cout << endl;
    }
}

int main(){
    //1. allocate int
    int *intPtr = new int(5);

    //using malloc
    int *mptr = (int *)malloc(4);
    *mptr = 5;

    cout << *intPtr << " " << *mptr << endl;
    delete intPtr;
    free(mptr);
    //1D allocation
    int *arr = new int[5];

    //using malloc
    int *arrmalloc = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        int d;
        cin>>d;
        arrnew[i] = arrmalloc[i] = d;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " " << arrmalloc[i] << endl;
    }
    delete[] arrnew;
    free(arrmalloc);

    //2D allocation
    int rows = 3, cols = 3;

    int **arr2d = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr2d[i] = new int[cols];
    }

    int **ptr2malloc = (int **)malloc(rows * sizeof(int *) * rows);
    for (int i = 0; i < rows; i++)
    {
        ptr2malloc[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr2d[i][j] = 7;
            ptr2malloc[i][j] = 8;
        }
        
    }
    
    print(ptr2d, rows, cols);
    print(ptr2malloc, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        delete[] arr2d[i];
    }
    delete[] arr2d;

    for (int i = 0; i < rows; i++)
    {
        free(ptr2malloc[i]);
    }
    free(ptr2malloc);
    
    
    
    // for (int i = 0; i < 3; i++)
    // {
    //     arr2d[i] = new int[3];
    // }

    // //using malloc
    // int **arr2dmalloc = (int **)malloc(3 * sizeof(int *));

    // for (int i = 0; i < 3; i++)
    // {
    //     arr2dmalloc[i] = (int *)malloc(3 * sizeof(int));
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         int d;
    //         cin>>d;
    //         arr2d[i][j] = arr2dmalloc[i][j] = d;
    //     }
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << arr2d[i][j] << " " << arr2dmalloc[i][j] << endl;
    //     }
    // }
    return 0;
}