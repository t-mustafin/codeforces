#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <list>

using namespace std;

#define T int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0

template<typename Type>
Type div_up(Type x, Type y)
{
    return x / y + (x % y ? 1 : 0);
}

//T a[SIZE];

void test()
{
    T n, m, ret;

    ret = 0;
    cin >> n;
    cin >> m;

    T num['G' - 'A' + 1] = { 0 };

    for (int i = 1; i <= n; i++)
    {
        char curr;
        cin >> curr;

        num[curr - 'A']++;
    }

    for (int i = 0; i <= 'G' - 'A'; i++)
    {
        if (num[i] < m)
            ret += m - num[i];
    }

    cout << ret << endl;

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
