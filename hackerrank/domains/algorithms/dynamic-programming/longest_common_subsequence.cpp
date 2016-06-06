#include<iostream>

using namespace std;

//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence
int main(){

    int n,m;
    cin >> n >> m;
    int x[n],y[m];//the two sequences
    int a[n][m],b[n+1][m+1];
    //array b stores the LCS length
    //array a stores the path for obtaining LCS
    for(int i=0;i<n;i++)
        cin >> x[i];
    for(int i=0;i<m;i++)
        cin >> y[i];

    //LCS algo [BEGINS]

    //setting up the base cases
    //if either i=0 or j=0, one of the sequences has length 0,
    //so the LCS of the two will be 0
    for(int i=0;i<=n;i++)
        b[i][0]=0;
    for(int i=1;i<=m;i++)
        b[0][i]=0;
    // Complexity : O(nm) - gives TLE
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){

            if(x[i-1]==y[j-1]){
                b[i][j]=b[i-1][j-1]+1;
                a[i-1][j-1]=0;
                //cout<<x[i-1]<<" ";
                //value 0 represents the path where x[i-1]=y[i-1]
            }else if(b[i-1][j]>=b[i][j-1]){
                b[i][j]=b[i-1][j];
                a[i-1][j-1]=1;
                //the value 1 for array a represents the path when
                //the length of LCS of x[i-1] and y[i] is greater than
                //the length of LCS of x[i] and y[i-1]
            }else{
                b[i][j]=b[i][j-1];
                a[i-1][j-1]=2;
                //the value 2 for array a represents the path when
                //the length of LCS of x[i-1] and y[i] is less than
                //the length of LCS of x[i] and y[i-1]
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
//     for printing  array b for debugging
            /*for(int p=0;p<n;p++){

                for(int q=0;q<m;q++){
                    cout<<a[p][q]<<"  ";
                }
                cout<<endl;
            }
            cout<<endl;*/
            //cout<<endl;
     int lcs_length = b[n][m];
     int LCS[lcs_length];
     int k=lcs_length-1;
     for(int i=n-1;i>0;){

        for(int j=m-1;j>0;){

            if(a[i][j]==0){
                LCS[k--]=x[i];
                --i;
                --j;
            }else if(a[i][j]==1){
                --i;
            }else{
                --j;
            }
        }
     }

     for(int i=0;i<lcs_length;i++)
        cout<<LCS[i]<<" ";


return 0;
}
