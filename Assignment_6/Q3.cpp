#include "simplex.h"

using namespace std;

int main() {
    int n,m;
    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<"Enter number of edges : ";
    cin>>m;
    int edge_matrix[m+1][n+1];
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) 
            edge_matrix[i][j] = 0;        
    }
    double weight[n+4];
    double B[n+4];
    double C[m+n+4];
    for(int i=1;i<=m;i++){
        int u,v;
        cout<<"Enter edge["<<i<<"] : ";
        cin >> u >> v;
        edge_matrix[i][u]=1;
        edge_matrix[i][v]=1;
    }
    for(int i=1;i<=n;i++){
        cout<<"Enter weight of node["<<i<<"] : ";
        cin >> weight[i];
        B[i] = weight[i];
    }
    for(int i=1;i<=m;i++) C[i]=-1;
    for(int i=m+1;i<=m+n;i++) C[i]=1;
    double A[n+1][1000];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n+m;j++) A[i][j]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) A[i][j] = edge_matrix[j][i];
        A[i][m+i] = -1;
    }
    Simplex object(A,B,C,n,m+n);
    object.form_augumented_matrix();
    vector<double> chosen = object.solve();
    cout<<endl<<endl;
    cout << "Minimum weight vertex cover contains the following vertices: ";
    for(vector<double>::iterator it=chosen.begin();it!=chosen.end();it++) 
        if(*it >= 0.5) cout<<(int)(it-chosen.begin())+1<<" ";
    cout<<endl<<endl;
    return 0;
}