#include <iostream>
#include <ctime>

using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int* L = new int[n1];
    int* R = new int[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
        
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int n = 5000;
    int sortedArr[5000], randomArr[5000], reverseArr[5000];
    
    for (int i = 0; i < n; i++) {
        sortedArr[i] = i;
        randomArr[i] = (i * 997) % 1000000;
        reverseArr[i] = n - i;
    }
    
    clock_t start, end;
    double timeTaken;
    
    cout << "MERGE SORT (n=" << n << ")\n";
    
    start = clock();
    mergeSort(sortedArr, 0, n - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Sorted input: " << timeTaken << " ms\n";
    
    start = clock();
    mergeSort(randomArr, 0, n - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Random input: " << timeTaken << " ms\n";
    
    start = clock();
    mergeSort(reverseArr, 0, n - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Reverse input: " << timeTaken << " ms\n";
    return 0;
}