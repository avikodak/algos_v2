/****************************************************************************************************************************************************
 *  File Name   		: countwalks.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page01\countwalks.h
 *  Created on			: Jan 12, 2015 :: 8:25:00 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/count-possible-paths-source-destination-exactly-k-edges/
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
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
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

#ifndef COUNTWALKS_H_
#define COUNTWALKS_H_

//Tested
int countWalks(vector<vector<bool> > adjacencyMatrix,int kEdges,int sourceVertex,int destinationVertex){
	if(kEdges == 0 && sourceVertex == destinationVertex){
		return 1;
	}
	if(kEdges <= 0){
		return 0;
	}
	int walkCounter = 0;
	for(unsigned int counter = 0;counter < adjacencyMatrix.size();counter++){
		if(adjacencyMatrix[sourceVertex][counter]){
			walkCounter += countWalks(adjacencyMatrix,kEdges-1,counter,destinationVertex);
		}
	}
	return walkCounter;
}

//Tested
int countWalksMemoization(vector<vector<bool> > adjacencyMatrix,int kEdges,int sourceVertex,int destinationVertex){
	if(kEdges == 0 && sourceVertex == destinationVertex){
		return 1;
	}
	if(kEdges <= 0){
		return 0;
	}
	int auxSpace[adjacencyMatrix.size()][adjacencyMatrix.size()][kEdges+1];
	for(int edgeCounter = 0;edgeCounter <= kEdges;edgeCounter++){
		for(unsigned int outerCounter = 0;outerCounter < adjacencyMatrix.size();outerCounter++){
			for(unsigned int innerCounter = 0;innerCounter < adjacencyMatrix.size();innerCounter++){
				auxSpace[outerCounter][innerCounter][edgeCounter] = 0;
				if(edgeCounter == 0 && outerCounter == innerCounter){
					auxSpace[outerCounter][innerCounter][edgeCounter] = 1;
				}else if(edgeCounter <= 0){
					auxSpace[outerCounter][innerCounter][edgeCounter] = 0;
				}else if(edgeCounter == 1 && adjacencyMatrix[outerCounter][innerCounter]){
					auxSpace[outerCounter][innerCounter][edgeCounter] = 1;
				}else if(edgeCounter <= 1){
					auxSpace[outerCounter][innerCounter][edgeCounter] = 0;
				}else{
					for(unsigned int vertexCounter = 0;vertexCounter < adjacencyMatrix.size();vertexCounter++){
						if(adjacencyMatrix[outerCounter][vertexCounter]){
							auxSpace[outerCounter][destinationVertex][edgeCounter] += auxSpace[vertexCounter][innerCounter][edgeCounter-1];
						}
					}
				}
			}
		}
	}
	return auxSpace[sourceVertex][destinationVertex][kEdges];
}

#endif /* COUNTWALKS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
