import math

#define T unsigned long long
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0

def test():
    n, c = input().split()

    n = int(n)
    c = int(c)

    S1 = S2 = 0

    string = input()
    for si in string.split():
        si = int(si)

        S1 += si
        S2 += si * si

    D = (S1 * S1 + n * (c - S2));
    Dsq = 4 * math.sqrt(D);

    w = (Dsq - 4 * S1) / (8 * n);

    print(int(w));

    return;

t = int(input())

for i in range(t):
    test();
