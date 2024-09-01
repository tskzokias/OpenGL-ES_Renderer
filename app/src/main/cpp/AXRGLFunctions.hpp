/********** AUTHOR NAME: TAKSH GOYAL ********************************
 ********** ORGANIZATION: AJNALENS (DIMENSIONNXG PVT. LTD.)**********
 ********** DATE: 14:03:2024 ****************************************
 ********** FILENAME: AXRGLFunctions.h ************************************/

#ifndef CUSTOMLAUNCHER_AXRGLFUNCTIONS_HPP
#define CUSTOMLAUNCHER_AXRGLFUNCTIONS_HPP

#include <GLES3/gl32.h>

bool checkGlError(const char* funcName);
void printGlString(const char* name, GLenum s);

#endif //CUSTOMLAUNCHER_AXRGLFUNCTIONS_HPP
