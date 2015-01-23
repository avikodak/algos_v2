/****************************************************************************************************************************************************
 *  File Name   		: bottomview.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page01\bottomview.h
 *  Created on			: Jan 22, 2015 :: 7:39:58 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/bottom-view-binary-tree/
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

#ifndef BOTTOMVIEW_H_
#define BOTTOMVIEW_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void bottomView(itNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<uint32_t,int> nodeHIndexMap;
	hash_map<uint32_t,int>::iterator itToNodeHIndexMap;
	hash_map<int,int> indexValueMap;
	hash_map<int,int>::iterator itToIndexValueMap;
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	int currentNodeHIndex;
	nodeHIndexMap.insert(pair<uint32_t,int>((uint32_t)ptr,0));
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		currentNodeHIndex = nodeHIndexMap.find((uint32_t)currentNode)->second;
		indexValueMap[currentNodeHIndex] = currentNode->value;
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
			nodeHIndexMap.insert(pair<uint32_t,int>((uint32_t)currentNode->left,currentNodeHIndex-1));
		}
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
			nodeHIndexMap.insert(pair<uint32_t,int>((uint32_t)currentNode->right,currentNodeHIndex+1));
		}
	}
	for(itToIndexValueMap = indexValueMap.begin();itToIndexValueMap != indexValueMap.end();itToIndexValueMap++){
		printf("%d\t",itToIndexValueMap->second);
	}
}

#endif /* BOTTOMVIEW_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
