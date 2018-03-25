
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
 
class compare {
 public:
    bool operator()(Node* l, Node* r)
    {
        return (l->freq > r->freq);
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
    class Node *left, *right, *top;
    priority_queue<Node*, vector<Node*>, compare> minHeap;
 
    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(data[i], freq[i]));
 
    while (minHeap.size() != 1) {
 
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
        top = new Node('_', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        minHeap.push(top);
    }
 
    print(minHeap.top(), "");
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