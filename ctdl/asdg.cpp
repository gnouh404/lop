#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Contact{
    public:
    string full_name;
    string phone_number;
    string email;
    Contact(string name, string phone, string email):full_name(name), phone_number(phone), email(email) {}
    void profile(){
        cout<<"Ho va ten:"<<full_name<<endl;
        cout<<"So dien thoai:"<<phone_number<<endl;
        cout<<"Email:"<<email<<endl;
    }
};
class AddressBook{
    vector<Contact> contacts;
    public:
    void add_contact(Contact contact){
        contacts.push_back(contact);
    }
    void remove_contact(string phone_number){
        for(auto it = contacts.begin(); it!= contacts.end(); ++it){
            if(it->phone_number == phone_number){
                contacts.erase(it);
                cout<<"Contact with phone number "<<phone_number<<" removed"<<endl;
                return;
            }
        }
        cout<<"No contact with phone number "<<phone_number<<" found"<<endl;
    }
    void search_contact(string phone_number){
        for(auto& contact : contacts){
            if(contact.phone_number == phone_number){
                contact.profile();
                return ;
            }
        }
        cout<<"No contact with phone number "<<phone_number<<" found"<<endl;
    }
    void show_contact(){
        for(auto& contact:contacts){
            contact.profile();
            cout<<endl;
            return;
        }
    }
};
int main(){
    AddressBook addressbook;
    while (true)
    {
        cout<<"\nMenu"<<endl;
        cout<<"1. Tao lien he moi."<<endl;
        cout<<"2. Tim kiem lien he."<<endl;
        cout<<"3. Xoa lien he."<<endl;
        cout<<"4. Hien thi tat ca lien he."<<endl;
        cout<<"5. Thoat."<<endl;

        int n;
        cin>>n;
        cin.ignore();

        switch (n)
        {
        case 1:{
            string name,phone,email;
            cout<<"Nhap ho va ten lien he:";
            getline(cin,name);
            cout<<"Nhap so dien thoai lien he:";
            getline(cin,phone);
            cout<<"Nhap email lien he:";
            getline(cin,email);
           
            Contact new_contact(name,phone,email);
            addressbook.add_contact(new_contact);
            break;
        }            
        case 2:{
            string phone;
            cout<<"Nhap so dien thoai can tim:";
            cin>>phone;
            addressbook.search_contact(phone);
            break;
        }           
        case 3:{
            string phone;
            cout<<"Nhap so dien thoai can xoa:";
            cin>>phone;
            addressbook.remove_contact(phone);
            break;
        }        
        case 4:{
            cout<<"Danh sach tat ca cac lien he:"<<endl;
            addressbook.show_contact();
            break;
        }   
        case 5:
            return 0;
        default:
            cout<<"Lua chon khong hop le."<<endl;
        }
    }
    return 0;
    
}