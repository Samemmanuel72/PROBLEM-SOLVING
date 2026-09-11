#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    string s;

    cin >> n >> s;

    if (s[0] == '0' || s.contains("00")) {
        cout << "-1" << endl;
        return;
    }

    int a = -1;

    if (s.contains("+-") || s.contains("-+")) {
        if (s.contains("+--+") || s.contains("-++-")) {
            a = 3;
        } else {
            a = 2;
        }
    } else {
        a = 1;

        for (int i = 0; i < n; i += 2) {
            if (s[i] == '0') {
                a = 2;
                break;
            }
        }
    }

    cout << a << endl;
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
