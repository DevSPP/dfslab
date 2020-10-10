"""
Name : SUBRAT PRASAD PANDA
Roll number : CS1913
Date : 12/12/2019
Program description : ASSIGNMENT 4, Question 1- Replacing delimiters to a particular delimiters
Acknowledgements : Python documentation website, Geeksforgeeks, stackoverflow
"""

import sys
import re
import collections

# 0 Checking if valid commandline argument is provided or not
if len(sys.argv) != 3:
    print("Please Enter input and output file")
    sys.exit(1)

# 0 Reading the file data to input_data
fp = open(sys.argv[1], "r")
input_data = fp.read()
fp.close()
if not input_data:
    print("File Empty")
    sys.exit(1)
""" -------------LOGIC---------------
    1. Find list of all the used delimiters (repeated delimiters case considered eg: 23,,4,,45) using "re.split".
    2. Find frequency of all delimiters using ".Counter".
    3. Find the maximal occurring delimiter using ".most_common()".
    4. If there are more than one maximum, then exit with printing "CONFUSING".
    5. Replace all delimiters with the maximal delimiters using ".join()".
----------------------------------------"""

# 1. Making the LIST of all used delimiters
delimiters = re.split('[^\t,;|‘’“”{}/\\ ]+', input_data)  # Particular delimiters are used which were given in
# question eg: ['/' , '|' , ',']
delimiters = list(filter(None, delimiters))  # Filter out invalid(null) delimiters
if len(delimiters) == 0:  # if no delimiters were used in the input file, copy same data to output file
    print("No delimiters Used in input file")
    fp = open(sys.argv[2], 'w')
    fp.write(input_data)  # Write to file
    fp.close()
    sys.exit(1)

# 2 and 3. Finding maximal occurring delimiter
frequency = collections.Counter(delimiters)
max_freq = frequency.most_common(1)[0][1]

# 4. Exit with printing confusing
if list(frequency.values()).count(max_freq) > 1:
    print("CONFUSING")
    sys.exit(1)

# 5. Replacing all the delimiters with correct delimiters
correct_delimiter = frequency.most_common(1)[0][0]
output_string = correct_delimiter.join(
    re.split('[\t,;|‘’“”{}/\\ ]+', input_data))
# Write to file
fp = open(sys.argv[2], 'w')
fp.write(output_string)
fp.close()
