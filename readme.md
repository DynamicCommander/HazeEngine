# Haze Engine
## ReadMe

#### Repository
[<b>[https://github.com/DynamicCommander/HazeEngine]</b>](https://github.com/DynamicCommander/HazeEngine)

#### Recommended Software
<b>Visual Studio 2017 Community</b> [IDE] (Free) - [<b>[https://visualstudio.microsoft.com/downloads/]</b>](https://visualstudio.microsoft.com/downloads/)  
<b>Git</b> [Version Control][Version 2.18.0] (Free) - [<b>[https://git-scm.com/download/win]</b>](https://git-scm.com/download/win)   
<b>Vulkan SDK</b> [Graphics Pipeline][Version 1.1.77.0] - [<b>[https://vulkan.lunarg.com/sdk/home]</b>](https://vulkan.lunarg.com/sdk/home)  
<b>GLM</b> [Math Library][Version .9.9.0] - [<b>[https://glm.g-truc.net/0.9.9/index.html]</b>](https://glm.g-truc.net/0.9.9/index.html)  
<b>GLFW</b> [Window Management Library][Version 3.2.1] - [<b>[http://www.glfw.org/]</b>](http://www.glfw.org/) - [<b>[http://www.glfw.org/download.html]</b>](http://www.glfw.org/download.html)

#### Installation Instructions

1. Download all neccessary software. All of the above is needed for compilation to occur.
1. Create Folder on `C:` drive called `CLIENT` inside that folder create another called `HAZE`. We are using this structure straight from the `C:` drive because it creates an absolute path for the includes and linker and any filepaths that the project may need.
1. Clone Repository into new folder called `HazeEngine` at `C:\CLIENT\HAZE\`
   - ```git status``` to see what files are modified
   - ```git commit ``` to commit changes
   - ```git push origin [branch.name]``` to push changes to repo
1. Under ```C:\CLIENT\HAZE\HazeEngine\``` create a folder named ``` Libraries ``` if it does not already exist
1. Visit [<b>[Vulkan Installation Tutorial]</b>](https://vulkan-tutorial.com/Development_environment#page_Windows) and follow instructions for Windows install.
     - This also covers setting up Visual Studio for GLM and GLFW 
     - Make sure to download both parts of GLFW [<b>[http://www.glfw.org/]</b>](http://www.glfw.org/) and [<b>[http://www.glfw.org/download.html]</b>](http://www.glfw.org/download.html), place ```glfw-3.2.1.bin.WIN32``` inside of the ```glfw-3.2.1``` folder
1. ```F5``` to compile.

#### Known Issues:

1. My camera code is janky as fuck. I'm not sure why it isn't working properly.
2. I'm in the process of writing the Transform component, the HazeCam component will be rewritten to use the Transform instead of storing it's own positions
3. There are a ton of warnings in the Vulkan code, I'm going to take the time at some point to clear those up.