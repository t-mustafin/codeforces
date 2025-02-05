#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <vector>

using namespace std;

#define T unsigned long long int
#define llT unsigned long long int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0
#define SIMPLE 0

#define MOD (7 + 1000 * 1000 * 1000)

T mod(llT x)
{
    return (T) (x % MOD);
}

T binpow(T x, T n)
{
    T res = 1;

    while (n != 0) {
        if (n & 1)
            res = mod(res * x);
        x = mod(x * x);

        n >>= 1;
    }

    return res;
}

T inv(T x) // https://ru.algorithmica.org/cs/modular/reciprocal/#%d1%87%d0%b5%d1%80%d0%b5%d0%b7-%d0%b1%d0%b8%d0%bd%d0%b0%d1%80%d0%bd%d0%be%d0%b5-%d0%b2%d0%be%d0%b7%d0%b2%d0%b5%d0%b4%d0%b5%d0%bd%d0%b8%d0%b5-%d0%b2-%d1%81%d1%82%d0%b5%d0%bf%d0%b5%d0%bd%d1%8c
{
    return binpow(x, MOD - 2);
}

void test()
{
    T n, k, ret;
    cin >> n;
    cin >> k;

    T n0, n1; // n0 - number of '0'; n1 - number of '1'
    n0 = n1 = ret = 0;

    // Need to find number of possible subsequences where k1 > k0, where:
    // k0 - number of '0' in picked subsequence
    // k1 - number of '1' in picked subsequence. Maximum k1 number is min(k, n1)
    // Number of possible subsequences where k1 > k0:
    // Sum(C(n1, k1) * C(n0, k - k1)) for each k1 from (k + 1)/2 to min(k, n1).

    // mod(a * b) = mod(mod(a) * mod(b))
    // mod(a + b) = mod(mod(a) + mod(b))

    for (T i = 0; i < n; i++) {
        T a;
        cin >> a;

        n1 += a;
    }
    n0 = n - n1;

    // Fill INV(i) for i = 1 .. min(n1, k)
    vector<T> INV;      // Inversion of number by module MOD
    INV.push_back(1);
    for (T i = 1; i <= min<T>(n1, k); i++)
        INV.push_back(inv(i));

    // C(n, k) = C(n, k - 1) * (n - k + 1) / k
    // Fill C(n1, i) for i = 0 .. min(n1, k)
    vector<T> C1;
    C1.push_back(1);
    for (T i = 1; i <= min<T>(n1, k); i++)
        C1.push_back(mod(C1[i - 1] * mod(mod(n1 + 1 - i) * INV[i])));

    // Fill C(n0, i) for i = 0 .. min(n1, k)
    vector<T> C0;
    C0.push_back(1);
    for (T i = 1; i <= min<T>(n1, k); i++)
        C0.push_back(mod(C0[i - 1] * mod(mod(n0 + 1 - i) * INV[i])));

    for (T i = (k + 1) / 2; i <= min<T>(n1, k); i++)
        ret = mod(ret + mod(C1[i] * C0[k - i]));

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
