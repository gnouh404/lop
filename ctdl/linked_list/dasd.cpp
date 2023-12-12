#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int num) {
        data = num;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertInOrder(int num) {
        Node* newNode = new Node(num);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else if (num < head->data) {
            newNode->next = head;
            head = newNode;
        } else if (num > tail->data) {
            tail->next = newNode;
            tail = newNode;
        } else {
            Node* curr = head;
            while (curr->next != NULL && curr->next->data < num) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    void printList() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    cout << "Nhập các số nguyên (nhập -1 để kết thúc nhập):" << endl;
    int num;
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        myList.insertInOrder(num);
    }
    cout << "Danh sách sau khi sắp xếp tăng dần và không có phần tử trùng nhau là:" << endl;
    myList.printList();

    return 0;
}
