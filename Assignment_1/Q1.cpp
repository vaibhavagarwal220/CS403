#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    char value;
    int key;
 
public:
    Node( int k, int v ) {
        this->key = k;
        this->value = v;
        
    }
    int Val() const { return this->value; }
    int Key() const { return this->key; }
};
 
struct CompareNode : public std::binary_function<Node, Node, bool>                                                                                     
{
  bool operator()(const Node lhs, const Node rhs) const
  {
     return lhs.Key() > rhs.Key();
  }
};

priority_queue<Node,vector<Node>, CompareNode> PriorityQueue(string order){
    int len = order.length();
    Node *newNode = NULL;
    priority_queue<Node,vector<Node>, CompareNode > pq;
    for(int n=1;n<=len;n++)
        {         
            newNode =  new Node(n,order[n-1]);  
            pq.push(*newNode);
        }
    return pq;
}

map<char,int> PriorityMap(string order){
    int len = order.length();    
    map<char,int> priority;
    for(int n=1;n<=len;n++)
        {         
            priority.insert(pair<char, int>(order[n-1],n));
        }
    return priority;
}

int main()
{
     
    string order,men_list,women_list;
    int num_people,num_free;
    cout<<"Enter number of men/women : ";
    cin>>num_people;
    cout<<"Enter list of men's initials(without spaces) : ";
    cin>>men_list;
    cout<<"Enter list of women's initials(without spaces) : ";
    cin>>women_list;
    num_free = num_people;
    
    vector<int> men_engaged_to(num_free,-1);
    vector<int> women_engaged_to(num_free,-1);

    vector<priority_queue<Node,vector<Node>, CompareNode> > mens_preference;
    vector<map<char,int> > womens_preference;

    for(int i=0;i<num_people;i++){
        cout<<"Enter preference list of " << men_list[i] <<" for women "<<women_list <<" : " ;
        cin>>order;
        mens_preference.push_back(PriorityQueue(order));
    }
    for(int i=0;i<num_people;i++){
        cout<<"Enter preference list of " << women_list[i] <<" for men "<<men_list <<" : " ;
        cin>>order;
        womens_preference.push_back(PriorityMap(order));
    }

    int m;
    while(num_free>0){
        for(m=0;m<num_people;m++){
            if(men_engaged_to[m]==-1) break;
        }
        while(!mens_preference[m].empty() && men_engaged_to[m]==-1){
            char woman = mens_preference[m].top().Val();
            int index = women_list.find(woman);
            if(women_engaged_to[index]!=-1){
                int new_preference = womens_preference[index].find(men_list[m])->second;
                int fiance_index = women_engaged_to[index];
                int cur_preference = womens_preference[index].find(men_list[fiance_index])->second;
                if(new_preference<cur_preference){
                    women_engaged_to[index] = m;
                    men_engaged_to[m]=index;
                    men_engaged_to[fiance_index]=-1;
                    cout<<endl<<"changed engagement of "<<women_list[index]<<" from "<<men_list[fiance_index]<<" to "<<men_list[m]<<endl; 
                }
            }
            else{
                cout<<endl<<"engaged "<<women_list[index]<<" to "<<men_list[m]<<endl;
                women_engaged_to[index]=m;
                men_engaged_to[m]=index;
                num_free--;
            }
            mens_preference[m].pop();
        }

    }
    cout<<endl<<endl<<"Stable Matching"<<endl;
    for(int i=0;i<num_people; i++){
    cout<<men_list[women_engaged_to[i]]<<"------"<<women_list[i]<<""<<endl;
    }

    return 0;
}
