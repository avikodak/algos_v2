/****************************************************************************************************************************************************
 *  File Name                   : heapsort.h
 *  File Location               : \algos_v2\src\main\avikodak\misc\sorting\heapsort.h
 *  Created on                  : Dec 23, 2014 :: 9:55:49 AM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void heapify(vector<int> &heap,int size,int index) {
    if(size == 0 || index >= size) {
        return;
    }
    while(index < size) {
        if(2*index + 2 < size) {
            if(heap[index] > heap[2*index+2] || heap[index] > heap[2*index+1]) {
                if(heap[2*index+1] < heap[2*index+2]) {
                    swap(heap[index],heap[2*index+1]);
                    index = 2*index+1;
                } else {
                    swap(heap[index],heap[2*index+2]);
                    index = 2*index+2;
                }
            } else {
                return;
            }
        } else if(2*index + 1 < size) {
            if(heap[index] > heap[2*index+1]) {
                swap(heap[index],heap[2*index+1]);
                index = 2*index+1;
            } else {
                return;
            }
        } else {
            return;
        }
    }
}

int getMin(vector<int> heap,int size) {
    if(size == 0) {
        throw "Heap is empty";
    }
    return heap[0];
}

//Tested
int deleteMin(vector<int> &userInput,int size) {
    if(size == 0) {
        return INT_MIN;
    }
    swap(userInput[0],userInput[size-1]);
    if(size != 1) {
        heapify(userInput,size-1,0);
        return size-1;
    }
    return 0;
}

//Tested
void hsReverseArray(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    int startIndex = 0,endIndex = userInput.size()-1;
    while(startIndex < endIndex) {
        swap(userInput[startIndex],userInput[endIndex]);
        startIndex++;
        endIndex--;
    }
}

//Tested
void heapSort(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    for(int counter = userInput.size()/2; counter >= 0; counter--) {
        heapify(userInput,(int)userInput.size(),counter);
    }
    int size = userInput.size();
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        size = deleteMin(userInput,size);
    }
    hsReverseArray(userInput);
}

#endif /* HEAPSORT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
