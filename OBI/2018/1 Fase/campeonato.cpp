#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<string> msg = {"final", "semifinal", "quartas", "oitavas"};
    int n = 16;
    vector<int>nums(16);
    for(int i = 0; i < 16; i++) scanf("%d",&nums[i]);
    while(true){
        for(int i = 0; i < n; i += 2){
            if(nums[i] > nums[i + 1]) swap(nums[i], nums[i + 1]);
            if(nums[i] == 1 && nums[i + 1] == 9){
                cout << msg[log2(n) - 1] << "\n";
                exit(0);
            }
            else if(nums[i] == 1 || nums[i] == 9) nums[i/2] = nums[i];
            else if(nums[i + 1] == 1 || nums[i + 1] == 9) nums[i/2] = nums[i + 1];
            else nums[i/2] = nums[i];  
        }
        n /= 2;
    }
}