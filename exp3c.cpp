#include <iostream>
#include <ctime>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
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

    cout << "SELECTION SORT (n=" << n << ")\n";

    start = clock();
    selectionSort(best, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Best case: " << timeTaken << " ms\n";

    start = clock();
    selectionSort(avg, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Average case: " << timeTaken << " ms\n";

    start = clock();
    selectionSort(worst, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Worst case: " << timeTaken << " ms\n";
    return 0;
}