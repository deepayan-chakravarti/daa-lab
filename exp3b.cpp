#include <iostream>
#include <ctime>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int n = 5000;
    int best[5000], avg[5000], worst[5000];

    for (int i = 0; i < n; i++) {
        best[i] = i;
        avg[i] = (i * 997) % 1000000;
        worst[i] = n - i;
    }

    clock_t start, end;
    double timeTaken;

    cout << "INSERTION SORT (n=" << n << ")\n";

    start = clock();
    insertionSort(best, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Best case: " << timeTaken << " ms\n";

    start = clock();
    insertionSort(avg, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Average case: " << timeTaken << " ms\n";

    start = clock();
    insertionSort(worst, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Worst case: " << timeTaken << " ms\n";

    return 0;
}