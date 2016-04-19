/****************************************************************************************************************************************************
 *  File Name                   : printelementsrowcolumnsorted.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\printelementsrowcolumnsorted.h
 *  Created on                  : Jan 5, 2015 :: 11:21:49 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/print-elements-sorted-order-row-column-wise-sorted-matrix/
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

#ifndef PRINTELEMENTSROWCOLUMNSORTED_H_
#define PRINTELEMENTSROWCOLUMNSORTED_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void pesmMinHeapify(vector<iRowColumn *> &heap,unsigned int index) {
    if(heap.size() == 0 || index >= heap.size()) {
        return;
    }
    while(2*index + 1 < heap.size()) {
        if(2*index + 2 < heap.size()) {
            if(heap[index]->value > heap[2*index+2]->value || heap[index]->value > heap[2*index + 1]->value) {
                if(heap[2*index+1]->value < heap[2*index+2]->value) {
                    swap(heap[2*index+1],heap[index]);
                    index = 2*index+1;
                } else {
                    swap(heap[2*index+2],heap[index]);
                    index = 2*index+2;
                }
            } else {
                break;
            }
        } else {
            if(heap[2*index+1]->value < heap[index]->value) {
                swap(heap[2*index+1],heap[index]);
                index = 2*index+1;
            } else {
                break;
            }
        }
    }
}

//Tested
iRowColumn *pesmGetMinElement(vector<iRowColumn *> &heap) {
    if(heap.size() == 0) {
        throw "Heap is empty";
    }
    return heap[0];
}

//Tested
void pesmDeleteMin(vector<iRowColumn *> &heap) {
    if(heap.size() == 0) {
        throw "Heap is empty";
    }
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    pesmMinHeapify(heap,0);
}

//Tested
void pesmInsertIntoHeap(vector<iRowColumn *> &heap,iRowColumn *key) {
    heap.push_back(key);
    unsigned int index = heap.size()-1;
    while(index > 0) {
        if(heap[index]->value < heap[index/2]->value) {
            swap(heap[index],heap[index/2]);
        } else {
            break;
        }
        index /= 2;
    }
}

//Tested
void printElementsSortedMatrix(vector<vector<int> > userInput) {
    if(userInput.size() == 0 || userInput[0].size() == 0) {
        return;
    }
    vector<iRowColumn *> heap;
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        heap.push_back(new iRowColumn(userInput[rowCounter][0],rowCounter,0));
    }
    for(int counter = (int)(heap.size()/2); counter >= 0; counter--) {
        pesmMinHeapify(heap,counter);
    }
    iRowColumn *min;
    while(heap.size() > 0) {
        min = pesmGetMinElement(heap);
        printf("%d\t",min->value);
        pesmDeleteMin(heap);
        if(min->column + 1 < (int)userInput[min->row].size()) {
            min->column += 1;
            min->value = userInput[min->row][min->column];
            pesmInsertIntoHeap(heap,min);
        }
    }
}

#endif /* PRINTELEMENTSROWCOLUMNSORTED_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
