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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TWOFOURTREEUTIL_H_
#define TWOFOURTREEUTIL_H_

class twofourtreeutils {
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
};


#endif /* TWOFOURTREEUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
