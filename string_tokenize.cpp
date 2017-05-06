#include<iostream>
#include<string>
#include<vector>
using namespace std;
void tokenize(string &s,vector<string> &tokens,string delim = " ")
{
	int lastpos=s.find_first_not_of(delim,0);//skipping the delim in starting and finding starting of substring
	int pos=s.find_first_of(delim,lastpos);//finding first token after substring ends


	//search till either you are not able to find the start of substring or end of substring
	while(lastpos!=string::npos ||pos!=string::npos)
	{
		
		tokens.push_back(s.substr(lastpos,pos-lastpos));
		//skip the delimiters,find start of substring
		lastpos=s.find_first_not_of(delim,pos);
		//find the end of string
		pos=s.find_first_of(delim,lastpos);
	}
	//return tokens;
}
int main()
{
	string y;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>y;
		vector<string>p;
		tokenize(y,p," .-,");
		for(vector<string>::iterator it=p.begin();it!=p.end();++it)
		{
			cout<<*it<<endl;
		}
		p.clear();//Deleting contents of vector
	}
	
	return 0;
}