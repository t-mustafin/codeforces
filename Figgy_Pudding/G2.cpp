#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <vector>

using namespace std;

#define T unsigned int
#define llT unsigned long long int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0
#define SIMPLE 0

void test()
{
    T min, max, x, lo, hi;

    min = 1;
    max = 1000;

    // Answering 2 numbers at once allows to use trisection method instead of bisection method.
    // It reduces complexity from O(log(2, 1000)) = 10 questions to O(log(3, 1000)) = 7 questions

    while (true)
    {
        T range = max - min;
        lo = min + range / 3;
        hi = min + 2 * range / 3;

        if (lo == hi) {
            break;
        }

        cout << "? " << lo << " " << hi << endl;
        cout.flush();

        T S;
        cin >> S;

        if (S == lo * hi) {
            min = hi;
        } else if (S == lo * (hi + 1)) {
            min = lo;
            max = hi;
        } else if (S == (lo + 1) * (hi + 1)) {
            max = lo;
        } else {
            cout << "! 1" << endl;
            exit(0);
        }
        continue;
    }

    cout << "! " << max << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 0; i < t; i++) {
        test();
    }

    return 0;
}
