/****************************************************************************************************************************************************
 *  File Name   		: hamiltoniancycle.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\hamiltoniancycle.h
 *  Created on			: Jan 12, 2015 :: 8:30:16 AM
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

#ifndef HAMILTONIANCYCLE_H_
#define HAMILTONIANCYCLE_H_

bool hcIsSafe(vector<vector<bool> > adjacencyMatrix,vector<int> cycle,int currentIndex,int vertex){
	if(currentIndex >= cycle.size() || vertex >= adjacencyMatrix.size()){
		return false;
	}
	if(!adjacencyMatrix[cycle[currentIndex-1]][vertex]){
		return false;
	}
	for(unsigned int counter = 0;counter < currentIndex;counter++){
		if(cycle[counter] == vertex){
			return false;
		}
	}
	return true;
}

bool hamiltonianCycleMain(vector<vector<bool> > adjacencyMatrix,vector<int> &cycle,int currentIndex){
	if(adjacencyMatrix.size() == 0 || currentIndex > adjacencyMatrix.size()){
		return false;
	}
	if(currentIndex == cycle.size()){
		return adjacencyMatrix[currentIndex-1][0];
	}
	for(unsigned int counter = 1;counter < adjacencyMatrix.size();counter++){
		if(hcIsSafe(adjacencyMatrix,cycle,currentIndex,counter)){
			cycle[currentIndex] = counter;
			if(hamiltonianCycleMain(adjacencyMatrix,cycle,currentIndex+1)){
				return true;
			}
		}
	}
	return false;
}

void printHamiltonianCycle(vector<vector<bool> > adjacencyMatrix){
	if(adjacencyMatrix.size() == 0){
		return;
	}
	vector<int> cycle(adjacencyMatrix.size(),INT_MIN);
	cycle[0] = 0;
	if(hamiltonianCycleMain(adjacencyMatrix,cycle,1)){
		printIVector(cycle);
	}
}

#endif /* HAMILTONIANCYCLE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
