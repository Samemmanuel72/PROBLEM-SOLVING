#include <iostream>
#include <vector>

using namespace std;

// Maximum possible temperature given in the problem constraints
const int MAX_TEMP = 200005;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> diff(MAX_TEMP, 0);

    // Step 1: Process recipes using the Difference Array technique
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        diff[l] += 1;
        diff[r + 1] -= 1;
    }

    // Step 2: Compute prefix sums to get actual recipe counts per temperature,
    // and convert it into a binary map (1 for admissible, 0 otherwise).
    vector<int> admissible(MAX_TEMP, 0);
    int current_recipes = 0;
    for (int i = 1; i < MAX_TEMP; ++i) {
        current_recipes += diff[i];
        if (current_recipes >= k) {
            admissible[i] = 1;
        } else {
            admissible[i] = 0;
        }
    }

    // Step 3: Compute prefix sum over the admissible array to answer range queries
    vector<int> pref_sum(MAX_TEMP, 0);
    for (int i = 1; i < MAX_TEMP; ++i) {
        pref_sum[i] = pref_sum[i - 1] + admissible[i];
    }

    // Step 4: Answer each query in O(1) time
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << pref_sum[b] - pref_sum[a - 1] << "\n";
    }

    return 0;
}
