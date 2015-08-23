/****************************************************************************************************************************************************
 *  File Name                   : cubicpermutations.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\cubicpermutations.h
 *  Created on                  : Aug 21, 2015 :: 3:54:23 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=62
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

#ifndef CUBICPERMUTATIONS_H_
#define CUBICPERMUTATIONS_H_

//Tested
string convertULLIntToString(unsigned long long int value){
	stringstream stream;
	stream << value;
	string result;
	result.append(stream.str());
	stream.clear();
	return result;
}

//Tested
//Ans : 127035954683
void getSmallestCubicPermutation(){
	unsigned long long int counter = 1,result;
	string strResult;
	map<string,vector<unsigned long long int> > valueCounterMap;
	map<string,vector<unsigned long long int> >::iterator itToValueCounterMap;
	while(true){
		result = counter * counter * counter;
		strResult = convertULLIntToString(result);
		sort(strResult.begin(),strResult.end());
		if((itToValueCounterMap = valueCounterMap.find(strResult)) != valueCounterMap.end()){
			itToValueCounterMap->second.push_back(result);
			if(itToValueCounterMap->second.size() == 5){
				cout << itToValueCounterMap->second[0];
				return;
			}
		}else{
			vector<unsigned long long int> counterList;
			counterList.push_back(result);
			valueCounterMap.insert(pair<string,vector<unsigned long long int> >(strResult,counterList));
		}
		counter++;
	}
}

#endif /* CUBICPERMUTATIONS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
