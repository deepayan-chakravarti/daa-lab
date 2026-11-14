#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int max_val(int a, int b) {
    if (a > b) return a;
    return b;
}

int LCS(const char a[], int m, const char b[], int n) {
    int** dp = new int*[m + 1];
    for (int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } 
            else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else {
                dp[i][j] = max_val(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int result = dp[m][n];

    for (int i = 0; i <= m; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

unsigned long int next_rand = 1;
int my_rand() {
    next_rand = next_rand * 1103515245 + 12345;
    return (unsigned int)(next_rand / 65536) % 32768;
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int sizes[] = {50, 500, 5000};   
    for (int s = 0; s < 3; s++) {
        int n = sizes[s];
        
        char* s1 = new char[n + 1];
        char* s2 = new char[n + 1];
        
        for (int i = 0; i < n; i++) {
            s1[i] = 'A' + (my_rand() % 26);
            s2[i] = 'A' + (my_rand() % 26);
        }
        s1[n] = '\0';
        s2[n] = '\0';

        cout << "\nString Length = " << n << "\n";

        auto start = high_resolution_clock::now();
        int result = LCS(s1, n, s2, n);
        auto stop = high_resolution_clock::now();

        double ms = duration<double, milli>(stop - start).count();

        cout << "LCS Length: " << result << "\n";
        cout << "Execution time: " << ms << " ms\n";

        delete[] s1;
        delete[] s2;
    }

    return 0;
}