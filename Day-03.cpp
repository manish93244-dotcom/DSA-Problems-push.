#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // Fast I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    char C;
    
    if (cin >> S >> C) {
        int count = 0;
        for (char ch : S) {
            if (ch == C) {
                count++;
            }
        }
        cout << count << "\n";
    }
    
    return 0;
}