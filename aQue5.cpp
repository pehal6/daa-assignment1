#include <iostream>
using namespace std;

bool canFit(long long n, long long h, long long w, long long s)
{
    long long rows = s / h;
    long long cols = s / w;

    if(rows * cols >= n)
        return true;
    else
        return false;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        long long n, h, w;
        cin >> n >> h >> w;

        long long low = 0;
        long long high = 1000000000;
        long long ans = 0;

        while(low <= high)
        {
            long long mid = (low + high) / 2;

            if(canFit(n, h, w, mid))
            {
                ans = mid;
                high = mid - 1;  
            }
            else
            {
                low = mid + 1;    
            }
        }

        cout << ans << endl;
    }

    return 0;
}
