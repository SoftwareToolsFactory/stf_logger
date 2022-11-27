# Software Tools Factory - Logger
Simple Logger that looks and feels like cout, supports colors and is simlilar to Android Log :)

### Platforms
 * Windows
 * Linux
 * Cygwin

### Build and Run
##### Windows
*.sln file + .vcxproj have everything that is needed to run/debug library

##### Linux & Cygwin
There are 3 build scripts:
```
./build.sh
./src/build.sh
./sandbox/build.sh
```
**./build.sh** - Calls other **build.sh** located in project directories.<br>
**src/build.sh** and **sandbox/build.sh** - can also be called directly to just buid single project<br>
**./run.sh** - this script can run linux and cygwin executable, script contains small pice of code that recognizes on what enviroment it's running.

### Concept
1. Simple to use as ***<span style="color:blue">std::cout</span>***
2. Colors support - I :heart_eyes: colors on output, evey one loves colors
3. ostream manips must work this same way as they work on cout
---
To make usage as simple as using ***<span style="color:blue">std::cout</span>***, there is global Log defined called ***<span style="color:blue">stf::theLog</span>***, and usage is exacly this same as for ***<span style="color:blue">std::cout</span>*** for example
```c++
    stf::theLog.i << "This is info message" << std::endl;
```
Class Log is a container for Logger classes. For each serverity (debug/info/warning/error), it contains
single Logger, named of first letter of serverity - like in Android [Log](https://developer.android.com/reference/android/util/Log) :smile:<br>

### Dir struct

```
|- bin 
|  `- <platform><architecture>_<configuration>
|
|- include
|- sandbox
|- src
`- tmp
   `- <platform><architecture>_<configuration>
      ` - <project_name>
```
***bin*** - lib/exe and pdb files end up here colected per platform<br>
***include*** - library public include files<br>
***sandbox*** - code for test and develop (may contain local headers)<br>
***src*** - libaray source code (may contain local/private headers)<br>
***tmp*** - intermediete files, that are created in process of compilation organized per platform

Personaly I find such structure easy to manage, cross platform and obvius to any one who see it for first time.

### .vcxproj config
To make this repo *submodule ready* prjects are configured with assumption that main project solution file will be located in root folder of project.<br>
- bin/lib/tmp is writen relative to ***$(SolutionDir)***<br>
```
$(SolutionDir)bin\win$(PlatformArchitecture)_$(Configuration)\
```
- additional include files are relative to ***$(ProjectDir)***
```
$(ProjectDir)..\include;
```

This way, after adding project as submodule structure of directories will look like this:
```
|- bin 
|  `- <platform><architecture>_<configuration>
|
|- @stf_logger
|  `- include
|  |- sandbox
|  `- src
|
`- tmp
   `- <platform><architecture>_<configuration>
      ` - <project_name>
```

### TODO:
- [ ] Log - store Loggers as shared_ptr: will be needed for registry
- [ ] Log/Logger registry
- [ ] Log sink support - so we can define for example file, attached per logger
- [ ] Log builder (Java like) so we can define Log with own loggers, instead of encapsulated ones
- [ ] Linux support
- [ ] Formating - something like (should format contain/accept endl?)
```c++
    stf::theSys.i.format << stf::cyellow << "[INFO]" << stf::cgeen << stf::logtime(std::chrono::std::chrono::system_clock) << stf::creset << "] " << stf::logmsgbody
```
Sample call later:<br>
```c++
    stf::theSys.i << "Sample message" << endl;<br>
```
Should output to console:<br>
<span style="background-color: black">
<span style="color:yellow;">[INFO]</span><span style="color:green;">[15:30:01]</span> <span style="color:white;">Sample message</span>

- [ ] Move to cmake ? ( that would be a bit of overkill / I hate cmake :confused: )