# UNotePad

This is a simple text editor application written in C++ using [wxWidgets](https://wxwidgets.org) (which is a cross platform library for building graphical user interfaces). This project is for beginners who wants to learn about basics about wxWidgets. You can just read the code. It doesn't have a good documentation but is has a readable and self-explanatory code. You can learn basics of wxWidgets (sizers, frames, events, file handling, etc) by reading the code.  
  
Currently this app is saving a .txt file in a directory that asked from user using a file dialog (the Save as feature) and have basic editing options like copy, cut, paste, etc. And I didn't have added much basic features such as open, save, etc. I'll add them when I have a time. So feel free to contribute to this project.  

## Build Instructions

To build this project you should have installed [CMake](https://cmake.org), a c++ compiler and [wxWidgets](https://wxwidgets.org). 
  
After that, open up the terminal:  
```bash
$ git clone https://github.com/usithadev/UNotePad.git #For this you need git installed. You can also go to the github repository and download the code.

$ cd UNotePad

$ cmake -S . -B ./build -G "Unix Makefiles"

$ cd build

$ cmake --build .

```

Now you can find the UNotePad.exe in the build folder.
