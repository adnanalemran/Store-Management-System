#include <conio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

// class dept contains main function to perform add, update,
// view, delete, and sell operations
class dept {
public:
    void control_panel();
    void add_item();
    void display_item();
    void check_item();
    void update_item();
    void delete_item();
    void sell_item();
};

void dept::control_panel()
{
    system("cls");

    system("Color 0A");
    cout << "**********************************************"
            "**********************************";
    cout << "\n\n\t\t\t     Store Management System";
    cout << "\n\n\t\t\t\t Control Panel\n";
    cout << "\n********************************************"
            "************************************\n";
    cout << "\n\n 1. Add New Item";
    cout << "\n 2. Display Items";
    cout << "\n 3. Check Specific Item";
    cout << "\n 4. Update Item";
    cout << "\n 5. Delete Item";
    cout << "\n 6. Sell Item";  // New option for selling an item
    cout << "\n 7. Exit";
}

void dept::add_item()
{
    system("cls");
    system("Color 0A");
    fstream file;
    int no_item, Item_Id;
    string itm_name;
    string c_name;
    cout << "\n\n\t\t\t\t Add New Item: \n";
    cout << "----------------------------------------------"
            "----------------------------\n";
    cout << " Item Code : ";
    cin >> Item_Id;
    cout << "----------------------------------------------"
            "----------------------------\n";
    cout << "\n\n\t\t\t Item Name: ";
    cin >> itm_name;
    cout << "\n\n Company Name: ";
    cin >> c_name;
    cout << "\n\n\t\t\t No. Of Item: ";
    cin >> no_item;
    file.open("D://item.txt", ios::out | ios::app);
    file << " " << Item_Id << " " << itm_name << " " << c_name << " " << no_item << "\n";
    cout << "=============================================="
            "============================"
         << endl;
    file.close();
}

void dept::display_item()
{
    system("cls");
    system("Color 0A");
    fstream file;
    int no_item, Item_code;
    string itm_name;
    string c_name;
    file.open("D://item.txt", ios::in);
    if (!file) {
        cout << "File Opening Error....";
    }
    else {
        cout << "------------------------------------------"
                "-----------------\n";
        cout << " Item Code         Item             "
                "Company No. of Item\n";
        cout << "------------------------------------------"
                "-----------------"
             << endl;
        while (file >> Item_code >> itm_name >> c_name >> no_item) {
            cout << " " << Item_code << "                " << itm_name << "            " << c_name << "\t         " << no_item << "\n";
        }
        cout << "=========================================="
                "================="
             << endl;
        file.close();
    }
}

void dept::check_item()
{
    system("cls");
    system("Color 0A");
    fstream file;
    int count = 0;
    int Item_code;
    int no_item;
    string itm_name, c_name;
    cout << "\n\n\t\t\t\t Check Specific Product\n";
    cout << "----------------------------------------------"
            "----------------------------\n";
    cout << "\n\n\t\t\t Enter Item Code to be Searched: ";
    cin >> Item_code;
    cout << "----------------------------------------------"
            "----------------------------\n";
    file.open("D://item.txt", ios::in);
    if (!file) {
        cout << "File Opening Error....";
    }
    else {
        while (file >> Item_code >> itm_name >> c_name >> no_item) {
            if (Item_code == Item_code) {
                count++;
                cout << "\n\n\t\t\t Item Code: " << Item_code;
                cout << "\n\n\t\t\t Item Name: " << itm_name;
                cout << "\n\n\t\t\t Item Company: " << c_name;
                cout << "\n\n\t\t\t Item No. of Items: " << no_item;
            }
        }
        if (count == 0) {
            cout << "\n\n\t\t\t Item Code Not Found....";
        }
        file.close();
    }
}

