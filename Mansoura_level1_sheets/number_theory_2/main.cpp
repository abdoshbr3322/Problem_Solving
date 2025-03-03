#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <string>
#include <vector>
#include <array>
#include <set>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;


#define ll long long
#define dd double
#define ld long double
#define pi 3.14159265359
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define el "\n"
#define Arwa ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fix(x) cout<<fixed<<setprecision(x)
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(int a,int b) {return a/gcd(a,b)*b;}
bool prime(ll n)
{
	if(n==2) return true;
	if(n%2==0||n==1) return false;
	else { for(ll i=3; i*i<=n; i+=2) {if(n%i==0) return false;}}return true;
}
//here we go again
bool comp(pair<ll,ll>a,pair<ll,ll>b)
{
    return a.first<b.first;
    if(a.first==b.first)
    return a.second<b.second;
}
int height(int left,int right,int med)
{
    for(int i=447;i>=0;i--)
    {
        if(left>=i*(i+1)/2&&right>=i*(i+1)/2&&med>=(i*(i+1)/2)-i)
        return i;
    }
   return 0;
}
int main()
{
    Arwa
    int t=1;
    //cin>>t;
    while(t--)
    {
      int right=0,left=0,med=0;
      string s;
      cin>>s;
      int arr[s.length()];
      for(int i=0;i<s.length();i++)
      {
          if(s[i]=='/')
          left++;
          if(s[i]=='\\')
          right++;
          if(s[i]=='_')
          med++;
          arr[i]=height(left,right,med);
      }
      int q;
      cin>>q;
      while(q--)
      {
          int l,r;
          cin>>l>>r;
          if(l==1)
          cout<<arr[r-1]<<el;
          else
          cout<<arr[r-1]-arr[l-2]<<el;
      }
    }
    return 0;
}
/*
/\_/\_/\
5
1 2
1 5
1 8
3 8
2 3
*/
 
 