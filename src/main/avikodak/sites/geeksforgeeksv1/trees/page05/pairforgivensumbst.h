/****************************************************************************************************************************************************
 *  File Name   		: pairforgivensumbst.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\pairforgivensumbst.h
 *  Created on			: Nov 13, 2014 :: 6:57:00 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PAIRFORGIVENSUMBST_H_
#define PAIRFORGIVENSUMBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void psFixLeftPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    psFixLeftPtr(ptr->left);
    ptr->left = prevNode;
    prevNode = ptr;
    psFixLeftPtr(ptr->right);
}

//Tested
itNode *psFixRightPtr(itNode **ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *currentNode = *ptr,*prevNode = null;
    while(currentNode->right != null) {
        currentNode = currentNode->right;
    }
    (*ptr) = currentNode;
    while(currentNode != null) {
        currentNode->right = prevNode;
        prevNode = currentNode;
        currentNode = currentNode->left;
    }
    return prevNode;
}

//Tested
iPair *checkForPairPostDllConversion(itNode *head,itNode *tail,int sum) {
    int currentSum;
    while(head != tail) {
        currentSum = head->value + tail->value;
        if(currentSum == sum) {
            return new iPair(head->value,tail->value);
        }
        if(head->right == tail) {
            break;
        }
        if(currentSum > sum) {
            tail = tail->left;
        } else {
            head = head->right;
        }
    }
    return null;
}

//Tested
iPair *getPairForSumDllConversion(itNode *ptr,int sum) {
    if(ptr == null) {
        return null;
    }
    psFixLeftPtr(ptr);
    itNode *head = psFixRightPtr(&ptr);
    itNode *tail = ptr;
    return checkForPairPostDllConversion(head,tail,sum);
}

//Tested
void pConvertTreeToDllONMain(itNode *ptr,itNode **head,itNode **tail) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    pConvertTreeToDllONMain(ptr->left,head,tail);
    ptr->left = prevNode;
    if(prevNode == null) {
        (*head) = ptr;
    } else {
        prevNode->right = ptr;
    }
    prevNode = *tail = ptr;
    pConvertTreeToDllONMain(ptr->right,head,tail);
}

//Tested
iPair *pFindPairForGivenSum(itNode *ptr,int sum) {
    if(ptr == null) {
        return null;
    }
    itNode *head = null,*tail = null;
    pConvertTreeToDllONMain(ptr,&head,&tail);
    return checkForPairPostDllConversion(head,tail,sum);
}

//Tested
iPair *findPairForGivenSum(itNode *ptr,int sum) {
    if(ptr == null) {
        return null;
    }
    stack<itNode *> auxSpace,revAuxSpace;
    itNode *currentPtr = ptr,*currentRevPtr = ptr;
    int inorderCurrentValue,revInorderCurrentValue,currentSum;
    bool getNextValInorder = true,getNextValRevInorder = true;
    while(true) {
        while(getNextValInorder) {
            if(currentPtr != null) {
                auxSpace.push(currentPtr);
                currentPtr = currentPtr->left;
            } else {
                currentPtr = auxSpace.top();
                auxSpace.pop();
                inorderCurrentValue = currentPtr->value;
                currentPtr = currentPtr->right;
                getNextValInorder = false;
            }
        }
        while(getNextValRevInorder) {
            if(currentRevPtr != null) {
                revAuxSpace.push(currentRevPtr);
                currentRevPtr = currentRevPtr->right;
            } else {
                currentRevPtr = revAuxSpace.top();
                revAuxSpace.pop();
                revInorderCurrentValue = currentRevPtr->value;
                currentRevPtr = currentRevPtr->left;
                getNextValRevInorder = false;
            }
        }
        if(inorderCurrentValue > revInorderCurrentValue) {
            return null;
        }
        currentSum = inorderCurrentValue + revInorderCurrentValue;
        if(currentSum == sum) {
            return new iPair(inorderCurrentValue,revInorderCurrentValue);
        } else if(currentSum > sum) {
            getNextValRevInorder = true;
        } else {
            getNextValInorder = true;
        }
    }
    return null;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getPairForGivenSumBST(itNode *ptr,int sum) {
    if(ptr == null) {
        return null;
    }
    treeutils *utils = new treeutils();
    vector<int> preOrderValues = utils->getValuesInPreorder(ptr);
    sort(preOrderValues.begin(),preOrderValues.end());
    unsigned int frontCrawler = 0,rearCrawler = preOrderValues.size()-1;
    int currentSum;
    while(frontCrawler < rearCrawler) {
        currentSum = preOrderValues[frontCrawler] + preOrderValues[rearCrawler];
        if(currentSum == sum) {
            return new iPair(preOrderValues[frontCrawler],preOrderValues[rearCrawler]);
        } else if(currentSum > sum) {
            rearCrawler--;
        } else {
            frontCrawler++;
        }
    }
    return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *pConvertTreeToDllON2Main(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *temp;
    if(ptr->left != null) {
        temp = pConvertTreeToDllON2Main(ptr->left);
        while(temp->right != null) {
            temp = temp->right;
        }
        temp->right = ptr;
        ptr->left = temp;
    }
    if(ptr->right != null) {
        temp = pConvertTreeToDllON2Main(ptr->right);
        while(temp->left != null) {
            temp = temp->left;
        }
        temp->left = ptr;
        ptr->right = temp;
    }
    return ptr;
}

//Tested
iPair *getPairForDllConversion(itNode *ptr,int sum) {
    if(ptr == null) {
        return null;
    }
    pConvertTreeToDllON2Main(ptr);
    itNode *head = ptr,*tail = ptr;
    while(tail->right != null) {
        tail = tail->right;
    }
    while(head->left != null) {
        head = head->left;
    }
    return checkForPairPostDllConversion(head,tail,sum);
}

//Tested
itNode *searchForNode(itNode *ptr,itNode *key,int reqiredSum) {
    if(ptr == null) {
        return null;
    }
    if(ptr != key) {
        if(ptr->value == reqiredSum) {
            return ptr;
        }
    }
    itNode *result = searchForNode(ptr->left,key,reqiredSum);
    if(result != null) {
        return result;
    }
    return searchForNode(ptr->right,key,reqiredSum);
}

//Tested
iPair *getPairForGivenSum(itNode *ptr,int sum) {
    if(ptr == null) {
        return null;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode,*result;
    auxSpace.push(ptr);
    while(!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        if((result = searchForNode(ptr,currentNode,sum-currentNode->value)) != null) {
            return new iPair(currentNode->value,result->value);
        }
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
    }
    return null;
}

#endif /* PAIRFORGIVENSUMBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
