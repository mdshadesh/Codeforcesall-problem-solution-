#include <cstdio>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    int prime[1000] = {3, 5}, count(2);
    for (int number = 7; number <= n && k != 0; number += 2)
    {
        int i = 0;
        while (i < count && number % prime[i] != 0)
        {
            ++i;
        }
        if (i == count)
        {
            for (int j = 1; j < count; ++j)
            {
                if (prime[j] + prime[j-1] + 1 == number)
                {
                    k -= 1;
                    break;
                }
            }
            prime[count++] = number;
        }
    }
    printf(k == 0 ? "YES\n" : "NO\n");
    return 0;
}