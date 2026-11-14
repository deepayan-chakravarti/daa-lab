#include <iostream>
#include <ctime>

using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    delete[] output;
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int n = 50000;
    int* sortedArr = new int[n];
    int* randomArr = new int[n];
    int* reverseArr = new int[n];
    
    for (int i = 0; i < n; i++) {
        sortedArr[i] = i;
        randomArr[i] = (i * 997) % 1000000;
        reverseArr[i] = n - i;
    }
    
    clock_t start, end;
    double timeTaken;
    
    cout << "RADIX SORT (n=" << n << ")\n";
    
    start = clock();
    radixSort(sortedArr, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Best case: " << timeTaken << " ms\n";
    
    start = clock();
    radixSort(randomArr, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Average case: " << timeTaken << " ms\n";
    
    start = clock();
    radixSort(reverseArr, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Worst case: " << timeTaken << " ms\n";
    
    delete[] sortedArr;
    delete[] randomArr;
    delete[] reverseArr;
    
    return 0;
}