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


int cost[10002][10002];
int visited[10002];
int n , e , x , y , w;


int Prims_MST(){
    int ans = 0;
    vector<int>v;
    v.push_back(1);
    visited[1] = 1;
    while(v.size() != n){
            int c = INT_MAX , x;
        for(int i = 0 ; i < v.size() ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(visited[j]==1 || v[i]==j || cost[v[i]][j]==0)
                    continue;
                if(cost[v[i]][j] < c){
                    c = cost[v[i]][j];
                    x = j;
                }
            }
        }
        ans+=c;
        v.push_back(x);
        visited[x] = 1;
    }
    v.clear();
    return ans;
}
int main(){
    scanf("%d%d",&n,&e);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cost[i][j] = 0;
            }visited[i]=0;
        }
        for(int i = 0 ; i < e ; i++){
            scanf("%d%d%d",&x,&y,&w);
            cost[x][y] = cost[y][x] = w;
        }
        printf("%d\n",Prims_MST());
return 0;
}

