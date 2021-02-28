#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int ans=n;
    for(int i=1;i<=4;i++)
    {
        cout<<ans<<' ';
        ans*=n;
    }
    cout<<ans<<endl;
    //cout<<endl;
}
