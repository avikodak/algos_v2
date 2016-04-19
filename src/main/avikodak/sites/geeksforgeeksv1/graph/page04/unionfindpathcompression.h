/****************************************************************************************************************************************************
 *  File Name                   : unionfindpathcompression.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\unionfindpathcompression.h
 *  Created on                  : Jan 12, 2015 :: 10:13:57 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef UNIONFINDPATHCOMPRESSION_H_
#define UNIONFINDPATHCOMPRESSION_H_

void ufpcUnion(vector<ncUnionfind *> unionFindDS,ncUnionfind *firstComponent,ncUnionfind *secondComponent) {
    if(firstComponent->nodeCounter < secondComponent->nodeCounter) {
        int vertexCounter = firstComponent->parentVertex;
        while(unionFindDS[vertexCounter]->parentVertex != vertexCounter) {
            unionFindDS[vertexCounter]->parentVertex = secondComponent->parentVertex;
            vertexCounter = unionFindDS[vertexCounter]->parentVertex;
        }
        firstComponent->parentVertex = secondComponent->parentVertex;
        secondComponent->nodeCounter += firstComponent->nodeCounter;
    } else {
        int vertexCounter = secondComponent->parentVertex;
        while(unionFindDS[vertexCounter]->parentVertex != vertexCounter) {
            unionFindDS[vertexCounter]->parentVertex = firstComponent->parentVertex;
            vertexCounter = unionFindDS[vertexCounter]->parentVertex;
        }
        secondComponent->parentVertex = firstComponent->parentVertex;
        firstComponent->nodeCounter += secondComponent->nodeCounter;
    }
}

ncUnionfind * ufpcFind(vector<ncUnionfind *> unionFindDS,int vertexIndex) {
    if(unionFindDS.size() == 0 || vertexIndex >= unionFindDS.size()) {
        return null;
    }
    while(unionFindDS[vertexIndex]->parentVertex != vertexIndex) {
        vertexIndex = unionFindDS[vertexIndex]->parentVertex;
    }
    return vertexIndex;
}

void unionFindPathCompression(vector<edge *> edgeList,int vertexCount) {
    if(edgeList.size() == 0) {
        return;
    }
    vector<ncUnionfind *> unionFindDS;
    for(unsigned int counter = 0; counter < vertexCount; counter++) {
        unionFindDS.push_back(new ncUnionfind(counter));
    }
    ncUnionfind *firstComponent,*secondComponent;
    for(unsigned int counter = 0; counter < edgeList.size(); counter++) {
        firstComponent = ufpcFind(edgeList[counter]->sourceVertex);
        secondComponent = ufpcFind(edgeList[counter]->destinationVertex);
        ufpcUnion(unionFindDS,firstComponent,secondComponent);
    }
}

#endif /* UNIONFINDPATHCOMPRESSION_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
