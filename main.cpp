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
    double getValue(){
        return  value;
    }
};

class Holiday: public Expense{
public:
    Holiday(string name, double value) : Expense(name, value) {}
};
class Going_out:public Expense{
public:
    Going_out(string name,double value): Expense(name,value){}
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
        expense.push_back(Going_out(name,amount));

    }
    if(choice == '4'){
        cout<<"What was the emergency: "<<endl;

        getline(cin,name);
        cout<<"How much did you spend?: ";
        cin>>amount;
        expense.push_back(Going_out(name,amount));

    }





}



double Expenses_total(vector<Expense>&expenses){
    double total = 0;
    cout<<"Yout total is: ";
    for(auto item:expenses){
        total+= item.getValue();
    }
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
                std::cout << "Your total is: " << Expenses_total(expenses) << "\n";
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
