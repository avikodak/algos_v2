/****************************************************************************************************************************************************
 *  File Name   		: firstnonrepeatingchar.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page05\firstnonrepeatingchar.h
 *  Created on			: Dec 3, 2014 :: 11:11:52 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
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

#ifndef FIRSTNONREPEATINGCHAR_H_
#define FIRSTNONREPEATINGCHAR_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
char getFirstnonRepeatingCharHashmap(char *userInput) {
    if(userInput == null) {
        return '\0';
    }
    hash_map<char,unsigned int> frequencyMap;
    hash_map<char,unsigned int>::iterator itToFrequencyMap;
    char *crawler = userInput;
    while(*crawler != '\0') {
        if(frequencyMap.find(crawler[0]) == frequencyMap.end()) {
            frequencyMap[crawler[0]] = 1;
        } else {
            frequencyMap[crawler[0]] += 1;
        }
        userInput++;
    }
    while(*userInput != '\0') {
        itToFrequencyMap = frequencyMap.find(userInput[0]);
        if(itToFrequencyMap->second > 1) {
            return itToFrequencyMap->first;
        }
    }
    return '\0';
}

char getFirstNonRepeatingCharArray(char *userInput) {
    if(userInput == null) {
        return '\0';
    }
    int frequency[ASCII_CHAR_SIZE] = {0};
    char *crawler = userInput;
    while(*crawler != '\0') {
        frequency[crawler[0]]++;
        crawler++;
    }
    while(*userInput != '\0') {
        if(frequency[userInput[0]] == 1) {
            return userInput[0];
        }
        userInput++;
    }
    return '\0';
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int gnrcDivideStepQuickSort(char *userInput,int startIndex,int endIndex) {
    if(userInput == null || startIndex > endIndex) {
        return INT_MIN;
    }
    int pivotIndex = endIndex;
    char key = userInput[pivotIndex],temp;
    while(startIndex < endIndex) {
        while(userInput[startIndex] < key) {
            startIndex++;
        }
        while(startIndex < endIndex && userInput[endIndex] >= key) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            temp = userInput[startIndex];
            userInput[startIndex] = userInput[endIndex];
            userInput[endIndex] = temp;
        }
    }
    temp = userInput[endIndex];
    userInput[endIndex] = userInput[pivotIndex];
    userInput[pivotIndex] = temp;
    return endIndex;
}

void gnrcQuickSort(char *userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return;
    }
    int dividingIndex = gnrcDivideStepQuickSort(userInput,startIndex,endIndex);
    gnrcQuickSort(userInput,startIndex,dividingIndex-1);
    gnrcQuickSort(userInput,dividingIndex+1,endIndex);
}

int getLowIndexForCharBinarySearch(char *userInput,char ch,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    int middleIndex = (startIndex + endIndex)/2;
    if(userInput[middleIndex] == ch) {
        if(middleIndex-1 >= startIndex && userInput[middleIndex-1] == ch) {
            return getLowIndexForCharBinarySearch(userInput,ch,startIndex,middleIndex-1);
        } else {
            return middleIndex;
        }
    } else if(userInput[middleIndex] > ch) {
        return getLowIndexForCharBinarySearch(userInput,ch,startIndex,middleIndex-1);
    } else {
        return getLowIndexForCharBinarySearch(userInput,ch,middleIndex+1,endIndex);
    }
}

char getFirstNonRepeatingChar(char *userInput) {
    if(userInput == null) {
        return '\0';
    }
    char *crawler = userInput;
    int lengthOfString = strlen(userInput);
    gnrcQuickSort(userInput,0,lengthOfString-1);
    int index;
    while(*crawler != '\0') {
        index = getLowIndexForCharBinarySearch(userInput,crawler[0],0,lengthOfString-1);
        if(index + 1 >= lengthOfString || userInput[index] != userInput[index+1]) {
            return true;
        }
        crawler++;
    }
}

void gnrcMerge(char *userInput,int startIndex,int middleIndex,int endIndex) {
    if(userInput == null) {
        return;
    }
    char *auxSpace = (char *)malloc(sizeof(char) * (endIndex - startIndex + 2));
    int firstCrawler = startIndex,secondCrawler = middleIndex+1;
    int fillCouter = -1;
    while(firstCrawler <= middleIndex || secondCrawler <= endIndex) {
        if(firstCrawler > middleIndex || secondCrawler > endIndex) {
            if(firstCrawler <= middleIndex) {
                auxSpace[++fillCouter] = userInput[firstCrawler++];
            } else {
                auxSpace[++fillCouter] = userInput[secondCrawler++];
            }
        } else {
            if(userInput[firstCrawler] < userInput[secondCrawler]) {
                auxSpace[++fillCouter] = userInput[firstCrawler++];
            } else {
                auxSpace[++fillCouter] = userInput[secondCrawler++];
            }
        }
    }
    for(unsigned int counter = 0; counter <= endIndex - startIndex; counter++) {
        userInput[startIndex + counter] = auxSpace[counter];
    }
}

void gnrcMergeSort(char *userInput,int startIndex,int endIndex) {
    if(userInput == null || startIndex > endIndex) {
        return;
    }
    int middleIndex = (startIndex + endIndex)/2;
    gnrcMergeSort(userInput,startIndex,middleIndex);
    gnrcMergeSort(userInput,middleIndex+1,endIndex);
    gnrcMerge(userInput,startIndex,middleIndex,endIndex);
}

void gnrcRotateNodes(cfpAvlNode *parent,cfpAvlNode *child) {
    if(parent == null || child == null) {
        return;
    }
    ifpAvlNode *grandParent = parent->parent;
    parent->parent = child;
    child->parent = grandParent;
    if(grandParent != null) {
        if(grandParent->left == parent) {
            grandParent->left = child;
        } else {
            grandParent->right = child;
        }
    }
    if(parent->left == child) {
        parent->left = child->right;
        child->right = parent;
    } else {
        parent->right = child->left;
        child->left = parent;
    }
}

cfpAvlNode *gnrcInsertAtRightPlace(cfpAvlNode **root,cfpAvlNode *currentNode,char ch) {
    if(*root == null) {
        (*root) = new cfpAvlNode(ch);
        return null;
    } else if(currentNode->ch == ch) {
        currentNode->frequency += 1;
        return null;
    } else if(currentNode->ch > ch) {
        if(currentNode->left == null) {
            currentNode->left = new cfpAvlNode(ch);
            currentNode->left->parent = currentNode;
            return currentNode;
        } else {
            return gnrcInsertAtRightPlace(root,currentNode->right,ch);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new cfpAvlNode(ch);
            currentNode->right->parent = currentNode;
            return currentNode;
        } else {
            return gnrcInsertAtRightPlace(root,currentNode->right,ch);
        }
    }
}

void gnrcInsertIntoAvlTree(cfpAvlNode **root,char ch) {
    cfpAvlNode *z = gnrcInsertAtRightPlace(root,*root,ch);
    if(z == null) {
        return;
    }
    cfpAvlNode *y,*x;
    int leftHeight,rightHeight;
    while(z != null) {
        leftHeight = z->left == null?0:z->left->height;
        rightHeight = z->right == null?0:z->right->height;
        if(abs(leftHeight - rightHeight) > 1) {
            y = z->ch > ch?z->left:z->right;
            x = y->ch > ch?y->left:y->right;
            if((z->left == y && y->left == x)||(z->right == y && y->right == x)) {
                if(z->parent == null) {
                    (*root) = y;
                }
                gnrcRotateNodes(z,y);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
            } else {
                if(z->parent == null) {
                    (*root) = x;
                }
                gnrcRotateNodes(y,x);
                gnrcRotateNodes(z,x);
                z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
                y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
                x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
            }
            return;
        }
        z->height = 1 + max(leftHeight,rightHeight);
        z = z->parent;
    }
}

cfpAvlNode *gnrcSearchInAvlTree(cfpAvlNode *ptr,char ch) {
    if(ptr == null) {
        return null;
    }
    if(ptr->ch == ch) {
        return ptr;
    } else if(ptr->ch > ch) {
        return gnrcSearchInAvlTree(ptr->left,ch);
    } else {
        return gnrcSearchInAvlTree(ptr->right,ch);
    }
}

char getNonRepeatingCharAvlTree(char *userInput) {
    if(userInput == null) {
        return '\0';
    }
    char *crawler = userInput;
    cfpAvlNode *root = null,*ptrToKey;
    while(*crawler != '\0') {
        gnrcInsertAtRightPlace(root,*root,crawler[0]);
        crawler++;
    }
    while(*userInput != '\0') {
        ptrToKey = gnrcSearchInAvlTree(root,userInput[0]);
        if(ptrToKey->frequency == 1) {
            return ptrToKey->ch;
        }
        userInput++;
    }
    return '\0';
}

void gnrcRotateNodes(cfpRbTNode *parent,cfpRbTNode *child) {
    if(parent == null || child == null) {
        return;
    }
    cfpRbTNode *grandParent = parent->parent;
    parent->parent = child;
    child->parent = grandParent;
    if(grandParent != null) {
        if(grandParent->left == parent) {
            grandParent->left = child;
        } else {
            grandParent->right = child;
        }
    }
    if(parent->left == child) {
        parent->left = child->right;
        child->right  = parent;
    } else {
        parent->right = child->left;
        child->left = parent;
    }
}

cfpRbTNode *gnrcInsertAtRightPlace(cfpRbTNode *parent,cfpRbTNode *child) {
    if(parent == null || child == null) {
        return;
    }
    cfpRbTNode *grandParent = parent->parent;
    parent->parent = child;
    child->parent = parent;
    if(grandParent != null) {
        if(grandParent->left == parent) {
            grandParent->left = child;
        } else {
            grandParent->right = child;
        }
    }
    if(parent->left == child) {
        parent->left = child->right;
        child->right = parent;
    } else {
        parent->right = child->left;
        child->left = parent;
    }
}

cfpRbTNode *gnrcInsertAtRightPlace(cfpRbTNode **root,cfpRbTNode *currentNode,char ch) {
    if(*root == null) {
        (*root) = new cfpRbTNode(ch);
        (*root)->isRedNode = false;
        return null;
    } else if(currentNode->ch == ch) {
        currentNode->frequency += 1;
        return null;
    } else if(currentNode->ch > ch) {
        if(currentNode->left == null) {
            currentNode->left = new cfpRbTNode(ch);
            currentNode->left->parent = currentNode;
            return currentNode->left;
        } else {
            return gnrcInsertIntoRbTree(root,currentNode->left,ch);
        }
    } else {
        if(currentNode->right == null) {
            currentNode->right = new cfpRbTNode(ch);
            currentNode->right->parent = currentNode;
            return currentNode->right;
        } else {
            return gnrcInsertIntoRbTree(root,currentNode->right,ch);
        }
    }
}

void gnrcReorganizeTreePostInsertion(cfpRbTNode **root,cfpRbTNode *currentNode) {
    if(*root == null || currentNode == null) {
        return;
    }
    cfpRbTNode *parent = currentNode->parent,*grandParent = parent->parent;
    if(!parent->isRedNode) {
        return;
    }
    if(grandParent->left == parent) {
        if(grandParent->right == null && !grandParent->right->isRedNode) {
            if(grandParent->parent == null) {
                (*root) = parent;
            }
            gnrcRotateNodes(grandParent,parent);
            grandParent->isRedNode = true;
            parent->isRedNode = false;
            return;
        } else {
            grandParent->isRedNode = true;
            grandParent->left->isRedNode = false;
            grandParent->right->isRedNode = false;
            if(!grandParent->parent == null) {
                grandParent->isRedNode = false;
                return;
            }
            gnrcReorganizeTreePostInsertion(root,grandParent);
        }
    } else {
        if(grandParent->left == null && !grandParent->left->isRedNode) {
            if(grandParent->parent == null) {
                (*root) = parent;
            }
            gnrcRotateNodes(grandParent,parent);
            grandParent->isRedNode = true;
            parent->isRedNode = false;
            return;
        } else {
            grandParent->isRedNode = true;
            grandParent->left->isRedNode = false;
            grandParent->right->isRedNode = false;
            if(!grandParent->parent == null) {
                grandParent->isRedNode = false;
                return;
            }
            gnrcReorganizeTreePostInsertion(root,grandParent);
        }
    }
}

void gnrcInsertIntoRbTree(cfpRbTNode **root,char ch) {
    cfpRbTNode *ptrToKey = gnrcInsertAtRightPlace(root,*root,ch);
    if(ptrToKey == null || !ptrToKey->parent->isRedNode) {
        return;
    }
    gnrcReorganizeTreePostInsertion(root,ptrToKey);
}

cfpRbTNode *gnrcSearchRbTree(cfpRbTNode *ptr,char ch) {
    if(ptr == null) {
        return null;
    }
    if(ptr->ch == ch) {
        return ptr;
    } else if(ptr->ch > ch) {
        return gnrcSearchRbTree(ptr->left,ch);
    } else {
        return gnrcSearchRbTree(ptr->right,ch);
    }
}

char getFirstNonRepeatingCharRbTree(char *userInput) {
    if(userInput == null) {
        return '\0';
    }
    cfpRbTNode *root = null;
    char *crawler = userInput;
    while(*crawler != '\0') {
        gnrcInsertIntoRbTree(&root,crawler[0]);
        crawler++;
    }
    cfpRbTNode *ptrToKey = null;
    while(*userInput != '\0') {
        ptrToKey = gnrcSearchRbTree(root,userInput[0]);
        if(ptrToKey->frequency == 1) {
            return ptrToKey->ch;
        }
        userInput++;
    }
    return '\0';
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
char getFirstNonRepeatingCharON2(char *userInput) {
    if(userInput == null) {
        return '\0';
    }
    char *crawler = userInput;
    while(*userInput != '\0') {
        crawler = userInput+1;
        while(*crawler != '\0') {
            if(crawler[0] == userInput[0]) {
                break;
            }
        }
        if(crawler == '\0') {
            return userInput[0];
        }
    }
    return '\0';
}

#endif /* FIRSTNONREPEATINGCHAR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
