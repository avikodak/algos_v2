/****************************************************************************************************************************************************
 *  File Name                   : mriu4.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/mriu4.h
 *  Created on                  : 20-Sep-2015 :: 12:28:12 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/MRIU4
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
#define gc getchar_unlocked

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MRIU4_H_
#define MRIU4_H_

//Tested
inline unsigned int scan() {
	unsigned int t=0,neg=0;
	char c;
	c=gc();
	while((c<'0' || c>'9')&& c!='-')
		c=gc();
	if(c=='-') {neg=1;c=gc();}
	while(c>='0' && c<='9')
	{
		t=(t<<3)+(t<<1)+c-'0';
		c=gc();
	}
	if(neg) t=-t;
	return(t);
}

//Tested
void printResults(){
	unsigned int testCases,input,size;
	vector<unsigned int> userInput;
	testCases = scan();
	while(testCases--){
		size = scan();
		userInput.clear();
		while(size--){
			input = scan();
			userInput.push_back(input);
		}
		sort(userInput.begin(),userInput.end());
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			printf("%u ",userInput[counter]);
		}
		printf("\n");
	}
}

#endif /* MRIU4_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
