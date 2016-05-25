#include<iostream>
#include<algorithm>//for sort()
using namespace std;

long num_of_change_ways(int n, int den[],int m){
    //the array den is used to store the denominations available for change
    //n = amount to be changed
    //m = number of denominations
    sort(den,den+m);
    long a[51][251]={0};//the array a is used to store the number of ways of changing amount i
    for(int i=1;i<=m;i++){
        a[i][0]=1;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){

            if(den[i-1]<=j){
                a[i][j]=a[i-1][j]+a[i][j-den[i-1]];
            }else{
                a[i][j]=a[i-1][j];
            }
        }
    }
    /*for(int x = 0 ;x <= m ; x++){
        cout<<endl;
        for(int y= 0;y<=n;y++){
            cout<<a[x][y]<<"\t";
        }
    }
    cout<<endl;*/
    return a[m][n];

}
int main(){

    int n;//total amount to be changed
    int m;//number of denominations available
    cin>>n>>m;
    int den[m];//the denominations available for change
    for(int i=0;i<m;i++)
        cin>>den[i];

    long ways = num_of_change_ways(n,den,m);
    //the number of ways can be a large number which could not be stored in int variable
    //hence long type has been used here
    //using int type 3 test cases gave wrong answer
    cout<<ways;
    return 0;
}
