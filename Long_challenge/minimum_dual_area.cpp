#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while (t--) {
        vector<pair<long long, long long> > point, upoint;
        multiset<long long> X, Y;
        long long n, area = LONG_MAX;
        cin>>n;
        long long i;
        long long temp1, temp2;
        for (i=0; i<n; i++){
            cin >> temp1 >> temp2;
            point.push_back(make_pair(temp1, temp2));
            upoint.push_back(make_pair(temp2, temp1));
            X.insert(temp1);
            Y.insert(temp2);
        }
        sort(point.begin(), point.end());
        sort(upoint.begin(), upoint.end());
        long long h1 = 0, h2 = 0, h1_max = 0;
        long long h1_min = LONG_MAX, new_area = 0;
        for(i=0; i<n-1; ++i){
            h1_max = max(h1_max, point[i].second);
            h1_min = min(h1_min, point[i].second);
            h1 = h1_max - h1_min;
            auto index = Y.find(point[i].second);
            Y.erase(index);
            h2 = *Y.rbegin() - *Y.begin();
            new_area = ((point[i].first - point[0].first) * h1) + ((point[n-1].first - point[i+1].first) * h2);
            area = min(area, new_area);
        }
        h1=0, h2=0, h1_max=0, h1_min = LONG_MAX, new_area=0;
        for(i=0; i<n-1; ++i){
            h1_max = max(h1_max, upoint[i].second);
            h1_min = min(h1_min, upoint[i].second);
            h1 = h1_max - h1_min;
            auto index = X.find(upoint[i].second);
            X.erase(index);
            h2 = *X.rbegin() - *X.begin();
            new_area = ((upoint[i].first - upoint[0].first) * h1) + ((upoint[n-1].first - upoint[i+1].first) * h2);
            area = min(area, new_area);
        }
        if(area == LONG_MAX){
            area = 0;
        }
        cout<<area<<endl;
    }
    return 0;
}