/****************************************************************************************************************************************************
 *  File Name   		: twofourtreeutil.h 
 *	File Location		: D:\algos\algos_v2\src\lib\utils\twofourtreeutil.h
 *  Created on			: Oct 9, 2014 :: 12:37:59 PM
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
#include <stdint.h>
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TWOFOURTREEUTIL_H_
#define TWOFOURTREEUTIL_H_

/*class twofourtreeutils {
private:
	//Tested
	void insertAtRightPlace(i24Node **root,i24Node *currentNode,int value){
		static i24Node *prevNode,*prevFirstSplitNode,*prevSecondSplitNode;
		static bool flag;
		if(*root == null){
			(*root) = new i24Node(value);
			return;
		}
		if(currentNode->noOfChildren == 0 || flag){
			if(currentNode->noOfKeys < 3){
				currentNode->noOfKeys += 1;
				int counter = currentNode->noOfKeys-2;
				while(counter >= 0 && currentNode->value[counter] > value){
					currentNode->value[counter+1] = currentNode->value[counter];
					counter++;
				}
				currentNode->value[counter+1] = value;
				if(prevNode != null){
					int fillCounter = -1;
					vector<i24Node *> childrenPtrs;
					bool prevPtrConnected = false;
					if(currentNode->noOfChildren > 0){
						for(unsigned int counter = 0;counter < currentNode->noOfChildren;){
							if(currentNode->children[counter] == prevNode){
								counter++;
								continue;
							}else if(currentNode->children[counter]->value[0] > prevFirstSplitNode->value[0] && !prevPtrConnected){
								childrenPtrs.push_back(prevFirstSplitNode);
								childrenPtrs.push_back(prevSecondSplitNode);
								prevPtrConnected = true;
							}else{
								childrenPtrs.push_back(currentNode->children[counter]);
								counter++;
							}
						}
						if(!prevPtrConnected){
							childrenPtrs.push_back(prevFirstSplitNode);
							childrenPtrs.push_back(prevSecondSplitNode);
						}
					}else{
						childrenPtrs.push_back(prevFirstSplitNode);
						childrenPtrs.push_back(prevSecondSplitNode);
					}
					for(unsigned int counter = 0;counter <= currentNode->noOfKeys;counter++){
						currentNode->children[counter] = childrenPtrs[counter];
					}
					currentNode->noOfChildren += 1;
					free(prevNode);
				}
				flag = false;
				prevNode = null;
				prevFirstSplitNode = null;
				prevSecondSplitNode = null;
				return;
			}
			i24Node *firstSplitNode = new i24Node();
			i24Node *secondSplitNode = new i24Node();
			firstSplitNode->parent = currentNode->parent;
			secondSplitNode->parent = currentNode->parent;
			bool valueInserted = false,firstSplitNodeFilled = false,prevPtrConnected = false;
			int fillCounter = -1,existingNodeCounter = 0;
			vector<i24Node *> childrenPtrs;
			for(unsigned int counter = 0;counter < currentNode->noOfKeys;){
				if(!firstSplitNodeFilled){
					if(currentNode->value[counter] < value){
						firstSplitNode->value[++fillCounter] = currentNode->value[counter];
						counter++;
					}else{
						firstSplitNode->value[++fillCounter] = value;
						valueInserted = true;
					}
					if(fillCounter == 1){
						fillCounter = -1;
						firstSplitNodeFilled = true;
					}
				}else{
					if(currentNode->value[counter] < value){
						secondSplitNode->value[++fillCounter] = currentNode->value[counter];
						counter++;
					}else{
						secondSplitNode->value[++fillCounter] = value;
						valueInserted = true;
					}
				}
			}
			if(!valueInserted){
				secondSplitNode->value[++fillCounter] = value;
			}
			firstSplitNode->noOfKeys = 1;
			secondSplitNode->noOfKeys = 2;
			if(prevNode != null){
				for(unsigned int counter = 0;counter < currentNode->noOfChildren;){
					if(currentNode->children[counter] == prevNode){
						counter++;
					}else if(currentNode->children[counter]->value[0] > prevFirstSplitNode->value[0] && !prevPtrConnected){
						childrenPtrs.push_back(prevFirstSplitNode);
						childrenPtrs.push_back(prevSecondSplitNode);
						prevPtrConnected = true;
					}else{
						childrenPtrs.push_back(currentNode->children[counter]);
						counter++;
					}
				}
				if(!prevPtrConnected){
					childrenPtrs.push_back(prevFirstSplitNode);
					childrenPtrs.push_back(prevSecondSplitNode);
				}
				if(childrenPtrs.size() > 0){
					unsigned int childrenCounter = 0;
					for(unsigned int counter = 0;counter <= firstSplitNode->noOfKeys;counter++){
						firstSplitNode->children[counter] = childrenPtrs[childrenCounter++];
					}
					for(unsigned int counter = 0;counter <= secondSplitNode->noOfKeys;counter++){
						secondSplitNode->children[counter] = childrenPtrs[childrenCounter++];
					}
				}
				firstSplitNode->noOfChildren = 2;
				secondSplitNode->noOfChildren = 3;
				free(prevNode);
			}
			if(currentNode->parent == null){
				(*root) = new i24Node(firstSplitNode->value[1]);
				(*root)->children[0] = firstSplitNode;
				(*root)->children[1] = secondSplitNode;
				(*root)->noOfChildren = 2;
				firstSplitNode->parent = (*root);
				secondSplitNode->parent = (*root);
				free(currentNode);
				flag = false;
				prevNode = null;
				prevFirstSplitNode = null;
				prevSecondSplitNode = null;
				return;
			}
			prevNode = currentNode;
			prevFirstSplitNode = firstSplitNode;
			prevSecondSplitNode = secondSplitNode;
			flag = true;
			insertAtRightPlace(root,currentNode->parent,firstSplitNode->value[1]);
		}else if(currentNode->value[0] > value){
			insertAtRightPlace(root,currentNode->children[0],value);
		}else if(currentNode->value[currentNode->noOfKeys - 1] < value){
			insertAtRightPlace(root,currentNode->children[currentNode->noOfKeys],value);
		}else{
			unsigned int counter = 1;
			while(currentNode->value[counter] > value){
				counter++;
			}
			insertAtRightPlace(root,currentNode->children[counter],value);
		}
	}

	void insertAtRightPlace(i24fNode **root,i24fNode *currentNode,int value,int frequency = 1){
		static i24fNode *prevNode,*prevFirstSplitNode,*prevSecondSplitNode;
		static bool flag;
		if(*root == null){
			(*root) = new i24fNode(value);
			return;
		}
		if(currentNode->children == 0 || flag){
			if(currentNode->noOfChildren < 3){
				return;
			}
			i24fNode *firstSplitNode = new i24fNode();
			i24fNode *secondSplitNode = new i24fNode();
			firstSplitNode->parent = currentNode->parent;
			secondSplitNode->parent = currentNode->parent;
			bool valueInserted = false,firstSplitNodeFilled = false;
			int fillCounter = -1;
			for(unsigned int counter = 0;counter < currentNode->noOfKeys;){
				if(!firstSplitNodeFilled){
					if(currentNode->value[counter] < value){
						firstSplitNode->value[++fillCounter] = currentNode->value[counter];
						firstSplitNode->frequency[fillCounter] = currentNode->frequency[counter];
						counter++;
					}else{
						firstSplitNode->value[++fillCounter] = value;
						firstSplitNode->value[fillCounter] = frequency;
						valueInserted = false;
					}
					if(fillCounter == 1){
						fillCounter = -1;
						firstSplitNodeFilled = true;
					}
				}else{
					if(currentNode->value[counter] < value){
						secondSplitNode->value[++fillCounter] = currentNode->value[counter];
						secondSplitNode->frequency[fillCounter] = currentNode->frequency[counter];
						counter++;
					}else{
						secondSplitNode->value[++fillCounter] = value;
						secondSplitNode->frequency[fillCounter] = frequency;
						valueInserted = false;
					}
				}
			}
			if(!valueInserted){
				secondSplitNode->value[1] = value;
				secondSplitNode->frequency[1]  = frequency;
			}
			firstSplitNode->noOfKeys = 1;
			secondSplitNode->noOfKeys = 2;
			if(prevNode != null){

			}
			if(currentNode->parent == null){
				return;
			}
			prevNode = currentNode;
			prevFirstSplitNode = firstSplitNode;
			prevSecondSplitNode = secondSplitNode;
			flag = true;
			insertAtRightPlace(root,currentNode->parent,firstSplitNode->value[0],firstSplitNode->frequency[0]);
		}else if(currentNode->value[0] <= value){
			if(currentNode->value[0] == value){
				currentNode->frequency[0]++;
				return;
			}
			insertAtRightPlace(root,currentNode->children[0],value);
		}else if(currentNode->value[currentNode->noOfKeys-1] >= value){
			if(currentNode->value[currentNode->noOfKeys-1] == value){
				currentNode->frequency[currentNode->noOfKeys-1]++;
				return;
			}
			insertAtRightPlace(root,currentNode->children[currentNode->noOfKeys],value);
		}else{
			unsigned int counter = 1;
			while(currentNode->value[counter] <= value){
				if(currentNode->value[counter] == value){
					currentNode->frequency[counter]++;
					return;
				}
				counter++;
			}
			insertAtRightPlace(root,currentNode->children[counter],value);
		}
	}

	void deleteFromTwoFourTreeMain(i24Node **root,i24Node *currentNode,int value,int index){
		static i24Node *prevNode,*prevMergedNode;
		if(*root == null || currentNode == null){
			return;
		}
		if(currentNode->noOfKeys > 1){
			unsigned int fillCounter = -1;
			for(unsigned int counter = 0;counter < currentNode->noOfKeys;counter++){
				if(currentNode->value[counter] != value){
					currentNode->value[++fillCounter] = currentNode->value[counter];
				}
			}
			if(prevNode != null){
				vector<i24Node *> childrenPtr;
				bool prevPtrConnected = false;
				for(unsigned int counter = 0;counter < currentNode->noOfChildren;){
					if(currentNode->children[counter] == prevNode){
						counter++;
					}else if(currentNode->children[counter]->value[0] < prevMergedNode->value[0]){
						childrenPtr.push_back(currentNode->children[counter]);
					}else{
						childrenPtr.push_back(prevMergedNode);
						prevPtrConnected = true;
					}
				}
				if(!prevPtrConnected){
					childrenPtr.push_back(prevMergedNode);
				}
				currentNode->children[currentNode->noOfChildren-1] = null;
				currentNode->noOfChildren -= 1;
				for(unsigned int counter = 0;counter < currentNode->noOfChildren;counter++){
					currentNode->children[counter] = childrenPtr[counter];
				}
			}
			currentNode->noOfKeys -= 1;
			return;
		}
		i24Node *leftSibling,*rightSibling;
		leftSibling = index == 0?null:currentNode->children[index-1];
		rightSibling = currentNode->children[index+1];
		if(leftSibling != null && leftSibling->noOfKeys > 1){

		}
		if(rightSibling != null && rightSibling->noOfKeys > 1){

		}
	}
public:
	//Tested
	void insertIntoTwoFourTree(i24Node **root,int value){
		insertAtRightPlace(root,*root,value);
	}

	//Tested
	i24Node *getTwoFourTreeFromVector(vector<int> userInput){
		i24Node *root = null;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			insertIntoTwoFourTree(&root,userInput[counter]);
		}
		return root;
	}

	//Tested
	void inorderTraversal(i24Node *ptr){
		if(ptr == null){
			return;
		}
		for(unsigned int counter = 0;counter < ptr->noOfKeys;counter++){
			inorderTraversal(ptr->children[counter]);
			printf("%d\t",ptr->value[counter]);
		}
		inorderTraversal(ptr->children[ptr->noOfKeys]);
	}

	i24TreeSearchResult *search(i24Node *ptr,int value){
		if(ptr == null){
			return null;
		}
		if(ptr->value[0] > value){
			return search(ptr->children[0],value);
		}else if(ptr->value[0] == value){
			return new i24TreeSearchResult(0,ptr);
		}else if(ptr->value[ptr->noOfKeys-1] < value){
			return search(ptr->children[ptr->noOfKeys],value);
		}else if(ptr->value[ptr->noOfKeys-1] == value){
			return new i24TreeSearchResult(ptr->noOfKeys-1,ptr);
		}else{
			unsigned int counter = 1;
			while(counter < ptr->noOfKeys){
				if(ptr->value[counter] == value){
					return new i24TreeSearchResult(counter,ptr);
				}else if(ptr->value[counter] > value){
					return search(ptr->children[counter],value);
				}
				counter++;
			}
		}
		return null;
	}

	i24Node *predecessorIfChildrenPresent(i24Node *ptr,int index){
		if(ptr == null){
			return null;
		}
		if(ptr->children[index] == null){
			return null;
		}
		i24Node *predecessor = ptr->children[index];
		while(predecessor->noOfChildren > 0){
			predecessor = predecessor->children[predecessor->noOfChildren-1];
		}
		return predecessor;
	}


	void deleteFromTwoFourTree(i24Node **root,int value){
		if(*root == null){
			return;
		}
		i24TreeSearchResult *result = search(*root,value);
		if(result == null){
			return;
		}
		i24Node *node = result->node;
		if(result->node->noOfChildren != 0){
			i24Node *predecessor = predecessorIfChildrenPresent(result->node,result->index);
			result->node->value[result->index] = predecessor->value[predecessor->noOfKeys-1];
			node = predecessor;
			sort(predecessor->value,predecessor->value + predecessor->noOfKeys);
		}
		deleteFromTwoFourTreeMain(root,node,value);
	}
};*/


#endif /* TWOFOURTREEUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
