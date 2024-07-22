#include <cmath>
#include <iostream>
//#include <list>
//#include <map>
#include <numeric>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;

#define T int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0

template<typename Type>
Type div_up(Type x, Type y)
{
    return x / y + (x % y ? 1 : 0);
}

T a[SIZE];
T b[SIZE];

T n;

bool check(int i)
{
    if (i == 1 || i == n)
    {
        return true;
    }

    T b_new = gcd(a[i - 1], a[i + 1]);

    if (i == 2)
    {
        if (b_new <= b[3])
            return true;
        else
            return false;
    }

    if (i == n - 1)
    {
        if (b[n - 3] <= b_new)
            return true;
        else
            return false;
    }

    if (b[i - 2] <= b_new && b_new <= b[i + 1])
        return true;

    return false;
}

void test()
{
    bool deleted = false;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    if (n == 3)
    {
        cout << "yes" << endl; return;
    }

    b[1] = std::gcd(a[1], a[2]);

    for (int i = 1; i <= n - 2; i++)
    {
        b[i + 1] = gcd(a[i + 1], a[i + 2]);
        if (b[i] <= b[i + 1])
        {
            continue;
        }
        else if (deleted)
        {
            cout << "no" << endl; return;
        }
        else if (i == n - 2)
        {
            cout << "yes" << endl; return;
        }
        else if (i == n - 3)
        {
            b[i + 2] = gcd(a[i + 2], a[i + 3]);

            if (b[i + 1] > b[i + 2] && (check(i + 1) || check(i + 2)))
            {
                cout << "yes" << endl; return;
            }
            else if (b[i + 1] <= b[i + 2] && (check(i) || check(i + 1) || check(i + 2)))
            {
                cout << "yes" << endl; return;
            }

            cout << "no" << endl; return;
        }
        else // i <= n - 4
        {
            b[i + 2] = gcd(a[i + 2], a[i + 3]);
            b[i + 3] = gcd(a[i + 3], a[i + 4]);

            if (b[i + 1] > b[i + 2])
            {
                if (b[i + 2] > b[i + 3] && check(i + 2))
                {
                    deleted = true;
                    i += 2;
                    continue;
                }

                if (b[i + 2] <= b[i + 3] && (check(i + 1) || check(i + 2)))
                {
                    deleted = true;
                    i += 2;
                    continue;
                }

                cout << "no" << endl; return;
            }
            else // b[i + 1] <= b[i + 2]
            {
                if (b[i + 2] > b[i + 3] && check(i + 2))
                {
                    deleted = true;
                    i += 2;
                    continue;
                }

                if (b[i + 2] <= b[i + 3] && (check(i) || check(i + 1) || check(i + 2)))
                {
                    deleted = true;
                    i += 2;
                    continue;
                }

                cout << "no" << endl; return;
            }
        }
    }

    cout << "yes" << endl;
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
