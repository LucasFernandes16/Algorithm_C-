#include <bits/stdc++.h>
using namespace std;

int main()
{
  cout << "\nTesting dynamic storage allocation! "<< endl;
  // To allocate storage:
  double width = 23.78;
  double* ptrWidth = &width;
  double* ptrLength = new double(32.54);
  double* ptrArea = new double;
  // To work with ptrWidth, ptrLength, and ptrArea:
  *ptrArea = *ptrWidth * *ptrLength;
  delete ptrLength; // Error: The object is still
  // in use!
  cout << "\nWidth : " << *ptrWidth<< "\nLength : " << *ptrLength<< "\nArea : " << *ptrArea << endl;
  // To free storage:
//  delete ptrWidth; // Error: The object has not
  // been dynamically reserved
  delete ptrLength; // ok
  delete ptrArea; // ok
//  delete ptrLength; // Error: Pointer doesn't
  // address any object.
  ptrLength = new double(19.45); // ok
  // To give a name to a dynamic object:
  double& length = *ptrLength; // Reference
  cout << "\nNew length : " << length << "\nCircumference : " << 2 * width * length<< endl;
  return 0; // On terminating the program
}