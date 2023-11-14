/*
Binary to decimal
1> divide by 2
2> store remainder
3> repeat above 2 step until n!=0
4> reverse answer

*/

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans=0;
    int i=0;
    while(n != 0)
    {
        int bit = n & 1;
        ans=(bit*pow(10,i)) + ans;
        n=n>>1;
        i++;
    }
    cout<< "bit is :"<<ans;
}