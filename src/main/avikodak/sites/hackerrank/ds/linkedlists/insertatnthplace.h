/****************************************************************************************************************************************************
 *  File Name                   : insertatnthplace.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\linkedlists\insertatnthplace.h
 *  Created on                  : May 24, 2015 :: 5:35:54 PM
 *  Author                      : avikodak
 *  Testing Status              : https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list
 *  URL                         : Tested
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef INSERTATNTHPLACE_H_
#define INSERTATNTHPLACE_H_

struct Node {
    int data;
    struct Node *next;
};

//Tested
Node *createNode(int data) {
    Node *nHead = (Node *)malloc(sizeof(Node));
    nHead->data = data;
    nHead->next = null;
    return nHead;
}

//Tested
Node* InsertNth(Node *head, int data, int position) {
    Node *newNode = createNode(data);
    if(position == 0) {
        if(head == null) {
            return newNode;
        } else {
            newNode->next = head;
            return newNode;
        }
    } else {
        int counter = 0;
        Node *crawler = head;
        while(counter+1 != position && crawler != null) {
            crawler = crawler->next;
            counter++;
        }
        if(crawler != null) {
            newNode->next = crawler->next;
            crawler->next = newNode;
        }
    }
    return head;
}


#endif /* INSERTATNTHPLACE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
