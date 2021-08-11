//1005 继续(3n+1)猜想

#ifndef PAT_1005_HPP
#define PAT_1005_HPP

#include <iostream>
#include <algorithm>
using namespace std;

#define N 310
bool isKey[N];
bool isValid[N];
void callatz(int n);

int main()
{
    fill(isKey, isKey + N, true);

    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &n);
        isValid[n] = true;
        callatz(n % 2 == 0 ? n / 2 : (3 * n + 1) / 2);
    }

    bool isFirstKey = true;
    for (int i = N - 1; i >= 0; --i)
    {
        if (isValid[i] && isKey[i])
        {
            if (isFirstKey)
            {
                printf("%d", i);
                isFirstKey = false;
            }
            else
            {
                printf(" %d", i);
            }
        }
    }

    system("pause");
    return 0;
}

void callatz(int n)
{
    while (n != 1)
    {
        if (isKey[n])
        {
            isKey[n] = false;

            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                n = (3 * n + 1) / 2;
            }
        }
        else
        {
            break;
        }
    }
}

#endif //PAT_1005_HPP
