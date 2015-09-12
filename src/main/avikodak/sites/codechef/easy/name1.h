/****************************************************************************************************************************************************
 *  File Name                   : name1.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/name1.h
 *  Created on                  : 11-Sep-2015 :: 6:58:31 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/NAME1
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

#ifndef NAME1_H_
#define NAME1_H_

//Tested
void areValidNames(){
	string fatherName,motherName,input;
	unsigned int children;
	vector<string> childNames;
	int frequency[26] = {0};
	cin >> fatherName >> motherName >> children;
	while(children--){
		cin >> input;
		childNames.push_back(input);
	}
	for(unsigned int counter = 0;counter < fatherName.length();counter++){
		frequency[fatherName[counter]-'a']++;
	}
	for(unsigned int counter = 0;counter < motherName.length();counter++){
		frequency[motherName[counter]-'a']++;
	}
	for(unsigned int outerCounter = 0;outerCounter < childNames.size();outerCounter++){
		for(unsigned int innerCounter = 0;innerCounter < childNames[outerCounter].length();innerCounter++){
			if(frequency[childNames[outerCounter][innerCounter]-'a'] == 0){
				printf("NO\n");
				return;
			}
			frequency[childNames[outerCounter][innerCounter]-'a']--;
		}
	}
	printf("YES\n");
}

//Tested
void printResults(){
	unsigned int testCases;
	scanf("%u",&testCases);
	while(testCases--){
		areValidNames();
	}
}


#endif /* NAME1_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
