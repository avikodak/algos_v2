/****************************************************************************************************************************************************
 *  File Name   		: insertintotwofourtree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture13\insertintotwofourtree.h
 *  Created on			: Nov 19, 2014 :: 11:46:50 PM
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef INSERTINTOTWOFOURTREE_H_
#define INSERTINTOTWOFOURTREE_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void insertIntoTwoFourTree(i24Node **root,i24Node *currentNode,int value){
	static i24Node *prevNode,*prevFirstSplitNode,*prevSecondSplitNode;
	static bool flag;
	if(*root == null){
		(*root) = new i24Node(value);
		return;
	}
	if(currentNode->noOfChildren == 0 || flag){
		if(currentNode->noOfKeys < 3){
			currentNode->noOfKeys += 1;
			int counter = currentNode->noOfKeys - 2;
			while(counter >= 0){
				currentNode->value[counter+1] = currentNode->value[counter];
			}
			currentNode->value[counter] = value;
			if(prevNode != null){
				vector<i24Node *> childrenPtr;
				bool prevNodesConnected = false;
				for(unsigned int counter = 0;counter < currentNode->noOfChildren;counter++){
					if(currentNode->children[counter] == prevNode){
						counter++;
					}else if(currentNode->children[counter] < prevFirstSplitNode){
						childrenPtr.push_back(currentNode->children[counter]);
						counter++;
					}else{
						childrenPtr.push_back(prevFirstSplitNode);
						childrenPtr.push_back(prevSecondSplitNode);
						prevNodesConnected = true;
					}
				}
				if(!prevNodesConnected){
					childrenPtr.push_back(prevFirstSplitNode);
					childrenPtr.push_back(prevSecondSplitNode);
				}
				for(unsigned int counter = 0;counter <= currentNode->noOfKeys;counter++){
					currentNode->children[counter] = childrenPtr[counter];
					currentNode->children[counter]->parent = currentNode;
				}
			}
			prevNode = null;
			prevFirstSplitNode = null;
			prevSecondSplitNode = null;
			flag = false;
			return;
		}
		i24Node *firstSplitNode = new i24Node();
		i24Node *secondSplitNode = new i24Node();
		firstSplitNode->parent = currentNode->parent;
		secondSplitNode->parent = currentNode->parent;
		bool firstSplitNodeFilled = false,isValueInserted = false;
		int fillCounter = -1;
		for(unsigned int counter = 0;counter < currentNode->noOfKeys;){
			if(!firstSplitNodeFilled){
				if(currentNode->value[counter] < value){
					firstSplitNode->value[++fillCounter] = currentNode->value[counter];
					counter++;
				}else{
					isValueInserted = true;
					firstSplitNode->value[++fillCounter] = value;
				}
				if(fillCounter == 1){
					fillCounter = -1;
				}
			}else{
				if(currentNode->value[counter] < value){
					secondSplitNode->value[++fillCounter] = currentNode->value[counter];
					counter++;
				}else{
					isValueInserted = true;
					secondSplitNode->value[++fillCounter] = value;
				}
			}
		}
		if(!isValueInserted){
			secondSplitNode->value[2] = value;
		}
		firstSplitNode->noOfKeys = 1;
		secondSplitNode->noOfKeys = 2;
		if(prevNode != null){
			vector<i24Node *> childrenPtr;
			bool prevPtrConnected = false;
			for(unsigned int counter = 0;counter < currentNode->noOfChildren;){
				if(currentNode->children[counter] == prevNode){
					counter++;
					continue;
				}else if(currentNode->children[counter]->value[0] < prevFirstSplitNode->value[0]){
					childrenPtr.push_back(currentNode->children[counter]);
					counter++;
				}else{
					childrenPtr.push_back(prevFirstSplitNode);
					childrenPtr.push_back(prevSecondSplitNode);
				}
			}
			if(!prevPtrConnected){
				childrenPtr.push_back(prevFirstSplitNode);
				childrenPtr.push_back(prevSecondSplitNode);
			}
			unsigned int childrenCounter = 0;
			for(unsigned int counter = 0;counter <= firstSplitNode->noOfKeys;counter++){
				firstSplitNode->children[counter] = childrenPtr[childrenCounter++];
				firstSplitNode->children[counter]->parent = firstSplitNode;
			}
			for(unsigned int counter = 0;counter <= secondSplitNode->noOfKeys;counter++){
				secondSplitNode->children[counter] = childrenPtr[childrenCounter++];
				secondSplitNode->children[counter]->parent = secondSplitNode;
			}
		}
		if(currentNode->parent  == null){
			(*root) = new i24Node(firstSplitNode->value[1]);
			(*root)->children[0] = firstSplitNode;
			(*root)->children[1] = secondSplitNode;
			(*root)->noOfChildren = 2;
			firstSplitNode->parent = (*root);
			secondSplitNode->parent = (*root);
			prevNode = null;
			prevFirstSplitNode = null;
			prevSecondSplitNode = null;
			flag = false;
			return;
		}
		prevNode = currentNode;
		prevFirstSplitNode = firstSplitNode;
		prevSecondSplitNode = secondSplitNode;
		flag = true;
		insertIntoTwoFourTree(root,currentNode->parent,firstSplitNode->value[1]);
	}else if(currentNode->value[0] > value){
		insertIntoTwoFourTree(root,currentNode->children[0],value);
	}else if(currentNode->value[currentNode->noOfKeys - 1] < value){
		insertIntoTwoFourTree(root,currentNode->children[currentNode->noOfKeys - 1],value);
	}else{
		unsigned int counter = 1;
		while(value > currentNode->value[counter]){
			counter++;
		}
		insertIntoTwoFourTree(root,currentNode->children[counter],value);
	}
}

#endif /* INSERTINTOTWOFOURTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
