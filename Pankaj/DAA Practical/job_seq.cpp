#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
    char id;      
    int deadline; 
    int profit;  
};


bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

void jobSequencingWithDeadline(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;

    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<char> result(maxDeadline, ' ');

    vector<bool> slot(maxDeadline, false);

    for (const auto& job : jobs) {

        for (int i = min(job.deadline, maxDeadline) - 1; i >= 0; --i) {
            if (!slot[i]) {
                result[i] = job.id;
                slot[i] = true;
                break;
            }
        }
    }

    cout << "Job sequence with deadline: ";
    for (char job : result) {
        cout << job << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter details for job " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> jobs[i].id;
        cout << "Deadline: ";
        cin >> jobs[i].deadline;
        cout << "Profit: ";
        cin >> jobs[i].profit;
    }

    jobSequencingWithDeadline(jobs);

    return 0;
}

/*

Worst-case time complexity: O(n^2) - Due to sorting and nested loop iteration.
Average-case time complexity: O(n^2) - Similar to the worst case.
Best-case time complexity: O(n log n) - If the jobs are already sorted based on profit.
*/
