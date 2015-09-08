/****************************************************************************************************************************************************
 *  File Name                   : totr.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\totr.h
 *  Created on                  : Sep 5, 2015 :: 8:54:27 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/TOTR
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

#ifndef TOTR_H_
#define TOTR_H_

//Tested
void translate(string userInput,string dictionary){
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] >= 'a' && userInput[counter] <='z'){
			printf("%c",dictionary[userInput[counter]-'a']);
		}else if(userInput[counter] >= 'A' && userInput[counter] <='Z'){
			printf("%c",dictionary[userInput[counter]-'A']-'a'+'A');
		}else{
			if(userInput[counter] == '_'){
				printf(" ");
			}else{
				printf("%c",userInput[counter]);
			}
		}
	}
	printf("\n");
}

//Tested
void printResults(){
	unsigned int testCases;
	string dictionary,userInput;
	scanf("%u",&testCases);
	cin >> dictionary;
	while(testCases--){
		cin >> userInput;
		translate(userInput,dictionary);
	}
}

#endif /* TOTR_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
