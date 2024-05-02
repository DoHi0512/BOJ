#include <bits/stdc++.h>
using namespace std;
map<string,bool> m;
int main() {
    int n;
    int idx = 0;
    int ans = 1;
    m["ChongChong"] = true;
    cin >> n;
    for(int i=0;i<n;i++) {
        string a, b;
        cin >> a >> b;
        if(m.find(a) == m.end()) m[a] = false;
        if(m.find(b) == m.end()) m[b] = false;
        if(m[a] ^ m[b]) {
            m[a] = m[b] = true;
            ans++;
        }
    }
   
    cout << ans;
    
    

    return 0;
}