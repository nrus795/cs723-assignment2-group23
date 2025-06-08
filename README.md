# cs723-assignment2-group23
Created by Nicholas Russell and Corban Ellison for the COMPSYS 732 Assignment 2 group project.
## Instructions to use the program:

Requires Esterel complier to be installed, along with gcc and make, for compiling the xes file.

To compile the program, ensure the included Makefile, cruiseControl.strl, ctypes.c, cruiseControl_data.c, and cruiseControl.h files are in the same directory.

Then in a terminal in that directory, run the following:
```{.sh}
make cruiseControl.xes
```
This will generate the cruiseControl.xes file, provided the requirements above are satisfied. Please ignore any and all warnings.

To open the generated simulator, either open the generated .exe file that was created alongside the .xes, or run the following in the same terminal:
```{.shell}
./cruiseControl.xes
```
Results may vary based on terminal shell used.

The same can be done for the validation xev file, by ruinning:
```{.shell}
make cruiseControl.xev
./cruiseControl.xev
```

## Bugs
If the compiled program fails to open, please review whether the files are marked as executable. To modify this on Linux, run the following commands:
```{.shell}
chmod +x cruiseControl.xes
chmod +x cruiseControl.exe
```
This will resolve the permission denied error if it occurs.