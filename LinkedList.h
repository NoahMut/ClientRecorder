#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

//Flight represents a departure flight
struct Flight
{

    string airLine;
    int flightNum;
    string deptDate;        //departure date
    struct Flight* next;
};

//class LinkedList will contains a linked list of flights
class LinkedList
{

int flightCount;

// Global variables
    private:
        struct Flight* head;

    public:
        LinkedList();
        ~LinkedList();
        bool addFlight(string airLine, int flightNum, string deptDate);
        bool searchFlight(string airLine, int flightNum, string deptDate);
        void displayAllFlights();
        void displayFlightsByAirLine(string airLine);
        void displayFlightsByDate(int flightNum);
        bool changeAFlightAirLine(string airLine, int flightNum, string oldDeptDate1, string newDeptDate1);
        bool delayAFlight(string airLine, int flightNum, string oldDeptDate, string newDeptDate);
        bool cancelFlightsByDate(int flightNum);
        bool cancelFlightsByAirLine(string airLine);
        bool cancelOneFlight(string airLine, int flightNum, string deptDate);


};

//Constructor to initialize an empty linked list
LinkedList::LinkedList()
{
      head = nullptr; // Initialize head to nullptr for an empty linked list
}

LinkedList::~LinkedList()
{
	//Add your own code
    int deletedFlights = 0; // To keep track of the number of deleted flights

    // Start from the head of the linked list
    struct Flight* current = head;
    while (current != nullptr)
    {
        struct Flight* temp = current; // Temporary pointer to the current flight node
        current = current->next; // Move to the next flight node
        delete temp; // Delete the current flight node
        deletedFlights++; // Increment the count of deleted flights
    }

    // After deleting all nodes, set the head to nullptr
    head = nullptr;


    cout<< "\nThe number of deleted Shoes is: " << flightCount <<"\n";
}

bool LinkedList::searchFlight(string airLine, int flightNum, string deptDate)
{
	struct Flight* current = head;
    
    // Iterate through the linked list
    while (current != nullptr)
    {
        // Check if the current flight matches the search criteria
        if (current->airLine == airLine &&
            current->flightNum == flightNum &&
            current->deptDate == deptDate)
        {
            // Found a matching flight, return true
            return true;
        }

        // Move to the next flight node
        current = current->next;
    }

    // Flight not found, return false
    return false;
}

bool LinkedList::addFlight(string airLine, int flightNum, string deptDate)
{
   // Check if the flight already exists (no duplicates allowed)
    if (searchFlight(airLine, flightNum, deptDate))
    {
        return false; // Flight already exists, cannot add it
    }

    // Create a new Flight node
    struct Flight* newFlight = new Flight;
    newFlight->airLine = airLine;
    newFlight->flightNum = flightNum;
    newFlight->deptDate = deptDate;
    newFlight->next = nullptr;

    // Case 1: If the linked list is empty, set the new flight as the head
    if (head == nullptr)
    {
        head = newFlight;
    }
    else
    {
        // Start from the head of the linked list
        struct Flight* current = head;
        struct Flight* previous = nullptr;

        // Iterate through the list to find the correct position to insert
        while (current != nullptr &&
               (current->airLine < airLine ||
                (current->airLine == airLine &&
                 (current->flightNum < flightNum ||
                  (current->flightNum == flightNum && current->deptDate < deptDate)))))
        {
            previous = current;
            current = current->next;
        }

        // Insert the new flight at the correct position
        if (previous == nullptr)
        {
            // Case 2: Inserting at the beginning (before the current head)
            newFlight->next = head;
            head = newFlight;
        }
        else
        {
            // Case 3: Inserting in the middle or at the end
            previous->next = newFlight;
            newFlight->next = current;
        }
    }

    return true; // Flight added successfully
}

