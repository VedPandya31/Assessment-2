#include <iostream>
#include <string>
using namespace std;

// Constants (Rate Card)
const double CostPerHour = 100.50;
const double CostPerMinute = 50.50;
const double CostOfDinner = 100.50;

class Event {
public:
    string eventName, firstName, lastName;
    int guests, minutes;

    // Function to take input
    void getDetails() {
        cout << "Enter Event Name: ";
        getline(cin, eventName);

        cout << "Enter First Name: ";
        getline(cin, firstName);

        cout << "Enter Last Name: ";
        getline(cin, lastName);

        cout << "Enter Number of Guests: ";
        cin >> guests;

        cout << "Enter Event Duration (in minutes): ";
        cin >> minutes;

    }

    // Function to calculate and show cost
    void showCost() {
        // 1 server can handle 20 guests (manual ceil trick)
        int servers = (guests + 19) / 20;

        double cost1 = (minutes / 60) * CostPerHour;
        double cost2 = (minutes % 60) * CostPerMinute;
        double cost_For_One_Server = cost1 + cost2;

        double foodCost = guests * CostOfDinner;
        double avgCost = foodCost / guests;
        double totalCost = foodCost + (cost_For_One_Server * servers);
        double deposit = totalCost * 0.25;

        // Display result
        cout << "\n===== EVENT MANAGEMENT SYSTEM =====\n";
        cout << "Enter The Name Of Event:\n" << eventName << endl;
        cout << "Enter Customer Name:\n" << firstName << " " << lastName << endl;
        cout << "Enter The Number Of Guests:\n" << guests << endl;
        cout << "\nEnter The Number of Minutes In The Event:\n" << minutes << endl;
        cout<<"\n=====  Event Estiment For :"<< firstName << " " << lastName<<"  =====";
        cout << "\nNumber of Server:\n" << servers << endl;
        cout << "The Cost For Server:\n" << cost_For_One_Server << endl;
        cout << "The Cost For Food: Rs:\n" << foodCost << endl;
        cout << "Average Cost per Person: Rs.\n" << avgCost << endl;
        cout << "\n\nTotal Cost is: Rs:\n" << totalCost << endl;
        cout << "Please Deposit a (25%) Deposite To Reserve The Event\n";
        cout << "The Deposite Needed is :" << deposit << endl;
        cout << "==========================\n";
    }
};

int main() {
    Event e;
    e.getDetails();
    e.showCost();

    return 0;
}
