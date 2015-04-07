/****************************************************************************************************************************************************
 *  File Name   		: printnodesbetweenlevels.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page01\printnodesbetweenlevels.h
 *  Created on			: Jan 22, 2015 :: 7:41:06 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/given-binary-tree-print-nodes-two-given-level-numbers/
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
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
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

#ifndef PRINTNODESBETWEENLEVELS_H_
#define PRINTNODESBETWEENLEVELS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printLevelUsingQueue(itNode *ptr,int firstLevel,int secondLevel){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	int levelCounter = 1,nodeLevelCounter;
	auxSpace.push(ptr);
	itNode *currentNode;
	while(!auxSpace.empty()){
		nodeLevelCounter = auxSpace.size();
		while(nodeLevelCounter--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(levelCounter >= firstLevel && levelCounter <= secondLevel){
				printf("%d\t",currentNode->value);
			}
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
		levelCounter++;
		if(levelCounter > secondLevel){
			break;
		}
		PRINT_NEW_LINE;
	}
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printLevel(itNode *ptr,int level){
	if(ptr == null){
		return;
	}
	if(level == 0){
		printf("%d\t",ptr->value);
		return;
	}
	printLevel(ptr->left,level-1);
	printLevel(ptr->right,level-1);
}

//Tested
void printNodesBetweenLevels(itNode *ptr,int firstLevel,int secondLevel){
	if(ptr == null){
		return;
	}
	for(int counter = firstLevel;counter <= secondLevel;counter++){
		printLevel(ptr,counter-1);
		PRINT_NEW_LINE;
	}
}

#endif /* PRINTNODESBETWEENLEVELS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/