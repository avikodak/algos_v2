/****************************************************************************************************************************************************
 *  File Name   		: cycleunionfind.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\cycleunionfind.h
 *  Created on			: Dec 15, 2014 :: 9:09:06 PM
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

#ifndef CYCLEUNIONFIND_H_
#define CYCLEUNIONFIND_H_

void ncUnion(ncUnionfind *firstComponent,ncUnionfind *secondComponent){
	if(firstComponent->nodeCounter >= secondComponent->nodeCounter){
		firstComponent->nodeCounter += secondComponent->nodeCounter;
		secondComponent->parentVertex = firstComponent->parentVertex;
	}else{
		secondComponent->nodeCounter += firstComponent->nodeCounter;
		firstComponent->parentVertex = secondComponent->parentVertex;
	}
}

ncUnionfind *ncFind(vector<ncUnionfind *> unionFindDS,int vertex){
	if(unionFindDS.size() >= vertex){
		return null;
	}
	while(unionFindDS[vertex]->parentVertex != vertex){
		vertex = unionFindDS[vertex]->parentVertex;
	}
	return unionFindDS[vertex];
}

bool isGraphAcyclic(vector<edge *> edgeList,int noOfVertices){
	if(edgeList.size() == 0){
		return true;
	}
	vector<ncUnionfind *>  unionFindDS;
	for(unsigned int counter = 0;counter < noOfVertices;counter++){
		unionFindDS.push_back(new ncUnionfind(counter));
	}
	ncUnionfind *firstComponent,*secondComponent;
	for(unsigned int counter = 0;counter < edgeList.size();counter++){
		firstComponent = ncFind(unionFindDS,edgeList[counter]->sourceVertex);
		secondComponent = ncFind(unionFindDS,edgeList[counter]->destinationVertex);
		if(firstComponent->parentVertex == secondComponent->parentVertex){
			return false;
		}
		ncUnion(firstComponent,secondComponent);
	}
	return true;
}

#endif /* CYCLEUNIONFIND_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
