#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int val){
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};
class Dequeue{
    node *head;
    node *tail;
    int size;
    public:
    Dequeue(){
        size = 0;
        head = NULL;
        tail = NULL;
    }
    void push_back(int val){
        node* new_node = new node(val);
        if(head == NULL) {
            head = new_node;
            tail = head;
        }
        else{
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;
        cout<<"ok"<<endl;
    }
    void push_front(int val){
        // cout<<"hello";
        node* new_node = new node(val);
        if(head == NULL){
            head = new_node;
            tail = head;
        }else{
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
        cout<<"ok"<<endl;
    }
    void pop_front(){
        if(head){
            node *temp = head;
            head = head->next;
            if(head)
                head->prev = NULL;
            else tail = NULL;
            cout<<temp->data<<endl;
            delete(temp);
            size--;
        }else{
            cout<<"Empty"<<endl;
        }
    }
    void pop_back(){
        if(tail){
            node *temp = tail;
            tail = tail->prev;
            if(tail)
                tail->next = NULL;
            else head = NULL;
            cout<<temp->data<<endl;
            delete(temp);
            size--;
        }else{
            cout<<"Empty"<<endl;
        }
    }
    void front(){
        if(head){
            cout<<head->data<<endl;
        }
    }
    void back(){
        if(tail){
            cout<<tail->data<<endl;
        }
    }
    void length(){
        cout<<size<<endl;
    }
    void clear(){
        while(head){
            node* temp = head;
            head = head->next;
            delete(temp);
        }
        tail = NULL;
        size = 0;
        cout<<"ok"<<endl;
    }
    void display(){
        node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};
void solve() {
    Dequeue d;
    int n = 1;
    while(n){
        string s;
        cin>>s;
        if(s == "push_back"){
            int val;
            cin>>val;
            d.push_back(val);
        }else if(s == "push_front"){
            int val;
            cin>>val;
            d.push_front(val);
        }else if(s == "pop_front"){
            d.pop_front();
        }else if(s == "pop_back"){
            d.pop_back();
        }else if(s == "size"){
            d.length();
        }else if(s == "clear"){
            d.clear();
        }else if(s == "front"){
            d.front();
        }else if(s == "back"){
            d.back();
        }else {
            cout<<"bye";
            break;
        }
    }
}

int32_t main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif */
    fast_io;
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}