/****************************************************************************************************************************************************
 *  File Name                   : printduplicates.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page05\printduplicates.h
 *  Created on                  : Dec 3, 2014 :: 6:45:53 PM
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

#ifndef PRINTDUPLICATES_H_
#define PRINTDUPLICATES_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void printDuplicatesHashmap(char *userInput) {
    if(userInput == null) {
        return;
    }
    hash_map<char,unsigned int> charFrequency;
    hash_map<char,unsigned int>::iterator itToCharFrequency;
    while(*userInput != '\0') {
        if(charFrequency.find(userInput[0]) == charFrequency.end()) {
            charFrequency[userInput[0]] = 1;
        } else {
            charFrequency[userInput[0]] += 1;
        }
        userInput++;
    }
    for(itToCharFrequency = charFrequency.begin(); itToCharFrequency != charFrequency.end(); itToCharFrequency++) {
        if(itToCharFrequency->second > 1) {
            printf("%c\t",itToCharFrequency->first);
        }
    }
}

void printDuplicatesArray(char *userInput) {
    if(userInput == null) {
        return;
    }
    int frequencies[ASCII_CHAR_SIZE] =  {0};
    while(*userInput != '\0') {
        frequencies[(int)userInput[0]]++;
        userInput++;
    }
    for(unsigned int counter = 0; counter < ASCII_CHAR_SIZE; counter++) {
        if(frequencies[counter] > 1) {
            printf("%c\t",counter);
        }
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void pdupMerge(char *userInput,int startIndex,int middleIndex,int endIndex) {
    if(userInput == null) {
        return;
    }
    char *auxSpace = (char *)malloc(sizeof(char)*(endIndex - startIndex + 2));
    int fillCounter = -1;
    int firstCrawler = startIndex,secondCrawler = middleIndex+1;
    while(firstCrawler <= middleIndex || secondCrawler <= endIndex) {
        if(firstCrawler >  middleIndex || secondCrawler > endIndex) {
            if(firstCrawler <= middleIndex) {
                auxSpace[++fillCounter] = userInput[firstCrawler++];
            } else {
                auxSpace[++fillCounter] = userInput[secondCrawler++];
            }
        } else {
            if(userInput[firstCrawler] < userInput[secondCrawler]) {
                auxSpace[++fillCounter] = userInput[firstCrawler++];
            } else {
                auxSpace[++fillCounter] = userInput[secondCrawler++];
            }
        }
    }
    auxSpace[++fillCounter] = '\0';
    for(int counter = 0; counter <= endIndex-startIndex; counter++) {
        userInput[startIndex+counter] = auxSpace[counter];
    }
}

void pdupMergeSort(char *userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex || startIndex == endIndex) {
        return;
    }
    int middleIndex = (startIndex + endIndex)/2;
    pdupMergeSort(userInput,startIndex,middleIndex);
    pdupMergeSort(userInput,middleIndex+1,endIndex);
    pdupMerge(userInput,startIndex,middleIndex,endIndex);
}

void printDuplicateSorting(char *userInput) {
    if(userInput == null) {
        return;
    }
    int length = strlen(userInput),crawler = 0;
    pdupMergeSort(userInput,0,length-1);
    while(crawler+1 < length) {
        if(userInput[crawler] == userInput[crawler+1]) {
            printf("%c\t",userInput[crawler]);
            while(crawler+1 < length && userInput[crawler] == userInput[crawler+1]) {
                crawler++;
            }
        } else {
            crawler++;
        }
    }
}

int pdupDivideStepQuickSort(char *userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    char key = userInput[endIndex];
    int pivotIndex = userInput[endIndex];
    while(startIndex < endIndex) {
        while(userInput[startIndex] < key) {
            startIndex++;
        }
        while(startIndex < endIndex && userInput[endIndex] >= key) {
            endIndex--;
        }
        if(startIndex <  endIndex) {
            swap(userInput[startIndex],userInput[endIndex]);
        }
    }
    swap(userInput[pivotIndex],userInput[endIndex]);
    return endIndex;
}

void pdupQuickSort(char *userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return;
    }
    int middleIndex = pdupDivideStepQuickSort(userInput,startIndex,endIndex);
    pdupQuickSort(userInput,startIndex,middleIndex-1);
    pdupQuickSort(userInput,middleIndex+1,endIndex);
}

void printDuplicatesQuickSort(char *userInput) {
    if(*userInput != '\0') {
        return;
    }
    pdupDivideStepQuickSort(userInput,0,strlen(userInput)-1);
    while(*(userInput+1) != '\0') {
        if(userInput[1] != '\0' && userInput[0] == userInput[1]) {
            printf("%c",userInput[0]);
            while(userInput[1] != '\0' && userInput[0] == userInput[1]) {
                userInput++;
            }
            userInput++;
        }
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void printDuplicatesON2(char *userInput) {

}

void printDuplicatesInorderBST(cftNode *ptr) {
    if(ptr == null) {
        return;
    }
    printDuplicatesInorderBST(ptr->left);
    if(ptr->frequency > 1) {
        printf("%d\t",ptr->ch);
    }
    printDuplicatesInorderBST(ptr->right);
}

void printDuplicatesBSTON2(char *userInput) {
    if(userInput == null) {
        return;
    }
    treeutils *utils = new treeutils();
    cftNode *root = utils->getCFBSTFromString(userInput);
    printDuplicatesInorderBST(root);
}

#endif /* PRINTDUPLICATES_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
