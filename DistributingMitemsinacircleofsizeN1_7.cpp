#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int res=m%n+k-1;
		if(res==0)
			cout<<n<<"\n";
		else
			cout<<res<<"\n";
	}
	return 0;
}
/*
5
5 2 1
5 8 2
4 5 2
4 5 4
4 4 4
4 4 3
1 1 1
1 2 1
10 10 1
10 10 2
10 1 5
*/