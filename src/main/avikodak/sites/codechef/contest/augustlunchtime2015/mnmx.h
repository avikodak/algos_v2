/****************************************************************************************************************************************************
 *  File Name                   : mnmx.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\contest\augustlunchtime2015\mnmx.h
 *  Created on                  : Aug 30, 2015 :: 11:04:10 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/LTIME27/problems/MNMX
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

#ifndef MNMX_H_
#define MNMX_H_

//Tested
void printMinOperationVal(vector<int> userInput){
	int minValue = *min_element(userInput.begin(),userInput.end());
	cout << (userInput.size()-1)*minValue << endl;
}

//Tested
void printResults(){
	unsigned int testCases,size;
	int input;
	vector<int> userInput;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u",&size);
		userInput.clear();
		while(size--){
			scanf("%d",&input);
			userInput.push_back(input);
		}
		printMinOperationVal(userInput);
	}
}


#endif /* MNMX_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