//Display all flights in the linked list starting from the head.
void LinkedList::displayAllFlights()
{
  struct Flight* temp = head;
    int counter = 0; // To count the total number of flights

    while (temp != nullptr)
    {
        cout << left << setw(5) << temp->airLine
             << setw(10) << temp->flightNum
             << setw(12) << temp->deptDate << "\n";

        temp = temp->next;
        counter++;
    }

    cout << "\nTotal # of Client Data: " << counter << "\n";
}

//Display all flights in the list with the specified airLine.
void LinkedList::displayFlightsByAirLine(string airLine)
{
   struct Flight* temp = head;
    int counter = 0; // To count the total number of flights

    while (temp != nullptr)
    {
        if (temp->airLine == airLine)
        {
            cout << left << setw(5) << temp->airLine
                 << setw(10) << temp->flightNum
                 << setw(12) << temp->deptDate << "\n";
            counter++;
        }

        temp = temp->next;
    }

    if (counter > 0)
    {
        cout << "\nTotal: " << counter << " Shoes found with Color " << airLine << "\n";
    }
    else
    {
        cout << "\nNo Shoes with the specified Color found\n";
    }
}
void LinkedList::displayFlightsByDate(int flightNum)
{
   struct Flight* temp = head;
    int counter = 0; // To count the total number of flights

    while (temp != nullptr)
    {
        if (temp->flightNum == flightNum)
        {
            cout << left << setw(5) << temp->airLine
                 << setw(10) << temp->flightNum
                 << setw(12) << temp->deptDate << "\n";
            counter++;
        }

        temp = temp->next;
    }

    if (counter > 0)
    {
        cout << "\nTotal: " << counter << " Shoes found with Color " << flightNum << "\n";
    }
    else
    {
        cout << "\nNo Shoes with the specified Color found\n";
    }
}
//Display all flights with the specified date


bool LinkedList::cancelOneFlight(string airLine, int flightNum, string deptDate)
{
   // Check if the list is empty
    if (head == nullptr)
    {
        cout << "\nNo Shoes in the list. Cancel failed.\n";
        return false;
    }

    struct Flight* current = head;
    struct Flight* previous = nullptr;

    // Traverse the list to find the flight to cancel
    while (current != nullptr)
    {
        if (current->airLine == airLine && current->flightNum == flightNum && current->deptDate == deptDate)
        {
            // Flight found, update pointers to remove it
            if (previous != nullptr)
            {
                // If it's not the first node
                previous->next = current->next;
            }
            else
            {
                // If it's the first node, update the head
                head = current->next;
            }

            delete current; // Free the memory
            cout << "\nShoes: " << airLine << " " << flightNum << " in Size " << deptDate << " is canceled\n";
            return true;
        }

        // Move to the next node
        previous = current;
        current = current->next;
    }

    // Flight not found
    cout << "\nFlight: " << airLine << " " << flightNum << " on " << deptDate << " is NOT found\n";
    return false;
}

bool LinkedList::cancelFlightsByAirLine(string airLine)
{
     if (head == nullptr)
    {
        cout << "\nNo flights in the list. Cancel failed.\n";
        return false;
    }

    struct Flight* current = head;
    struct Flight* previous = nullptr;
    bool canceled = false; // Flag to track if any flights were canceled

    while (current != nullptr)
    {
        if (current->airLine == airLine)
        {
            // Flight with matching airline found, cancel it
            if (previous != nullptr)
            {
                // If it's not the first node
                previous->next = current->next;
                delete current; // Free the memory
                current = previous->next; // Move to the next node
            }
            else
            {
                // If it's the first node, update the head
                head = current->next;
                delete current; // Free the memory
                current = head; // Move to the next node
            }

            canceled = true; // Set the flag to true
        }
        else
        {
            // Move to the next node
            previous = current;
            current = current->next;
        }
    }

    if (canceled)
    {
        cout << "\nAll flights for " << airLine << "Dollars are canceled\n";
        return true;
    }
    else
    {
        cout << "\nFlights fo airline " << airLine << "Dollars do NOT exist. Cancel failed.\n";
        return false;
    }
}

