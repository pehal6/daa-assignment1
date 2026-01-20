#include<iostream>
using namespace std;
bool check(int a[], int n, int m, int limit)
{
    int parts = 1;
    int curr_or = 0;

    for(int i=0;i<n;i++)
    {
        curr_or = curr_or | a[i];

        if(curr_or > limit)
        {
            parts++;
            curr_or = a[i];

            if(parts > m)
                return false;
        }
    }
    return true;
}

int main()
{
    int a[] = {1,2,3,4,5};
    int n = 5;
    int m = 3;
    int low = 0, high = 0;
    for(int i=0;i<n;i++)
        high = high | a[i];
        
    int ans = high;

    while(low <= high)
    {
        int mid = (low + high)/2;

        if(check(a,n,m,mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout<<"Minimum possible maximum OR = "<<ans;
    return 0;
}
