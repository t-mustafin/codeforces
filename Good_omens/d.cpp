#include <iostream>
#include <set>
#include <cmath>
#include <list>

using namespace std;

#define T unsigned int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0

void test()
{
    T n, k, ai;

    cin >> n;
    cin >> k;

    multiset<T> a;

    for (int i = 1; i <= n; i++) {
        cin >> ai;

        a.emplace(ai);
    }

    T max = 0;
    T curr = 0;

    auto prev = a.begin();

    for (auto it = a.begin(); it != a.end(); it++)
    {
        if (*it - *prev > k)
        {
            curr = 0;
        }

        curr++;
        if (max < curr)
            max = curr;

        prev = it;
    }

    cout << n - max << endl;

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
