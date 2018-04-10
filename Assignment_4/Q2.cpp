#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,W;
	cin>>n>>W;
	vector<int> values(n+1);
	vector<int> weights(n+1);
	vector<vector<int> > Memo(n+1,vector<int>(W+1,0));
	vector<vector<int> > Keep(n+1,vector<int>(W+1,0));

	for(int i=1;i<=n;i++)
	{
		cin>>weights[i];
	}

	for(int i=1;i<=n;i++)
	{
		cin>>values[i];
	}

	
	
	for(int w=0;w<=W;w++)
	{
		Memo[0][w] = 0;
	}

	for(int i=1;i<=n;i++)
	{
		for(int w=1;w<=W;w++)
		{
		//Memo[0][w] = 0;

			if(weights[i]>w) 
				Memo[i][w] = Memo[i-1][w];
			else 
			{
				Memo[i][w] = max(Memo[i-1][w-weights[i]]+values[i],Memo[i-1][w]);
				if( Memo[i-1][w-weights[i]]+values[i] > Memo[i-1][w] )  
				{
					Keep[i][w] = 1;
				}
				//cout<<"Added ( Weight : "<<weights[n0]<<" Value : "<<values[n0]<<" )"<<endl;				
			}			
		}		
	}
	cout<<Memo[n][W]<<endl;

	for(int i=1;i<=n;i++)
	{
		for(int w=1;w<=W;w++)
		{
			cout<<Keep[i][w]<<" ";
		}
		cout<<endl;
	}

	int n0 = n,W0=W;
	while(n0!=0)
	{
		if(Keep[n0][W0]) 
		{ 
			cout<<"Added ( Weight : "<<weights[n0]<<" Value : "<<values[n0]<<" )"<<endl;
			W0 = W0 - weights[n0];
		}
		n0--;

	}

	return 0;


}