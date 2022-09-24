# UNotePad

This is a simple text editor application written in C++ using [wxWidgets](https://wxwidgets.org) (which is a cross platform library for building graphical user interfaces). This project is for beginners who wants to learn about basics about wxWidgets. You can just read the code. It don't has a good documentation but is has a readable and self-explanatory code. You can learn basics of wxWidgets (sizers, frames, events, file handling, etc) by reading the code.  
  
Currently this app is saving an Untitled.txt file in the same directory. I will add a file dialog box and let the user to choose the directory to save the file when I have a time. And also feel free to contribute to this project.  

## Build Instructions

To build this project you should have installed [CMake](https://cmake.org), a c++ compiler and built wxWidgets from source using CMake. (For wxWidgets build instructions see https://docs.wxwidgets.org/latest/overview_cmake.html).  
  
After that, open up the terminal:  
```bash
git clone https://github.com/usithadev/UNotePad.git #For this you need git installed. You can also go to the github repository and download the coe.

cd UNotePad

cmake -DwxWidgets_DIR=path/to/wxWidgets -S . -B ./build -DCMAKE_BUILD_TYPE="Release" -G "MinGW Makefiles"

cd build

```

Now you can find the UNotePad.exe (and the doxygen documentation files) in the build folder.