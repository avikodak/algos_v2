/****************************************************************************************************************************************************
 *  File Name                   : trieutil.h
 *  File Location               : \algos_v2\src\lib\utils\trieutil.h
 *  Created on                  : Oct 24, 2014 :: 11:00:25 AM
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

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef TRIEUTIL_H_
#define TRIEUTIL_H_

class trieutils {
private:
    void insertMain(cTrieNode *ptr,char *userInput) {
        if(ptr == null && userInput == null) {
            return;
        }
        if(ptr == null) {
            throw "Node is null";
        }
        if(userInput == null) {
            ptr->isLeafNode = true;
            return;
        }
        char ch = *userInput;
        unsigned int currentCharIndex = ch - 'a';
        if(ptr->children[currentCharIndex] == null) {
            ptr->children[currentCharIndex] = new cTrieNode();
        }
        insertMain(ptr->children[currentCharIndex],userInput+1);
    }

    void insertMain(cpTrieNode *ptr,char *userInput) {
        if(ptr == null && userInput == null) {
            return;
        }
        if(ptr == null) {
            throw "Node is null";
        }
        if(userInput == null) {
            ptr->isLeafNode = true;
            return;
        }
        char ch = *userInput;
        char currentCharIndex = ch - 'a';
        if(ptr->children[currentCharIndex] == null) {
            ptr->children[currentCharIndex] = new cpTrieNode(ptr);
        }
        insertMain(ptr->children[currentCharIndex],userInput+1);
    }

public:
    void insert(cTrieNode **root,char *userInput) {
        if(*root == null) {
            *root = new cTrieNode();
        }
        insertMain(*root,userInput);
    }

    void insert(cpTrieNode **root,char *userInput) {
        if(*root == null) {
            *root = new cpTrieNode();
        }
        insert(root,userInput);
    }

    void insertIterative(cTrieNode **root,char *userInput) {
        if(*root == null) {
            *root = new cTrieNode();
        }
        char ch = *userInput;
        unsigned int currentCharIndex;
        cTrieNode *crawler = *root;
        while((ch = *userInput) != '\0') {
            currentCharIndex = ch - 'a';
            if(crawler->children[currentCharIndex] == null) {
                crawler->children[currentCharIndex] = new cTrieNode();
            }
            crawler = crawler->children[currentCharIndex];
            userInput++;
        }
        crawler->isLeafNode = true;
    }

    void insertIterative(cpTrieNode **root,char *userInput) {
        if(*root == null) {
            *root = new cpTrieNode();
        }
        char ch;
        unsigned int currentCharIndex;
        cpTrieNode *crawler = *root;
        while((ch = *userInput) != '\0') {
            currentCharIndex = ch - 'a';
            if(crawler->children[currentCharIndex] == null) {
                crawler->children[currentCharIndex] = new cpTrieNode(crawler);
            }
            crawler = crawler->children[currentCharIndex];
            userInput++;
        }
        crawler->isLeafNode = true;
    }

    bool searchIterative(cTrieNode *root,char *userInput) {
        if(root == null && userInput == null) {
            return true;
        }
        cTrieNode *crawler = root;
        char ch = *userInput;
        unsigned int currentCharIndex;
        while(userInput != null) {
            ch = *userInput;
            currentCharIndex = ch - 'a';
            if(crawler->children[currentCharIndex] == null) {
                return false;
            }
            crawler = crawler->children[currentCharIndex];
            userInput++;
        }
        return crawler->isLeafNode;
    }
};

#endif /* TRIEUTIL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
