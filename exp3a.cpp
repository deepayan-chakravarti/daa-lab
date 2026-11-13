#include <iostream>
#include <ctime>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
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

    cout << "BUBBLE SORT (n=" << n << ")\n";

    start = clock();
    bubbleSort(best, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Best case: " << timeTaken << " ms\n";

    start = clock();
    bubbleSort(avg, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Average case: " << timeTaken << " ms\n";

    start = clock();
    bubbleSort(worst, n);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "Worst case: " << timeTaken << " ms\n";

    return 0;
}