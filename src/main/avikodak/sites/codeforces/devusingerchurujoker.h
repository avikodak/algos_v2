/****************************************************************************************************************************************************
 *  File Name                   : devusingerchurujoker.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\devusingerchurujoker.h
 *  Created on                  : Apr 11, 2015 :: 9:29:02 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/439/A
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

#ifndef DEVUSINGERCHURUJOKER_H_
#define DEVUSINGERCHURUJOKER_H_

//Tested
void printMaxJokes(){
	unsigned int totalSongs,timeTaken,input,totalTimeSongs = 0;
	scanf("%u %u",&totalSongs,&timeTaken);
	for(unsigned int counter = 0;counter < totalSongs;counter++){
		scanf("%u",&input);
		totalTimeSongs += input;
	}
	totalTimeSongs += (10*(totalSongs-1));
	if(totalTimeSongs > timeTaken){
		printf("-1");
	}else{
		printf("%u",((timeTaken - totalTimeSongs)/5 + (10*(totalSongs-1))/5));
	}
}

#endif /* DEVUSINGERCHURUJOKER_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