void dept::update_item()
{
    system("cls");
    system("Color 0A");
    fstream file, temp;
    int no_item, Item_code, upd_code;
    string itm_name;
    string c_name;
    cout << "\n\n\t\t\t Update Item: \n";
    cout << "----------------------------------------------"
            "----------------------------\n";
    cout << "\n\n\t\t\t Enter Item Code to Update: ";
    cin >> upd_code;
    cout << "----------------------------------------------"
            "----------------------------\n";
    file.open("D://item.txt", ios::in);
    temp.open("D://temp.txt", ios::out);
    bool itemFound = false;
    while (file >> Item_code >> itm_name >> c_name >> no_item) {
        if (upd_code == Item_code) {
            itemFound = true;
            cout << "\n\n\t\t\t Enter New Details: ";
            cout << "\n\n Item Code : " << Item_code;
            cout << "\n\n\t\t\t Item Name: ";
            cin >> itm_name;
            cout << "\n\n\t\t\t Company Name: ";
            cin >> c_name;
            cout << "\n\n\t\t\t No. Of Item: ";
            cin >> no_item;
        }
        temp << " " << Item_code << " " << itm_name << " " << c_name << " " << no_item << "\n";
    }
    if (!itemFound) {
        cout << "\n\n\t\t\t Item Not Found....";
    }
    file.close();
    temp.close();
    remove("D://item.txt");
    rename("D://temp.txt", "D://item.txt");
}

void dept::delete_item()
{
    system("cls");
    system("Color 0A");
    fstream file, temp;
    int no_item, Item_code, del_code;
    string itm_name;
    string c_name;
    cout << "\n\n\t\t\t Delete Item: \n";
    cout << "----------------------------------------------"
            "----------------------------\n";
    cout << "\n\n\t\t\t Enter Item Code to Delete: ";
    cin >> del_code;
    cout << "----------------------------------------------"
            "----------------------------\n";
    file.open("D://item.txt", ios::in);
    temp.open("D://temp.txt", ios::out);
    bool itemFound = false;
    while (file >> Item_code >> itm_name >> c_name >> no_item) {
        if (del_code == Item_code) {
            itemFound = true;
            cout << "\n\n\t\t\t Item Deleted Successfully....";
        }
        else {
            temp << " " << Item_code << " " << itm_name << " " << c_name << " " << no_item << "\n";
        }
    }
    if (!itemFound) {
        cout << "\n\n\t\t\t Item Not Found....";
    }
    file.close();
    temp.close();
    remove("D://item.txt");
    rename("D://temp.txt", "D://item.txt");
}

void dept::sell_item()
{
    system("cls");
    system("Color 0A");
    fstream file, temp;
    int no_item, Item_code, sell_code, sell_quantity;
    string itm_name;
    string c_name;
    cout << "\n\n\t\t\t Sell Item: \n";
    cout << "----------------------------------------------"
            "----------------------------\n";
    cout << "\n\n\t\t\t Enter Item Code to Sell: ";
    cin >> sell_code;
    cout << "----------------------------------------------"
            "----------------------------\n";
    file.open("D://item.txt", ios::in);
    temp.open("D://temp.txt", ios::out);
    bool itemFound = false;
    while (file >> Item_code >> itm_name >> c_name >> no_item) {
        if (sell_code == Item_code) {
            itemFound = true;
            cout << "\n\n\t\t\t Enter Quantity to Sell: ";
            cin >> sell_quantity;
            if (sell_quantity <= no_item) {
                no_item -= sell_quantity;
                cout << "\n\n\t\t\t Sale Successful....";
            }
            else {
                cout << "\n\n\t\t\t Insufficient Stock....";
            }
        }
        temp << " " << Item_code << " " << itm_name << " " << c_name << " " << no_item << "\n";
    }
    if (!itemFound) {
        cout << "\n\n\t\t\t Item Not Found....";
    }
    file.close();
    temp.close();
    remove("D://item.txt");
    rename("D://temp.txt", "D://item.txt");
}

int main()
{
    int ch;
    dept d;
    do {
        d.control_panel();
        cout << "\n\n\n\t\t\t Enter Choice [1-7] ";
        cin >> ch;
        switch (ch) {
        case 1:
            d.add_item();
            break;
        case 2:
            d.display_item();
            break;
        case 3:
            d.check_item();
            break;
        case 4:
            d.update_item();
            break;
        case 5:
            d.delete_item();
            break;
        case 6:
            d.sell_item();
            break;
        case 7:
            exit(0);
        }
        getch();
    } while (ch != 7);
    return 0;
}
