/****************************************************************************************************************************************************
 *  File Name                   : circleline.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\circleline.h
 *  Created on                  : Apr 13, 2015 :: 12:50:05 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/278/A
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

#ifndef CIRCLELINE_H_
#define CIRCLELINE_H_

//Tested
void printMinDistance(){
	unsigned int stationsCount,userInput,source,destination;
	scanf("%u",&stationsCount);
	vector<int> distances;
	unsigned int totalDistance = 0;
	while(stationsCount--){
		scanf("%u",&userInput);
		distances.push_back(userInput);
		totalDistance += userInput;
	}
	scanf("%u %u",&source,&destination);
	if(source > destination){
		swap(source,destination);
	}
	unsigned int calculatedDistance = 0;
	for(unsigned int counter = source-1;counter < destination;counter++){
		calculatedDistance += distances[counter];
	}
	printf("%u",min(calculatedDistance,totalDistance-calculatedDistance));
}

#endif /* CIRCLELINE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
