#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define FILE "db.dat"

using namespace std;

class Item {
    private:
        int Code;
        char Name[80];
        int Quantity;
        double Cost;
    public:
        void Create();
        int Search(int);
        void Modify(int);
        void Delete(int);
        void GetData();
        void Display();
        void Arrange();
        void Purchase(int, int);
        friend bool compare(Item, Item);
};

bool compare(Item i1, Item i2) {
    return i1.Code < i2.Code;
}

void Item::GetData() {
    cout << "Enter Item Details\nEnter Item Code: ";
    cin >> Code;
    cout << "Enter Item Name: ";
    cin >> Name;
    cout << "Enter Item Quantity: ";
    cin >> Quantity;
    cout << "Enter Item Cost: ";
    cin >> Cost;
}

void Item::Create() {
    ofstream file (FILE, ios::binary | ios::app);
    GetData();
    file.write((char*)this, sizeof(Item));
    file.close();
}

int Item::Search(int i) {
    int index = 0;
    ifstream file(FILE, ios::binary);
    while (file.read((char*)this, sizeof(Item)))
    {
        if (Code == i)
        {
            file.close();
            return index;
        }
        index++;
    }
    file.close();
    return -1;
}

void Item :: Display() {
    cout << "Item Code: " << Code << "\n";
    cout << "Item Name: " << Name << "\n";
    cout << "Item Quantity: " << Quantity << "\n";
    cout << "Item Cost: " << Cost << "\n";
}

void Item::Modify(int i) {
    int index = Search(i);
    if (index == -1)
    {
        cout << "Item does not exist.";
        return;
    }
    ofstream file(FILE, ios::out | ios::binary);
    file.seekp(sizeof(Item) * index, ios::beg);
    GetData();
    file.write((char*)this, sizeof(Item));
    file.close();
    cout << "Item has been modified successfully";
}

void Item::Delete(int i) {
    int index = Search(i);
    if (index == -1)
    {
        cout << "Item does not exist";
        return;
    }
    fstream file(FILE, ios::out | ios::binary | ios::in);
    vector<Item> Items;
    while (file.read((char*)this, sizeof(Item)))
    {
        if (index != 0)
        {
            Items.push_back(*this);
        }
        index--;
    }
    file.close();
    file.open(FILE, ios::out | ios::trunc);
    for (Item it: Items) {
        file.write((char*) &it, sizeof(Item));
    }
    file.close();
    cout << "Item has been deleted successfully\n";
}

void Item::Arrange() {
    vector<Item> Items;
    fstream file(FILE, ios::in | ios::binary);
    while (file.read((char*)this, sizeof(Item))) 
    {
        Items.push_back(*this);
    }    
    sort(Items.begin(), Items.end(), compare);
    file.close();
    file.open(FILE, ios::out | ios::trunc);
    for (Item it: Items) {
        file.write((char*)&it, sizeof(Item));
    }
    file.close();
}

void Item::Purchase(int C, int Buy) {
    int index = Search(C);
    if (index == -1)
    {
        cout << "Item does not exist";
    }
    if (Quantity >= Buy)
    {
        Quantity -= Buy;
    }
    else
    {
        cout << "Required quantity is not available";
        return;
    }
    fstream file(FILE, ios::in | ios::out | ios::binary);
    file.seekp(index * sizeof(Item), ios::beg);
    file.write((char*)this, sizeof(Item));
    file.close();
    cout << "Item was successfully purchased";
}

int main() {
    while (true)
    {
        Item i;
        int n;
        cout << "\nMENU\n" << "1. Create Item\n2. Search Item\n3. Modify Item\n4. Delete Item\n5. Purchase Item\n6. Exit\n\nEnter Choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            i.Create();
            cout << "New Item was successfully created\n";
            break;
        case 2: {
            cout << "Enter Id of Item to be Searched: ";
            cin >> n;
            int index = i.Search(n);
            if (index == -1)
            {
                cout << "Item does not exist\n";
                break;
            }
            i.Display();
            break;
        }
        case 3:
            cout << "Enter Id of Item to be modified: ";
            cin >> n;
            i.Modify(n);
            break;
        case 4:
            cout << "Enter Id of Item to be deleted: ";
            cin >> n;
            i.Delete(n);
            break;
        case 5: {
            cout << "Enter Id of Item to be purchased: ";
            cin >> n;
            cout << "Enter quantity of item to be purchased: ";
            int q;
            cin >> q; 
            i.Purchase(n, q);
            break;
        }
        case 6:
            exit(0);
        default:
            break;
        } 
    }
}