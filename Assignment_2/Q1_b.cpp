
#include <bits/stdc++.h>
using namespace std;
 
class Node {
 
    public:
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
 
void print(class Node* root, string str)
{
    if (!root)
        return;
 
    if (root->data != '_')
        cout << root->data << " - " << str << "\n";
 
    print(root->left, str + "0");
    print(root->right, str + "1");
}
 
void huffman(char data[], int freq[], int size)
{
    Node *left, *right, *top;
    vector<Node*> vec;
    int lft,rgt;
    Node *test = new Node('_', INT_MAX);


    for (int i = 0; i < size; ++i)
        vec.push_back(new Node(data[i], freq[i]));
 
    while (vec.size() > 1) {
        left=test,right=test;

        for(int i=0;i<vec.size();i++){
            if(vec[i]->freq < left->freq){
                right = left;
                left = vec[i];
                rgt = lft;
                lft = i;                
            }
            else if(vec[i]->freq < right->freq){
                right = vec[i];
                rgt = i;
            }
        }
        vec.erase(vec.begin() + lft);
        if(rgt>lft) vec.erase(vec.begin() + rgt-1);
        else {vec.erase(vec.begin() + rgt);}

        top = new Node('_', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        vec.push_back(top);
    }
 
    print(vec[0], "");
}
 
int main()
{
    int size;
    cin>>size;
    char arr[size];
    int freq[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    for(int i=0;i<size;i++){
        cin>>freq[i];
    }
    huffman(arr, freq, size);
 
    return 0;
}