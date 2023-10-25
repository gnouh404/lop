#include "node_iterator.cpp"
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
    void insert(T x, int position)
    {
        
        node<T> *new_node = new node<T>;
        new_node->setelem(x);
        if (!num){
            push_front(x);
        }
            
        else
        {
            node<T>* current = head;
            for(int i = 0; i < position - 1; i++){
                if(current->getnext() == NULL){
                    cout << "Vi tri vuot qua kich thuoc cua danh sach lk";
                }
                current = current->getnext();
            }
            new_node->setnext(current);
            current->setnext(new_node);
            num++;
            // temp->setnext(p->getnext());
            // p->setnext(temp);
            // temp->setelem(x);
            // if (end == p)
            //     end = temp;
            // num++;
        }
    }
    void push_back(T x)
    {
        if(num == 0) push_front(x);
        else{
            node<T> *tmp = new node<T>;
            tmp->setelem(x);
            tmp->setnext(NULL);
            end->setnext(tmp);
            end = end->getnext();
            num++;    
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
        temp = head->getNext();
        head = temp;
        num--;
    }
    void in(){
        while(this->head != this->end){
            cout << this->head->getelem();
            this->head = this->head->getnext();
        }
    }
    void erase(node<T> *p)
    {
        node<T> *temp = p->getNext();
        p = temp->getNext();
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
    
    iter<T> dau() { return head; }
    iter<T> cuoi() { return end->getnext(); }
};
#endif