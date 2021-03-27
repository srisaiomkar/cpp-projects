#include <iostream>
using namespace std;

struct patient
{
    string name;
    int specialization_Id;
    bool isUrgent, isActive;
};

int start_the_tool()
{
    int choice;
    cout << "\n**************************************************" << endl
         << "Welcome to the Hospital admin tool!!!" << endl
         << "Please select an option from below" << endl
         << "1. Add a patient" << endl
         << "2. View all the patients for a specialization" << endl
         << "3. Send a patient to doctor for a specialization" << endl
         << "4. Exit" << endl;
    cin >> choice;
    return choice;
}

void add_patient(patient &p)
{
    cout << "Enter the patient's name" << endl;
    cin >> p.name;
    cout << "Which specialization does the patient fall under? (enter the ID)" << endl;
    cin >> p.specialization_Id;
    cout << "Is it urgent (1 or 0)" << endl;
    cin >> p.isUrgent;
    p.isActive = 1;
    cout << "Patient added successfully!" << endl;
}
void print_patients_by_spec(patient patients_list[], int added)
{
    int spec_id;
    string urgency;
    bool is_spec_exist = 0;
    cout << "For which specialization do you want to view the patients?\n";
    cin >> spec_id;
    for (int i = 0; i < added; i++)
    {
        if (patients_list[i].specialization_Id == spec_id)
        {
            is_spec_exist = 0;
        }
        if (patients_list[i].isActive == 1 && patients_list[i].specialization_Id == spec_id && patients_list[i].isUrgent == 1)
        {
            urgency = "Yes";
            cout << patients_list[i].name << " Urgency: "
                 << urgency
                 << "\n\n";
        }
    }
    for (int i = 0; i < added; i++)
    {
        if (patients_list[i].isActive == 1 && patients_list[i].specialization_Id == spec_id && patients_list[i].isUrgent == 0)
        {
            urgency = "No";
            cout << patients_list[i].name << " Urgency: "
                 << urgency
                 << "\n\n";
        }
    }
    if (!is_spec_exist)
        cout << "No patients for this specialization\n";
}

void please_send_patient(patient &p)
{
    cout << "Please send " << p.name << " to the doctor\n";
    bool is_sent;
    while (true)
    {
        cout << "Did you send the patient?";
        cin >> is_sent;
        if (is_sent)
        {
            p.isActive = 0;
            cout << "Thanks for sending the patient\n\n";
            return;
        }
        else
            cout << "Please send " << p.name << " to the doctor\n";
    }
}
void send_patient_to_doctor(patient p[], int added)
{
    cout << "Enter the Specialization Id: ";
    int spec_id;
    cin >> spec_id;
    for (int i = 0; i < added; i++)
    {
        if (p[i].isActive == 1 && p[i].specialization_Id == spec_id && p[i].isUrgent == 1)
        {
            please_send_patient(p[i]);
            return;
        }
    }
    for (int i = 0; i < added; i++)
    {
        if (p[i].isActive == 1 && p[i].specialization_Id == spec_id && p[i].isUrgent == 0)
        {
            please_send_patient(p[i]);
            return;
        }
    }
    cout << "No patients for this specialization\n";
}
int main()
{
    int patients_added = 0;
    patient patients_list[100];
    while (true)
    {
        int choice = start_the_tool();
        if (choice == 1)
        {
            add_patient(patients_list[patients_added]);
            patients_added++;
        }
        else if (choice == 2)
        {
            print_patients_by_spec(patients_list, patients_added);
        }
        else if (choice == 3)
        {
            send_patient_to_doctor(patients_list, patients_added);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << "\nPlease enter a valid option\n\n";
        }
    }
    return 0;
}