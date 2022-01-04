#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n;
		cin>>n;
		long long num;
		priority_queue<long long, vector<long long>, greater<long long> > pq;
		for(long i=0;i<n;i++)
		{
			cin>>num;
			pq.push(num);
			if(pq.size()>10)
				pq.pop();
		}
		while(!pq.empty())
		{
			cout<<pq.top()<<"\t";
			pq.pop();
		}
		cout<<"\n";
	}
	return 0;
}