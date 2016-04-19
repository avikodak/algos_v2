/****************************************************************************************************************************************************
 *  File Name                   : cycleunionfind.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page03\cycleunionfind.h
 *  Created on                  : Dec 15, 2014 :: 9:09:06 PM
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

#ifndef CYCLEUNIONFIND_H_
#define CYCLEUNIONFIND_H_

void ncUnion(ncUnionfind *firstComponent,ncUnionfind *secondComponent) {
    if(firstComponent->nodeCounter >= secondComponent->nodeCounter) {
        firstComponent->nodeCounter += secondComponent->nodeCounter;
        secondComponent->parentVertex = firstComponent->parentVertex;
    } else {
        secondComponent->nodeCounter += firstComponent->nodeCounter;
        firstComponent->parentVertex = secondComponent->parentVertex;
    }
}

ncUnionfind *ncFind(vector<ncUnionfind *> unionFindDS,int vertex) {
    if(unionFindDS.size() >= vertex) {
        return null;
    }
    while(unionFindDS[vertex]->parentVertex != vertex) {
        vertex = unionFindDS[vertex]->parentVertex;
    }
    return unionFindDS[vertex];
}

bool isGraphAcyclic(vector<edge *> edgeList,int noOfVertices) {
    if(edgeList.size() == 0) {
        return true;
    }
    vector<ncUnionfind *>  unionFindDS;
    for(unsigned int counter = 0; counter < noOfVertices; counter++) {
        unionFindDS.push_back(new ncUnionfind(counter));
    }
    ncUnionfind *firstComponent,*secondComponent;
    for(unsigned int counter = 0; counter < edgeList.size(); counter++) {
        firstComponent = ncFind(unionFindDS,edgeList[counter]->sourceVertex);
        secondComponent = ncFind(unionFindDS,edgeList[counter]->destinationVertex);
        if(firstComponent->parentVertex == secondComponent->parentVertex) {
            return false;
        }
        ncUnion(firstComponent,secondComponent);
    }
    return true;
}

#endif /* CYCLEUNIONFIND_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
