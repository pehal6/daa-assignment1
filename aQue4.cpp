#include <iostream>
using namespace std;

int main()
{
    int A[] = {3,1,4,2};
    int n = 4;
    int k = 1;

    int sum = 0;

    for(int i=0;i<n;i++)   
    {
        int isSpecial = 0;

        for(int l=0;l<=i;l++)     
        {
            for(int r=i;r<n;r++) 
            {
                int cnt = 0;

                for(int x=l;x<=r;x++)
                {
                    if(A[x] > A[i])
                        cnt++;
                }

                if(cnt == k)
                    isSpecial = 1;
            }
        }

        if(isSpecial)
            sum += A[i];
    }

    cout<<"Specialty of sequence = "<<sum;
    return 0;
}
