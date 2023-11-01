#include "node_iterator.cpp"
#include <math.h>
#ifndef _linked_list_CPP
#define _linked_list_CPP
using namespace std;
template <class T>
class LIST
{
    node<T> *head, *end;
    int num;

public:
    LIST()
    {
        head = end = nullptr;
        num = 0;
    }
    int size() { return num; }
    bool empty() { return num == 0; }
    T &front() { return head->getelem(); }
    T &back() { return end->getelem(); }
    void push_front(T x)
    {
        node<T> *temp = new node<T>;
        temp->setnext(NULL);
        temp->setelem(x);
        head = temp;
        if (!num)
            end = temp;
        num++;
    }
    void push_back(T x)
    {
        if (num == 0)
            push_front(x);
        else
        {
            node<T> *tmp = new node<T>;
            tmp->setelem(x);
            tmp->setnext(NULL);
            end->setnext(tmp);
            end = end->getnext();
            num++;
        }
    }
    void insert(T x, int position)
    {
        node<T> *new_node = new node<T>;
        new_node->setelem(x);
        new_node->setnext(NULL);
        if (position == 1 || num == 0)
        {
            push_front(x);
        }
        node<T> *current = head;
        node<T> *previous = NULL;
        int cnt = 0;
        while (current != NULL && cnt < position - 1)
        {
            previous = current;
            current = current->getnext();
            cnt++;
        }
        previous->setnext(new_node);
        new_node->setnext(current);
        num++;
        // new_node->setnext(current);
        // current->setnext(new_node);
        // num++;
        // temp->setnext(p->getnext());
        // p->setnext(temp);
        // temp->setelem(x);
        // if (end == p)
        //     end = temp;
        // num++;
    }
    void equal(T k)
    {
        node<T> *current = head;
        int cnt = 0;
        int found = 0;
        while (current != NULL && cnt < num)
        {
            if (current->getelem() == k)
            {
                found++;
            }
            current = current->getnext();
            cnt++;
        }
        if (found == 0)
            cout << "\nKhong co so nao trong day co gia tri bang " << k;
        else
            cout << "Co " << found << " gia tri trong day bang " << k;
    }
    void check_3_even()
    {
        node<T>* p = head;
        bool check = false;
        if(num >= 3){
          while (p != NULL && p->getnext() != NULL && p->getnext()->getnext() != NULL)
            {
                if (p->getelem() % 2 == 0 && p->getnext()->getelem() % 2 == 0 && p->getnext()->getnext()->getelem() % 2 == 0)
                {
                    cout << p->getelem() << " " << p->getnext()->getelem() << " " << p->getnext()->getnext()->getelem() << "\n";
                    check = true;
                }
                    p = p->getnext();
                }
            if (check == false){
                cout << "Trong day ko co 3 so duong chan canh nhau\n";
            }  
        }
        else cout << "Day ko du 3 so de xet\n";
        
    }
    void sapxep()
    {
        for (node<T> *p = head; p->getnext() != NULL; p = p->getnext())
        {
            for (node<T> *q = p->getnext(); q != NULL; q = q->getnext())
            {
                if (p->getelem() > q->getelem())
                {
                    T tmp = p->getelem();
                    p->setelem(q->getelem());
                    q->setelem(tmp);
                }
            }
        }
    }
    void erase_head()
    {
        if (!num)
            return;
        if (num == 1)
        {
            head = end = nullptr;
            return;
        }
        node<T> *temp = new node<T>;
        temp = head->getnext();
        head = temp;
        num--;
    }
    void pop_front()
    {
        erase_head();
    }
    void pop_back()
    {
        if (num < 2)
            erase_head();
        else
        {
            node<T> *temp = new node<T>;
            while (temp->getNext() != end)
            {
                temp++;
            }
            erase(temp);
        }
    }
    int prime(node<T> *p)
    {
        for (int i = 2; i <= sqrt(p->getelem()); i++)
        {
            if (p->getelem() % 2 == 0)
            {
                return 0;
            }
        }
        return p->getelem() > 1;
    }
    void deletePrime()
    {
        node<T> *p = head;
        node<T> *previousX = head;
        while (p != NULL)
        {
            if (prime(p))
            {
                node<T> *r = p;
                if (p == head)
                {
                    head = head->getnext();
                    p = head;
                    previousX = head;
                    num--;
                }
                else
                {
                    previousX->setnext(p->getnext());
                    p = p->getnext();
                    num--;
                }
                free(r);
                continue;
            }
            previousX = p;
            p = p->getnext();
        }
    }
    void delete_duplicate()
    {
        node<T>* current = head;
        while(current->getnext() != NULL)
        {
            node<T>* temp = current;
            node<T>* index = current->getnext();
            while(index != NULL)
            {
                if (current->getelem() == index->getelem())
                {
                    temp->setnext(index->getnext());
                    free(index);
                }
                else{
                    temp = index;
                }
                index = index->getnext();
            }
            current = current->getnext();
        }
    }
    
    LIST<T> merge(LIST<T> a, LIST<T> b){
        LIST<T> mergedlist;
        node<T>* curr1 = a.begin();
        node<T>* curr2 = b.begin();
        while( curr1 !=nullptr && curr2 != nullptr){
            if(curr1->getelem() <= curr2->getelem()){
                mergedlist.push_back(curr1->getelem());
                curr1 = curr1->getnext();
            }
            else{
                mergedlist.push_back(curr2->getelem());
                curr2 = curr2->getnext();
            }
        }
        while( curr1 != nullptr){
            mergedlist.push_back(curr1->getelem());
            curr1 = curr1->getnext();
        }
        while( curr2 != nullptr){
            mergedlist.push_back(curr2->getelem());
            curr2 = curr2->getnext();
        }
        return mergedlist;
    }
    LIST<T> even_list(LIST<T> a){
        LIST<T> evenlist;
        node<T>* curr = a.begin();
        while(curr != nullptr){
            if(curr->getelem() % 2 == 0){
                evenlist.push_back(curr->getelem());
            }
            curr = curr->getnext();
        }
        return evenlist;
    }
    LIST<T> odd_list(LIST<T> a){
        LIST<T> oddlist;
        node<T>* curr = a.begin();
        while(curr != nullptr){
            if(curr->getelem() % 2 != 0){
                oddlist.push_back(curr->getelem());
            }
            curr = curr->getnext();
        }
        return oddlist;
    }
    void in(){
        node<T>* p = head;
        while(p != NULL){
            cout << p->getelem() << " ";
            p = p->getnext();
        }
    }
    
    
    node<T> *begin() { return head; }
    node<T> *tail() { return end->getnext(); }
    iter<T> dau() { return head; }
    iter<T> cuoi() { return end->getnext(); }
};
#endif