bool LinkedList::cancelFlightsByDate(int flightNum)
{
  if (head == nullptr)
    {
        cout << "\nNo Shoes in the list. Cancel failed.\n";
        return false;
    }

    struct Flight* current = head;
    struct Flight* previous = nullptr;
    bool canceled = false; // Flag to track if any flights were canceled

    while (current != nullptr)
    {
        if (current->flightNum == flightNum)
        {
            // Flight with matching departure date found, cancel it
            if (previous != nullptr)
            {
                // If it's not the first node
                previous->next = current->next;
                delete current; // Free the memory
                current = previous->next; // Move to the next node
            }
            else
            {
                // If it's the first node, update the head
                head = current->next;
                delete current; // Free the memory
                current = head; // Move to the next node
            }

            canceled = true; // Set the flag to true
        }
        else
        {
            // Move to the next node
            previous = current;
            current = current->next;
        }
    }

    if (canceled)
    {
        cout << "\nAll Appointments on " << flightNum << "were canceled\n";
        return true;
    }
    else
    {
        cout << "\nNo Shoes for" << flightNum << "Dollars were found. Cancel failed.\n";
        return false;
    }
}





bool LinkedList::delayAFlight(string airLine, int flightNum, string oldDeptDate, string newDeptDate)
{
    struct Flight* current = head;
    struct Flight* previous = nullptr;
    bool found = false;

    // Search for the flight with matching airLine, flightNum, and oldDeptDate
    while (current != nullptr)
    {
        if (current->airLine == airLine && current->deptDate == oldDeptDate)
        {
            // Flight found, update its departure date
            current->deptDate = newDeptDate;
            found = true;
            break;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    if (!found)
    {
        cout << "\nFlight with Airline: " << airLine << ", Flight Num: " << flightNum << ", and Departure Date: " << oldDeptDate << " not found. Delay failed.\n";
        return false;
    }

    // Remove the updated flight from the list
    if (previous != nullptr)
    {
        previous->next = current->next;
    }
    else
    {
        head = current->next;
    }

    // Reinsert the updated flight in the correct location to maintain alphabetical order
    bool success = addFlight(current->airLine, current->flightNum, current->deptDate);

    if (success)
    {
        cout << "\nFlight: " << airLine << " " << flightNum << " on " << oldDeptDate << " departure date is changed to " << newDeptDate << "\n";
    }
    else
    {
        cout << "\nFlight: " << airLine << " " << flightNum << " on " << oldDeptDate << " departure date is NOT changed\n";
    }

    delete current; // Free the memory of the updated flight
    return success;
}








bool LinkedList::changeAFlightAirLine(string airLine, int flightNum, string oldDeptDate1, string newDeptDate1)
{
    struct Flight* current = head;
    struct Flight* previous = nullptr;
    bool found = false;

    // Search for the flight with matching airLine, flightNum, and oldDeptDate
    while (current != nullptr)
    {
        if (current->airLine == airLine && current->deptDate == oldDeptDate1)
        {
            // Flight found, update its departure date
            current->deptDate = newDeptDate1;
            found = true;
            break;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    if (!found)
    {
        cout << "\nFlight with Airline: " << airLine << ", Flight Num: " << flightNum << ", and Departure Date: " << oldDeptDate1 << " not found. Delay failed.\n";
        return false;
    }

    // Remove the updated flight from the list
    if (previous != nullptr)
    {
        previous->next = current->next;
    }
    else
    {
        head = current->next;
    }

    // Reinsert the updated flight in the correct location to maintain alphabetical order
    bool success = addFlight(current->airLine, current->flightNum, current->deptDate);

    if (success)
    {
        cout << "\nFlight: " << airLine << " " << flightNum << " on " << oldDeptDate1 << " departure date is changed to " << newDeptDate1 << "\n";
    }
    else
    {
        cout << "\nFlight: " << airLine << " " << flightNum << " on " << oldDeptDate1 << " departure date is NOT changed\n";
    }

    delete current; // Free the memory of the updated flight
    return success;

}
#endif