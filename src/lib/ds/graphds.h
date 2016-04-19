/****************************************************************************************************************************************************
 *  File Name                   : graphds.h
 *  File Location               : \algos_v2\src\lib\ds\graphds.h
 *  Created on                  : Dec 5, 2014 :: 9:00:20 AM
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
#include <stdint.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef GRAPHDS_H_
#define GRAPHDS_H_

struct edge {
    int sourceVertex;
    int destinationVertex;
    bool isUndirectedEdge;

    edge() {

    }

    edge(int sourceVertex,int destinationVertex,bool isUndirectedEdge) {
        this->sourceVertex = sourceVertex;
        this->destinationVertex = destinationVertex;
        this->isUndirectedEdge = isUndirectedEdge;
    }
};

struct wEdge {
    int sourceVertex;
    int destinationVertex;
    int weight;
    bool isUndirectedEdge;

    wEdge() {

    }

    wEdge(int sourceVertex,int destinationVertex,int weight) {
        this->sourceVertex = sourceVertex;
        this->destinationVertex = destinationVertex;
        this->weight = weight;
        this->isUndirectedEdge = false;
    }

    wEdge(int sourceVertex,int destinationVertex,int weight,bool isUndirectedEdge) {
        this->sourceVertex = sourceVertex;
        this->destinationVertex = destinationVertex;
        this->weight = weight;
        this->isUndirectedEdge = isUndirectedEdge;
    }
};

struct dfsTimes {
    int arrivalTimes;
    int departureTimes;

    dfsTimes() {
        this->arrivalTimes = INT_MAX;
        this->departureTimes = INT_MAX;
    }

    dfsTimes(int arrivalTimes,int departureTimes) {
        this->arrivalTimes = arrivalTimes;
        this->departureTimes = departureTimes;
    }
};

struct ncUnionfind {
    int vertex;
    int nodeCounter;
    int parentVertex;

    ncUnionfind() {
        this->vertex = INT_MIN;
        this->nodeCounter = 0;
        this->parentVertex = NULL;
    }

    ncUnionfind(int vertex) {
        this->vertex = vertex;
        this->nodeCounter = 1;
        this->parentVertex = vertex;
    }

    ncUnionfind(int vertex,int parentVertex) {
        this->vertex = vertex;
        this->parentVertex = parentVertex;
        this->nodeCounter = 1;
    }
};

struct wVertex {
    int vertex;
    int weight;

    wVertex() {

    }

    wVertex(int vertex,int weight) {
        this->vertex = vertex;
        this->weight = weight;
    }
};

#endif /* GRAPHDS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
