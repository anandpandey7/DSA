#include<iostream>
#include<math.h>
using namespace std;
int main ()
{
    int n,a=0,i=0;
    cin >> n;
    while(n!=0)
    {
        int digit= n%10;
        if(digit==1)
        {
            a= a + pow(2,i);
        }
        n = n/10;
        i++;
    }
    cout << a << endl;
}