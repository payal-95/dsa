#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
using namespace std;

class record
{
private:
    int roll;
    char name[50];
    char contact[10];

public:
    record()
    {
        roll = 5;
    }
    void userIn();
    void disFile();
    void fileWrt(int n);
    void filedlt(int s);
    void fileRead();
    void fileedit(int s);
    void srch(int s);
    void disOut();
};

void record::disOut()
{
    cout << "\n" << roll << "\t" << name << "\t" << contact;
}

void record::userIn()
{
    cout << "\nEnter roll No. of student: ";
    cin >> roll;
    cout << "Enter name of student: ";
    cin >> name;
    cout << "Enter contact number: ";
    cin >> contact;
}

void record::fileWrt(int n)
{
    fstream out;
    out.open("RECORD.DAT", ios::binary | ios::app | ios::out | ios::in);
    record obj;
    for (int i = 0; i < n; i++)
    {
        obj.userIn();
        out.write(reinterpret_cast<char *>(&obj), sizeof(obj));
    }
    out.close();
}

void record::disFile()
{
    ifstream in;
    in.open("RECORD.DAT", ios::binary | ios::in);
    record obj;
    in.seekg(0);
    cout << "\n";
    in.read(reinterpret_cast<char *>(&obj), sizeof(obj));
    while (!in.eof())
    {
        obj.disOut();
        in.read(reinterpret_cast<char *>(&obj), sizeof(obj));
    }
    in.close();
}

void record::srch(int s)
{
    ifstream in;
    in.open("RECORD.DAT", ios::binary | ios::in);
    record obj;
    in.seekg(0);
    in.read(reinterpret_cast<char *>(&obj), sizeof(obj));
    while (!in.eof())
    {
        if (obj.roll == s)
        {
            cout << "Search found";
            obj.disOut();
            break;
        }
        in.read(reinterpret_cast<char *>(&obj), sizeof(obj));
    }
    in.close();
}

void record::filedlt(int s)
{
    ifstream in;
    in.open("RECORD.DAT", ios::binary | ios::in);
    record obj;
    in.seekg(0);
    fstream out;
    out.open("RECORD2.DAT", ios::binary | ios::app | ios::out);
    in.read(reinterpret_cast<char *>(&obj), sizeof(obj));
    while (!in.eof())
    {
        if (obj.roll != s)
        {
            out.write(reinterpret_cast<char *>(&obj), sizeof(obj));
        }
        in.read(reinterpret_cast<char *>(&obj), sizeof(obj));
    }
    in.close();
    out.close();
    remove("RECORD.DAT");
    rename("RECORD2.DAT", "RECORD.DAT");
    cout << "\nRecord deleted successfully.";
}

void record::fileedit(int s)
{
    fstream obj1, obj2;
    obj1.open("RECORD.DAT", ios::binary | ios::in);
    obj1.seekg(0);
    obj2.open("RECORD2.DAT", ios::binary | ios::out | ios::app);
    record r;
    obj1.read(reinterpret_cast<char *>(&r), sizeof(r));
    while (!obj1.eof())
    {
        if (r.roll == s)
        {
            cout << "\nEnter new details:\n";
            r.userIn();
        }
        obj2.write(reinterpret_cast<char *>(&r), sizeof(r));
        obj1.read(reinterpret_cast<char *>(&r), sizeof(r));
    }
    obj1.close();
    obj2.close();
    remove("RECORD.DAT");
    rename("RECORD2.DAT", "RECORD.DAT");
    cout << "\nRecord updated successfully.";
}

int main()
{
    int n;
    cout << "Enter the number of records to be created: ";
    cin >> n;
    record o;
    o.fileWrt(n);
    o.disFile();
    int slct;
    do
    {
        cout << "\n#Menu:\n\t0. Display list\n\t1. Add New Contact\n\t2. Search\n\t3. Delete\n\t4. Edit\n\t5. Exit\n";
        cout << "Select an option: ";
        cin >> slct;
        switch (slct)
        {
        case 0:
            o.disFile();
            break;
        case 1:
            o.fileWrt(1);
            break;
        case 2:
        {
            int s = 0;
            cout << "Enter roll no to search: ";
            cin >> s;
            o.srch(s);
        }
        break;
        case 3:
        {
            int s = 0;
            cout << "Enter roll no to delete: ";
            cin >> s;
            o.filedlt(s);
        }
        break;
        case 4:
        {
            int s;
            cout << "Enter roll no to edit: ";
            cin >> s;
            o.fileedit(s);
        }
        break;
        case 5:
            return 0;
        }
    } while (1);
    return 0;
}

