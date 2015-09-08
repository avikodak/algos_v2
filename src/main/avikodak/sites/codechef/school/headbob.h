/****************************************************************************************************************************************************
 *  File Name                   : headbob.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\school\headbob.h
 *  Created on                  : Aug 24, 2015 :: 8:48:35 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/HEADBOB
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

#ifndef HEADBOB_H_
#define HEADBOB_H_

//Tested
void printTypeOfPerson(string userInput){
	unsigned int yCount = 0,iCount = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == 'Y'){
			yCount++;
		}else if(userInput[counter] == 'I'){
			iCount++;
		}
	}
	if(yCount != 0 || iCount != 0){
		if(yCount != 0 && iCount != 0){
			printf("NOT SURE\n");
		}else{
			printf("%s\n",yCount > 0?"NOT INDIAN":"INDIAN");
		}
	}else{
		printf("NOT SURE\n");
	}
}

//Tested
void getTypesForInput(){
	unsigned int testCases,length;
	string userInput;
	cin >> testCases;
	while(testCases--){
		cin >> length >> userInput;
		printTypeOfPerson(userInput);
	}
}

#endif /* HEADBOB_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
