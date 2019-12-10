#include<bits/stdc++.h>
#include<ctype.h>
#include<string.h>

#include<stdio.h>

#define TAKING         freopen("input.txt" , "r" , stdin);
#define MAKING         freopen("output.txt","w" , stdout);

#define     ll         long long
#define     sf         scanf
#define     pf         printf
#define     pb         push_back
#define     mp         make_pair
#define     DOS        10000000000
#define     OO         0xfffffff
#define     nl         "\n"
#define     BOLT       ios_base::sync_with_stdio(0)

#define     all(x)     x.begin(), x.end()
#define     rall(x)    x.rbegin(), x.rend()
#define     fi         first
#define     se         second
#define     sz(v)      (int)(v).size()

using namespace std;

inline int ini(){int n;cin >> n;return n;}
inline ll inl(){ll n;cin >> n;return n;}
inline double ind(){double n;cin >> n;return n;}
inline string ins(){string n;cin >> n;return n;}
inline string insl(){string n;getline(cin,n);return n;}


inline int string_to_int(string s){int n;stringstream ss;ss << s;ss >> n;return n;}    // Same for double and long long
inline string int_to_string(int n){string s;stringstream ss;ss << n;ss >> s;return s;} // Same for double and long long


inline long long string_to_Long_Long(string s){ll res = 0;for(int i = 0 ; i < s.size() ; i++){res = res*10 + (s[i]-'0');}return res;}

struct edge{
    int u , v , w;
};

int cost[100] = {0};
edge edges[100];

void BellMan_Ford(int s , int n , int e){
    for(int i = 0 ; i < n ; i++){
        cost[i] = INT_MAX;
    }
    cost[s] = 0;

    for(int i = 0 ; i < (n-1) ; i++){
        for(int j = 0 ; j < e ; j++){
            if(cost[edges[j].v] > cost[edges[j].u] + edges[j].w){
                cost[edges[j].v] = cost[edges[j].u] + edges[j].w;
            }
        }
    }
    for(int i = 0 ; i < e ; i++){
        if(cost[edges[i].v] > cost[edges[i].u] + edges[i].w){
            cout << "Negative Cycle Found\n";
        }
    }
    cout << "COSTS:";
    for(int i = 0 ; i < n ; i++){
        cout << " " <<  cost[i];
    }

}
int main(){
    int node = ini() , edgeNum = ini();
    for(int i = 0 ; i < edgeNum ; i++){
        edge n;
        n.u = ini() , n.v = ini() , n.w = ini();
        edges[i] = n;
    }

    int source = ini();
    BellMan_Ford(source , node , edgeNum);

return 0;
}





