/****************************************************************************************************************************************************
 *  File Name                   : nologic.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/nologic.h
 *  Created on                  : 11-Sep-2015 :: 10:48:35 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/NOLOGIC
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
#include <ctype.h>
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

#ifndef NOLOGIC_H_
#define NOLOGIC_H_

//Tested
void printNoLogicAns(string userInput){
	unsigned int frequencyCount[26] = {0};
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] >= 'a' && userInput[counter] <= 'z')
		frequencyCount[userInput[counter]-'a']++;
	}
	for(unsigned int counter = 0;counter < 26;counter++){
		if(frequencyCount[counter] == 0){
			printf("%c\n",counter+'a');
			return;
		}
	}
	cout << "~" << endl;
}

//Tested
void printResults(){
	unsigned int testCases;
	string userInput;
	cin >> testCases;
	cin.ignore();
	while(testCases--){
		getline(cin,userInput);
		transform(userInput.begin(),userInput.end(),userInput.begin(),::tolower);
		printNoLogicAns(userInput);
	}
}

#endif /* NOLOGIC_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
