#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>& a , pair<int,int>& b){

    return a.second <  b.second;
}



int maximumActivities(vector<int> &start, vector<int> &finish) {


       vector<pair<int,int> > p;

       for(int i = 0; i < start.size(); i++){
    p.push_back(make_pair(start[i], finish[i]));
}


       sort(p.begin() , p.end() , cmp);

       int count  = 1;

      int prev = p[0].second;

       for(int i= 1 ;i<p.size() ; i++){
           if(p[i].first >= prev){
               count++;
               prev = p[i].second;
           }
       }

    return count;   
}

int main() {
    vector<int> start;
    start.push_back(1);
    start.push_back(3);
    start.push_back(0);
    start.push_back(5);
    start.push_back(8);
    start.push_back(5);
    
    vector<int> finish;
    finish.push_back(2);
	finish.push_back(4);
	finish.push_back(6);
	finish.push_back(7);
	finish.push_back(9);
	finish.push_back(9);
	
    int maxAct = maximumActivities(start, finish);

    cout << "Maximum number of activities that can be performed: " << maxAct << endl;

    return 0;
}
