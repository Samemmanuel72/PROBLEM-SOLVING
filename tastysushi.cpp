#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    // Sort both arrays in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int shari_ptr = 0;
    int neta_ptr = 0;
    int sushi_count = 0;

    // Two-pointer approach
    while (shari_ptr < n && neta_ptr < m) {
        // Condition: weight of neta must be at most twice the weight of shari
        if (b[neta_ptr] <= 2 * a[shari_ptr]) {
            sushi_count++;
            shari_ptr++;
            neta_ptr++;
        } else {
            // If the current neta is too heavy for this shari, 
            // try a larger shari piece.
            shari_ptr++;
        }
    }

    cout << sushi_count << "\n";

    return 0;
}
