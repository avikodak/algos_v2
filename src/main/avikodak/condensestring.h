/****************************************************************************************************************************************************
 *  File Name   		: condensestring.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\condensestring.h
 *  Created on			: Feb 4, 2015 :: 12:58:14 PM
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef CONDENSESTRING_H_
#define CONDENSESTRING_H_

string condenseString(string str) {
    string result;
    int crawler = 0,frequency = 0;
    stringstream convert;
    while(crawler < str.length()) {
        frequency = 1;
        while(crawler+1 < str.length() && str[crawler] == str[crawler+1]) {
            frequency++;
            crawler++;
        }
        if(frequency == 1) {
            result.push_back(str[crawler]);
        } else if(frequency == 2) {
            result.push_back(str[crawler]);
            result.push_back(str[crawler]);
        } else {
            convert << frequency;
            result.append(convert.str());
            convert.str("");
            result.push_back('@');
            result.push_back(str[crawler]);
        }
        crawler++;
    }
    return result;
}

#endif /* CONDENSESTRING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
