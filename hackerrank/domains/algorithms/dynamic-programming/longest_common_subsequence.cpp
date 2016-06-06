#include<iostream>

using namespace std;

//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence
int main(){

    int n,m;
    cin >> n >> m;
    int x[n],y[m];//the two sequences
    int b[n+1][m+1];
    //array b stores the LCS length
    //array a stores the path for obtaining LCS
    for(int i=0;i<n;i++)
        cin >> x[i];
    for(int i=0;i<m;i++)
        cin >> y[i];

    //LCS algo [BEGINS]

    //the base cases
    //if either i=0 or j=0, one of the sequences has length 0,
    //so the LCS of the two will be 0
    // Complexity : O(nm)
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++){

            if(i==0||j==0){
                b[i][j]=0;
            }else if(x[i-1]==y[j-1]){
                b[i][j]=b[i-1][j-1]+1;
            }else if(b[i-1][j]>=b[i][j-1]){
                b[i][j]=b[i-1][j];
            }else{
                b[i][j]=b[i][j-1];
            }

            /*
            for printing  array b for debugging
            for(int p=0;p<=n;p++){

                for(int q=0;q<=m;q++){
                    cout<<b[p][q]<<"  ";
                }
                cout<<endl;
            }
            cout<<endl;*/

        }
     //LCS Length
     //cout<<"LCS Length: "<<b[n][m]<<endl;

     //printing the LCS ...
     int lcs_length = b[n][m];
     int LCS[lcs_length];
     int k=lcs_length-1;
     int i=n,j=m;
     while(i>0&&j>0){
            if(x[i-1]==y[j-1]){
                LCS[k]=x[i-1];
                i--;j--;k--;
            }else if(b[i-1][j]>b[i][j-1]){
                i--;
            }else{
                j--;
            }

     }

     for(int i=0;i<lcs_length;i++)
        cout<<LCS[i]<<" ";
return 0;
}
