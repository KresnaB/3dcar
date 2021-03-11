# 3dcar
a 3D car model created using freeglut/OpenGL

#how to install codeblocks (skip the graphic.h part)
https://sangams.com.np/adding-graphics-h-tdm-gcc-c-compiler/

#download link for freeglut 3.0.0
https://www.transmissionzero.co.uk/files/software/development/GLUT/freeglut-MinGW.zip

#installation step
1. Install and Use DevC ++ / CodeBlock / Visual Studio Code / Sublime Text as a C ++ IDE
2. Download and extract the freeglut-MinGW-3.0.0-1.mp.zip file
3. Move the contents of the file from the include folder & gt; GL to directory: C: \ Program Files (x86) \ Dev-
Cpp \ MinGW64 \ x86_64-w64-mingw32 \ include \ GL
4. Move the contents of the folder lib & gt; x64 to directory C: \ Program Files (x86) \ Dev-Cpp \ MinGW64 \ x86_64-w64-
mingw32 \ lib
5. Move the contents of the bin & gt; x64 to the C: \ Windows \ System32 directory, for 64-bit computers, there are additions
files that must be added by adding how to move freeglut.dll in the bin folder (outside the x64 folder) to
C: \ Windows \ SysWOW64
6. Create a Project Console in Dev-C ++
7.Linker settings on your IDE C ++ of choice are as follows:
-lopengl32
-lfreeglut
-lglu32
8. Run the following OGL01Shape3D.cpp program to make sure Freeglut is connected. Download test program in this link :
https://www3.ntu.edu.sg/home/ehchua/programming/opengl/CG_Examples.html
