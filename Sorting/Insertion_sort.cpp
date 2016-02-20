#include<iostream>
using namespace std;
int main(){
    int arr[10]={98,76,56,43,12,12,11,7,3,1};
    int saved_element,j;


    for(int k=0;k<10;k++){
            cout<<arr[k]<<"\t";
        }
        cout<<endl;

    for(int i=1;i<10;i++){
        saved_element=arr[i];
        j=i;

        while(arr[j-1]>saved_element&&j>0){
            arr[j]=arr[j-1];
            --j;
        }
        arr[j]=saved_element;

        for(int k=0;k<10;k++){
            cout<<arr[k]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
