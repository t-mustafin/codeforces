#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <vector>

using namespace std;

#define T long long
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0
#define SIMPLE 0

void test()
{
    char n1, n2;
    cin >> n1;
    cin >> n2;

    cout << n1 - '0' + n2 - '0' << endl;

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
