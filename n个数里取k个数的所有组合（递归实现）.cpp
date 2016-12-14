#include <iostream>
using namespace std;
void f(int n,int k,int a[],int m)
{     int i;
      if( k == 0 )
      {
          for(int j= 0; j < m; ++j)
          cout<<a[j];
          cout<<" ";
      }
      else
      {
          for( i = n; i >= k; --i )
          {
              a[m] = i;
              f(i-1,k-1,a,m+1);
          }  //for
       }  //else
}

int main()
{
    int n,k,m=0;
    int a[10];
    cout<<"Please enter n and k :";
    cin>>n>>k;
    f(n,k,a,m);
    cout<<endl;
    return 0;
}
