#include "linked_list.cpp"
#include <math.h>
#ifndef _dayso_CPP
#define _dayso_CPP
using namespace std;
bool cnt = true;
template <class T>
class dayso{
    LIST<T> a;
    public:
    dayso(){}
    dayso(LIST<T> a){
        this->a = a;
    }
    void create_list(){
        cout << "\nTao danh sach so(nhap den khi gap dau # se ket thuc tao danh sach):";
        while(true){
            int inp;
            if(cin >> inp){
                a.push_back(inp);
            }
            else{
                cin.clear();
                cin.ignore(1, '\n');
                break;
            }
        }
    }
    void add(){
        if(a.size() == 0) cout << "\nBan chua tao danh sach. Vui long chon 1\n";
        else{
            cout << "Hien tai danh sach co " << a.size() << " phan tu.\n";
            cout << "Ban muon chon vi tri se them?\n";
            cout << "\tChon vi tri muon them: ";
            int n;
            cin >> n;
            while (n < 1 || n > a.size() + 1)
            {
                cout << "Khong hop le, vui long nhap lai: ";
                cin >> n;
            }
            T x;
            cout << "Nhap gia tri phan tu muon them:";
            cin >> x;
            if(n == 1) a.push_front(x);
            else if(n == a.size() + 1) a.push_back(x);
            else{
                a.insert(x, n);
            }
        }
        
    }
    
    void check_equal(){
        if(a.size() == 0) cout << "\nBan chua tao danh sach. Vui long chon 1\n";
        else{
            cout << "Nhap so k:";
            T k;
            cin >> k;
            node<T> *current = a.begin();
            int cnt = 0;
            int found = 0;
            while (current != NULL && cnt < a.size())
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
        
    }
    void check_3_even(){
        if(a.size() == 0) cout << "\nBan chua tao danh sach. Vui long chon 1\n";
        else{
            node<T>* p = a.begin();
            bool check = false;
            if(a.size() >= 3){
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
               
    }
    void sort(){
        if(a.size() == 0) cout << "\nBan chua tao danh sach. Vui long chon 1\n";
        else{
            for (node<T> *p = a.begin(); p->getnext() != NULL; p = p->getnext())
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
    void delete_prime(){
        if(a.size() == 0) cout << "\nBan chua tao danh sach. Vui long chon 1\n";
        else{
           a.deletePrime(); 
        }
        
    }
    void delete_duplicate(){
        if(a.size() == 0) cout << "\nBan chua tao danh sach. Vui long chon 1\n";
        else{
           a.delete_duplicate(); 
        }
        
    }
    void display(){
        if(a.size() == 0) cout << "\nBan chua tao danh sach. Vui long chon 1\n";
        else{
            node<T>* p = a.begin();
            while(p != NULL){
                cout << p->getelem() << " ";
                p = p->getnext();
            }
        }
        
    }
};
#endif