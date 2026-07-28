#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string S;
    char C;
    
    if (cin >> S >> C) {
        int count = 0;
        for (char ch : S) {
            if (ch == C) {
                count++;
            }
        }
        cout << count << endl;
    }
    
    return 0;
}