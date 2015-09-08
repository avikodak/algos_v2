/****************************************************************************************************************************************************
 *  File Name                   : rowcolop.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\rowcolop.h
 *  Created on                  : Sep 6, 2015 :: 11:22:46 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/ROWCOLOP
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef ROWCOLOP_H_
#define ROWCOLOP_H_

//Tested
void printResults(){
	long long int size,opsCount,incrementBy,dimension;
	long long int maxRowSum = 0,maxColSum = 0;
	string operation;
	cin >> size >> opsCount;
	map<unsigned int,long long int> rowSumMap,columnSumMap;
	while(opsCount--){
		cin >> operation >> dimension >> incrementBy;
		if(operation.compare("RowAdd") == 0){
			if(rowSumMap.find(dimension) != rowSumMap.end()){
				rowSumMap[dimension] += incrementBy;
			}else{
				rowSumMap[dimension] = incrementBy;
			}
			maxRowSum = max(maxRowSum,rowSumMap[dimension]);
		}else{
			if(columnSumMap.find(dimension) != columnSumMap.end()){
				columnSumMap[dimension] += incrementBy;
			}else{
				columnSumMap[dimension] = incrementBy;
			}
			maxColSum = max(maxColSum,columnSumMap[dimension]);
		}
	}
	cout << maxRowSum+maxColSum << endl;
}

#endif /* ROWCOLOP_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
