/****************************************************************************************************************************************************
 *  File Name                   : timeinwords.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\warmup\timeinwords.h
 *  Created on                  : Jun 16, 2015 :: 8:45:22 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.hackerrank.com/challenges/the-time-in-words
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

#ifndef TIMEINWORDS_H_
#define TIMEINWORDS_H_

map<unsigned int,string> init() {
    map<unsigned int,string> numberWordsMap;
    numberWordsMap.insert(pair<unsigned int,string>(1,"one"));
    numberWordsMap.insert(pair<unsigned int,string>(2,"two"));
    numberWordsMap.insert(pair<unsigned int,string>(3,"three"));
    numberWordsMap.insert(pair<unsigned int,string>(4,"four"));
    numberWordsMap.insert(pair<unsigned int,string>(5,"five"));
    numberWordsMap.insert(pair<unsigned int,string>(6,"six"));
    numberWordsMap.insert(pair<unsigned int,string>(7,"seven"));
    numberWordsMap.insert(pair<unsigned int,string>(8,"eight"));
    numberWordsMap.insert(pair<unsigned int,string>(9,"nine"));
    numberWordsMap.insert(pair<unsigned int,string>(10,"ten"));
    numberWordsMap.insert(pair<unsigned int,string>(11,"eleven"));
    numberWordsMap.insert(pair<unsigned int,string>(12,"twelve"));
    numberWordsMap.insert(pair<unsigned int,string>(13,"thirteen"));
    numberWordsMap.insert(pair<unsigned int,string>(14,"fourteen"));
    numberWordsMap.insert(pair<unsigned int,string>(15,"fifteen"));
    numberWordsMap.insert(pair<unsigned int,string>(16,"sixteen"));
    numberWordsMap.insert(pair<unsigned int,string>(17,"seventeen"));
    numberWordsMap.insert(pair<unsigned int,string>(18,"eighteen"));
    numberWordsMap.insert(pair<unsigned int,string>(19,"nineteen"));
    numberWordsMap.insert(pair<unsigned int,string>(20,"twenty"));
    numberWordsMap.insert(pair<unsigned int,string>(21,"twenty one"));
    numberWordsMap.insert(pair<unsigned int,string>(22,"twenty two"));
    numberWordsMap.insert(pair<unsigned int,string>(23,"twenty three"));
    numberWordsMap.insert(pair<unsigned int,string>(24,"twenty four"));
    numberWordsMap.insert(pair<unsigned int,string>(25,"twenty five"));
    numberWordsMap.insert(pair<unsigned int,string>(26,"twenty six"));
    numberWordsMap.insert(pair<unsigned int,string>(27,"twenty seven"));
    numberWordsMap.insert(pair<unsigned int,string>(28,"twenty eight"));
    numberWordsMap.insert(pair<unsigned int,string>(29,"twenty nine"));
}



#endif /* TIMEINWORDS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
