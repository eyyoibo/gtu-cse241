#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createCircularList(int n) {
    Node* head = new Node{1, nullptr};
    Node* curr = head;
    for (int i = 2; i <= n; i++) {
        curr->next = new Node{i, nullptr};
        curr = curr->next;
    }
    curr->next = head;
    return head;
}

int findWinner(int n) {
    Node* head = createCircularList(n);
    Node* prev = nullptr;
    Node* curr = head;

    prev = head;
    while (prev->next != head)
        prev = prev->next;
    curr = head;

    while (curr->next != curr) {
        for (int i = 1; i < 3; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    int winner = curr->data;
    delete curr;
    return winner;
}

int main() {
    int n;
    cout << "Enter the number of suitors: ";
    cin >> n;
    cout << "The lucky winner is suitor " << findWinner(n) << endl;
    return 0;
}
