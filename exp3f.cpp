#include <iostream>
#include <ctime>

using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
        
    if (r < n && arr[r] > arr[largest])
        largest = r;
        
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
        
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        heapify(arr, i, 0);
    }
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
    
    cout << "HEAP SORT (n=" << n << ")\n";
    
    start = clock();
    heapSort(sortedArr, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Best case: " << timeTaken << " ms\n";
    
    start = clock();
    heapSort(randomArr, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Average case: " << timeTaken << " ms\n";
    
    start = clock();
    heapSort(reverseArr, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Worst case: " << timeTaken << " ms\n";
    return 0;
}