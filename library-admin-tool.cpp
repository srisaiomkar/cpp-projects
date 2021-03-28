#include <iostream>
#include <string>
using namespace std;

struct user
{
    int id;
    string name;
    string email;
    bool is_active = 1;
    void print()
    {
        cout << id << " " << name << " " << email << " " << is_active << endl;
    }
};
struct book
{
    int id;
    string name;
    int quantity, users_count;
    user users[100];

    book()
    {
        id = 0, name = "", quantity = 0, users_count = 0;
    }
    void print()
    {
        cout << id << " " << name << " " << quantity << endl;
    }
    bool is_substring(string &search_string)
    {
        bool is_substring = true;
        if ((int)search_string.size() > (int)name.size())
        {
            is_substring = false;
            return is_substring;
        }
        for (int i = 0; i <= (int)name.size() - (int)search_string.size(); i++)
        {
            is_substring = true;
            for (int j = 0; j < (int)search_string.size(); j++)
            {
                if (name[i + j] != search_string[j])
                {
                    is_substring = false;
                    break;
                }
            }
            if (is_substring)
                return is_substring;
        }
        return is_substring;
    }
    bool starts_with(string &prefix)
    {
        bool does_it_start = true;
        if ((int)prefix.size() > (int)name.size())
        {
            does_it_start = false;
        }
        for (int i = 0; i < (int)prefix.size(); i++)
        {
            if (name[i] != prefix[i])
            {
                does_it_start = false;
                break;
            }
        }
        return does_it_start;
    }
};
struct library_system
{
    book books[100];
    user users[100];
    int books_count, users_count;
    library_system()
    {
        books_count = 0;
        users_count = 0;
    }
    void add_user()
    {
        user u;
        cout << "Enter the name of the user\n";
        // getline(cin, b.name);
        cin >> u.name;
        cout << "Enter the email of the user\n";
        cin >> u.email;
        for (int i = 0; i < users_count; i++)
        {
            if (users[i].name == u.name)
            {
                cout << "User already exists\nThe User Id of the user is " << u.id << endl;
                return;
            }
        }
        u.id = users_count + 1;
        users[users_count] = u;
        users_count++;
    }
    void add_a_book()
    {
        book b;
        cout << "Enter the name of the book\n";
        // getline(cin, b.name);
        cin >> b.name;
        cout << "How many quantity of this book are you adding\n";
        cin >> b.quantity;
        for (int i = 0; i < books_count; i++)
        {
            if (books[i].name == b.name)
            {
                books[i].quantity += b.quantity;
                return;
            }
        }
        b.id = books_count + 1;
        books[books_count] = b;
        books_count++;
    }
    void print_books()
    {
        cout << "Books List:\n";
        for (int i = 0; i < books_count; i++)
        {
            books[i].print();
        }
    }
    void print_users()
    {
        cout << "Users List:\n";
        for (int i = 0; i < users_count; i++)
        {
            users[i].print();
        }
    }
    void search_books(bool isPrefix = false)
    {
        string search_term;
        bool match_count = 0, is_first_book = 1;
        cout << "Enter the search term: \n";
        cin >> search_term;
        if (isPrefix)
        {
            for (int i = 0; i < books_count; i++)
            {
                if (books[i].starts_with(search_term))
                {
                    if (is_first_book)
                    {
                        cout << "Books Available:\n";
                        is_first_book = false;
                    }
                    cout << books[i].name << endl;
                    match_count = 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < books_count; i++)
            {
                if (books[i].is_substring(search_term))
                {
                    if (is_first_book)
                    {
                        cout << "Books Available:\n";
                        is_first_book = false;
                    }
                    cout << books[i].name << endl;
                    match_count = 1;
                }
            }
        }
        if (!match_count)
            cout << "No books found!\n";
    }
    void give_book_to_user()
    {
        string book_name, user_name;
        bool user_exists = false, book_exists = false;
        cout << "Enter the name of the book\n";
        cin >> book_name;
        for (int i = 0; i < books_count; i++)
        {
            if (books[i].name == book_name && books[i].quantity > 0)
            {
                cout << "The books is available\nWhom do you to want to give the book to?\n";
                cin >> user_name;
                for (int j = 0; j < users_count; j++)
                {
                    if (users[j].name == user_name)
                    {
                        books[i].quantity--;
                        books[i].users[books[i].users_count] = users[j];
                        books[i].users_count++;
                        cout << "Please give the book to " + users[j].name;
                        return;
                    }
                }
                if (!user_exists)
                {
                    cout << "The user does not exist. Please add the user and try again";
                    return;
                }
                book_exists = 1;
            }
        }
        if (!book_exists)
        {
            cout << "Sorry! The book is unavailable\n";
        }
    }
    void collect_book_from_user()
    {
        string user_name, book_name;
        cout << "Enter the name of the book\n";
        cin >> book_name;
        cout << "who is returning the book?\n";
        cin >> user_name;
        for (int i = 0; i < books_count; i++)
        {
            if (books[i].name == book_name)
            {
                for (int j = 0; i < books[i].users_count; j++)
                {
                    if (books[i].users[j].name == user_name)
                    {
                        books[i].users[j].is_active = 0;
                        books[i].quantity++;
                        cout << "Book successfully recieved!";
                        return;
                    }
                }
            }
        }
    }
    void find_users_of_book()
    {
        string book_name;
        cout << "Enter the name of the book\n";
        cin >> book_name;
        for (int i = 0; i < books_count; i++)
        {
            if (books[i].name == book_name)
            {
                for (int j = 0; j < books[i].users_count; j++)
                {
                    if (books[i].users[j].is_active)
                    {
                        cout << books[i].users[j].name << " ";
                    }
                }
            }
        }
    }
    int menu()
    {
        int choice;
        cout << "\n\n**********************************\n"
             << "Welcome to the Library Admin tool!!!\nPlease enter your choice:\n"
             << "1. Add a book" << endl
             << "2. Search a book by its prefix" << endl
             << "3. Search a book by its substring" << endl
             << "4. Print all the books" << endl
             << "5. Add a User" << endl
             << "6. Give book to the User" << endl
             << "7. Collect book from the User" << endl
             << "8. Print all the Users" << endl
             << "9. Find users who borrowed a book" << endl
             << "10. Exit the system" << endl;
        cin >> choice;
        return choice;
    }

    void start()
    {
        while (true)
        {
            int choice = menu();
            switch (choice)
            {
            case 1:
                add_a_book();
                break;
            case 2:
                search_books(true);
                break;
            case 3:
                search_books();
                break;
            case 4:
                print_books();
                break;
            case 5:
                add_user();
                break;
            case 6:
                give_book_to_user();
                break;
            case 7:
                collect_book_from_user();
                break;
            case 8:
                print_users();
                break;
            case 9:
                find_users_of_book();
                break;
            case 10:
                cout << "Thanks for using our system\nPlease come back again!\n";
                break;
            default:
                cin.clear();
                cin.ignore();
                cout << "Please enter a valid choice\n";
                break;
            }
        }
    }
};
int main()
{
    library_system l;
    l.start();
    return 0;
}