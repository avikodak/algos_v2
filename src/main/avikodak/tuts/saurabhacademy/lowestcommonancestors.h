/****************************************************************************************************************************************************
 *  File Name   		: lowestcommonancestors.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\lowestcommonancestors.h
 *  Created on			: Dec 19, 2014 :: 11:12:39 AM
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

#ifndef LOWESTCOMMONANCESTORS_H_
#define LOWESTCOMMONANCESTORS_H_

//Assuming all values are unique
int lowestCommonAncestors(itNode *root,int firstValue,int secondValue){
	if(root == null){
		return INT_MAX;
	}
	treeutils *utils = new treeutils();
	vector<int> inorder = utils->getValuesInInorder(root);
	vector<int> postorder = utils->getValuesInPostorder(root);
	hash_map<int,unsigned int> valueRankMap;
	hash_map<int,unsigned int>::iterator itToValueRankMap;
	int firstValIndex,secondValIndex;
	for(unsigned int counter = 0;counter < postorder.size();counter++){
		valueRankMap.insert(pair<int,unsigned int>(postorder[counter],counter));
	}
	for(unsigned int counter = 0;counter < inorder.size();counter++){
		if(inorder[counter] == firstValue){
			firstValIndex = counter;
		}else if(inorder[counter] == secondValue){
			secondValIndex = counter;
		}
	}
	unsigned int ancestorIndex = 0;
	for(unsigned int counter = firstValIndex < secondValIndex?firstValIndex:secondValIndex;counter <= firstValIndex > secondValIndex?firstValIndex:secondValIndex;counter++){
		itToValueRankMap = valueRankMap.find(postorder[counter]);
		ancestorIndex = max(ancestorIndex,itToValueRankMap->second);
	}
	return postorder[ancestorIndex];
}

#endif /* LOWESTCOMMONANCESTORS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
