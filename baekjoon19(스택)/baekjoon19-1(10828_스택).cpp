
#include <iostream>
#include <string>

using namespace std;

class Node {
    friend class teststack;

private:
    int data;
    Node* link;
public:
    Node(int value, Node* _link) {
        data = value;
        link = _link;
    }
};

class teststack {
private:
    Node* curNode;
    Node* newNode;
    int topnum;
    
public:
    teststack() {
        curNode = new Node(0, NULL);
        newNode = NULL;
        topnum = 0;
    }
    void push(int X) {
        newNode = new Node(X, curNode);
        curNode = newNode;
        topnum++;
    }
    int pop() {
        if (topnum == 0) {
            return -1;
        }
        int num = curNode->data;
        newNode = curNode;
        curNode = curNode->link;
        topnum--;
        return num;
    }
    int size() {
        return topnum;
    }
    int empty() {
        if (topnum == 0)return 1;
        else return 0;
    }
    int top() {
        if (topnum == 0)return -1;
        else return curNode->data;
    }
};

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, x;
    string r;
    cin >> N;
    teststack a;
    for (int i = 0; i < N; i++) {
        cin >> r;
        if (r == "push") {
            cin >> x;
            a.push(x);
        }
        else if (r == "pop") {
            cout << a.pop() << "\n";
        }
        else if (r == "size") {
            cout << a.size() << "\n";
        }
        else if (r == "empty") {
            cout << a.empty() << "\n";
        }
        else if( r == "top") {
            cout << a.top() << "\n";
        }
    }
}

