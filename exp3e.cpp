#include <iostream>
#include <ctime>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int nWorst = 3000;
    int nOther = 20000;
    
    int* sortedArr = new int[nWorst];
    int* reverseArr = new int[nWorst];
    int* randomArr = new int[nOther];
    
    for (int i = 0; i < nWorst; i++) {
        sortedArr[i] = i;
        reverseArr[i] = nWorst - i;
    }
    
    for (int i = 0; i < nOther; i++) {
        randomArr[i] = (i * 997) % 1000000;
    }
    
    clock_t start, end;
    double timeTaken;
    
    cout << "QUICK SORT\n";
    
    start = clock();
    quickSort(randomArr, 0, nOther - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Average case (n=" << nOther << "): " << timeTaken << " ms\n";
    
    start = clock();
    quickSort(sortedArr, 0, nWorst - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Worst case (n=" << nWorst << "): " << timeTaken << " ms\n";
    
    start = clock();
    quickSort(reverseArr, 0, nWorst - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Worst case (n=" << nWorst << "): " << timeTaken << " ms\n";
    
    return 0;
}