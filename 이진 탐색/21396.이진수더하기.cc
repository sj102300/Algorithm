//[실버2] 21396.이진수더하기 https://www.acmicpc.net/problem/21396

#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100001];

int getLowerboundIdx(int n, int target)
{
    int left = 0;
    int right = n-1;
    int mid;
    while (left < right)
    {
        mid = (left+right)/2;
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return target == arr[left] ? left : -1;
}

int getUpperboundIdx(int n, int target)
{

    int left = 0;
    int right = n;
    int mid;
    while (left < right)
    {
        mid = (left+right)/2;
        if (arr[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

int main(void)
{
    long long t, n, x;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (int _ = 0; _ < t; ++_)
    {
        cin >> n >> x;
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        long long answer = 0;
        for (int i = 0; i < n; ++i)
        {
            long long target = x ^ arr[i];
            int lowerbound = getLowerboundIdx(n, target);
            if (lowerbound == -1)
                continue;
            int upperbound = getUpperboundIdx(n, target);
            int cnt = upperbound - lowerbound;
            if(target == arr[i])
                cnt--;
            answer += cnt;
        }
        cout << answer/2 << "\n";
    }
}
