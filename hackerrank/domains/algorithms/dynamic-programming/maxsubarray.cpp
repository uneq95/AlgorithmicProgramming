#include<iostream>
#include<algorithm>
#include<climits>// for using INT_MIN
using namespace std;

//refer here
//https://www.youtube.com/watch?v=hXlv88ddcgw

int max_subsequence_sum(int a[],int n){
    //just sort the array in increasing order
    //if the array contains positive numbers then take the sum of
    //positive numbers from the end of the array

    //if the number does not contain positive number then
    //take the first negative number as the max subsequence sum for obvious reasons

    int sum =0;
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){

        if(a[i]<0){
                //this if(i==n-1) condition is to check whether the array contains a negative number
                //as the last element(or the biggest element)
                //because if the array does not contain a zero at the last index then it will have a
                // negative number at the last index, which will be the maximum sum subsequence
                if(i==n-1)
                    sum=sum+a[i];

            return sum;
        }else{
            sum=sum+a[i];
        }
    }
    return sum;
}

int max_subarray_sum(int a[], int n){
    int s[n];

    s[0]=a[0];
    int mss = INT_MIN;
    if(s[0]>mss){
        mss=s[0];
    }
    for(int i=1;i<n;i++){
        s[i]=max(s[i-1]+a[i],a[i]);
        if(s[i]>mss)
            mss=s[i];
    }
    return mss;

}
int main(){

    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int max_subarr_sum = max_subarray_sum(a,n);
        int max_subseq_sum = max_subsequence_sum(a,n);

        cout<<max_subarr_sum<<" "<<max_subseq_sum<<endl;

    }
return 0;
}
