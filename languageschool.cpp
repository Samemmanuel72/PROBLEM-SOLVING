#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve() {
    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    int F = N / K;

    vector<bool> own(F, false);

    for (int i = 0; i < N; i++) {
        if (s[i] == '0') {
            int farmidx = i / K;
            own[farmidx] = true;
        }
    }

    int count = 0;

    for (int f = 0; f < F; f++) {
        if (!own[f]) {
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
