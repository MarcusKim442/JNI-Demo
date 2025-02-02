# JNI-Demo

This demo repository demonstrates how to send varying data structures to and from Java and C programming using JNI and the command line.

This demo project contains: 
* Jside.java - Java program that calls a function from C
* Jside.h - The header file that is automatically generated by javac according to java class in Jside.java
* Cside.c - The C program source code that includes the implementations of a function defined in Jside.h
* Demo.dll - The shared Library File compiled by C compiler  
* Jside.class - The compiled Java file. 

## How to Run the Demo *(On 64-Bit Windows OS with Java 14)* :
On Windows: 
   * You need a C compiler (etc. GCC supplied from [MinGW](http://www.mingw.org/)) 
   * You need to install JDK - Java Development Kit either [Oracle-JDK](https://www.oracle.com/java/technologies/javase/jdk14-archive-downloads.html), or [OpenJDK](https://jdk.java.net/14/)
```bash
git clone https://github.com/MarcusKim442/JNI-Demo
cd JNI-Demo
```
If you have already configure JAVA_HOME in your system path as in [Tutorial](https://confluence.atlassian.com/doc/setting-the-java_home-variable-in-windows-8895.html) 

You can run the Demo as:
```bash
java -cp . -Djava.library.path=. Jside
```

Otherwise you can directly call java executable program by providing the full path:
```bash
"{JDK_INSTALL_DIR}\bin\java.exe" -cp . -Djava.library.path=. Jside
```
## Please read the following document for a walkthrough of the demo:
https://docs.google.com/presentation/d/1frAAhsxWRVRLxykLCntK-PpnlVhA7yr2xGOe635VrcI/edit?usp=sharing

## Steps to create your own JNI project (calls C function from Java)
Manually Compile Files *(On 64-Bit Windows OS with Java 14)* :
* Write the Java (e.g. Jside.java) program and compile it.
```bash
javac Jside.java
# output Jside.class file
```
* Generate header file from java class
```bash
javac Jside.java -h .
# output Jside.h file
```
* Write the C program (e.g. Cside.c) and compile it
```bash
gcc -shared -fPIC Cside.c -I "[directory to personal jni.h file]" -I "[directory to personal jni_md.h file]" -o Demo.dll
# In my case, I input the following: 
# gcc -shared -fPIC Cside.c -I "C:\Program Files\Java\jdk-14.0.2\include" -I "C:\Program Files\Java\jdk-14.0.2\include\win32" -o Demo.dll
# output Demo.dll
```
## Extra Readings 
* https://javapapers.com/core-java/how-to-call-a-c-program-from-java/
* [From Java call C functions in 4 mins](https://www.youtube.com/watch?v=Hw7563ojRbU&ab_channel=GaurAssociates)
* [JNI Documentation](https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/jniTOC.html)
