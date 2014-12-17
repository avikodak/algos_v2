/****************************************************************************************************************************************************
 *  File Name   		: isgraphbipartite.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\isgraphbipartite.h
 *  Created on			: Dec 15, 2014 :: 6:55:10 PM
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

#ifndef ISGRAPHBIPARTITE_H_
#define ISGRAPHBIPARTITE_H_

bool isGraphBipartite(vector<vector<int> > adjacencyList){
	if(adjacencyList.size() == 0){
		return true;
	}
	vector<int> bfsLevels(adjacencyList.size(),INT_MIN);
	queue<int> auxSpace;
	auxSpace.push(0);
	bfsLevels[0] = 0;
	int currentIndex;
	while(!auxSpace.empty()){
		currentIndex = auxSpace.front();
		auxSpace.pop();
		for(unsigned int counter = 0;counter < adjacencyList[currentIndex].size();counter++){
			if(bfsLevels[adjacencyList[currentIndex][counter]] == INT_MIN){
				bfsLevels[adjacencyList[currentIndex][counter]] = bfsLevels[currentIndex];
				auxSpace.push(adjacencyList[currentIndex][counter]);
			}else if(bfsLevels[currentIndex] ==  bfsLevels[adjacencyList[currentIndex][counter]]){
				return false;
			}
		}
	}
	return true;
}


#endif /* ISGRAPHBIPARTITE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
