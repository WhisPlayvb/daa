#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    char id;
    int deadline;
    int profit;
};

// Function to compare two jobs based on their profit
bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to print the sequence of jobs and their total profit
void printJobSequence(Job arr[], int n) {
    // Sort the jobs based on their profit in non-increasing order
    sort(arr, arr + n, compare);

    // Find the maximum deadline among all jobs
    int maxDeadline = 0;
    for (int i = 0; i < n; ++i) {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }

    // Initialize an array to keep track of slots for each deadline
    char result[maxDeadline] = {'\0'};
    bool slot[maxDeadline] = {false};

    // Fill the result array by selecting jobs
    int totalProfit = 0;
    for (int i = 0; i < n; ++i) {
        // Find a slot for the current job starting from its deadline
        for (int j = min(arr[i].deadline, maxDeadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                result[j] = arr[i].id;
                slot[j] = true;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    // Print the sequence of jobs and their total profit
    cout << "Sequence of jobs: ";
    for (int i = 0; i < maxDeadline; ++i) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << "\nTotal profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    // Input the details of each job
    Job arr[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for job " << i + 1 << " (id, deadline, profit): ";
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }

    // Print the sequence of jobs and their total profit
    printJobSequence(arr, n);

    return 0;
}

/*
Time complexity of Job Sequencing with Deadline using the greedy method is 
worst case: O(n^2)
average and best cases: O(nlogn)

Enter the number of jobs: 5
Enter details for job 1 (id, deadline, profit): 1 2 20
Enter details for job 2 (id, deadline, profit): 2 2 15
Enter details for job 3 (id, deadline, profit): 3 1 10
Enter details for job 4 (id, deadline, profit): 4 3 5
Enter details for job 5 (id, deadline, profit): 5 3 1
Sequence of jobs: 2 1 4
Total profit: 40

*/

