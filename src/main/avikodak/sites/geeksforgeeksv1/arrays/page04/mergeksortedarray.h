/****************************************************************************************************************************************************
 *  File Name                   : mergeksortedarray.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\mergeksortedarray.h
 *  Created on                  : Dec 22, 2014 :: 9:26:52 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/merge-k-sorted-arrays/
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

#ifndef MERGEKSORTEDARRAY_H_
#define MERGEKSORTEDARRAY_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void mksaHeapify(vector<iRowColumn *> &heap,unsigned int index) {
    if(heap.size() == 0) {
        return;
    }
    while(index < heap.size()) {
        if(2*index+2 < heap.size()) {
            if(heap[2*index+2]->value < heap[index]->value || heap[2*index+1]->value < heap[index]->value) {
                if(heap[2*index+2]->value > heap[2*index+1]->value) {
                    swap(heap[index],heap[2*index+1]);
                    index = 2*index + 1;
                } else {
                    swap(heap[index],heap[2*index+2]);
                    index = 2*index + 2;
                }
            } else {
                break;
            }
        } else if(2*index + 1 < heap.size()) {
            if(heap[2*index+1]->value < heap[index]->value) {
                swap(heap[index],heap[2*index+1]);
                index = 2*index + 1;
            } else {
                break;
            }
        } else {
            break;
        }
    }
}

//Tested
iRowColumn *mksaGetMin(vector<iRowColumn *> &heap) {
    if(heap.size() == 0) {
        throw "Heap is empty";
    }
    return heap[0];
}

//Tested
void mksaDeleteMin(vector<iRowColumn *> &heap) {
    if(heap.size() == 0) {
        throw "Heap is empty";
    }
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    if(heap.size() > 0) {
        mksaHeapify(heap,0);
    }
}

//Tested
void mksaInsertIntoHeap(vector<iRowColumn *> &heap,iRowColumn *key) {
    heap.push_back(key);
    int index = heap.size()-1;
    while(index > 0) {
        if(heap[index/2]->value > heap[index]->value) {
            swap(heap[index],heap[index/2]);
        } else {
            break;
        }
        index = index/2;
    }
}

//Tested
vector<int> mksaMergeKSortedArray(vector<vector<int> > userInput) {
    vector<int> mergedArray;
    if(userInput.size() == 0 || userInput[0].size() == 0) {
        return mergedArray;
    }
    vector<iRowColumn *> heap;
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        heap.push_back(new iRowColumn(userInput[rowCounter][0],rowCounter,0));
    }
    for(int counter = heap.size()/2; counter >= 0; counter--) {
        mksaHeapify(heap,counter);
    }
    iRowColumn *temp;
    while(heap.size() != 0) {
        temp = mksaGetMin(heap);
        mergedArray.push_back(temp->value);
        mksaDeleteMin(heap);
        if(temp->column+1 < (int)userInput[temp->row].size()) {
            temp->column += 1;
            temp->value = userInput[temp->row][temp->column];
            mksaInsertIntoHeap(heap,temp);
        }
    }
    return mergedArray;
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
vector<int> mergeKSortedArrayBySorting(vector<vector<int> > userInput) {
    vector<int> mergedArray;
    if(userInput.size() < 0) {
        return mergedArray;
    }
    for(unsigned int outerCrawler = 0; outerCrawler < userInput.size(); outerCrawler++) {
        for(unsigned int innerCrawler = 0; innerCrawler < userInput[0].size(); innerCrawler++) {
            mergedArray.push_back(userInput[outerCrawler][innerCrawler]);
        }
    }
    sort(mergedArray.begin(),mergedArray.end());
    return mergedArray;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/


#endif /* MERGEKSORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
