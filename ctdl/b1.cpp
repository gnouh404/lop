#include<bits/stdc++.h>
using namespace std;

class Contact{
        
    public:
        string name, phone_number, email;
        Contact(string name, string phone_number, string email):name(name), phone_number(phone_number), email(email){}

         
        void print(){
            cout << "Ho ten:" << name << "\n";
            cout << "So dien thoai:" <<phone_number << "\n";
            cout << "Email:" << email << "\n";
        }
        // friend istream &operator>>(istream &cin, Contact &a){
        //     cout << "Nhap ho ten:";
        //     cin.ignore();
        //     getline(cin, a.ht);
        //     cout << "Nhap sdt:";
        //     cin >> a.sdt;
        //     cout << "Nhap email:";
        //     cin.ignore();
        //     getline(cin,a.email);
        //     return cin;
        // }
        // friend ostream &operator<<(ostream &cout, const Contact &a){
        //     cout << "Ho ten:" << a.ht << "\n";
        //     cout << "So dien thoai:" << a.sdt << "\n";
        //     cout << "Email:" << a.email << "\n";
        //     return cout;
        // }
        // string get_sdt(){
        //     return this->sdt;
        // }
        
};
class AddressBook
{
        vector<Contact> contacts;
    public:
        // friend istream &operator>>(istream &cin, AddressBook &lst){
        //     int n;
        //     cout << "So lien he:"; cin >> lst.n;
        //     lst.v.resize(lst.n);
        //     for (int i =0; i < lst.n; i++){
        //         cin >> lst.v[i];
        //     }
        //     return cin;
        // }
        // friend ostream &operator<<(ostream &cout, const AddressBook &lst){
        //     for (int i=0;i<lst.n;i++){
		// 	    cout << lst.v[i];
		// }
        // return cout;
        // }
        void add_contact(Contact contact){
            contacts.push_back(contact);
        }

        void delete_contact(string phone_number){
            for (auto it = contacts.begin(); it != contacts.end(); ++it){
                if ( it->phone_number == phone_number){
                    contacts.erase(it);
                    cout << "Contact with phone number " << phone_number << " has been deleted!" << "\n";
                    return ;
                } 
                else cout << "Contact with phone number " << phone_number << " was not found" << "\n";
            }
            
        }

        void found( string phone_number){
            for (auto &contact : contacts){
                if ( contact.phone_number == phone_number){
                    contact.print();
                    return ;
                }  
            }
            cout << "Contact with phone number " << phone_number << " was not found";
        }

        void show_contacts(){
            for(auto &contact : contacts){
                contact.print();
                cout << endl;
                return;
            }
        }
};

int main(){
    AddressBook addressbook;
    while(true){
        cout<<"\nMenu:"<<endl;
        cout<<"1. Tao lien he moi."<<endl;
        cout<<"2. Tim kiem lien he."<<endl;
        cout<<"3. Xoa lien he."<<endl;
        cout<<"4. Hien thi tat ca lien he."<<endl;
        cout<<"5. Thoat."<<endl;

        int n;
        cout << "Xin moi nhap:";
        cin >> n;
        cin.ignore();
        switch(n)
        {
        case 1:{
            string name, phone_number, email;
            cout << "Nhap ho ten:";
            getline(cin, name);
            cout << "Nhap sdt:";
            cin >> phone_number;
            cout << "Nhap email:";
            cin.ignore();
            getline(cin,email);
            Contact contact(name,phone_number,email);
            addressbook.add_contact(contact);
            break;
        }

        case 2:{
            string phone_number;
            cout << "Nhap sdt cua lien he can tim:";
            cin >> phone_number;
            addressbook.found(phone_number);
            break;
        }

        case 3:{
            string phone_number;
            cout << "Nhap so dien thoai cua lien he can xoa:";
            cin >> phone_number;
            addressbook.delete_contact(phone_number);
            break;
        }

        case 4:{
            cout << "\nDanh sach lien he:\n";
            addressbook.show_contacts();
            break;
        }   
        
        case 5:{
            return 0;
        }

        default:
            cout << "Lua chon ko hop le." << endl;
        }

    }
    return 0;
}