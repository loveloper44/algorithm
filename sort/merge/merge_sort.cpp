//
//  merge_sort.cpp
//  Test
//
//  Created by 윤인규 on 2018. 9. 12..
//  Copyright © 2018년 윤인규. All rights reserved.
//

#include "merge_sort.hpp"
#include <iostream>
using namespace std;

void print_arr(int * list){
    for(int i =0,size = 5;i<size;i++)
        cout << list[i] <<" ";
    cout <<endl;
}

void _merge(int* list, int start,int mid, int end){
    int temp[end-start+1];
    
    int li=start, ri=mid+1;
    
    int temp_index =0;
    
    while(li<=mid && ri <=end){
        if(list[li]<list[ri]){
            temp[temp_index] = list[li++];
        }else{
            temp[temp_index] = list[ri++];
        }
        temp_index++;
    }
    
    if(li<=mid){
        while(li<=mid){
            temp[temp_index] = list[li++];
            temp_index++;
        }
    }
    
    if(ri<=end){
        while(ri<=end){
            temp[temp_index] = list[ri++];
            temp_index++;
        }
    }
    
    for(int j=start;j<=end;j++){
        list[j] = temp[j-start];
    }
}

void _merge_sort(int* list,int start, int end){
    if(start>=end)return;
    
    int mid = (start+end)/2;
    
    //left
    _merge_sort(list,start,mid);
    //right
    _merge_sort(list,mid+1,end);
    
    
    _merge(list,start,mid,end);
    
    print_arr(list);
    
 }
