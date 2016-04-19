/****************************************************************************************************************************************************
 *  File Name                   : largestproductingrid.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\largestproductingrid.h
 *  Created on                  : Aug 20, 2015 :: 12:52:27 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=11
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

#ifndef LARGESTPRODUCTINGRID_H_
#define LARGESTPRODUCTINGRID_H_

//Tested
vector<vector<unsigned int> > getMatrix() {
    unsigned int size,input;
    cin >> size;
    vector<vector<unsigned int> > matrix(size);
    for(unsigned int rowCounter = 0; rowCounter < size; rowCounter++) {
        matrix[rowCounter].assign(size,0);
    }
    for(unsigned int rowCounter = 0; rowCounter < size; rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < size; columnCounter++) {
            cin >> input;
            matrix[rowCounter][columnCounter] = input;
        }
    }
    return matrix;
}

//Tested
//Ans : 70600674
void getMaxAdjacentProduct() {
    vector<vector<unsigned int> > matrix = getMatrix();
    int size = matrix.size();
    cout << size << endl;
    if(size < 4) {
        return;
    }
    unsigned int maxProduct = 0,rowProduct,columnProduct,diagonalProduct,otherDiagonalProduct;
    for(int rowCounter = 0; rowCounter < size; rowCounter++) {
        for(int columnCounter = 0; columnCounter < size; columnCounter++) {
            if(columnCounter+3 < size) {
                rowProduct = matrix[rowCounter][columnCounter] * matrix[rowCounter][columnCounter+1] * matrix[rowCounter][columnCounter+2] * matrix[rowCounter][columnCounter+3];
            }
            if(rowCounter+3 < size) {
                columnProduct = matrix[rowCounter][columnCounter] * matrix[rowCounter+1][columnCounter] * matrix[rowCounter+2][columnCounter] * matrix[rowCounter+3][columnCounter];
            }
            if(rowCounter-3 >= 0 && columnCounter+3 < size) {
                diagonalProduct = matrix[rowCounter][columnCounter] * matrix[rowCounter-1][columnCounter+1] * matrix[rowCounter-2][columnCounter+2] * matrix[rowCounter-3][columnCounter+3];
            }
            if(rowCounter-3 >= 0 && columnCounter-3 >= 0) {
                otherDiagonalProduct = matrix[rowCounter][columnCounter] * matrix[rowCounter-1][columnCounter-1] * matrix[rowCounter-2][columnCounter-2] * matrix[rowCounter-3][columnCounter-3];
            }
            maxProduct = max(maxProduct,max(rowProduct,max(columnProduct,max(otherDiagonalProduct,diagonalProduct))));
        }
    }
    cout << maxProduct << endl;
}

#endif /* LARGESTPRODUCTINGRID_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
