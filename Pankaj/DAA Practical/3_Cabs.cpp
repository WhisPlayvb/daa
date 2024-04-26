#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int person, start, end;
};

struct CabUsage {
    int person, cab;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

int minCabsRequired(vector<Interval>& intervals, vector<CabUsage>& cabUsages) {
    if (intervals.empty())
        return 0;

    sort(intervals.begin(), intervals.end(), compareIntervals);

    int cabsRequired = 1;
    vector<int> endTimes;
    endTimes.push_back(intervals[0].end);
    cabUsages.push_back({intervals[0].person, 1});

    for (int i = 1; i < intervals.size(); ++i) {
        bool assigned = false;
        for (int j = 0; j < endTimes.size(); ++j) {
            if (intervals[i].start > endTimes[j]) {
                endTimes[j] = intervals[i].end;
                cabUsages.push_back({intervals[i].person, j + 1});
                assigned = true;
                break;
            }
        }
        if (!assigned) {
            cabsRequired++;
            endTimes.push_back(intervals[i].end);
            cabUsages.push_back({intervals[i].person, cabsRequired});
        }
    }

    return cabsRequired;
}

int main() {
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;

    vector<Interval> intervals(n);
    cout << "Enter the start and end times for each person:\n";
    for (int i = 0; i < n; ++i) {
        intervals[i].person = i + 1;
        cout << "Person " << intervals[i].person << ": ";
        cin >> intervals[i].start >> intervals[i].end;
    }

    vector<CabUsage> cabUsages;
    int minCabs = minCabsRequired(intervals, cabUsages);
    cout << "Minimum number of cabs required: " << minCabs << endl;
    cout << "Cab usages:\n";
    for (const auto& usage : cabUsages) {
        cout << "Person " << usage.person << " uses cab " << usage.cab << endl;
    }

    return 0;
}

/*
Enter the number of persons: 5
Enter the start and end times for each person:
Person 1: 3 6
Person 2: 1 4
Person 3: 5 6
Person 4: 2 8
Person 5: 7 9
Minimum number of cabs required: 3
Cab usages:
Person 2 uses cab 1
Person 4 uses cab 2
Person 1 uses cab 3
Person 3 uses cab 1
Person 5 uses cab 1
*/

/*
Interval 1: [3, 6]
Interval 2: [1, 4]
Interval 3: [5, 7]
Interval 4: [2, 5]

vector<Interval> intervals = {{3, 6}, {1, 4}, {5, 7}, {2, 5}};

After sorting, the intervals will look like this:
Interval 2: [1, 4]
Interval 4: [2, 5]
Interval 1: [3, 6]
Interval 3: [5, 7]

With this sorted order, we can now apply the greedy algorithm to find the minimum number of cabs required to accommodate all the intervals without overlaps.
 


working: 
Intervals:     [1, 4]   [2, 5]   [3, 6]   [5, 7] 

Person 1:    [====]
Person 2:      [====]
Person 3:        [====]
Person 4:         [====]

1 : Sort the intervals based on start times:
Person 1:    [====]
Person 2:      [====]
Person 4:         [====]
Person 3:        [====]

2 : Initialize the number of cabs required to 1 and keep track of end times:
Person 1:    [====]
Person 2:      [====]
Person 4:         [====]
Person 3:        [====]
Cabs:          [    ]


3 : Iterate through intervals and assign cabs:
Interval 1 [1, 4]: Allocate cab 1
Person 1:    [====]
Person 2:      [====]
Person 4:         [====]
Person 3:        [====]
Cabs:          [====]

Interval 2 [2, 5]: Reuse cab 1 as its end time (4) is before the start time of interval 2 (5).
Person 1:    [====]
Person 2:      [====]
Person 4:         [====]
Person 3:        [====]
Cabs:          [==========]

Interval 3 [3, 6]: Allocate cab 2 as there is no cab available whose end time is before its start time.
Person 1:    [====]
Person 2:      [====]
Person 4:         [====]
Person 3:        [====]
Cabs:          [==========]
                            [====]'


Interval 4 [5, 7]: Reuse cab 1 as its end time (5) is before the start time of interval 4 (7).
Person 1:    [====]
Person 2:      [====]
Person 4:         [====]
Person 3:        [====]
Cabs:          [==========]
                            [====]
                              [====]



*/