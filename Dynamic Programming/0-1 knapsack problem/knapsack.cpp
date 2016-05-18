#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int optimal_weight_dp(int W, const vector<int> &w) {
  //write your code here

  int n = w.size(); //represents the number of gold bars
  int max_weight[n+1][W+1];

  for(int i=0;i<=n;i++){

    for(int j=0;j<=W;j++){

        if(i==0||j==0){
            max_weight[i][j]=0;
        }else if(w[i-1]<=j){
            max_weight[i][j]= std::max(w[i-1]+max_weight[i-1][j-w[i-1]],max_weight[i-1][j]);

        }else{
            max_weight[i][j]=max_weight[i-1][j];
        }

    }
  }
  return max_weight[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight_dp(W, w) << '\n';
}
