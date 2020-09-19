#include <stdio.h>
#include "Jside.h"

JNIEXPORT jintArray JNICALL Java_Jside_cFunctionName
(JNIEnv* jenv, jobject jobj, jcharArray jMapChars)
{
	//Get the length, and entries of java map data array
		const jsize jLength = (*jenv)->GetArrayLength(jenv, jMapChars);
		jchar *jArray = (*jenv)->GetCharArrayElements(jenv, jMapChars, 0);
		
	//Copy java array elements to a C array, print result
		printf("\nCharacters from Java, printed from C: \n"); 
		
		char cChars[jLength];
	
		for (int i = 0; i < jLength; i++) {
			cChars[i] = jArray[i];
			
			printf("%c ", cChars[i]);
			printf("\n");
		} 
		printf("\n");
	
	//No longer need java version of charcter array (jArray[])
	//(It is copied to C variable cChars[])
		(*jenv)->ReleaseCharArrayElements(jenv, jMapChars, jArray, 0);
				
	//Complete Calculations Here:
		int cInts[jLength];
		
		for (int i = 0; i < jLength; i++) {
			cInts[i] = cChars[i];
		}
		
	//Create Java int array, copy C ints to Java array
		jintArray returnArr = (*jenv)->NewIntArray(jenv, jLength);
		jint *arrPointer = (*jenv)->GetIntArrayElements(jenv, returnArr, 0);
		
		for (int i = 0; i < jLength; i++) {
			arrPointer[i] = cInts[i];
		}
		(*jenv)->ReleaseIntArrayElements(jenv, returnArr, arrPointer, 0);
		
	//Pass values to Java
		return returnArr;	
}