#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter dimensions of matrices:\n";
    cout << "For example, for A1 = 10x20, A2 = 20x30, "
         << "enter: 10 20 30\n";

    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }


    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int length = 2; length <= n; length++) {

        for (int i = 1; i <= n - length + 1; i++) {

            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << "\nMinimum number of scalar multiplications = "
         << dp[1][n] << endl;

    return 0;
}
