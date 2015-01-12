/****************************************************************************************************************************************************
 *  File Name   		: unionfindpathcompression.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\unionfindpathcompression.h
 *  Created on			: Jan 12, 2015 :: 10:13:57 AM
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

#ifndef UNIONFINDPATHCOMPRESSION_H_
#define UNIONFINDPATHCOMPRESSION_H_

void ufpcUnion(vector<ncUnionfind *> unionFindDS,ncUnionfind *firstComponent,ncUnionfind *secondComponent){
	if(firstComponent->nodeCounter < secondComponent->nodeCounter){
		int vertexCounter = firstComponent->parentVertex;
		while(unionFindDS[vertexCounter]->parentVertex != vertexCounter){
			unionFindDS[vertexCounter]->parentVertex = secondComponent->parentVertex;
			vertexCounter = unionFindDS[vertexCounter]->parentVertex;
		}
		firstComponent->parentVertex = secondComponent->parentVertex;
		secondComponent->nodeCounter += firstComponent->nodeCounter;
	}else{
		int vertexCounter = secondComponent->parentVertex;
		while(unionFindDS[vertexCounter]->parentVertex != vertexCounter){
			unionFindDS[vertexCounter]->parentVertex = firstComponent->parentVertex;
			vertexCounter = unionFindDS[vertexCounter]->parentVertex;
		}
		secondComponent->parentVertex = firstComponent->parentVertex;
		firstComponent->nodeCounter += secondComponent->nodeCounter;
	}
}

ncUnionfind * ufpcFind(vector<ncUnionfind *> unionFindDS,int vertexIndex){
	if(unionFindDS.size() == 0 || vertexIndex >= unionFindDS.size()){
		return null;
	}
	while(unionFindDS[vertexIndex]->parentVertex != vertexIndex){
		vertexIndex = unionFindDS[vertexIndex]->parentVertex;
	}
	return vertexIndex;
}

void unionFindPathCompression(vector<edge *> edgeList,int vertexCount){
	if(edgeList.size() == 0){
		return;
	}
	vector<ncUnionfind *> unionFindDS;
	for(unsigned int counter = 0;counter < vertexCount;counter++){
		unionFindDS.push_back(new ncUnionfind(counter));
	}
	ncUnionfind *firstComponent,*secondComponent;
	for(unsigned int counter = 0;counter < edgeList.size();counter++){
		firstComponent = ufpcFind(edgeList[counter]->sourceVertex);
		secondComponent = ufpcFind(edgeList[counter]->destinationVertex);
		ufpcUnion(unionFindDS,firstComponent,secondComponent);
	}
}

#endif /* UNIONFINDPATHCOMPRESSION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
