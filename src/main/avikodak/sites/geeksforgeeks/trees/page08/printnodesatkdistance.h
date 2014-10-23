/****************************************************************************************************************************************************
 *  File Name   		: printnodesatkdistance.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\printnodesatkdistance.h
 *  Created on			: Oct 20, 2014 :: 1:56:29 PM
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

#ifndef PRINTNODESATKDISTANCE_H_
#define PRINTNODESATKDISTANCE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printNodesAtKDistance(itNode *ptr,unsigned int kValue){
	if(ptr == null || kValue == 0){
		return;
	}
	if(kValue == 1){
		printf("%d\t",ptr->value);
		return;
	}
	printNodesAtKDistance(ptr->left,kValue-1);
	printNodesAtKDistance(ptr->right,kValue-1);
}

//Tested
void printNodesAtKDistanceLevelOrder(itNode *ptr,unsigned int kValue){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	unsigned int levelCounter = 0;
	itNode *currentNode;
	auxSpace.push(ptr);
	unsigned int level = 1;
	while(!auxSpace.empty()){
		levelCounter = auxSpace.size();
		while(levelCounter--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(level == kValue){
				printf("%d\t",currentNode->value);
			}
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
		if(level > kValue){
			break;
		}
		level++;
	}
}

//Tested
inrNode *pGetNextRightPtr(inrNode *ptr){
	if(ptr == null){
		return null;
	}
	while(ptr != null){
		if(ptr->left != null){
			return ptr->left;
		}else if(ptr->right != null){
			return ptr->right;
		}
		ptr = ptr->nextRight;
	}
	return null;
}

//Tested
void pConnectNodesAtSameLevel(inrNode *ptr){
	if(ptr == null){
		return;
	}
	pConnectNodesAtSameLevel(ptr->nextRight);
	if(ptr->left != null){
		if(ptr->right != null){
			ptr->left->nextRight = ptr->right;
			ptr->right->nextRight = pGetNextRightPtr(ptr->nextRight);
		}else{
			ptr->left->nextRight = pGetNextRightPtr(ptr->nextRight);
		}
		pConnectNodesAtSameLevel(ptr->left);
	}else if(ptr->right != null){
		ptr->right->nextRight = pGetNextRightPtr(ptr->nextRight);
		pConnectNodesAtSameLevel(ptr->right);
	}else{
		pConnectNodesAtSameLevel(pGetNextRightPtr(ptr));
	}
}

//Tested
void printLevelAfterConnecting(inrNode *ptr){
	if(ptr == null){
		return;
	}
	printf("%d\t",ptr->value);
	printLevelAfterConnecting(ptr->nextRight);
}

//Tested
void printNodesAtKDistanceAfterLevelConnection(inrNode *ptr,unsigned int kValue){
	if(ptr == null){
		return;
	}
	ptr->nextRight = null;
	pConnectNodesAtSameLevel(ptr);
	while(ptr != null && kValue--){
		if(kValue == 0){
			printLevelAfterConnecting(ptr);
		}
		if(ptr->left != null){
			ptr = ptr->left;
		}else if(ptr->right != null){
			ptr = ptr->right;
		}else{
			ptr = pGetNextRightPtr(ptr->nextRight);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* PRINTNODESATKDISTANCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
