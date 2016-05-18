#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    long double a,b,temp;
    cin>>a>>b>>n;
    //unsigned long long fib[n];
    //fib[0]=a;
    //fib[1]=b;

    for(int i=2;i<n;i++){
        temp=b*b+a;
        a=b;
        b=temp;
    }
    cout<<fixed<<setprecision(0)<<temp;
    /*for(int i=2;i<n;i++){
        fib[i]=fib[i-1]*fib[i-1]+fib[i-2];
    }
    cout<<fib[n-1];*/
    return 0;
}
