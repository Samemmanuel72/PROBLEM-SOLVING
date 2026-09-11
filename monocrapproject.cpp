#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<stack>

#define ll long long int
#define INF 2e9

using namespace std;

void solve(){
    ll x,y,k;
    cin >> x >> y >> k;

    ll ans=0,ctr=0;

    while(ctr<k){
        ll rem=(y+ctr)%(x+ctr);

        if(rem==y-x)
            break;

        ans+=rem;
        ctr++;
    }

    if(k>ctr){
        ans+=(k-ctr)*(y-x);
    }

    cout << ans << endl;
}
