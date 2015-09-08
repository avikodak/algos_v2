/****************************************************************************************************************************************************
 *  File Name                   : points.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\points.h
 *  Created on                  : Sep 6, 2015 :: 2:33:10 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/POINTS
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef POINTS_H_
#define POINTS_H_

//Tested
struct point{
	int xValue;
	int yValue;

	point(){};

	point(int xValue,int yValue){
		this->xValue = xValue;
		this->yValue = yValue;
	}
};

//Tested
double distance(point *first,point *second){
	double firstValue = pow((first->xValue - second->xValue),2);
	double secondValue = pow((first->yValue - second->yValue),2);
	return sqrt(firstValue + secondValue);
}

//Tested
bool sortFunc(point *first,point *second){
	if(first->xValue == second->xValue){
		return first->yValue > second->yValue;
	}
	return first->xValue < second->xValue;
}

//Tested
void calTotalDistance(vector<point *> userInput){
	sort(userInput.begin(),userInput.end(),sortFunc);
	double totalDistance = 0;
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		totalDistance += distance(userInput[counter],userInput[counter+1]);
	}
	cout.precision(2);
	cout << fixed << totalDistance << endl;
}

//Tested
void printResults(){
	unsigned int testCases,size;
	int xValue,yValue;
	scanf("%u",&testCases);
	vector<point *> userInput;
	while(testCases--){
		scanf("%u",&size);
		userInput.clear();
		for(unsigned int counter = 0;counter < size;counter++){
			scanf("%d %d",&xValue,&yValue);
			userInput.push_back(new point(xValue,yValue));
		}
		calTotalDistance(userInput);
	}
}

#endif /* POINTS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
