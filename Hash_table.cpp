#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <ctime>
#include <map>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <list>
#include <vector>
#include <iomanip>
#include <cctype>
#include <complex>
#include <iterator>
#include <ostream>
#include <bitset>
#include <assert.h>
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define clx complex<long double>
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;
int _bufint;
inline int in(){
	scanf("%d", &_bufint);
	return _bufint;
}

ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

const ll LINF=~((1ll)<<63);
const int INF=~(1<<31);
const double eps=1e-6;


class hash_table{
	static const int mod = 1000003;
	int max_str_len;
	int table[mod];
	vector <ll> val;
	vector <int> next;
	
private:	
	void set_max_str_len(int _max_str_len){
		max_str_len = _max_str_len;
	}

	ll get_hash(char* str){
		ll hash = 0;	
		for(int i = 0; i < max_str_len; ++i){
			if(str[i] == '\0') break;
			hash = hash*37 + str[i];
		}
		return hash;
	}
public:
	hash_table(){
		set_max_str_len(15);
		for(int i = 0; i < mod; ++i){
			table[i] = -1;
		}
	}

	bool find(char* s){
		bool f = false;
		ll hash = get_hash(s);
		int ind = table[hash % mod];
		if(ind != -1){
			while(!val.empty() && ind != -1){
				if(val[ind] == hash){
					f = true;
					break;
				}
				ind = next[ind];
			}
		}
		return f;
	}	
	void add(char* s){
		bool f = false;
		ll hash = get_hash(s);
		int ind = table[hash % mod];

		if(table[hash % mod] == -1){
			table[hash % mod] = val.size();
			val.push_back(hash);
			next.push_back(-1);
		}
		else{
			bool f = false;
            ll hash = get_hash(s);
    	    int ind = table[hash % mod];
		    while(next[ind] != -1){
			    if(val[ind] == hash){
				    f = true;
				    break;
			    }
			    ind = next[ind];
		    }
			if(!f){					
				val.push_back(hash);
				next[ind] = next.size();
				next.push_back(-1);
			}
		}
	}
};


int main(){
#ifdef PHD
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
#else
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
#endif
	char ch;
	hash_table *ht = new hash_table();
	while(true){
		scanf("%c", &ch);
		if(ch == '#') break;
		char s[15];
		gets(s);	
		if(ch == '+'){
			ht->add(s);
		}
		if(ch == '?'){
			bool f = ht->find(s);
			if(f) puts("YES");
			else puts("NO");
		}


	}
	return 0;
}