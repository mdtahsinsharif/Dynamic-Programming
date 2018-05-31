//
//  main.cpp
//  min cost house
//
//  Created by Md Tahsin Sharif on 2018-05-30.
//  Copyright © 2018 Md Tahsin Sharif. All rights reserved.
//

using namespace std;
#include <iostream>
#include <vector>

#define MAX_COL 3
#define MAX_ROWS 3
int min_cost = 9999;

int min_cost_house(int arr[][MAX_COL], int row, int col){
    int  curr_cost = 0;
    vector<int> v;
    vector<int> costs;
    int start = 0;
    col = start;
    do{
        do{
            for(int x=0; x<MAX_COL; x++){
                if(col != x){
                    v.push_back(x);
                }
            }
            curr_cost += min(arr[row][v[0]], arr[row][v[1]]);
            
            
            for(int i=0; i<2; i++){
                std::cout << v[i] << " ";
            }
            cout << endl;
            
            col = arr[row, v[0]] > arr[row,v[1]]? v[1] : v[0];
            v.clear();
            row++;
        } while(row < MAX_ROWS);
        costs.push_back(curr_cost);
        start++;
        cout << " Start: " << start << endl;
        if(min_cost > curr_cost){
            min_cost = curr_cost;
        }
        
        curr_cost = 0;
        row = 0;
        col = start;
    } while (start < MAX_COL);
    
    return min_cost;
}

int main(int argc, const char * argv[]) {
    
    int arr[MAX_ROWS][MAX_COL] = {{5, 40, 10}, {35, 55, 5}, { 1, 15, 19}};
    std::cout << min_cost_house(arr, 0, 0);
    return 0;
}
