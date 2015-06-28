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

#ifndef TIMEINWORDS_H_
#define TIMEINWORDS_H_

map<unsigned int,string> init(){
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
