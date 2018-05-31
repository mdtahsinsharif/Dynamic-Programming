//
//  Max Rectangular Area.cpp
//  
//
//  Created by Md Tahsin Sharif on 2018-05-31.
//
/*
A city represented by a rectangular matrix is divided into plot of lands, and the cost of each plot is known. Find the largest rectangular area of land we can buy, within a budget B.

    4 6 7
    3 5 2
    2 4 5

    B = 16
*/


#include "Max Rectangular Area.hpp"
#include <iostream>

using namespace std;
#define V 3


int calculate_largest(int mat[][3], int max_cost){
    int curr_cost = 0, min_count = -1, curr_count = 0, j=0, dir = 0;
    
    int dir_arr[2] = {0,0};
    for(int i=0; i<2; i++)
    {
        while(dir_arr[!dir] < V)
        {
            curr_cost += mat[dir_arr[0]][dir_arr[1]];
            if(curr_cost > max_cost)
            {
                if(min_count < curr_count)
                {
                    min_count = curr_count;
                }
                curr_count = 0;
                curr_cost = 0;
                
            }
            else
            {
                curr_count++;
                ++dir_arr[dir];
            }
            
            if(dir_arr[dir] == V){
                dir_arr[dir] = 0;
                ++dir_arr[!dir];
                if(min_count < curr_count)
                {
                    min_count = curr_count;
                    curr_count = 0;
                }
                
            }
        }
        dir = !dir;
        dir_arr[dir] = 0;
        dir_arr[!dir] = 0;
    }
    return min_count;
}

int main()
{
    int max_cost = 20;
    int mat[V][V] = {{20,1,20},{1,2,3},{1,1,2}};
    
    cout<<calculate_largest(mat, max_cost);
    
    return 0;
}
