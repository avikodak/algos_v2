/****************************************************************************************************************************************************
 *  File Name   		: tlg.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\tlg.h
 *  Created on			: Feb 3, 2015 :: 6:55:31 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.codechef.com/problems/TLG
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TLG_H_
#define TLG_H_

//Tested
void printWinner(){
	int noOfRounds;
	scanf("%d",&noOfRounds);
	int firstPersonScore,secondPersonScore,maxLead = INT_MIN,maxLeadPerson,firstLead = 0,secondLead = 0;
	while(noOfRounds--){
		scanf("%d %d",&firstPersonScore,&secondPersonScore);
		firstLead += (firstPersonScore - secondPersonScore);
		secondLead += (secondPersonScore - firstPersonScore);
		if(firstLead > maxLead){
			maxLead = firstLead;
			maxLeadPerson = 1;
		}else if(secondLead > maxLead){
			maxLead = secondLead;
			maxLeadPerson = 2;
		}
	}
	printf("%d %d\n",maxLeadPerson,maxLead);
}

#endif /* TLG_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
