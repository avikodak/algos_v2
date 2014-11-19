/****************************************************************************************************************************************************
 *  File Name   		: printverticalorder.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\printverticalorder.h
 *  Created on			: Nov 15, 2014 :: 11:38:42 PM
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

#ifndef PRINTVERTICALORDER_H_
#define PRINTVERTICALORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void setNodesVerticalOrderMain(itNode *ptr,int verticalLevel,map<int,list<itNode *> > &verticalLevelNodesMap){
	if(ptr == null){
		return;
	}
	map<int,list<itNode *> >::iterator itToVerticalLevelNodeMap = verticalLevelNodesMap.find(verticalLevel);
	if(itToVerticalLevelNodeMap == verticalLevelNodesMap.end()){
		list<itNode *> nodesList;
		nodesList.push_back(ptr);
		itToVerticalLevelNodeMap[verticalLevel] = nodesList;
	}else{
		itToVerticalLevelNodeMap->second.push_back(ptr);
	}
	setNodesVerticalOrderMain(ptr->left,verticalLevel-1,verticalLevelNodesMap);
	setNodesVerticalOrderMain(ptr->right,verticalLevel+1,verticalLevelNodesMap);
}

void printVerticalOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	map<int,list<itNode *> > verticalLevelNodesMap;
	map<int,list<itNode *> >::iterator itToVerticalLevelNodesMap;
	setNodesVerticalOrderMain(ptr,0,verticalLevelNodesMap);
	for(itToVerticalLevelNodesMap = verticalLevelNodesMap.begin();itToVerticalLevelNodesMap != verticalLevelNodesMap.end();itToVerticalLevelNodesMap++){
		for(unsigned int counter = 0;counter < itToVerticalLevelNodesMap->second.size();counter++){
			printf("%d\t",itToVerticalLevelNodesMap->second[counter]->value);
		}
		PRINT_NEW_LINE;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void findMinMaxVerticalLevel(itNode *ptr,int currentVerticalLevel,int *minVerticalLevel,int *maxVerticalLevel){
	if(ptr == null){
		return;
	}
	*minVerticalLevel = min(*minVerticalLevel,currentVerticalLevel);
	*maxVerticalLevel = max(*maxVerticalLevel,currentVerticalLevel);
	findMinMaxVerticalLevel(ptr->left,currentVerticalLevel-1,minVerticalLevel,maxVerticalLevel);
	findMinMaxVerticalLevel(ptr->right,currentVerticalLevel+1,minVerticalLevel,maxVerticalLevel);
}

void printVerticalLevel(itNode *ptr,int verticalLevel,int currentLevel){
	if(ptr == null){
		return;
	}
	if(currentLevel == verticalLevel){
		printf("%d\t",ptr->value);
	}
	printVerticalLevel(ptr->left,verticalLevel,currentLevel-1);
	printVerticalLevel(ptr->right,verticalLevel,currentLevel+1);
}

void printAllVerticalLevel(itNode *ptr){
	if(ptr == null){
		return;
	}
	int minVerticalLevel = INT_MAX,maxVerticalLevel = INT_MIN;
	findMinMaxVerticalLevel(ptr,0,&minVerticalLevel,&maxVerticalLevel);
	for(int counter = minVerticalLevel;counter <= maxVerticalLevel;counter++){
		printVerticalLevel(ptr,counter,0);
	}
}

#endif /* PRINTVERTICALORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
