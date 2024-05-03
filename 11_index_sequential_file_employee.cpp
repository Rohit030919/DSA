#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct Employee
{
    int employee_id;
    string name;
    string designation;
    float salary;
};

void add_employee()
{
    Employee e;
    cout << "Enter the employee ID: ";
    cin >> e.employee_id;
    cout << "Enter the name of the employee: ";
    cin >> e.name;
    cout << "Enter the designation of the employee: ";
    cin >> e.designation;
    cout << "Enter the salary of the employee: ";
    cin >> e.salary;

    ofstream write;
    write.open("employee_records.txt", ios::app);
    if (!write)
    {
        cerr << "Error opening file." << endl;
        exit(1);
    }
    write << e.employee_id << " " << e.name << " " << e.designation << " " << e.salary << endl;
    write.close();
}

void display_employee(int employee_id)
{
    ifstream read;
    read.open("employee_records.txt");
    if (!read)
    {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    Employee e;
    bool found = false;
    while (read >> e.employee_id >> e.name >> e.designation >> e.salary)
    {
        if (e.employee_id == employee_id)
        {
            cout << "Employee ID: " << e.employee_id << endl;
            cout << "Name: " << e.name << endl;
            cout << "Designation: " << e.designation << endl;
            cout << "Salary: " << e.salary << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Employee record not found!" << endl;
    }
    read.close();
}

void delete_employee(int employee_id)
{
    ifstream read;
    ofstream write;
    read.open("employee_records.txt");
    if (!read)
    {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    write.open("temp.txt");
    if (!write)
    {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    Employee e;
    bool found = false;
    while (read >> e.employee_id >> e.name >> e.designation >> e.salary)
    {
        if (e.employee_id == employee_id)
        {
            found = true;
            continue;
        }
        write << e.employee_id << " " << e.name << " " << e.designation << " " << e.salary << endl;
    }
    read.close();
    write.close();

    if (found)
    {
        if (remove("employee_records.txt") != 0)
        {
            cerr << "Error deleting file." << endl;
            exit(1);
        }
        if (rename("temp.txt", "employee_records.txt") != 0)
        {
            cerr << "Error renaming file." << endl;
            exit(1);
        }
        cout << "Employee record deleted successfully!" << endl;
    }
    else
    {
        cout << "Employee record not found!" << endl;
        remove("temp.txt");
    }
}

int main()
{
    char choice;
    do
    {
        add_employee();
        cout << "Do you want to add another employee? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    int search_id;
    cout << "Enter the employee ID to search: ";
    cin >> search_id;
    cout << "Displaying employee details for ID: " << search_id << endl;
    display_employee(search_id);

    int delete_id;
    cout << "Enter the employee ID to delete: ";
    cin >> delete_id;
    cout << "Deleting employee with ID: " << delete_id << endl;
    delete_employee(delete_id);

    return 0;
}

