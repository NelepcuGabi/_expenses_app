#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class Expense{
protected:

    string name;
    double value;
public:
    Expense(){}
    Expense(string name,double value){
        this->name = name;
        this->value = value;
    }
    string getName()const {
        return name;
    }
    double getValue()const {
        return  value;
    }
    virtual ~Expense()=default;
};

class Holiday: public Expense{
public:
    Holiday(string name, double value) : Expense(name, value) {}
};
class Going_out:public Expense{
public:
    Going_out(string name,double value): Expense(name,value){}
};

class Vices:public Expense{
public:
    Vices(string name,double value): Expense(name,value){}
};
class Medical:public Expense{
public:
    Medical(string name,double value): Expense(name,value){}
};



void addExpense(vector<Expense>&expense) {
    string name;
    double amount;
    char choice;
    cout <<"What kind expenses do you have?: "<<"\n";
    cout <<"1. Holiday"<<"\n"<<"2. Going out"<<"\n"<<"3. Vices"<<"\n"<<"4. Medical "<<"\n";


    cin>>choice;
    cin.ignore();
    if(choice  == '1'){

        cout<<"What place did you visit? :"<<endl;
        getline(cin,name);
        cout<<"What value?: ";
        cin>>amount;
        expense.push_back(Holiday(name,amount));
    }

    if(choice == '2'){
        cout<<"Where did you hang out?: "<<endl;

        getline(cin,name);
        cout<<"How much did you spend?: ";
        cin>>amount;
        expense.push_back(Going_out(name,amount));

    }

    if(choice == '3'){
        cout<<"What did you buy: "<<endl;

        getline(cin,name);

        cout<<"How much did you spend?: ";
        cin>>amount;
        expense.push_back(Vices(name,amount));

    }
    if(choice == '4'){
        cout<<"What was the emergency: "<<endl;

        getline(cin,name);
        cout<<"How much did you spend?: ";
        cin>>amount;
        expense.push_back(Medical(name,amount));

    }





}



double Expenses_total(vector<Expense>&expenses){
    double total = 0;
    double holiday_total = 0;
    double going_out_total = 0;
    double vices_total = 0;
    double medical_total = 0;

    for(auto& item:expenses) {
        total += item.getValue();
        if (dynamic_cast<const Holiday*>(&item) != nullptr) {
            holiday_total += item.getValue();
        }
        if (dynamic_cast<const Going_out*>(&item) != nullptr) {
            going_out_total += item.getValue();
        }
        if (dynamic_cast<const Vices*>(&item) != nullptr) {
            vices_total += item.getValue();
        }
        if (dynamic_cast<const Medical*>(&item) != nullptr) {
            medical_total += item.getValue();
        }
    }
        if (total > 0) {
            double holidayPercentage = (holiday_total/total) * 100;
            double goingOutPercentage = (going_out_total / total) * 100;
            double vicespercentage = (vices_total / total) * 100;
            double medicalpercentage = (medical_total / total) * 100;
            cout << fixed << setprecision(2);
            cout << "Holiday Expenses: " << holidayPercentage << "% of total" << endl;
            cout << "Going Out Expenses: " << goingOutPercentage << "% of total" << endl;
            cout << "Medical Expenses: " << medicalpercentage << "% of total" << endl;
            cout << "Vices Expenses: " << vices_total << "% of total" << endl;

        } else {
            cout << "No expenses recorded." << endl;
        }

    cout<<"Your total is: ";
    return total;
}
void Display_Expense(vector<Expense>&expenses){
    cout<<"List of expenses:\n";
    for(auto item:expenses){
        cout<<item.getName()<<" "<<item.getValue()<<endl;
    }

}


int main() {
    vector<Expense>expenses;

    char choice;

    while (choice != '4') {

        std::cout << "\nMeniu:\n";
        std::cout << "1. Add expenses\n";
        std::cout << "2. Display expenses\n";
        std::cout << "3. Total of the expenses\n";
        std::cout << "4. Exit\n";
        std::cout << "Pick your option: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                addExpense(expenses);
                break;
            case '2':
                Display_Expense(expenses);
                break;
            case '3':
                std:: cout<< Expenses_total(expenses) << "\n";
                break;
            case '4':
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Inavlid option. Please pick from the list above\n";

        }
    }
    return 0;
}
