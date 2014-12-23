/****************************************************************************************************************************************************
 *  File Name   		: minhorsemovesinchess.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\careercup\microsoft\minhorsemovesinchess.h
 *  Created on			: Dec 22, 2014 :: 10:22:50 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.careercup.com/question?id=5657515507318784
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

#ifndef MINHORSEMOVESINCHESS_H_
#define MINHORSEMOVESINCHESS_H_

int minHorseMoveInChess(vector<vector<bool> > configuration,int destinationX,int destinationY,int currentX,int currentY){
	if(currentX > configuration[0].size() || currentX < 0 || currentY > configuration.size() || currentY < 0){
		return INT_MAX;
	}
	if(currentX == destinationX && currentY == destinationY){
		return 0;
	}
	int minMoves = INT_MAX;
	configuration[currentX][currentY] = true;
	if(!configuration[currentX+1][currentY-2]){
		minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX+1,currentY-2));
	}
	if(!configuration[currentX+1][currentY+2]){
		minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX+1,currentY+2));
	}
	if(!configuration[currentX+2][currentY-1]){
		minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX+2,currentY-1));
	}
	if(!configuration[currentX+2][currentY+1]){
		minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX+2,currentY+1));
	}
	if(!configuration[currentX-1][currentY-2]){
		minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX-1,currentY-2));
	}
	if(!configuration[currentX-1][currentY+2]){
		minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX-1,currentY+2));
	}
	if(!configuration[currentX-2][currentY-1]){
		minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX-2,currentY-1));
	}
	if(!configuration[currentX-2][currentY+1]){
		minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX-2,currentY+1));
	}
	return minMoves;
}

#endif /* MINHORSEMOVESINCHESS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
