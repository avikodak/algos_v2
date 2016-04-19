/****************************************************************************************************************************************************
 *  File Name                   : sillutil.h
 *  File Location               : \algos_v2\src\lib\utils\sillutil.h
 *  Created on                  : Oct 9, 2014 :: 12:36:41 PM
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
#include <stdint.h>
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/commonutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef SILLUTIL_H_
#define SILLUTIL_H_

class sillutils {
private:
    void frontBackSplit(sillNode *ptr,sillNode **firstPtr,sillNode **secondPtr) {
        if(ptr == null || ptr->next == null) {
            (*firstPtr) = ptr;
            (*secondPtr) = null;
            return;
        }
        sillNode *slowPtr = ptr,*fastPtr = ptr->next;
        while(fastPtr != null) {
            fastPtr = fastPtr->next;
            if(fastPtr != null) {
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
        }
        (*secondPtr) = slowPtr->next;
        slowPtr->next = null;
        (*firstPtr)  = ptr;
    }

    sillNode *merge(sillNode *firstPtr,sillNode *secondPtr) {
        if(firstPtr == null || secondPtr == null) {
            return firstPtr == null?secondPtr:firstPtr;
        }
        sillNode *result = null;
        if(firstPtr->value < secondPtr->value) {
            result  = firstPtr;
            result->next = merge(firstPtr->next,secondPtr);
        } else {
            result = secondPtr;
        }
        return result;
    }
public:
    //Tested
    sillNode *getSillFromVector(vector<int> userInput,unsigned int currentIndex = 0) {
        if(currentIndex >= userInput.size()) {
            return null;
        }
        sillNode *node = new sillNode(userInput[currentIndex]);
        node->next = getSillFromVector(userInput,currentIndex+1);
        return node;
    }

    //Tested
    sillNode *getRandomSill(unsigned int numberOfNodes,int minValue = INT_MIN,int maxValue = INT_MAX) {
        vector<int> randomVector = generateIRandomVector(numberOfNodes,minValue,maxValue);
        printIVector(randomVector);
        return getSillFromVector(randomVector);
    }

    //Tested
    unsigned int lengthOfSill(sillNode *ptr) {
        return ptr == null?0:1+lengthOfSill(ptr->next);
    }

    //Tested
    iSillHashmap *getSillAsHashmap(sillNode *ptr,unsigned int startIndex = 0) {
        if(ptr == null) {
            return null;
        }
        hash_map<unsigned int,sillNode *> indexNodeMap;
        hash_map<intptr_t,unsigned int> nodeIndexMap;
        while(ptr != null) {
            indexNodeMap.insert(pair<unsigned int,sillNode *>(startIndex,ptr));
            nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,startIndex));
            startIndex += 1;
            ptr = ptr->next;
        }
        iSillHashmap *hashMapOfSill = new iSillHashmap();
        hashMapOfSill->indexNodeMap = indexNodeMap;
        hashMapOfSill->nodeIndexMap = nodeIndexMap;
        return hashMapOfSill;
    }

    //Tested
    void printSill(sillNode *ptr) {
        while(ptr != null) {
            printf("%d\t",ptr->value);
            ptr = ptr->next;
        }
    }

    void mergeSort(sillNode **ptr) {
        if(*ptr == null || (*ptr)->next == null) {
            return;
        }
        sillNode *firstPtr = null,*secondPtr = null;
        frontBackSplit(*ptr,&firstPtr,&secondPtr);
        mergeSort(&firstPtr);
        mergeSort(&secondPtr);
        (*ptr) = merge(firstPtr,secondPtr);
    }
};

#endif /* SILLUTIL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
