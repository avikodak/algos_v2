/****************************************************************************************************************************************************
 *  File Name   		: verticalorderhashmap.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\verticalorderhashmap.h
 *  Created on			: Nov 16, 2014 :: 8:40:06 AM
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

#ifndef VERTICALORDERHASHMAP_H_
#define VERTICALORDERHASHMAP_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void setNodesInVerticalLevel(itNode *ptr,int currentVerticalLevel,map<int,vector<itNode *> > &verticalNodesMap){
	if(ptr == null){
		return;
	}
	map<int,vector<itNode *> >::iterator itToVerticalNodeMap = verticalNodesMap.find(currentVerticalLevel);
	if(itToVerticalNodeMap == verticalNodesMap.end()){
		list<itNode *> nodesList;
		nodesList.push_back(ptr);
		verticalNodesMap[currentVerticalLevel] = nodesList;
	}else{
		itToVerticalNodeMap->second.push_back(ptr);
	}
	setNodesInVerticalLevel(ptr->left,currentVerticalLevel-1,verticalNodesMap);
	setNodesInVerticalLevel(ptr->right,currentVerticalLevel+1,verticalNodesMap);
}

void printVerticalLevels(itNode *ptr){
	if(ptr == null){
		return;
	}
	map<int,vector<itNode *> > verticalNodesMap;
	map<int,vector<itNode *> >::iterator itToVerticalNodeMap;
	setNodesInVerticalLevel(ptr,0,verticalNodesMap);
	for(itToVerticalNodeMap = verticalNodesMap.begin();itToVerticalNodeMap != verticalNodesMap.end();itToVerticalNodeMap++){
		for(unsigned int counter = 0;counter < itToVerticalNodeMap->second.size();counter++){
			printf("%d\t",itToVerticalNodeMap->second[counter]);
		}
		PRINT_NEW_LINE;
	}
}

#endif /* VERTICALORDERHASHMAP_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
