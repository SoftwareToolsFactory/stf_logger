# Software Tools Factory - Logger
Simple Logger that looks and feels like cout, supports colors and is simlilar to Android Log :)

### Platforms
 * Windows

### Concept
1. Simple to use as ***<span style="color:blue">std::cout</span>***
2. Colors support - Love colors on output
3. ostream manips must work this same way as they work on cout
---
To make usage as simple as ***<span style="color:blue">std::cout</span>***, there is global Log defined called ***<span style="color:blue">stf::theLog</span>***, and usage is exacly this same as for ***<span style="color:blue">std::cout</span>*** for example
```c++
    stf::theLog.i << "This is info message" << std::endl;
```
Class Log is a container for Logger classes. For each serverity (debug/info/warning/error), it contains
single Logger, named of first letter of serverity - like in Android [Log](https://developer.android.com/reference/android/util/Log) :smile:<br>

As this moment, ostring manips, that work on ***<span style="color:blue">std::cout</span>***, should also work with Logger, as manip is passed down to ***<span style="color:blue">std::cout</span>***<br>

### Dir struct

```
|- bin 
|  `- <platform>-<configuration>
|
|- include
|  `- stf_logger
|
|- src
|  |- stf_logger
|  `- sandbox
|
`- tmp
   `- <platform>
      ` - <project_name>
          `- <platform>-<configuration>
```
***bin*** - lib/exe and pdb files end up here colected per platform<br>
***include/stf_logger*** - library include files<br>
***src/stf_logger*** - libaray source code (may contain local headers)<br>
***src/sandbox*** - code for test (may contain local headers)<br>
***tmp*** - intermediete files, that are created in process of compilation

### TODO:
- [ ] Log - store Loggers as shared_ptr: will be needed for registry
- [X] Log and Logger must have names: will be needed for registry
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

- [ ] Move to cmake ? ( that would be a bit of overkill :confused: )