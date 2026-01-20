#include <iostream>
using namespace std;

int main()
{
    int A[] = {1,2,3,4,5};
    int n = 5;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i] > A[j])
            {
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }
    }

    // sum of last two elements
    int ans = A[n-1] + A[n-2];
    cout<<"Sum of remaining elements = "<<ans;
    return 0;
}
