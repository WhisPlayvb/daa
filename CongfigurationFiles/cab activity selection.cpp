#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent a person's travel time
struct Person {
    int start_time;
    int end_time;
    int index; // Added to track the index of the person
};

// Function to compare persons based on their end times
bool compareEndTime(const Person& a, const Person& b) {
    return a.end_time < b.end_time;
}

// Function to find the minimum number of cabs needed
int minCabsNeeded(Person* persons, int N, int* selectedActivities) {
    // Sort persons based on their end times
    sort(persons, persons + N, compareEndTime);

    int cabsNeeded = 0;
    int lastEndTime = -1; // Initialize to a value before any possible time
    int numSelected = 0; // Counter for selected activities

    // Iterate through sorted persons and assign cabs greedily
    for (int i = 0; i < N; ++i) {
        if (persons[i].start_time > lastEndTime) {
            cabsNeeded++;
            lastEndTime = persons[i].end_time;
            selectedActivities[numSelected++] = persons[i].index; // Add the index of the selected person
        }
    }

    return cabsNeeded;
}

int main() {
    int N;
    cout << "Enter the number of persons: ";
    cin >> N;

    Person* persons = new Person[N];
    int* selectedActivities = new int[N]; // Array to store selected activities

    cout << "Enter the start and end times for each person:\n";
    for (int i = 0; i < N; ++i) {
        cout << "Person " << i + 1 << ": ";
        cin >> persons[i].start_time >> persons[i].end_time;
        persons[i].index = i + 1; // Assign index to track the person
    }

    int minCabs = minCabsNeeded(persons, N, selectedActivities);

    cout << "Minimum number of cabs required: " << minCabs << endl;

    cout << "Selected activities: ";
    for (int i = 0; i < minCabs; ++i) {
        cout << "Person " << selectedActivities[i] << " ";
    }
    cout << endl;

    delete[] persons;
    delete[] selectedActivities;

    return 0;
}
/*Enter the number of persons: 11
Enter the start and end times for each person:
Person 1: 1 4
Person 2: 3 5
Person 3: 0 6
Person 4: 5 7
Person 5: 3 8
Person 6: 5 9
Person 7: 6 10
Person 8: 8 11
Person 9: 8 12
Person 10: 2 13
Person 11: 12 14
Minimum number of cabs required: 4
Selected activities: Person 1 Person 4 Person 8 Person 11
*/
