/****************************************************************************************************************************************************
 *  File Name   		: printrightview.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\printrightview.h
 *  Created on			: Nov 16, 2014 :: 12:11:12 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/print-right-view-binary-tree-2/
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

#ifndef PRINTRIGHTVIEW_H_
#define PRINTRIGHTVIEW_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void pPrintRightView(itNode *ptr,int currentLevel,int *maxLevel){
	if(ptr == null){
		return;
	}
	if(*maxLevel < currentLevel){
		printf("%d\t",ptr->value);
		*maxLevel = currentLevel;
	}
	pPrintRightView(ptr->right,currentLevel+1,maxLevel);
	pPrintRightView(ptr->left,currentLevel+1,maxLevel);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void printFirstNodeInLevel(itNode *ptr,unsigned int level){
	static bool flag = false;
	if(ptr == null){
		return;
	}
	if(level == 0){
		if(!flag){
			printf("%d\t",ptr->value);
		}
		flag = true;
		return;
	}
	printFirstNodeInLevel(ptr->right,level-1);
	printFirstNodeInLevel(ptr->left,level-1);
}

void pPrintRightView(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->getHeightOfTree(ptr);
	for(unsigned int counter = 0;counter < height;counter++){
		printFirstNodeInLevel(ptr,counter);
	}
}

#endif /* PRINTRIGHTVIEW_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
