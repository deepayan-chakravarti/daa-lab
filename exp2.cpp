#include <iostream>
#include <ctime>

using namespace std;

const int INF = 999999999; 

int matrixChainMultiplication(int p[], int size) {
    int n = size - 1;
    if (n <= 0) return 0;
    
    int dp[100][100] = {0}; 
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INF;
            
            for (int k = i; k < j; k++) {
                long long cost = (long long)dp[i][k] + dp[k + 1][j] + 
                                 (long long)p[i] * p[k + 1] * p[j + 1];
                                 
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int repetitions = 100;
    cout << "Repetitions: " << repetitions << "\n";
    
    int sizes[] = {24, 48, 96};
    double recordedTimes[3];
    
    for (int s = 0; s < 3; s++) {
        int n = sizes[s];
        int dimensions[100]; 
        
        for (int j = 0; j <= n; j++) {
            dimensions[j] = 5 + j;
        }
        
        if (s == 0) cout << "\nSmall N (24):\n";
        else if (s == 1) cout << "\nAverage N (48):\n";
        else cout << "\nLarge N (96):\n";
        
        int minMultiplications = 0;
        
        clock_t start = clock();
        for (int r = 0; r < repetitions; r++) {
            minMultiplications = matrixChainMultiplication(dimensions, n + 1);
        }
        clock_t end = clock();
        
        double avgTimeMs = (double)(end - start) / CLOCKS_PER_SEC * 1000.0 / repetitions;
        recordedTimes[s] = avgTimeMs;
        
        cout << "Average Time Taken: " << avgTimeMs << " ms\n";
        cout << "Minimum Multiplications: " << minMultiplications << "\n";
    }
    
    cout << "\nExperimental Ratios:\n";
    for (int i = 1; i < 3; i++) {
        double ratio = recordedTimes[i] / recordedTimes[i - 1];
        cout << sizes[i - 1] << " -> " << sizes[i] << " : " << ratio << "x\n";
    }
    
    cout << "\nTheoretical Ratios (Cubic Growth):\n";
    for (int i = 1; i < 3; i++) {
        double ratio = (double)sizes[i] / sizes[i - 1];
        double theoretical = ratio * ratio * ratio;
        cout << sizes[i - 1] << " -> " << sizes[i] << " : " << theoretical << "x\n";
    }
    return 0;
}