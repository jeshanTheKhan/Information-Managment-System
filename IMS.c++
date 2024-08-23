//Information Managment System
#include<bits/stdc++.h>

using namespace std;
// Function to check administrator login
bool isAdminLogin()
{
    string username, password;
    cout << "Enter Administrator Username: ";
    cin >> username;
    cout << "Enter Administrator Password: ";
    cin >> password;

// Check if username and password match
    return (username == "admin" && password == "password");
}

// Function to add information
void addInformation()
{
    ofstream file("student_info.txt", ios::app);
    if (!file)
    {
        cout << "Error opening file for writing." << endl;
        return;
    }

// Function to show information
void showInformation()
{
    ifstream file("student_info.txt");
    if (!file)
    {
        cout << "No information available." << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

// Function to clear information
void clearInformation()
{
    ofstream file("student_info.txt", ios::trunc);
    if (!file)
    {
        cout << "Error clearing file." << endl;
        return;
    }

    file.close();
    cout << "Information cleared successfully!" << endl;
}


int main()
{
    if (!isAdminLogin())
    {
        cout << "Authentication failed. Exiting..." << endl;
        return 1;
    }

    int choice;
    do
    {
        cout << "\nSecurity System Menu:\n";
        cout << "1. Add Information\n";
        cout << "2. Show Information\n";
        cout << "3. Clear Information\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addInformation();
            break;
        case 2:
            showInformation();
            break;
        case 3:
            clearInformation();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
