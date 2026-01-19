#include <iostream>
using namespace std;

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = 8;

    int max = arr[0], sum = 0;

    for(int i=0;i<n;i++)
    {
        sum = sum + arr[i];

        if(sum > max)
            max = sum;

        if(sum < 0)
            sum = 0;
    }

    cout<<"Maximum subarray sum is: "<<max;
    return 0;
}
