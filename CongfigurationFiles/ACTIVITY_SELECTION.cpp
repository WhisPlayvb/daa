#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to compare activities based on their finish times
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

// Function to find the maximum number of activities that can be performed
int activitySelection(Activity activities[], int n) {
    // Sort activities based on their finish times in non-decreasing order
    sort(activities, activities + n, compare);

    // The first activity always gets selected
    int selectedCount = 1;
    int prevFinishTime = activities[0].finish;

    // Print the first selected activity
    cout << "Selected activities: ";
    cout << "[" << activities[0].start << ", " << activities[0].finish << "] ";

    // Iterate through the remaining activities
    for (int i = 1; i < n; i++) {
        // If the current activity starts after or at the time the previous activity finishes,
        // it can be performed
        if (activities[i].start >= prevFinishTime) {
            selectedCount++;
            prevFinishTime = activities[i].finish;
            // Print the selected activity
            cout << "[" << activities[i].start << ", " << activities[i].finish << "] ";
        }
    }

    cout << endl;
    return selectedCount;
}

int main() {
    int n; // Number of activities
    cout << "Enter the number of activities: ";
    cin >> n;

    Activity activities[n]; // Array to store activities
    cout << "Enter the start and finish times of each activity:\n";
    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }

    // Find the maximum number of activities that can be performed
    int selectedCount = activitySelection(activities, n);

    // Print the maximum number of activities that can be performed
    cout << "Maximum number of activities that can be performed: " << selectedCount << endl;

    return 0;
}

/*
Output:
Enter the number of activities: 6
Enter the start and finish times of each activity:
Activity 1: 5
9
Activity 2: 1
2
Activity 3: 3
4
Activity 4: 0
6
Activity 5: 5
7
Activity 6: 8
9
Selected activities: [1, 2] [3, 4] [5, 7] [8, 9]
Maximum number of activities that can be performed: 4





output-2
Enter the number of activities: 6
Enter the start and finish times of each activity:
Activity 1: 5 9
Activity 2: 1 2
Activity 3: 3 4
Activity 4: 0 6
Activity 5: 5 7
Activity 6: 8 9
Selected activities: [1, 2] [3, 4] [5, 7] [8, 9]
Maximum number of activities that can be performed: 4
*/

/*
Time complexity:
O( n log n)  where n is the number of activities for all cases
*/
