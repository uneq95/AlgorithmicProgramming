#include<iostream>
using namespace std;

//reference link :
//http://stackoverflow.com/questions/9514191/maximizing-profit-for-given-stock-quotes

//logic:
//the logic is to travel back in time from the last day, and pick the largest stock price
// we sell the stock if its price is the largest/max so far
//otherwise we buy it
int main(){

    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int price[n];

        for(int i=0;i<n;i++){
            cin>>price[i];
        }

        unsigned long long profit =0, max_price_so_far=0;

        for(int i=n-1;i>=0;i--){
            if(max_price_so_far<=price[i])
                max_price_so_far=price[i];
            profit=profit+max_price_so_far-price[i];
        }
        cout<<profit<<endl;

    }

return 0;
}
