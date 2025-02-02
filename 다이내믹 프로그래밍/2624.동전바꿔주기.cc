//[골드4] 2624.동전바꿔주기 https://www.acmicpc.net/problem/2624

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

unsigned int dp[10001];
int T, K;

int main(void)
{

    cin >> T >> K;
    int pi, ni;
    dp[0] = 1;
    for (int i = 0; i < K; ++i)
    {
        cin >> pi >> ni;
        for (int t = T - pi; t >= 0; t--)
        {
            if (dp[t] == 0)
                continue;

            for (int n = ni; n >= 1; n--)
            {
                if (t + n * pi <= T)
                    dp[t + n * pi] += dp[t];
            }
        }
    }
    cout << dp[T];
}