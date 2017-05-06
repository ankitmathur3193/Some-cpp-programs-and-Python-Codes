#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		getline(cin,s);
		while(s.length()==0)
		{
			getline(cin,s);
		}
		cout<<s<<endl;
		int p;
		cin>>p;
		cout<<p<<endl;
	}
}