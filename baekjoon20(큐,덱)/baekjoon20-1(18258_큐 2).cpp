
#include <iostream>
#include <queue>

using namespace std;

class Node {
    friend class queueChain;
private:
    int data;
    Node* link;
public:
    Node(int value, Node* _link) {
        data = value;
        link = _link;
    }
};

class queueChain {
private:
    Node* firstNode;
    Node* curNode;
    Node* newNode;
    int size;
public:
    queueChain() {
        firstNode = NULL;
        curNode = new Node(0, NULL);
        newNode = NULL;
        size = 0;
    }
    void push(int X) {
        newNode = new Node(X, NULL);
        curNode->link = newNode;
        curNode = newNode;
        if (size == 0) {
            firstNode = curNode;
        }
        size++;
    }
    void pop() {
        if (size == 0)cout << "-1\n";
        else {
            cout << firstNode->data << "\n";
            firstNode = firstNode->link;
            size--;
        }
    }
    void sizee() {
        cout << size << "\n";
    }
    void empty() {
        if (size == 0) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    void front() {
        if (size == 0) {
            cout << -1 << "\n";
        }
        else {
            cout << firstNode->data << "\n";
        }
    }
    void back() {
        if (size == 0) {
            cout << -1 << "\n";
        }
        else {
            cout << curNode->data << "\n";
        }
    }
};

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    queueChain a;
    int N, c;
    string b;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> b;
        if (b == "push") {
            cin >> c;
            a.push(c);
        }
        else if (b == "pop") {
            a.pop();
        }
        else if (b == "size") {
            a.sizee();
        }
        else if (b == "empty") {
            a.empty();
        }
        else if (b == "front") {
            a.front();
        }
        else if (b == "back") {
            a.back();
        }
    }
}

