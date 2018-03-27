
#include <bits/stdc++.h>
using namespace std;
#define MAX_TASKS 100000

vector<int> Memo(MAX_TASKS,-1);
/*

6
1 4 3
2 6 5
4 7 2
6 8 6
5 9 4
7 10 8

13

*/
class Task {
    public:
    int start;
    int finish;
    int weight;
    Task(int s,int f,int c)
    {
        this->start = s;
        this->finish = f;
        this->weight = c;
    }
};
 
class comparef {
 public:
    bool operator()(Task l, Task r)
    {
        return (l.finish < r.finish);
    }
};

vector<int> find_disjoint(vector<Task> tasks){
    vector<int> find_last;
    int size =tasks.size();
    find_last.push_back(-1);
    for(int i=1;i<size;i++){
        for(int j=i-1;j>=0;j--){
            if(tasks[j].finish <= tasks[i].start){
                find_last.push_back(j);
                break;
            }
        }
        if(find_last.size()!=i+1) find_last.push_back(-1);
    }

    return find_last;
}


int compute_opt(int j,vector<int> p,vector<Task> tasks){  // part a
    if(j==-1) return 0;
    else 
        return max(tasks[j].weight+compute_opt(p[j],p,tasks),compute_opt(j-1,p,tasks));
}

int m_compute_opt(int j,vector<int> p,vector<Task> tasks){ // part b
    if(j==-1) return 0;
    else if(Memo[j]!=-1) return Memo[j];
    else 
     {
        Memo[j] = max(tasks[j].weight+m_compute_opt(p[j],p,tasks),m_compute_opt(j-1,p,tasks));
        return Memo[j];
     }
}

void find_solution(int j,vector<Task> tasks,vector<int> p){ //part c
    if(j==-1) return;
    else{
        if(tasks[j].weight + Memo[p[j]] >= Memo[j-1])
        {
            cout<<"Task ( start : "<<tasks[j].start<<", finish : "<<tasks[j].finish<<", weight : "<<tasks[j].weight<<" )"<<endl;
            find_solution(p[j],tasks,p);
        }
        else find_solution(j-1,tasks,p);
    }
}
 
int main()
{
    int s,f,c,size;
    cin>>size;
    vector<Task> tasks;
    Task *newTask = NULL;
    for(int i=0;i<size;i++){
        cin>>s>>f>>c;
        newTask = new Task(s,f,c);
        tasks.push_back(*newTask);
    }
    sort(tasks.begin(),tasks.end(),comparef());

    vector<int> p = find_disjoint(tasks);
    
    cout<<"Part a) Compute-Opt(j) "<<endl;
    cout<<"Result : "<<compute_opt(size-1,p,tasks)<<endl<<endl;
    
    cout<<"Part b) M-Compute-Opt(j) "<<endl;
    cout<<"Result : "<<m_compute_opt(size-1,p,tasks)<<endl<<endl;
    
    cout<<"Part c) Find-Solution(j) "<<endl;
    find_solution(size-1,tasks,p);
    cout<<endl;
    return 0;
}