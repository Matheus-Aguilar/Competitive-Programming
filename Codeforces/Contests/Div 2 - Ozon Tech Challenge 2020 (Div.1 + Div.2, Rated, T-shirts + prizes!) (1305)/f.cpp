#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

vector<int> primes;
vector<bool> nums;
vector<int> small;
vector<int> big;

void crivo(ll size){
    nums.assign(size + 1, true);
    nums[0] = nums[1] = false;

    for(ll i = 2; i <= size; i++){
        if(nums[i]){
            for(ll j = i * i; j <= size; j += i){
                nums[j] = false;
            }
            primes.push_back(i);
        }
    }
}

int main(){
    optimize;

    crivo(1000000);

    return 0;   
}
