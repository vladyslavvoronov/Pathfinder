# Pathfinder

    Implementation of the algorithm for finding short and alternative paths

## Building the program
1. Download/Clone the source code
2. `/cd` into the root directory
3. Run `./make all`
4. Run `./pathfinder [file]`

As input arguments, the utility accepts a text file with the instruction:

```
4
One-Two,1
Zero-Eight,8
Two-Zero,2
```
- 4 - is number of islands
- 1,8,2 - distance, from island to island

## Result
``` 
========================================
Path: One -> Two
Route: One -> Two
Distance: 1
========================================
========================================
Path: One -> Zero
Route: One -> Two -> Zero
Distance: 1 + 2 = 3
========================================
========================================
Path: One -> Eight
Route: One -> Two -> Zero -> Eight
Distance: 1 + 2 + 8 = 11
========================================
========================================
Path: Two -> Zero
Route: Two -> Zero
Distance: 2
========================================
========================================
Path: Two -> Eight
Route: Two -> Zero -> Eight
Distance: 2 + 8 = 10
========================================
========================================
Path: Zero -> Eight
Route: Zero -> Eight
Distance: 8
========================================

```