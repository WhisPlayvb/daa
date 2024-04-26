#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<int>& job1, vector<int>& job2) {
    return job1[2] > job2[2];
}

vector<int> jobScheduling(vector<vector< int > >& jobs) {
    int n = jobs.size();

    // Sort jobs based on profit in descending order
    sort(jobs.begin(), jobs.end(), cmp);

    // Find maximum deadline among all jobs
    int maxdeadline = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxdeadline = max(maxdeadline, jobs[i][1]);
    }

    // Initialize a sequence vector to track job scheduling
    vector<int> sequence(maxdeadline + 1, -1);

    int count = 0;
    int maxprofit = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++) {
        int currentdeadline = jobs[i][1];
        int currentprofit = jobs[i][2];

        for (int k = currentdeadline; k > 0; k--) {
            if (sequence[k] == -1) {
                count++;
                maxprofit += currentprofit;
                sequence[k] = 10; // Not sure what this line is for, so I've kept it as is.
                break;
            }
        }
    }

    // Store the result in a vector and return
    vector<int> ans;
    ans.push_back(count);
    ans.push_back(maxprofit);
    return ans;
}

int main() {
    // Example usage
    vector<vector<int> > jobs ;
//= {
//        {1, 2, 30}, 
//        {2, 2, 40},  
//        {3, 1, 10},  
//        {4, 1, 10} ,  
//    };

	int numJobs;
    cout << "Enter the number of jobs: ";
    cin >> numJobs;

    for (int i = 0; i < numJobs; ++i) {
        int id, duration, priority;
        cout << "Enter details for job " << i + 1 << " (ID Duration Priority): ";
        cin >> id >> duration >> priority;
        vector<int> jobDetails;
        jobDetails.push_back(id);
        jobDetails.push_back(duration);
        jobDetails.push_back(priority);
        jobs.push_back(jobDetails);
    }

    // Call the jobScheduling function and store the result
    vector<int> result = jobScheduling(jobs);

    // Display the result
    std::cout << "Maximum number of jobs that can be completed: " << result[0] << std::endl;
    std::cout << "Maximum profit: " << result[1] << std::endl;

    return 0;
}
