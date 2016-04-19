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

#ifndef CUBICPERMUTATIONS_H_
#define CUBICPERMUTATIONS_H_

//Tested
string convertULLIntToString(unsigned long long int value) {
    stringstream stream;
    stream << value;
    string result;
    result.append(stream.str());
    stream.clear();
    return result;
}

//Tested
//Ans : 127035954683
void getSmallestCubicPermutation() {
    unsigned long long int counter = 1,result;
    string strResult;
    map<string,vector<unsigned long long int> > valueCounterMap;
    map<string,vector<unsigned long long int> >::iterator itToValueCounterMap;
    while(true) {
        result = counter * counter * counter;
        strResult = convertULLIntToString(result);
        sort(strResult.begin(),strResult.end());
        if((itToValueCounterMap = valueCounterMap.find(strResult)) != valueCounterMap.end()) {
            itToValueCounterMap->second.push_back(result);
            if(itToValueCounterMap->second.size() == 5) {
                cout << itToValueCounterMap->second[0];
                return;
            }
        } else {
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
