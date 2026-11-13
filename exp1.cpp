#include <iostream>
#include <ctime>

using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int n = 5000;
    int repetitions = 100000;
    int arr[5000];
    
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2; 
    }

    cout << "Array Size: " << n << "\n";
    cout << "Number of repetitions: " << repetitions << "\n\n";

    int index = -1;
    clock_t start, end;
    double avgTime;

    cout << "Linear Search Results\n";
    
    int bestCaseTarget = arr[0]; 
    start = clock();
    for(int i = 0; i < repetitions; i++) index = linearSearch(arr, n, bestCaseTarget);
    end = clock();
    avgTime = (double)(end - start) / CLOCKS_PER_SEC * 1000.0 / repetitions;
    
    cout << "Best Case (First Element)\n";
    cout << "Searching element: " << bestCaseTarget << "\n";
    cout << "Average Time Taken: " << avgTime << " ms\n";
    cout << "Found at index: " << index << "\n\n";

    int avgCaseTarget = arr[n / 2]; 
    start = clock();
    for(int i = 0; i < repetitions; i++) index = linearSearch(arr, n, avgCaseTarget);
    end = clock();
    avgTime = (double)(end - start) / CLOCKS_PER_SEC * 1000.0 / repetitions;
    
    cout << "Average Case (Middle Element)\n";
    cout << "Searching element: " << avgCaseTarget << "\n";
    cout << "Average Time Taken: " << avgTime << " ms\n";
    cout << "Found at index: " << index << "\n\n";

    int worstCaseTarget = arr[n - 1] + 10; 
    start = clock();
    for(int i = 0; i < repetitions; i++) index = linearSearch(arr, n, worstCaseTarget);
    end = clock();
    avgTime = (double)(end - start) / CLOCKS_PER_SEC * 1000.0 / repetitions;
    
    cout << "Worst Case (Not Found)\n";
    cout << "Searching element: " << worstCaseTarget << "\n";
    cout << "Average Time Taken: " << avgTime << " ms\n";
    cout << "Found at index: " << index << "\n\n";

    cout << "Binary Search Results\n";
    
    int bestBinaryTarget = arr[n / 2]; 
    start = clock();
    for(int i = 0; i < repetitions; i++) index = binarySearch(arr, n, bestBinaryTarget);
    end = clock();
    avgTime = (double)(end - start) / CLOCKS_PER_SEC * 1000.0 / repetitions;
    
    cout << "Best Case (Middle Element)\n";
    cout << "Searching element: " << bestBinaryTarget << "\n";
    cout << "Average Time Taken: " << avgTime << " ms\n";
    cout << "Found at index: " << index << "\n\n";

    int avgBinaryTarget = arr[n / 4]; 
    start = clock();
    for(int i = 0; i < repetitions; i++) index = binarySearch(arr, n, avgBinaryTarget);
    end = clock();
    avgTime = (double)(end - start) / CLOCKS_PER_SEC * 1000.0 / repetitions;
    
    cout << "Average Case (Element Near Beginning)\n";
    cout << "Searching element: " << avgBinaryTarget << "\n";
    cout << "Average Time Taken: " << avgTime << " ms\n";
    cout << "Found at index: " << index << "\n\n";

    int worstBinaryTarget = arr[n - 1] + 10;
    start = clock();
    for(int i = 0; i < repetitions; i++) index = binarySearch(arr, n, worstBinaryTarget);
    end = clock();
    avgTime = (double)(end - start) / CLOCKS_PER_SEC * 1000.0 / repetitions;
    
    cout << "Worst Case (Not Found)\n";
    cout << "Searching element: " << worstBinaryTarget << "\n";
    cout << "Average Time Taken: " << avgTime << " ms\n";
    cout << "Found at index: " << index << "\n";

    return 0;
}