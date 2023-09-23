#include<bits/stdc++.h>
using namespace std;

class Document{
    public:
        string doc_name, author_name, format;
        int year;
        Document(string doc_name, string author_name, string format, int year):doc_name(doc_name),author_name(author_name),format(format),year(year){}

        void print(){
            cout << "Ten tai lieu:" << doc_name << "\n";
            cout << "Ten tac gia:" << author_name << "\n";
            cout << "Dinh dang tai lieu:" << format << "\n";
            cout << "Nam xuat ban:" << year<< "\n";
        }
};

class Folder{
    public:
    vector<Document> docs;
    string folder_name;
    // Folder(string folder_name):folder_name(folder_name){}
    void print_folder(){
        cout << "Ten folder:" << folder_name << "\n";
    }
    void add_document(Document document){
        docs.push_back(document);
    }
    void remove_doc(const string &doc_name){
        for (auto it = docs.begin(); it != docs.end(); ++it){
            if (it->doc_name == doc_name){
                docs.erase(it);
                cout << "Document name " << doc_name << " has been deleted!" << "\n";
                return ;
            }
        }
        cout << "Document name " << doc_name << " was not found" << "\n";
    }
    void show_doc(){
        for(auto &doc : docs){
            doc.print();
            cout << "\n";
        }
    }
};

class Users{

    vector<Folder> folds;
    public:

    void add_folder(Folder folder){
        folds.push_back(folder);
    }

    void remove_folder(string folder_name){
        for (auto it = folds.begin(); it != folds.end(); ++it){
            if (it->folder_name == folder_name){
                folds.erase(it);
                cout << "Document name " << folder_name << " has been deleted!" << "\n";
                return ;
            }
        }
        cout << "Document name " << folder_name << " was not found" << "\n";
    }
    void show_folder(){
        for(auto &folder : folds){
            folder.print_folder();
            cout << "\n";
        }
    }
};

int main(){
    Folder folders;
    Users users;
    while(true){
        cout<<"\nMenu:"<<endl;
        cout<<"1. Them tai lieu vao thu muc."<<endl;
        cout<<"2. Xoa tai lieu khoi thu muc."<<endl;
        cout<<"3. Hien thi danh sach tai lieu."<<endl;
        cout<<"4. Them thu muc vao Users."<<endl;
        cout<<"5. Xoa thu muc khoi Users."<<endl;
        cout<<"6. Hien thi danh sach thu muc."<<endl;

        int n;
        cout << "Xin moi nhap:";
        cin >> n;
        cin.ignore();

        switch (n)
        {
        case 1:{
            string doc_name, author_name, format;
            int year;
            cout << "Nhap ten:";
            getline(cin, doc_name);
            cout << "Nhap ten tac gia:";
            getline(cin,author_name);
            cout << "Nhap dinh dang:";
            getline(cin,format);
            cout << "Nhap nam xuat ban:";
            cin >> year;
            Document document(doc_name,author_name,format,year);
            folders.add_document(document);
            break;
        }

        case 2:{
            string doc_name;
            cout << "Nhap ten tai lieu can xoa:";
            getline(cin,doc_name);
            folders.remove_doc(doc_name);
            break;
        }

        case 3:{
            cout << "\nDanh sach tai lieu:\n";
            folders.show_doc();
            break;
        }

        case 4:{
            Folder folders;
            cout << "Nhap ten thu muc can them:";
            getline(cin, folders.folder_name);
            users.add_folder(folders);
            break;
        }   
        
        case 5:{
            string folder_name;
            cout << "Nhap ten thu muc can xoa:";
            getline(cin,folders.folder_name);
            users.remove_folder(folder_name);
            break;
        }

        case 6:{
            cout << "\nDanh sach thu muc:\n";
            users.show_folder();
            break;
        }

        default:
            cout << "Lua chon ko hop le." << endl;
        }
        
    }
    return 0;
}