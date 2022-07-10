# Algorithm Visualizer

## Build

### Visual Studio

Start screen → Open a local folder

**or**

File → Open → Folder

I don't recommend generating the project files with the `cmake` command since I cannot guarantee that it will work. Opening the folder as a CMake project is much better (in my opinion)

### Others

Run the `cmake` command to generate your project files.

It does not seem to work for Clang or G++. So my advice would be to MSVC for this. I cannot for the life of me get it to work for the other compilers. Plus, this is on Windows so why would you want to use other compilers in the first place?

(I would eventually try and solve this compiler problem)
