#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];

    cout << "Enter dimensions of matrices:\n";
    cout << "For " << n << " matrices, enter " << n + 1 << " dimensions:\n";

    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int m[n + 1][n + 1];

    // Initialize
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // MCM logic
    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k]
                         + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    cout << "\nMinimum number of multiplications = "
         << m[1][n] << endl;

    return 0;
}
