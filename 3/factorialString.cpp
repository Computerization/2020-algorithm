#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n >= 23) {
            cout << "NO" << endl;
        } else {
            short NEXT[26][450];
            for (int i = s.length() - 1; i >= 0; i--) {
                if (i == s.length() - 1) {
                    for (int j = 0; j < 26; j++)
                        NEXT[j][i] = -1;
                } else {
                    for (int j = 0; j < 26; j++)
                        NEXT[j][i] = NEXT[j][i + 1];
                }
                NEXT[s[i] - 'a'][i] = i;
            }
            short *f = new short[1 << n];
            for (int i = 0; i < (1 << n); i++) {
                f[i] = 0;
                for (int j = 0; (1 << j) <= i; j++) {
                    if (i & (1 << j)) {
                        if (NEXT[j][f[i - (1 << j)]] == -1) {
                            cout << "NO" << endl;
                            return 0;
                        }
                        f[i] = max(f[i], NEXT[j][f[i - (1 << j)]]);
                    }
                }
            }
            cout << "YES" << endl;
        }
    }
}
