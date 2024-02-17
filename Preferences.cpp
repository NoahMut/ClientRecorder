#include <iostream>
#include <string>
#include "LinkedList.h" // Include the header file for your LinkedList class

using namespace std;


int main() {
    // Define local variables
    char input1 = 'Z';
    string airLine, deptDate;
    int flightNum;
    bool success = false;

    // Instantiate a LinkedList object
    LinkedList list1;

    printMenu();

    do {
        cout << "\n---------------------------\n";
        cin.get(input1);
        input1 = toupper(input1); // Convert to uppercase
        cin.ignore(20, '\n'); // Flush the buffer

        switch (input1) {
            case 'A':
                // Add a Flight
                cout << "\nEnter the following information\n";
                cout << "Enter Client Name: ";
                cin >> airLine;
                cout << "Enter Client email/phone number: ";
                cin >> deptDate;
                cout << "Enter Client Appointment Date in YYYYMMDD format:: ";
                cin >> flightNum;
                

                // Call the addFlight method of the LinkedList class
                success = list1.addFlight(airLine, flightNum, deptDate);

                if (success)
                    cout << "\nClient Data: " << airLine << " @ " << deptDate << " on " << flightNum <<  " is added\n";
                else
                    cout << "\nData NOT added\n";
                break;
                
            // Add cases for other menu options here

case 'C': // Assuming 'C' is the chosen option for cancelling flights
    {
        string airlineName;

        cout << "Enter Client Name to Cancel Appointment: ";
        getline(cin, airlineName); // Read the airline name

        bool result = list1.cancelFlightsByAirLine(airlineName); // Assuming 'list' is your LinkedList object

        if (result) {
            cout << "Appointment with " << airlineName << " has been canceled." << endl;
        } else {
            cout << "Appointment with " << airlineName << " has failed to be cancelled." << endl;
        }

        break;
    }
            case 'D':
                // Display All Flights
                list1.displayAllFlights();
                break;

            case 'E':
                // Display Flights by airline
                cout << "\nEnter Client Name for Appointment Info:  ";
                cin >> airLine;
                list1.displayFlightsByAirLine(airLine);
                break;

            case 'F':
                // Display Flights by departure date
                cout << "\nWhich budget would you like to display choices: ";
                cin >> flightNum;
                list1.displayFlightsByDate(flightNum);

                break;

case 'R': // Let's say 'D' is for cancelling by departure date
        {
            int deptDate;
            cout << "Enter the Departure Date to cancel all flights (or shoes) on that date: ";
            cin >> deptDate; // Assuming deptDate is in a format that the user knows, like 'YYYY-MM-DD'

            bool success = list1.cancelFlightsByDate(flightNum);

            if (success) {
                cout << "\n" "\n";
            } else {
                cout << "\n \n";
            }
            break;
        }
        
 case 'U': {// Delay a flight, i.e. update a flight departure date
 int flightNum; // Assuming flightNum is an integer
    string oldDeptDate, newDeptDate;

            cout << "\nEnter airline code: ";
            cin >> airLine;

            cin.ignore(20, '\n'); // flush the buffer

            cout << "\nEnter old departure date: ";
            cin >> oldDeptDate;

            cout << "\nEnter new departure date: ";
            cin >> newDeptDate;

            success = list1.delayAFlight(airLine, flightNum, oldDeptDate, newDeptDate);

            if (success)
                cout << "\nFlight: " << airLine << " " << deptDate << " on " << oldDeptDate << " departure date is changed to " << newDeptDate << "\n";
            else
                cout << "\nFlight: " << airLine << " " << flightNum << " on " << oldDeptDate << " departure date is NOT changed" << "\n";
          
            break;

 }
case 'V': {// Delay a flight, i.e. update a flight departure date
 int flightNum; // Assuming flightNum is an integer
    string oldDeptDate1, newDeptDate1;

            cout << "\nEnter airline code: ";
            cin >> airLine;

            cin.ignore(20, '\n'); // flush the buffer

            cout << "\nEnter old departure date: ";
            cin >> oldDeptDate1;

            cout << "\nEnter new departure date: ";
            cin >> newDeptDate1;

            success = list1.delayAFlight(airLine, flightNum, oldDeptDate1, newDeptDate1);

            if (success)
                cout << "\nFlight: " << airLine << " " << deptDate << " on " << oldDeptDate1 << " departure date is changed to " << newDeptDate1 << "\n";
            else
                cout << "\nFlight: " << airLine << " " << flightNum << " on " << oldDeptDate1 << " departure date is NOT changed" << "\n";
          
            break;


 }
            case 'Q':
                // Quit
                cout << "\nExiting the program.\n";
                break;

            case '?':
                // Display Menu
                printMenu();
                break;

            default:
                cout << " ";
                break;
        }
 input1 = 'Z';

    } while (input1 != 'Q');

    return 0;
}

// The rest of your code remains unchanged.

// Define the printMenu function
void printMenu() {
    cout << "Choice\t\tAction\n";
    cout << "------\t\t------\n";
    cout << "A\t\tAdd Client Appointment Info\n";
    cout << "D\t\tDisplay All Appointment Info\n";
    cout << "E\t\tDisplay Appointment Info by Name\n";
    cout << "F\t\tDisplay Appointment Info by Date (YYYYMMDD Format)\n";
    cout << "C\t\tCancel Appointment by Name\n";
    cout << "R\t\tCancel Appointment by Date (YYYYMMDD Format)\n";
    cout << "U\t\tChange a Client Contact Info\n";
    cout << "Q\t\tQuit\n";
    cout << "?\t\tDisplay Help\n\n";
}