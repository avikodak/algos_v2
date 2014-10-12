/****************************************************************************************************************************************************
 *  File Name   		: treeutil.h 
 *	File Location		: D:\algos\algos_v2\src\lib\utils\treeutil.h
 *  Created on			: Oct 9, 2014 :: 12:37:32 PM
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
#include <algorithm/utils/commonutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TREEUTIL_H_
#define TREEUTIL_H_

class treeutils{
private:
	void setNodesInPreorderMain(itNode *ptr,vector<itNode *> &auxSpace){
		if(ptr == null){
			return;
		}
		auxSpace.push_back(ptr);
		setNodesInPreorderMain(ptr->left,auxSpace);
		setNodesInPreorderMain(ptr->right,auxSpace);
	}

	void setValuesInPreorderMain(itNode *ptr,vector<int> &auxSpace){
		if(ptr == null){
			return;
		}
		auxSpace.push_back(ptr->value);
		setValuesInPreorderMain(ptr->left,auxSpace);
		setValuesInPreorderMain(ptr->right,auxSpace);
	}

	void setNodesInInorderMain(itNode *ptr,vector<itNode *> &auxSpace){
		if(ptr == null){
			return;
		}
		setNodesInInorderMain(ptr->left,auxSpace);
		auxSpace.push_back(ptr);
		setNodesInInorderMain(ptr->right,auxSpace);
	}

	void setValuesInInorderMain(itNode *ptr,vector<int> &auxSpace){
		if(ptr == null){
			return;
		}
		setValuesInInorderMain(ptr->left,auxSpace);
		auxSpace.push_back(ptr->value);
		setValuesInInorderMain(ptr->right,auxSpace);
	}

	void setNodesInPostorderMain(itNode *ptr,vector<itNode *> &auxSpace){
		if(ptr == null){
			return;
		}
		setNodesInPostorderMain(ptr->left,auxSpace);
		setNodesInPostorderMain(ptr->right,auxSpace);
		auxSpace.push_back(ptr);
	}

	void setValuesInPostorderMain(itNode *ptr,vector<int> auxSpace){
		if(ptr == null){
			return;
		}
		setValuesInPostorderMain(ptr->left,auxSpace);
		setValuesInPostorderMain(ptr->right,auxSpace);
		auxSpace.push_back(ptr->value);
	}
public:
	//Tested
	itNode *getITreeFromVector(vector<int> userInput,unsigned int currentIndex = 0) {
		if(currentIndex >= userInput.size()){
			return null;
		}
		itNode *node = new itNode(userInput[currentIndex]);
		node->left = getITreeFromVector(userInput,2*currentIndex+1);
		node->right = getITreeFromVector(userInput,2*currentIndex+2);
		return node;
	}

	//Tested
	itNode *getRandomTree(unsigned int numberOfNodes,int minValue = INT_MIN,int maxValue = INT_MAX) {
		if(numberOfNodes == 0){
			return null;
		}
		vector<int> randomValues = generateIRandomVector(numberOfNodes,minValue,maxValue);
		printIVector(randomValues);
		return getITreeFromVector(randomValues);
	}

	//Tested
	unsigned int getHeightOfTree(itNode *ptr){
		if(ptr == null){
			return 0;
		}
		return 1 + max(getHeightOfTree(ptr->left),getHeightOfTree(ptr->right));
	}

	void preOrderTraversal(itNode *ptr){
		if(ptr == null){
			return;
		}
		printf("%d\t",ptr->value);
		preOrderTraversal(ptr->left);
		preOrderTraversal(ptr->right);
	}

	void inOrderTraversal(itNode *ptr){
		if(ptr == null){
			return;
		}
		inOrderTraversal(ptr->left);
		printf("%d\t",ptr->value);
		inOrderTraversal(ptr->right);
	}

	void postOrderTraversal(itNode *ptr){
		if(ptr == null){
			return;
		}
		postOrderTraversal(ptr->left);
		postOrderTraversal(ptr->right);
		printf("%d\t",ptr->value);
	}

	vector<itNode *> getNodesInPreorder(itNode *ptr){
		vector<itNode *> preOrderNodes;
		if(ptr == null){
			return preOrderNodes;
		}
		setNodesInPreorderMain(ptr,preOrderNodes);
		return preOrderNodes;
	}

	vector<int> getValuesInPreorder(itNode *ptr){
		vector<int> preOrderValues;
		if(ptr == null){
			return preOrderValues;
		}
		setValuesInPreorderMain(ptr,preOrderValues);
		return preOrderValues;
	}

	vector<itNode *> getNodesInInorder(itNode *ptr){
		vector<itNode *> inOrderNodes;
		if(ptr == null){
			return inOrderNodes;
		}
		setNodesInInorderMain(ptr,inOrderNodes);
		return inOrderNodes;
	}

	vector<int> getValuesInInorder(itNode *ptr){
		vector<int> inOrderValues;
		if(ptr == null){
			return inOrderValues;
		}
		setValuesInInorderMain(ptr,inOrderValues);
		return inOrderValues;
	}

	vector<itNode *> getNodesInPostorder(itNode *ptr){
		vector<itNode *> postOrderNodes;
		if(ptr == null){
			return postOrderNodes;
		}
		setNodesInPostorderMain(ptr,postOrderNodes);
		return postOrderNodes;
	}

	vector<int> getValuesInPostorder(itNode *ptr){
		vector<int> postOrderValues;
		if(ptr == null){
			return postOrderValues;
		}
		setValuesInPostorderMain(ptr,postOrderValues);
		return postOrderValues;
	}

	//Tested
	itHashmap *getTreeAsHashMap(itNode *ptr,unsigned int startIndex = 0){
		if(ptr == null){
			return null;
		}
		hash_map<unsigned int,itNode *> indexNodeMap;
		hash_map<uint32_t,unsigned int> nodeIndexMap;
		hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
		hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
		itNode *currentNode;
		queue<itNode *> auxSpace;
		unsigned int currentIndex;
		auxSpace.push(ptr);
		indexNodeMap.insert(pair<unsigned int,itNode *>(startIndex,ptr));
		nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,startIndex));
		while(!auxSpace.empty()){
			currentNode = auxSpace.front();
			auxSpace.pop();
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			currentIndex = itToNodeIndexMap->second;
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
				if(startIndex == 0){
					indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentIndex+1,currentNode->left));
					nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*currentIndex+1));
				}else{
					indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentIndex,currentNode->left));
					nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*currentIndex));
				}
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
				if(startIndex == 0){
					indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentIndex+2,currentNode->right));
					nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*currentIndex+2));
				}else{
					indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentIndex+1,currentNode->right));
					nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*currentIndex+1));
				}
			}
		}
		itHashmap *hashMapOfTree = new itHashmap();
		hashMapOfTree->indexNodeMap = indexNodeMap;
		hashMapOfTree->nodeIndexMap = nodeIndexMap;
		return hashMapOfTree;
	}
};
#endif /* TREEUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
