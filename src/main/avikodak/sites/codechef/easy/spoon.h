/****************************************************************************************************************************************************
 *  File Name                   : spoon.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/spoon.h
 *  Created on                  : 11-Sep-2015 :: 7:32:01 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SPOON
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

#ifndef SPOON_H_
#define SPOON_H_

//Tested
void isSpoonPresent(vector<string> userInput){
	for(int rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		for(int columnCounter = 0;columnCounter < userInput[0].length();columnCounter++){
			if(columnCounter+4 < userInput[0].length()){
				if(userInput[rowCounter][columnCounter] == 's' &&
						userInput[rowCounter][columnCounter+1] == 'p' &&
						userInput[rowCounter][columnCounter+2] == 'o' &&
						userInput[rowCounter][columnCounter+3] == 'o' &&
						userInput[rowCounter][columnCounter+4] == 'n'){
					printf("There is a spoon!\n");
					return;
				}
			}else{
				break;
			}
		}
	}
	for(int columnCounter = 0;columnCounter < userInput[0].length();columnCounter++){
		for(int rowCounter = 0;rowCounter < userInput.size();rowCounter++){
			if(rowCounter+4 < userInput.size()){
				if(userInput[rowCounter][columnCounter] == 's' &&
						userInput[rowCounter+1][columnCounter] == 'p' &&
						userInput[rowCounter+2][columnCounter] == 'o' &&
						userInput[rowCounter+3][columnCounter] == 'o' &&
						userInput[rowCounter+4][columnCounter] == 'n'){
					printf("There is a spoon!\n");
					return;
				}
			}else{
				break;
			}
		}
	}
	printf("There is indeed no spoon!\n");
}

//Tested
void printResults(){
	unsigned int testCases,rows,columns;
	string input;
	vector<string> userInput;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u %u",&rows,&columns);
		userInput.clear();
		while(rows--){
			cin >> input;
			transform(input.begin(),input.end(),input.begin(),::tolower);
			userInput.push_back(input);
		}
		isSpoonPresent(userInput);
	}
}


#endif /* SPOON_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
