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

#ifndef CONDENSESTRING_H_
#define CONDENSESTRING_H_

string condenseString(string str) {
    string result;
    int crawler = 0,frequency = 0;
    stringstream convert;
    while(crawler < str.length()){
        frequency = 1;
        while(crawler+1 < str.length() && str[crawler] == str[crawler+1]){
            frequency++;
            crawler++;
        }
        if(frequency == 1){
            result.push_back(str[crawler]);
        }else if(frequency == 2){
            result.push_back(str[crawler]);
            result.push_back(str[crawler]);
        }else{
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
