#include <bits/stdc++.h>
using namespace std;



void lcs(string s1,string s2)
{
	int n1=s1.size(),n2=s2.size();
	vector<vector<int> > lcs(n1+1,vector<int>(n2+1));
	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			if(i==0 || j==0) lcs[i][j] = 0;
			else if(s1[i-1]==s2[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
			else lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
		}	
	}
	int lcs_len = lcs[n1][n2] ;
	cout<<endl<<"Longest Common Subsequence length : "<<lcs_len<<endl;
	int i=n1,j=n2;
	string s = "";
	while(lcs_len!=0)
		{
			if(s1[i-1]==s2[j-1]) 
			{
				s = s1[i-1]+s;
				i--;
				j--;
				lcs_len--;
			}
			else if(lcs[i-1][j] < lcs[i][j-1]) 
			{
				j--;
			}
			else i--;

			
		}
		cout<<"String 1 : " <<s1<<" 	String 2 :"<< s2 <<endl;
		cout<<"Longest Common Subsequence : "<<s<<endl<<endl;
}

int main(){

	string s1,s2;
	cin>>s1>>s2;	
	lcs(s1,s2);
	return 0;
}