#include <iostream>
#include <vector>
#include <cmath>
#include <list>

using namespace std;

#define T unsigned int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0

void test()
{
    T n, a, b, x, bx;

    cin >> n;

    bx = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        cin >> b;

        if (a <= 10 && b > bx)
        {
            bx = b;
            x = i;
        }
    }

    cout << x << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    //    std::cout << "Hello! N = " << N << " K = " << K << endl;

    for (int i = 0; i < t; i++) {
        test();
    }

    return 0;
}
