#include<bits/stdc++.h>
using namespace std;


int closest2(int size)
{
	return (int)(pow(2,ceil((float)log2(size))));
}

void print(vector<vector<int> > m){
	cout<<endl;
	int size = m.size();
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


vector<vector<int> > add(vector<vector<int> > m1,vector<vector<int> > m2)
{
	int size=m1.size();
	vector<vector<int> > C(size,vector<int>(size,0));
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			C[i][j] = m1[i][j]+m2[i][j];			
		}
	}
	return C;
}


vector<vector<int> > subtract(vector<vector<int> > m1,vector<vector<int> > m2)
{
	int size=m1.size();	
	vector<vector<int> > C(size,vector<int>(size,0));
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			C[i][j] = m1[i][j]-m2[i][j];			
		}
	}
	return C;
}

vector<vector<int> > strassen(vector<vector<int> > A,vector<vector<int> > B , int size)
{
	if(size == 1) {
		int result = (A[0][0] * B[0][0]);
		vector<vector<int> > C(1,vector<int>(1,result));
		cout<<result<<endl;
		return C;
	}

	int new_size = size/2 ;
	vector<vector<int> > A11(new_size,vector<int>(new_size,0)),
	A12(new_size,vector<int>(new_size,0)),
	A21(new_size,vector<int>(new_size,0)),
	A22(new_size,vector<int>(new_size,0)),
	aTemp;

	vector<vector<int> > B11(new_size,vector<int>(new_size,0)),
	B12(new_size,vector<int>(new_size,0)),
	B21(new_size,vector<int>(new_size,0)),
	B22(new_size,vector<int>(new_size,0)),
	bTemp;

	vector<vector<int> > C11,C12,C21,C22,C(size,vector<int>(size));

	vector<vector<int> > M1,M2,M3,M4,M5,M6,M7;

	for(int i=0;i<new_size;i++)
	{
		for(int j=0;j<new_size;j++)
		{
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][j+new_size];
			A21[i][j] = A[i+new_size][j];
			A22[i][j] = A[i+new_size][j+new_size];
			B11[i][j] = A[i][j];
			B12[i][j] = A[i][j+new_size];
			B21[i][j] = A[i+new_size][j];
			B22[i][j] = A[i+new_size][j+new_size];
		}
	}


        aTemp = add(A11, A22); // A11 + A22
        bTemp = add(B11, B22); // B11 + B22
        M1 = strassen(aTemp, bTemp, new_size); // M1 = (A11+A22) * (B11+B22)
 
        aTemp = add(A21, A22); // A21 + A22
        M2 = strassen(aTemp, B11, new_size); // M2 = (A21+A22) * (B11)
 
        bTemp = subtract(B12, B22); // B12 - B22
        M3 = strassen(A11, bTemp, new_size); // M3 = (A11) * (B12 - B22)
 
        bTemp = subtract(B21, B11); // B21 - B11
        M4 = strassen(A22, bTemp, new_size); // M4 = (A22) * (B21 - B11)
 
        aTemp = add(A11, A12); // A11 + A12
        M5 = strassen(aTemp, B22, new_size); // M5 = (A11+A12) * (B22)   
 
        aTemp = subtract(A21, A11); // A21 - A11
        bTemp = add(B11, B12); // B11 + B12
        M6 = strassen(aTemp, bTemp, new_size); // M6 = (A21-A11) * (B11+B12)
 
        aTemp = subtract(A12, A22); // A12 - A22
        bTemp = add(B21, B22); // B21 + B22
        M7 = strassen(aTemp, bTemp, new_size); // M7 = (A12-A22) * (B21+B22)
 
        C12 = add(M3, M5); // C12 = M3 + M5
        C21 = add(M2, M4); // C21 = M2 + M4
 
        aTemp = add(M1, M4); // M1 + M4
        bTemp = add(aTemp, M7); // M1 + M4 + M7
        C11 = subtract(bTemp, M5); // C11 = M1 + M4 - M5 + M7
 
        aTemp = add(M1, M3); // M1 + M3
        bTemp = add(aTemp, M6); // M1 + M3 + M6
        C22 = subtract(bTemp, M2); // C22 = M1 + M3 - M2 + M6

        for(int i=0;i<new_size;i++)
		{
			for(int j=0;j<new_size;j++)
			{
				C[i][j] = C11[i][j];
				C[i][j+new_size] = C12[i][j];
				C[i+new_size][j] = C21[i][j];
				C[i+new_size][j+new_size] = C22[i][j];				
			}
		}

	return C;

}

vector<vector<int> > multiply_matrix(vector<vector<int> > m1,vector<vector<int> > m2,int size)
{
	int new_size = closest2(size);
	vector<vector<int> > A(new_size,vector<int>(new_size,0)),
	B(new_size,vector<int>(new_size,0)),
	C(size,vector<int>(size,0)),
	CTemp;
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			A[i][j] = m1[i][j];
			B[i][j] = m2[i][j];
		}
	}

	CTemp = strassen(A,B,new_size);

	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{			
			C[i][j] = CTemp[i][j];
		}
	}
	return C;
}


int main(){

	int size;
	cin>>size;
	vector<vector<int> > m1(size,vector<int>(size));
	vector<vector<int> > m2(size,vector<int>(size));
	vector<vector<int> > m3;

	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cin>>m1[i][j];
		}
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cin>>m2[i][j];
		}
	}

	m3 = multiply_matrix(m1,m2,size);

	cout<<"Matrix A";
	print(m1);
	cout<<"Matrix B";
	print(m2);
	cout<<"Matrix C = Matrix A X Matrix B";
	print(m3);

	return 0;

}