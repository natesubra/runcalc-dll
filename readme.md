# runcalc.dll

After mucking around trying to create a DLL to use for testing DLL Hijacks and testing RUNDLL32 exection I finally just wrote my own. There are plenty of things still on my todo list. But this is a start. A binary release is available but you __should build your own__. Pull requests welcome.

## Build Details

Last built in [Visual Studio Community 2017 v141](https://visualstudio.microsoft.com/vs/community/)

## Example Usage

I've included several methods of file execution. You can specify which to use by passing it to rundll32. If loaded without without specified function; dllmain will call the CreateProcess function.

* Run empty function. Used for testing DLL_PROCESS_ATTACH via rundll32, calls CreateProcess

   `rundll32.exe runcalc.dll,empty`

* Using _popen

   `rundll32.exe runcalc.dll,ex`

* Using WinExec

   `rundll32.exe runcalc.dll,we`

* Using system

   `rundll32.exe runcalc.dll,sys`

* Using ShellExecute

   `rundll32.exe runcalc.dll,se`

* Using CreateProcess

   `rundll32.exe runcalc.dll,cp`

## Todo

* Add example hijack usage
* add logic to link to correct library if handling hijack