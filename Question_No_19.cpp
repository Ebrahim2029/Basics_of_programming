#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Train {
    int number;
    string destination;
    string departureTime;

    Train(int num, string dest, string time) : number(num), destination(dest), departureTime(time) {}
};

void printTrain(const Train& train) {
    
    cout << "1- Train Number: " << train.number << endl;
    cout << "2- Destination: " << train.destination << endl;
    cout << "3-Departure Time: " << train.departureTime << endl;
}

void addTrain(list<Train>& trains) {
    
    int number;
    string destination, time;

    cout << "Enter train number: ";
    cin >> number;
    cin.ignore(); // Clear newline left in the buffer

    cout << "Enter destination: ";
    getline(cin, destination);

    cout << "Enter departure time: ";
    getline(cin, time);

    trains.emplace_back(number, destination, time);
}

void viewAllTrains(const list<Train>& trains) {
   
    for (const auto& train : trains) {
        printTrain(train);
    }
}

void findTrainByNumber(const list<Train>& trains) {
    
    int number;
    cout << "Enter train number: ";
    cin >> number;

    for (const auto& train : trains) {
        if (train.number == number) {
            printTrain(train);
            return;
        }
    }

    cout << "Train not found." << endl;
}

void findTrainsByDestination(const list<Train>& trains) {
   
    string destination;
    cout << "Enter destination: ";
    cin.ignore(); // Clear newline left in the buffer
    getline(cin, destination);

    bool found = false;
    for (const auto& train : trains) {
        if (train.destination == destination) {
            printTrain(train);
            found = true;
        }
    }

    if (!found) {
        cout << "No trains found for this destination." << endl;
    }
}

int main() {
    list<Train> trains;
    int choice;

    do {
        
        cout << "\t1.Add Train\n";
        cout << "\t2.View All Trains\n";
        cout << "\t3.Find Train by Number\n";
        cout << "\t4.Find Trains by Destination\n";
        cout << "\t5.Exit\n\n\n";

        cout << "Enter your choice :";
        
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            addTrain(trains);
            system("pause && cls");
            break;
        case 2:
            system("cls");
            viewAllTrains(trains);
            system("pause && cls");
            break;

        case 3:
            system("cls");
            findTrainByNumber(trains);
            system("pause && cls");
            break;
        case 4:
            system("cls");
            findTrainsByDestination(trains);
            system("pause && cls");
            break;
        case 5:
            
            cout << "Exiting program." << endl;
           
            break;
        default:
            cout << "Invalid choice. Please try again.\n\n" << endl;
            system("pause && cls");
        }
    } while (choice != 5);

    return 0;
}
