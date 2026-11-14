#include <iostream>
#include <ctime>

using namespace std;

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            arr[j] = temp;
        }
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
    
    cout << "SHELL SORT (n=" << n << ")\n";
    
    start = clock();
    shellSort(sortedArr, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Best case: " << timeTaken << " ms\n";
    
    start = clock();
    shellSort(randomArr, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Average case: " << timeTaken << " ms\n";
    
    start = clock();
    shellSort(reverseArr, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Worst case: " << timeTaken << " ms\n";
    
    delete[] sortedArr;
    delete[] randomArr;
    delete[] reverseArr;
    
    return 0;
}