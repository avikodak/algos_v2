/****************************************************************************************************************************************************
 *  File Name   		: dynamicset.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture02\dynamicset.h
 *  Created on			: Oct 18, 2014 :: 1:16:25 PM
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef DYNAMICSET_H_
#define DYNAMICSET_H_

//Tested
class dynamicset {
private:
    sillNode *head;
public:
    dynamicset() {
        head = null;
    }

    //Tested
    bool isIn(int value) {
        sillNode *crawler = head;
        while(crawler != null) {
            if(crawler->value == value) {
                return true;
            }
        }
        return false;
    }

    //Tested
    unsigned int size() {
        sillNode *crawler = head;
        unsigned int counter = 0;
        while(crawler != null) {
            counter++;
            crawler = crawler->next;
        }
        return counter;
    }

    //Tested
    void insert(int value) {
        if(head == null) {
            head = new sillNode(value);
        } else {
            sillNode *crawler = head;
            while(crawler->next != null) {
                if(crawler->value == value) {
                    return;
                }
                crawler = crawler->next;
            }
            if(crawler->value == value) {
                return;
            }
            crawler->next = new sillNode(value);
        }
    }

    //Tested
    void deleteVal(int value) {
        sillNode *crawler = head,*temp;
        if(crawler->value == value) {
            head = crawler->next;
            free(crawler);
            return;
        }
        while(crawler->next != null && crawler->next->value != value) {
            crawler = crawler->next;
        }
        if(crawler->next != null) {
            temp = crawler->next;
            crawler->next = crawler->next->next;
            free(temp);
        }
    }

    //Tested
    void printSet() {
        sillNode *crawler = head;
        while(crawler != null) {
            printf("%d\t",crawler->value);
            crawler = crawler->next;
        }
    }
};

#endif /* DYNAMICSET_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
