#include<iostream>
using namespace std;

int main()
{
    int A[] = {1, 5, 8, 12, 14, 15, 3};
    int n = 7;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i] > A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }

    int i = 0, ans = 1;

    for(int j=0; j<n; j++)
    {
        while(A[j] - A[i] > 10)
            i++;

        if(j-i+1 > ans)
            ans = j-i+1;
    }

    cout<<"Maximum length of good subsequence = "<<ans;
    return 0;
}
