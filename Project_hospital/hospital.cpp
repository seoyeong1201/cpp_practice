#include <iostream>
#include <cstring>
using namespace std;

enum {GENERAL=1, HEART, LUNG, PLASTIC, EXIT};
enum {NORMAL, URGENT};

class Patient
{
private:
    char* firstName;
    char* lastName;
    char* bloodGroup;
    char* gender;
    int age;
    char* mobileNumber;
    Patient* nextPatient;
public:
    Patient(char* fName, char* lName, char* bGroup, char* gender, int age, char* mNumber)
    :age(age), nextPatient(NULL)
    {
        this->firstName=new char[strlen(fName)+1];
        this->lastName=new char[strlen(lName)+1];
        this->bloodGroup=new char[strlen(bGroup)+1];
        this->gender=new char[strlen(gender)+1];
        this->mobileNumber=new char[strlen(mNumber)+1];
        strcpy(this->firstName, fName);
        strcpy(this->lastName, lName);
        strcpy(this->bloodGroup, bGroup);
        strcpy(this->gender, gender);
        strcpy(this->mobileNumber, mNumber);
    }
    virtual void showInfo()
    {
        cout<<"first name: "<<firstName<<endl;
        cout<<"last name: "<<lastName<<endl;
        cout<<"blood group: "<<bloodGroup<<endl;
        cout<<"gender: "<<gender<<endl;
        cout<<"age: "<<age<<endl;
        cout<<"mobile number: "<<mobileNumber<<endl;
    }
    void putNextPatient(Patient* nextPatient)
    {
        this->nextPatient=nextPatient;
    }
    Patient* getNextPatient() const
    {
        return this->nextPatient;
    }
    ~Patient()
    {
        delete[] firstName;
        delete[] lastName;
        delete[] bloodGroup;
        delete[] gender;
        delete[] mobileNumber;
    }
};

class NormalPatient : public Patient
{
private:
    // int state;
public:
    NormalPatient(char* fName, char* lName, char* bGroup, char* gender, int age, char* mNumber)
    : Patient(fName, lName, bGroup, gender, age, mNumber)
    {}
    void showInfo()
    {
        Patient::showInfo();
        cout<<"state: Normal"<<endl;
    }
};

class UrgentPatient : public Patient
{
private:
    // int state;
public:
    UrgentPatient(char* fName, char* lName, char* bGroup, char* gender, int age, char* mNumber)
    : Patient(fName, lName, bGroup, gender, age, mNumber)
    {}
    void showInfo()
    {
        Patient::showInfo();
        cout<<"state: Urgent"<<endl;
    }
};

class PatientList
{
private:
    int patientNum;
    Patient* firstPatient;
    Patient* lastPatient;
public:
    PatientList()
    :patientNum(0), firstPatient(NULL), lastPatient(NULL)
    {}
    void InsertNormalPatient();
    void InsertUrgentPatient();
    void TakeToDoctor();
    void ShowList();
};

void PatientList::InsertNormalPatient()
{

    char firstName[100];
    char lastName[100];
    char bloodGroup[100];
    char gender[100];
    int age;
    char mobileNumber[100];
    Patient* newPatient;

    cout<<"[Normal Patient]"<<endl;
    cout<<"first name: "; cin>>firstName;
    cout<<"last name: "; cin>>lastName;
    cout<<"blood group(A+,A-,B+,B-,O+,O-,AB+,AB-): "; cin>>bloodGroup;
    cout<<"gender(m/f): "; cin>>gender;
    cout<<"age: "; cin>>age;
    cout<<"mobile number: "; cin>>mobileNumber;
    cout<<endl<<endl;

    newPatient = new NormalPatient(firstName, lastName, bloodGroup, gender, age, mobileNumber);
    if (!patientNum)
    {
        firstPatient=newPatient;
        lastPatient=newPatient;
    }
    else
    {
        lastPatient->putNextPatient(newPatient);
        lastPatient=newPatient;
    }
    patientNum+=1;
}

void PatientList::InsertUrgentPatient()
{

    char firstName[100];
    char lastName[100];
    char bloodGroup[100];
    char gender[100];
    int age;
    char mobileNumber[100];
    Patient* newPatient;

    cout<<"[Urgent Patient]"<<endl;
    cout<<"first name: "; cin>>firstName;
    cout<<"last name: "; cin>>lastName;
    cout<<"blood group(A+,A-,B+,B-,O+,O-,AB+,AB-): "; cin>>bloodGroup;
    cout<<"gender(m/f): "; cin>>gender;
    cout<<"age: "; cin>>age;
    cout<<"mobile number: "; cin>>mobileNumber;
    cout<<endl<<endl;

    newPatient = new UrgentPatient(firstName, lastName, bloodGroup, gender, age, mobileNumber);
    if (!patientNum)
    {
        firstPatient=newPatient;
        lastPatient=newPatient;
    }
    else
    {
        newPatient->putNextPatient(firstPatient);
        firstPatient=newPatient;
    }
    patientNum+=1;
}

void PatientList::TakeToDoctor()
{
    if (!patientNum)
    {
        cout<<"No patient to operate"<<endl<<endl;
    }
    else
    {
        Patient* tempPatient;
        tempPatient=firstPatient;
        firstPatient=firstPatient->getNextPatient();
        delete tempPatient;
        patientNum-=1;
    }
}

