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
    int token;
public:
    Expense(){}
    Expense(string name,double value,int token){
        this->name = name;
        this->value = value;
        this->token=token;
    }
    string getName()const {
        return name;
    }
    double getValue()const {
        return value;
    }
    int getToken()const{
        return token;
    }


};

class Holiday: public Expense{
public:
    Holiday(string name, double value,int token) : Expense(name, value,token) {}
};
class Going_out:public Expense{
public:
    Going_out(string name,double value,int token): Expense(name,value,token){}
};

class Vices:public Expense{
public:
    Vices(string name,double value,int token): Expense(name,value,token){}
};
class Medical:public Expense{
public:
    Medical(string name,double value,int token): Expense(name,value,token){}
};



void addExpense(vector<Expense>&expense) {
    string name;
    double amount;
    char choice;
    int token = 0;
    cout <<"What kind expenses do you have?: "<<"\n";
    cout <<"1. Holiday"<<"\n"<<"2. Going out"<<"\n"<<"3. Vices"<<"\n"<<"4. Medical "<<"\n";


    cin>>choice;
    cin.ignore();
    if(choice  == '1'){

        cout<<"What place did you visit? :"<<endl;
        getline(cin,name);
        cout<<"What value?: ";
        cin>>amount;
        token =1;
        expense.push_back(Holiday(name,amount,token));
    }

    if(choice == '2'){
        cout<<"Where did you hang out?: "<<endl;

        getline(cin,name);
        cout<<"How much did you spend?: ";
        cin>>amount;
        token =2;
        expense.push_back(Going_out(name,amount,token));

    }

    if(choice == '3'){
        cout<<"What did you buy: "<<endl;

        getline(cin,name);

        cout<<"How much did you spend?: ";
        cin>>amount;
        token = 3;
        expense.push_back(Vices(name,amount,token));

    }
    if(choice == '4'){
        cout<<"What was the emergency: "<<endl;

        getline(cin,name);
        cout<<"How much did you spend?: ";
        cin>>amount;
        token =4;
        expense.push_back(Medical(name,amount,token));

    }





}



double Expenses_total(vector<Expense>&expenses){
    double total = 0;
    double holiday_total = 0;
    double going_out_total = 0;
    double vices_total = 0;
    double medical_total = 0;
    double holidayPercentage = 0;
    double goingOutPercentage =0;
    double medicalpercentage=0;
    double vicespercentage =0;
    for(auto& item:expenses) {
        total += item.getValue();
    }
    for(auto& item:expenses){
        if (total > 0) {
            if (item.getToken() == '1') {
                 holidayPercentage = (holiday_total / total) * 100;
            }
            if (item.getToken() == '2') {
                goingOutPercentage = (going_out_total / total) * 100;
            }
            if (item.getToken() == '3') {
                vicespercentage = (holiday_total / total) * 100;
            }
            if (item.getToken() == '4') {
                 medicalpercentage = (medical_total/ total) * 100;
            }
            cout << fixed << setprecision(2);
            cout << "Holiday Expenses: " << holidayPercentage << "% of total" << endl;
            cout << "Going Out Expenses: " << goingOutPercentage << "% of total" << endl;
            cout << "Medical Expenses: " << medicalpercentage << "% of total" << endl;
            cout << "Vices Expenses: " << vicespercentage << "% of total" << endl;

        } else {
            cout << "No expenses recorded." << endl;
        }
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

       cout << "\nMeniu:\n";
       cout << "1. Add expenses\n";
        cout << "2. Display expenses\n";
        cout << "3. Total of the expenses\n";
        cout << "4. Exit\n";
        cout << "Pick your option: ";
        cin >> choice;

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
