//Exactly one valid chain/path exists Find Itinerary from Tickets problem using unordered_map + unordered_set 
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void printItinerary(unordered_map<string, string> tickets) {

    // Store all destinations
    unordered_set<string> to;

    for (pair<string,string> ticket : tickets) {
        to.insert(ticket.second);
    }

    // Find starting point
    string start = "";

    for (pair<string,string> ticket : tickets) {

        // city not present in destination set
        if (to.find(ticket.first) == to.end()) {
            start = ticket.first;
        }
    }

    // Print path
    cout << start << " -> ";

    while (tickets.count(start)) {

        cout << tickets[start] << " -> ";

        start = tickets[start];
    }

    cout << "destination" << endl;
}

int main() {

    unordered_map<string, string> tickets;

    tickets["Chennai"] = "Bangalore";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);

    return 0;
}

//ANS:=
//Mumbai -> Delhi -> Goa -> Chennai -> Bangalore -> destination