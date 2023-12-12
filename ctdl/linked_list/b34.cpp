#include "linked_list.cpp"

using namespace std;



int main(){
    LIST<int> myListA;
    LIST<int> myListB;
    LIST<int> merged_list;
    LIST<int> even_listA;
    LIST<int> odd_listA;
    LIST<int> even_listB;
    LIST<int> odd_listB;
    while(true){
        cout<<"\nMenu:"<<endl;
        cout<<"1. Tao danh sach A tang dan."<<endl;
        cout<<"2. Tao danh sach B tang dan."<<endl;
        cout<<"3. Tron 2 danh sach."<<endl;
        cout<<"4. Tach danh sach A thanh chan, le."<<endl;
        cout<<"5. Hien thi day so A."<<endl;
        cout<<"6. Hien thi day so B."<<endl;
        cout<<"7. Hien thi day so tron."<<endl;
        cout<<"8. Hien thi day so A chan."<<endl;
        cout<<"9. Hien thi day so A le."<<endl;
        cout<<"10. Hien thi day so B chan."<<endl;
        cout<<"11. Hien thi day so B le."<<endl;
        cout<<"12. Thoat."<<endl;
        int n;
        cout << "\nXin moi nhap:";
        cin >> n;
        switch (n)
        {
        case 1:{
            cout << "Nhap cac so nguyen (nhap -1 de ket thuc):" << endl;
            int num;
            while (true) {
                cin >> num;
                if (num == -1) {
                    break;
                }
            myListA.insertInOrder(num);
            }
            break;
        }
        case 2:{
            cout << "Nhap cac so nguyen (nhap -1 de ket thuc):" << endl;
            int num;
            while (true) {
                cin >> num;
                if (num == -1) {
                    break;
                }
            myListB.insertInOrder(num);
            } 
            break;   
        }
        case 3:{
            merged_list = merge(myListA,myListB);
            break;
        }
        case 4:{
            even_listA = even_list(myListA);
            odd_listA = odd_list(myListA);
            break;
        }
        case 5:{
            myListA.in();
            break;
        }
        case 6:{
            myListB.in();
            break;
        }
        case 7:{
            merged_list.in();
            break;
        }
        case 8:{
            even_listA.in();
            break;
        }
        case 9:{
            odd_listA.in();
            break;
        }
        case 10:{
            even_listB.in();
            break;
        }
        case 11:{
            odd_listB.in();
            break;
        }
        case 12:{
            return 0;
        }
        default:{
            cout << "\nLua chon khong hop le";
        }
        }
    }

    return 0;
}
