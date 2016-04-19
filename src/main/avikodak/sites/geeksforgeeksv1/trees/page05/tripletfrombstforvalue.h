/****************************************************************************************************************************************************
 *  File Name                   : tripletfrombstforvalue.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\tripletfrombstforvalue.h
 *  Created on                  : Nov 13, 2014 :: 7:47:17 PM
 *  Author                      : avikodak
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef TRIPLETFROMBSTFORVALUE_H_
#define TRIPLETFROMBSTFORVALUE_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

iTriplet *getTripletForSumPostConversion(itNode *head,itNode *tail,int sum) {
    if(head == null) {
        return null;
    }
    itNode *outerCrawler = head,*frontCrawler,*rearCrawler;
    int currentSum;
    while(outerCrawler != null) {
        frontCrawler = outerCrawler->right;
        rearCrawler = tail;
        currentSum = outerCrawler->value;
        while(frontCrawler != rearCrawler) {
            currentSum = frontCrawler->value + rearCrawler->value;
            if(currentSum == sum) {
                return new iTriplet(outerCrawler->value,frontCrawler->value,rearCrawler->value);
            }
            if(frontCrawler->right == rearCrawler) {
                break;
            }
            if(currentSum > sum) {
                rearCrawler = rearCrawler->left;
            } else {
                frontCrawler = frontCrawler->right;
            }
        }
        outerCrawler = outerCrawler->right;
    }
    return null;
}

void tFixLeftPtr(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    tFixLeftPtr(ptr->left);
    ptr->left = prevNode;
    prevNode = ptr;
    tFixLeftPtr(ptr->right);
}

itNode *tFixRightPtr(itNode **ptr) {
    if(*ptr == null) {
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

iTriplet *tConvertTreeToDllONByFixingPtr(itNode *ptr,int sum) {
    if(ptr == null) {
        return null;
    }
    tFixLeftPtr(ptr);
    itNode *head = tFixRightPtr(&ptr);
    while(head != null) {
        printf("%d\t",head->value);
        head = head->right;
    }
    return 0;
    //return getTripletForSumPostConversion(head,ptr,sum);
}

void triConvertTreeToDllON(itNode *ptr,itNode **head,itNode **tail) {
    if(ptr == null) {
        return;
    }
    static itNode *prevNode = null;
    triConvertTreeToDllON(ptr->left,head,tail);
    ptr->left = prevNode;
    if(prevNode != null) {
        (*head) = ptr;
    } else {
        prevNode->right = ptr;
        *tail = prevNode;
    }
    prevNode = ptr;
    triConvertTreeToDllON(ptr->right,head,tail);
}

iTriplet *tripletByTreeToDllConversion(itNode *ptr,int sum) {
    if(ptr == null) {
        return null;
    }
    itNode *head = null,*tail = null;
    triConvertTreeToDllON(ptr,&head,&tail);
    while(head != null) {
        printf("%d\t",head->value);
        head = head->right;
    }
    return 0;
    //return getTripletForSumPostConversion(head,tail,sum);
}

itNode *tConvertTreeToDLLON2(itNode *ptr) {
    if(ptr == null) {
        return null;
    }
    itNode *temp;
    if(ptr->left != null) {
        temp = tConvertTreeToDLLON2(ptr->left);
        while(temp->right != null) {
            temp = temp->right;
        }
        temp->right = ptr;
        ptr->left = temp;
    }
    if(ptr->right != null) {
        temp = tConvertTreeToDLLON2(ptr->right);
        while(temp->left != null) {
            temp = temp->left;
        }
        temp->left = ptr;
        ptr->right = temp;
    }
    return ptr;
}

iTriplet *tripletByTreeToDllConversionON2(itNode *ptr,int sum) {
    if(ptr == null) {
        return null;
    }
    tConvertTreeToDLLON2(ptr);
    itNode *head = ptr,*tail = ptr;
    while(head->left != null) {
        head = head->left;
    }
    while(tail->right != null) {
        tail = tail->right;
    }
    return getTripletForSumPostConversion(head,tail,sum);
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^3) Algorithm                                                                     */
/****************************************************************************************************************************************************/


#endif /* TRIPLETFROMBSTFORVALUE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
