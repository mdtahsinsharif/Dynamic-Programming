#include <bits/stdc++.h>
using namespace std;
#define V 4

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int arr[][V], int start){
    vector<int> v;
    for(int i=0; i<V; i++){
        if(i!=(start-1)){
            v.push_back(i);
        }
    }
    
    int min_length, curr_length = 0, k;
    do{
        cout << "Perm: ";
        k = start-1;
        for(int i=0; i<v.size(); i++){
            cout << " " << v[i] << " ";
            curr_length += arr[k][v[i]];
            k = v[i];
        }
        cout << endl;
        curr_length += arr[k][start-1];
        
        if(min_length > curr_length){
            min_length = curr_length;
        }
        curr_length = 0;
    } while(next_permutation(v.begin(),v.end()));
    
    return min_length;
}

// driver program to test above function
int main()
{
    // matrix representation of graph
    int graph[][V] = { { 0, 10, 15, 10 },
        { 10, 0, 15, 25 },
        { 15, 15, 0, 10 },
        { 10, 25, 30, 0 } };
    int s = 1;
    cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}
