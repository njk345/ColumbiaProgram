#include <stdio.h>

long long fib_helper(long long n, long long *values, int nvalues)
{
    if (values[n] != -1) {
        return values[n];
    }
    else {
        long long y1 = fib_helper(n-1, values, nvalues);
        long long y2 = fib_helper(n-2, values, nvalues);
        values[n] = y1 + y2;
        return values[n];
    }
}

long long fib_new(long long n)
{
    long long values[100];
    values[0] = 0;
    values[1] = 1;
    for (int i = 2; i < 100; i++)
        values[i] = -1;
    return fib_helper(n, values, 100);
}

int main(void)
{
    for (long long i = 0; i < 50; i++) {
        printf("%lld => %lld\n", i, fib_new(i));
    }
    return 0;
}

