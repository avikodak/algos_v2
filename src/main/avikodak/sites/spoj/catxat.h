/****************************************************************************************************************************************************
 *  File Name                   : catxat.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/spoj/catxat.h
 *  Created on                  : 23-Sep-2015 :: 10:29:57 am
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.spoj.com/problems/CATXAT/
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
#include <stdint.h>
#include <iomanip>
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

#ifndef CATXAT_H_
#define CATXAT_H_

string replaceAll(string input,string original,string updated){
	size_t position;
	while((position = input.find(original)) != string::npos){
		input.replace(position,original.length(),updated);
		position += updated.length();
	}
	return input;
}

void printResults(){
	unsigned int testCases;
	scanf("%u",&testCases);
	string replaceXAT = "UBXEQX",replaceCAT = "ZGXEQX",input;
	while(testCases--){
		cin >> input;
		input = replaceAll(input,"XAT","UBXEQX");
		input = replaceAll(input,"CAT","ZGXEQX");
		cout << input << endl;
	}
}

#endif /* CATXAT_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
