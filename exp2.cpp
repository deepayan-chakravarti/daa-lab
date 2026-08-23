#include <iostream>
#include <vector>
#include <climits>
#include <ctime>

int matrixChainOrder(const std::vector<int>& p, int n) {
    std::vector<std::vector<int>> m(n + 1, std::vector<int>(n + 1, 0));

    for (int L = 2; L <= n; ++L) {
        for (int i = 1; i <= n - L + 1; ++i) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n];
}

int main() {
    std::cout << "Deepayan Chakravarti\n";
    std::cout << "04714802724\n";
    int sizes[] = {10, 100, 1000};

    for (int n : sizes) {
        std::vector<int> p(n + 1);
        for (int i = 0; i <= n; ++i) {
            p[i] = (i % 10) + 10;
        }

        clock_t start = clock();
        int minOps = matrixChainOrder(p, n);
        clock_t end = clock();

        double executionTime = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "N = " << n << "\n";
        std::cout << "Min Multiplications: " << minOps << "\n";
        std::cout << "Execution Time: " << executionTime << " s\n\n";
    }

    return 0;
}