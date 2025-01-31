#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0); cin.tie(0);

class node {
public:
    int data;
    node* prev;
    node* next;
    node(int val) {
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class Dequeue {
    node* head;
    node* tail;

public:
    Dequeue() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int val) {
        node* new_node = new node(val);
        if (!head) {
            head = new_node;
            tail = head;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void push_front(int val) {
        node* new_node = new node(val);
        if (!head) {
            head = new_node;
            tail = head;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void pop_front() {
        if (!head) {
            cout << "No job for Ada?" << endl;
            return;
        }
        node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL;
        cout << temp->data << endl; // Fix: Ensuring newline for correct formatting
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "No job for Ada?" << endl;
            return;
        }
        node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL;
        cout << temp->data << endl; // Fix: Ensuring newline for correct formatting
        delete temp;
    }

    void reverse() {
        node* curr = head;
        node* temp = NULL;

        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev; // Move to next node (which is prev due to swap)
        }

        // Swap head and tail
        if (temp) {
            head = temp->prev;
        }
    }
};

void solve() {
    Dequeue d;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "back") {
            d.pop_back();
        } else if (s == "front") {
            d.pop_front();
        } else if (s == "reverse") {
            d.reverse();
        } else if (s == "push_back") {
            int val;
            cin >> val;
            d.push_back(val);
        } else if (s == "toFront") {
            int val;
            cin >> val;
            d.push_front(val);
        }
    }
}

int32_t main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}

/*
back - Print number from back and then erase it
front - Print number from front and then erase it
reverse - Reverses all elements in queue
push_back N - Add element N to back
toFront N - Put element N to front
*/