void PatientList::ShowList()
{
    Patient* indexPatient=firstPatient;
    if (indexPatient==NULL) 
    {
        cout<<"No patient"<<endl<<endl;
        return;
    }
    while (indexPatient!=NULL)
    {
        indexPatient->showInfo();
        cout<<endl;
        indexPatient=indexPatient->getNextPatient();
    }
}

class HospitalHandler
{
private:
    PatientList General;
    PatientList Heart;
    PatientList Lung;
    PatientList Plastic;
public:
    void ShowMenu();
    void ShowSubmenu(int);
    void ExecuteSubmenu(int, int);
};

void HospitalHandler::ShowMenu()
{
    cout<<"=================================="<<endl;
    cout<<"|-- HOSPITAL MANAGEMENT SYSTEM --|"<<endl;
    cout<<"=================================="<<endl;
    cout<<endl<<"Main Menu"<<endl<<endl;
    cout<<"1: GENERAL CLINIC"<<endl;
    cout<<"2: HEART CLINIC"<<endl;
    cout<<"3: LUNG CLINIC"<<endl;
    cout<<"4: PLASTIC CLINIC"<<endl;
    cout<<"5: Exit"<<endl;
    cout<<endl<<"Please enter your choice : ";
}

void HospitalHandler::ShowSubmenu(int choice)
{
    cout<<"=================================="<<endl;
    cout<<"|-- HOSPITAL MANAGEMENT SYSTEM --|"<<endl;
    cout<<"=================================="<<endl;
    
    switch(choice)
    {
        case GENERAL:
            cout<<endl<<"GENERAL CLINIC"<<endl<<endl;
            break;
        case HEART:
            cout<<endl<<"HEART CLINIC"<<endl<<endl;
            break;
        case LUNG:
            cout<<endl<<"LUNG CLINIC"<<endl<<endl;
            break;
        case PLASTIC:
            cout<<endl<<"PLASTIC CLINIC"<<endl<<endl;
            break;
    }

    cout<<"[1] Add normal patient"<<endl;
    cout<<"[2] Add critically ill patient"<<endl;
    cout<<"[3] Take patient to Doctor"<<endl;
    cout<<"[4] Display list"<<endl;
    cout<<"[5] Change department or exit"<<endl;
    cout<<endl<<"Please enter your choice : ";
}

void HospitalHandler::ExecuteSubmenu(int choice, int subchoice)
{
    switch(choice)
    {
        case GENERAL:
            switch(subchoice)
            {
                case 1:
                    General.InsertNormalPatient();
                    break;
                case 2:
                    General.InsertUrgentPatient();
                    break;
                case 3:
                    General.TakeToDoctor();
                    break;
                case 4:
                    General.ShowList();
                    break;
                case 5:
                    return;
            }
            break;
        case HEART:
            switch(subchoice)
            {
                case 1:
                    Heart.InsertNormalPatient();
                    break;
                case 2:
                    Heart.InsertUrgentPatient();
                    break;
                case 3:
                    Heart.TakeToDoctor();
                    break;
                case 4:
                    Heart.ShowList();
                    break;
                case 5:
                    return;
            }
            break;
        case LUNG:
            switch(subchoice)
            {
                case 1:
                    Lung.InsertNormalPatient();
                    break;
                case 2:
                    Lung.InsertUrgentPatient();
                    break;
                case 3:
                    Lung.TakeToDoctor();
                    break;
                case 4:
                    Lung.ShowList();
                    break;
                case 5:
                    return;
            }
            break;
        case PLASTIC:
            switch(subchoice)
            {
                case 1:
                    Plastic.InsertNormalPatient();
                    break;
                case 2:
                    Plastic.InsertUrgentPatient();
                    break;
                case 3:
                    Plastic.TakeToDoctor();
                    break;
                case 4:
                    Plastic.ShowList();
                    break;
                case 5:
                    return;
            }
            break;
        default:
            return;
    }
}

int main(void)
{
    HospitalHandler manager;
    int choice;
    int subchoice;

    while (1)
    {
        manager.ShowMenu();
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case GENERAL:
                manager.ShowSubmenu(choice); cin>>subchoice;
                cout<<endl;
                manager.ExecuteSubmenu(choice, subchoice);
                break;
            case HEART:
                manager.ShowSubmenu(choice); cin>>subchoice;
                cout<<endl;
                manager.ExecuteSubmenu(choice, subchoice);
                break;
            case LUNG:
                manager.ShowSubmenu(choice); cin>>subchoice;
                cout<<endl;
                manager.ExecuteSubmenu(choice, subchoice);
                break;
            case PLASTIC:
                manager.ShowSubmenu(choice); cin>>subchoice;
                cout<<endl;
                manager.ExecuteSubmenu(choice, subchoice);
                break;
            case EXIT:
                cout<<"Thank you!"<<endl<<endl;
                return 0;
            default:
                cout<<"Illegal selection"<<endl;
                cout<<"Choose between the number 1~5"<<endl;
                break;
        }
    }

    return 0;
}