# SP03
 


# Basic Statistics Program

This program calculates basic statistical measures such as minimum, maximum, mean, median, standard deviation, and sum for a given dataset. The dataset is provided in a text file, with one floating-point number per line.

## How to Run the Program

### 1. Ensure You Have GCC Installed  
Check if GCC (GNU Compiler Collection) is installed on your system. Run:
bash: gcc --version

If not installed, follow the installation instructions for your operating system.



### 2. Open a Terminal and Navigate to the Project Directory  
In your terminal, navigate to the directory where you saved the program files (`basicstats.c`, `small.txt`, and `large.txt`):
bash: cd /path/to/your/project/directory




### 3. Compile the Program  
Use the following GCC command to compile the source file. This will generate an executable named `basicstats`:
bash: gcc -o basicstats basicstats.c -lm


### 4. Prepare the Input File  
Ensure you have a text file with the input data. The file should contain one floating-point number per line. For example:

123.45
67.89
-12.34
45.67




### 5. Run the Program  
Execute the program by passing the input file as a command-line argument:
bash: ./basicstats small.txt

Replace `small.txt` with the name of your input file.



### 6. View the Results  
The program will output the following statistics:
- Number of values
- Minimum value
- Maximum value
- Mean (average)
- Median
- Standard deviation
- Sum
- Unused array capacity

Example output:

Results:
--------
Num values: 12
min: 0.3322
max: 311.6825
mean: 85.7762
median: 67.4698
stddev: 90.3804
sum: 1029.31
Unused array capacity: 8




### 7. Debugging with Valgrind
Run Valgrind: After installation, you can use Valgrind to debug your program:

bash: valgrind ./basicstats small.txt



