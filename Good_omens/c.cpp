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
    T n;

    char c;
    string word("");

    //cin >> n;
    n = 8;

    for (int i = 1; i <= n * n; i++) {
        cin >> c;

        if (c != '.')
        {
            word.push_back(c);
        }
    }

    cout << word << endl;

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
