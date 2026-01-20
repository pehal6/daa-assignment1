#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;
};

double dist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) +
                (a.y-b.y)*(a.y-b.y));
}

double brute(Point p[], int n)
{
    double mn = 99999;

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(dist(p[i],p[j]) < mn)
                mn = dist(p[i],p[j]);

    return mn;
}

void sortX(Point p[], int n)
{
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(p[i].x > p[j].x)
                swap(p[i], p[j]);
}

double closest(Point p[], int n)
{
    if(n <= 3)
        return brute(p, n);

    int mid = n/2;
    Point midPoint = p[mid];

    double dl = closest(p, mid);
    double dr = closest(p+mid, n-mid);

    double d = min(dl, dr);

    Point strip[20];
    int k = 0;

    for(int i=0;i<n;i++)
        if(abs(p[i].x - midPoint.x) < d)
            strip[k++] = p[i];

    double minStrip = d;

    for(int i=0;i<k;i++)
        for(int j=i+1;j<k;j++)
            if(dist(strip[i],strip[j]) < minStrip)
                minStrip = dist(strip[i],strip[j]);

    return min(d, minStrip);
}

int main()
{
    Point p[] = {{9,3},{2,6},{15,3},{5,1},{1,2},{12,4},
                {7,2},{4,7},{16,5},{3,3},{10,5},
                {6,4},{14,6},{8,6},{11,1},{13,2}};

    int n = 16;

    sortX(p,n);

    double ans = closest(p,n);

    cout<<"Minimum distance = "<<ans;
    return 0;
}
