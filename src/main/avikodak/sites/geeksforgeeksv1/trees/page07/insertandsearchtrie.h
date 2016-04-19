/****************************************************************************************************************************************************
 *  File Name   		: insertandsearchtrie.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\insertandsearchtrie.h
 *  Created on			: Oct 24, 2014 :: 10:32:37 AM
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

#ifndef INSERTANDSEARCHTRIE_H_
#define INSERTANDSEARCHTRIE_H_

void insertIntoTrieIterative(cTrieNode **root,char *userInput) {
    if(*root == null) {
        (*root) = new cTrieNode();
    }
    cTrieNode *crawler = *root;
    char ch;
    unsigned int currentCharIndex;
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

void insertIntoTrieMain(cTrieNode *root,char *userInput) {
    if(root == null && userInput == null) {
        return;
    }
    if(root == null) {
        throw "Node is null";
    }
    if(userInput == '\0') {
        root->isLeafNode = true;
        return;
    }
    char ch = *userInput;
    unsigned int currentCharIndex = ch-'a';
    if(root->children[currentCharIndex] == null) {
        root->children[currentCharIndex] = new cTrieNode();
    }
    insertIntoTrieMain(root->children[currentCharIndex],userInput+1);
}

void insertIntoTrie(cTrieNode **root,char *userInput) {
    if(*root == null) {
        *root = new cTrieNode();
    }
    insertIntoTrieMain(root,userInput);
}

bool searchForWordInTrie(cTrieNode *root,char *userInput) {
    if(root == null) {
        return userInput == null;
    }
    cTrieNode *crawler = root;
    char ch;
    unsigned int currentCharIndex;
    while((ch = *userInput) != '\0') {
        currentCharIndex = ch - 'a';
        if(crawler->children[currentCharIndex] == null) {
            return false;
        }
        crawler = crawler->children[currentCharIndex];
        userInput++;
    }
    return crawler->isLeafNode;
}

bool searchForWordInTrie(cTrieNode *root,char *userInput) {
    if(root == null && userInput == null) {
        return true;
    }
    if(root == null || userInput == null) {
        if(userInput == null) {
            return root->isLeafNode;
        } else {
            return false;
        }
    }
    char ch = *userInput;
    unsigned int currentCharIndex = ch - 'a';
    if(root->children[currentCharIndex] == null) {
        return false;
    }
    return searchForWordInTrie(root->children[currentCharIndex],userInput+1);
}

#endif /* INSERTANDSEARCHTRIE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
