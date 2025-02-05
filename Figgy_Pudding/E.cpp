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
    T l, r, ret;
    cin >> l;
    cin >> r;

    // (x,y) -> (3x, ⌊y/3⌋) operation will not increment x only if x is 0.
    // So Ivi should nullify l first, and after that choose 0 as x for every next operation.
    // [l, r] will be divided into parts with 3^k borders.
    // Each number in some part has same number of ⌊y/3⌋ operations to be nullified.
    // So answer will be SUM(op_i * LEN(part_i)) where op_i is number of operations to nullify first number of part_i.
    // O(ln(r)) complexity.

    T op = 1;

    int pow_prev = 1;
    int pow_next = 3 * pow_prev; // [pow_prev, pow_next) is part_i

    for (; pow_next <= l; op++)
        pow_next *= 3;

    ret = op;

    while (pow_next <= r)
    {
        ret += op * (pow_next - max<T>(pow_prev, l));

        op++;
        pow_prev = pow_next;
        pow_next *= 3;
    }

    ret += op * (r - max<T>(pow_prev, l) + 1);

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
