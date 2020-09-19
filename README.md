# JNI-Demo

Please read the following document for an explanation of the demo:
https://docs.google.com/presentation/d/1frAAhsxWRVRLxykLCntK-PpnlVhA7yr2xGOe635VrcI/edit?usp=sharing

How to Run the Demo *(On 64-Bit Windows OS with java 14)* :

    1) Open command prompt, change directory to folder with demo files

    2) java -cp . -Djava.library.path=. Jside

How to Manually Compile Files *(On 64-Bit Windows OS with java 14)* :

    After editing any of the files you will need to recompile,
    
    1) Open command prompt, change directory to folder with edited demo files

    2) javac Jside.java -h .

    3) gcc -shared -fPIC Cside.c -I "[directory to personal jni.h file]" -I "[directory to personal jni_md.h file]" -o Demo.dll

       In my case, I input the following: 
   
       gcc -shared -fPIC Cside.c -I "C:\Program Files\Java\jdk-14.0.2\include" -I "C:\Program Files\Java\jdk-14.0.2\include\win32" -o Demo.dll
