#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n;//total amount to be changed
    int m;//number of denominations available
    //n=1;
    //m=25;
    cin>>n>>m;
    int den[m];//the denominations available for change
    //int s[] ={5 ,37, 8, 39, 33, 17, 22, 32, 13, 7 ,10, 35, 40 ,2 ,43, 49, 46, 19, 41, 1, 12, 11 ,28 };
    for(int i=0;i<m;i++)
        cin>>den[m];//den[i]=s[i];

    int a[51][251]={0};

    for(int i=0;i<=m;i++){
        a[i][0]=1;
    }
    for(int x = 0 ;x <= m ; x++){
                    cout<<endl;
                for(int y= 0;y<=n;y++){
                    cout<<a[x][y]<<"\t";
                }
            }
        cout<<endl;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){

            if(den[j-1]<=i){
                a[j][i]=a[j-1][i]+a[j][i-den[j-1]];
            }else{
                a[j][i]=a[j-1][i];
            }

            for(int x = 0 ;x <= m ; x++){
                    cout<<endl;
                for(int y= 0;y<=n;y++){
                    cout<<a[x][y]<<"\t";
                }
            }
        cout<<endl;
        }
        //cout<<endl<<endl;
    }
    cout<<a[m+1][n+1];
    /*int sum=0;
    for(int i = 0; i <= n; i++){
        for(int j = 0 ; j <= m; j ++){
            sum = sum + a[i][j];
        }
    }
    cout<<sum;*/
    return 0;
}
