#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start, end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

int minCabs(const vector<Interval>& intervals) {
    vector<Interval> sortedIntervals = intervals;
    sort(sortedIntervals.begin(), sortedIntervals.end(), compareIntervals);

    int cabs = 0, lastEndTime = -1;

    for (const auto& interval : sortedIntervals) {
        if (interval.start >= lastEndTime) {
            cabs++;
            lastEndTime = interval.end;
        }
    }

    return cabs;
    
}

int main() {
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;

    vector<Interval> intervals;
    cout << "Enter start and end times for each person:\n";
    for (int i = 0; i < n; ++i) {
        Interval person;
        cout << "Person " << i + 1 << " - Start time: ";
        cin >> person.start;
        cout << "Person " << i + 1 << " - End time: ";
        cin >> person.end;
        intervals.push_back(person);
        cout<<endl;
    }

    int result = minCabs(intervals);

    cout << "Minimum number of cabs required: " << result << endl;

    return 0;
}