#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <vector>

using namespace std;

#define T int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0
#define SIMPLE 0

void test()
{
    T a1, a2; // Sunit cards
    T b1, b2; // Slavik cards

    cin >> a1;
    cin >> a2;

    cin >> b1;
    cin >> b2;

    T ret = 0;

    if (a1 > b1) // Round 1
    {
        if (a2 > b2) // Round 2
            ret += 2; // Add 2 cause (a2,b2) pair might be compared in Round 1 while (a1,b1) in Round 2
        if (a2 == b2) // Round 2. Equal leads to Sunit overall win cause Sunit already won Round 1
            ret += 2;
    }

    if (a1 == b1) { // Round 1
        if (a2 > b2) // Round 2
            ret += 2;
            // Equal in Round 2 does not leads to win of Sunit => do not increment
    }


    if (a1 > b2) // Round 1
    {
        if (a2 > b1) // Round 2
            ret += 2;
        if (a2 == b1) // Round 2
            ret += 2;
    }

    if (a1 == b2) // Round 1
        if (a2 > b1) // Round 2
            ret += 2;

    cout << ret << endl;

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
