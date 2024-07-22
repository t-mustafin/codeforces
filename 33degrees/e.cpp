#include <cmath>
#include <iostream>
#include <vector>
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

#define A(x, y) a[y - 1][x - 1]
#define B(x, y) b[y - 1][x - 1]

vector<vector<T>> a;
vector<vector<T>> b;

T ib[SIZE]; // i index of number in b
T jb[SIZE]; // j index of number in b

T n, m;

void mvi(T i1, T i2)
{
    for (int j = 1; j <= n; j++)
    {
        T buf = A(i1, j);
        A(i1, j) = A(i2, j);
        A(i2, j) = buf;
    }
}

void mvj(T j1, T j2)
{
    for (int i = 1; i <= m; i++)
    {
        T buf = A(i, j1);
        A(i, j1) = A(i, j2);
        A(i, j2) = buf;
    }
}

void test()
{
    cin >> n;
    cin >> m;

    a.resize(n);
    b.resize(n);

    for (int j = 1; j <= n; j++)
    {
        a[j - 1].resize(m);

        for (int i = 1; i <= m; i++)
        {
            cin >> A(i, j);
        }
    }

    for (int j = 1; j <= n; j++)
    {
        b[j - 1].resize(m);
        for (int i = 1; i <= m; i++)
        {
            cin >> B(i, j);

            ib[B(i, j)] = i;
            jb[B(i, j)] = j;
        }
    }

    vector<bool> imoved(m + 1, false);
    vector<bool> jmoved(n + 1, false);

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            while (A(i, j) != B(i, j))
            {
                if (i != ib[A(i, j)])
                {
                    if (imoved[ib[A(i, j)]] || imoved[i])
                    {
                        cout << "no" << endl; return;
                    }
                    else
                    {
                        imoved[ib[A(i, j)]] = true;
                    }
                    mvi(i, ib[A(i, j)]);

                    continue;
                }

                if (j != jb[A(i, j)])
                {
                    if (jmoved[jb[A(i, j)]] || jmoved[j])
                    {
                        cout << "no" << endl; return;
                    }
                    else
                    {
                        jmoved[jb[A(i, j)]] = true;
                    }
                    mvj(j, jb[A(i, j)]);
                }
            }
            imoved[i] = true;
        }
        jmoved[j] = true;
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
