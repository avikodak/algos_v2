/****************************************************************************************************************************************************
 *  File Name   		: checkiftreesubtree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\checkiftreesubtree.h
 *  Created on			: Oct 23, 2014 :: 10:15:35 AM
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

#ifndef CHECKIFTREESUBTREE_H_
#define CHECKIFTREESUBTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isContinousSubset(vector<int> firstUserinput,vector<int> secondUserinput){
	if(firstUserinput.size() == 0 || secondUserinput.size() == 0){
		return true;
	}
	unsigned int outerCrawler,firstCrawler,secondCrawler;
	if(firstUserinput.size() >= secondUserinput.size()){
		for(;outerCrawler < firstUserinput.size() - secondUserinput.size() + 1;outerCrawler++){
			firstCrawler = outerCrawler;
			secondCrawler = 0;
			while(secondCrawler < secondUserinput.size()){
				if(firstUserinput[firstCrawler] != secondUserinput[secondCrawler]){
					return false;
				}
			}
			if(secondCrawler == secondUserinput.size()){
				return true;
			}
		}
	}else{
		for(;outerCrawler < secondUserinput.size() - firstUserinput.size() + 1;outerCrawler++){
			firstCrawler = outerCrawler;
			secondCrawler = 0;
			while(secondCrawler < firstUserinput.size()){
				if(secondUserinput[firstCrawler] != firstUserinput[secondCrawler]){
					return false;
				}
			}
			if(firstCrawler == firstUserinput.size()){
				return true;
			}
		}
	}
	return false;
}

bool isTreeSubTree(itNode *firstPtr,itNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return true;
	}
	treeutils *utils = new treeutils();
	vector<int> preOrderValuesFirstTree = utils->getValuesInPreorder(firstPtr);
	vector<int> preOrderValuesSecondTree = utils->getValuesInPreorder(secondPtr);
	vector<int> inOrderValuesFirstTree = utils->getValuesInInorder(firstPtr);
	vector<int> inOrderValuesSecondTree = utils->getValuesInInorder(secondPtr);
	return isContinousSubset(preOrderValuesFirstTree,preOrderValuesSecondTree) && isContinousSubset(inOrderValuesFirstTree,inOrderValuesSecondTree);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool areTreesIdentical(itNode *firstPtr,itNode *secondPtr){
	if(firstPtr == null && secondPtr == null){
		return true;
	}
	if(firstPtr == null || secondPtr == null){
		return false;
	}
	return firstPtr->value == secondPtr->value && areTreesIdentical(firstPtr->left,secondPtr->left) && areTreesIdentical(firstPtr->right,secondPtr->right);
}

//Tested
bool isTreeSubTreeON2(itNode *firstPtr,itNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return true;
	}
	return areTreesIdentical(firstPtr,secondPtr) || isTreeSubTreeON2(firstPtr->left,secondPtr) || isTreeSubTreeON2(firstPtr->right,secondPtr);
}

#endif /* CHECKIFTREESUBTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
