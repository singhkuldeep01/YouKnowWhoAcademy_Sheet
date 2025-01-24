#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> superLuckyNumbers;

// Function to generate super lucky numbers recursively
void generateSuperLucky( int length) {
    int subSets = 1<<length;
    for(int mask = 0 ; mask < subSets ; mask++){
        int setBits = __builtin_popcount(mask);
        if(setBits ==  length / 2){
            string num = "";
            for(int i = 0 ; i < length ; i++){
                if(mask & (1<<i)){
                    num += "4";
                }else{
                    num += "7";
                }
            }
            superLuckyNumbers.push_back(stoll(num));

        }
    }
}

void solve() {
    string n;
    cin >> n;
    
    int len = n.size();
    if(len % 2 == 1) {
        len--;
    }
    // Generate all super lucky numbers of length ≤ 10
    for (int l = 2; l <= 10; l += 2) {
        generateSuperLucky(l);
    }
    sort(superLuckyNumbers.begin(), superLuckyNumbers.end());

    // Find the smallest valid super lucky number >= N
    int numN = stoll(n);
    for (int num : superLuckyNumbers) {
        if (num >= numN) {
            cout << num << endl;
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
