/****************************************************************************************************************************************************
 *  File Name   		: taxi.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\taxi.h
 *  Created on			: Feb 3, 2015 :: 12:39:04 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/158/B
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

#ifndef TAXI_H_
#define TAXI_H_

//Tested
void getTotalNoOfTaxis(){
	unsigned int testCases;
	scanf("%u",&testCases);
	map<unsigned int,unsigned int> groupSizeCountMap;
	map<unsigned int,unsigned int>::iterator itToGroupSizeCountMap;
	unsigned int groupSize,carsRequired = 0;;
	while(testCases--){
		scanf("%u",&groupSize);
		if((itToGroupSizeCountMap = groupSizeCountMap.find(groupSize)) != groupSizeCountMap.end()){
			groupSizeCountMap[groupSize] += 1;
		}else{
			groupSizeCountMap[groupSize] = 1;
		}
	}
	for(unsigned int counter = 4;counter > 0;counter--){
		switch (counter) {
		case 1:
			if(groupSizeCountMap.find(1) != groupSizeCountMap.end() && groupSizeCountMap.find(1)->second > 0){
				carsRequired += ((groupSizeCountMap.find(1)->second)/4);
				carsRequired += ((groupSizeCountMap.find(1)->second)%4 > 0)?1:0;
			}
			break;
		case 2:
			if(groupSizeCountMap.find(2) != groupSizeCountMap.end()){
				if((groupSizeCountMap.find(2)->second)%2 == 1){
					if(groupSizeCountMap.find(1) != groupSizeCountMap.end() && groupSizeCountMap.find(1)->second > 0){
						if(groupSizeCountMap.find(1)->second >= 2){
							groupSizeCountMap[1] -= 2;
						}else{
							groupSizeCountMap[1] -= 1;
						}
						groupSizeCountMap[2] -= 1;
					}
					carsRequired += 1;
				}
				carsRequired += (groupSizeCountMap.find(2)->second)/2;
			}
			break;
		case 3:
			if(groupSizeCountMap.find(3) != groupSizeCountMap.end()){
				if(groupSizeCountMap.find(1) != groupSizeCountMap.end()){
					if(groupSizeCountMap.find(1)->second > groupSizeCountMap.find(3)->second){
						groupSizeCountMap[1] -= groupSizeCountMap.find(3)->second;
						if(groupSizeCountMap[1] == 0){
							groupSizeCountMap.erase(1);
						}
					}else{
						groupSizeCountMap.erase(1);
					}
				}
				carsRequired += groupSizeCountMap.find(3)->second;
				groupSizeCountMap.erase(3);
			}
			break;
		case 4:
			if(groupSizeCountMap.find(4) != groupSizeCountMap.end()){
				carsRequired += groupSizeCountMap.find(4)->second;
				groupSizeCountMap.erase(4);
			}
			break;
		}
	}
	printf("%d",carsRequired);
}

#endif /* TAXI_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
