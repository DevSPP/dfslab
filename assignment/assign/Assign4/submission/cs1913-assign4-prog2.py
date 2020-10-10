"""
Name : SUBRAT PRASAD PANDA
Roll number : CS1913
Date : 12/12/2019
Program description : ASSIGNMENT 4, Question 2- Phone number lookup using TRIE
Acknowledgements : TRIE code from DFSLAB 2019 webpage ISI Kolkata, Python documentation website, Geeksforgeeks, stackoverflow
"""

import sys


# --------------- Trie Functions---------------
def insert_num(trie, num, name):
    current_node = trie
    for c in num.lower():
        if c not in current_node:  # c is not a key in this dictionary
            new_node = [{}, set([name])]  # Set is used to ignore repeated elements
            current_node[c] = new_node
            current_node = new_node[0]
        else:
            current_node[c][1].add(name)
            current_node = current_node[c][0]
    current_node['flag'] = True


def search(trie, s):
    current_node = trie
    for c in s.lower():
        if 'flag' in current_node is ['flag']:
            return False
        if c not in current_node:
            return False
        else:
            output_list = current_node[c][1]
            current_node = current_node[c][0]
    return list(output_list)  # List is sent to main


# ---------------- Main Program----------------
""" -------------LOGIC---------------
    1. Keep Inserting the data into TRIE 
    (eg: for a number (xyz, 1234) >> 1234, 234, 34 and 4 will be entered to the trie under the name xyz)
    2. Search operation on TRIE.
    3. Each node in TRIE have list of names which are valid outputs
----------------------------------------"""

# 0 Checking if valid commandline argument is provided or not
if len(sys.argv) != 3:
    print("Please Enter input file and search string")
    sys.exit(1)
file_name = sys.argv[1]
search_num = sys.argv[2]

# 0 Initialization of trie and input_data
input_data = {}
trie = {}

# 1. Inserting data to input_data and also to the TRIE
with open(file_name) as fp:  # no need of fp.close()
    next(fp)  # To skip the first line
    for line in fp:
        temp = line.rsplit(maxsplit=1)  # Split from right side with name and number
        input_data.update({temp[0]: temp[1]})  # Update data to input_data dictionary
        for i, c in enumerate(temp[1]):  # Inserting number into the TRIE(eg for 9934 >> 9934, 934, 34, 3 entered)
            insert_num(trie, temp[1][i:], temp[0])

# 2. Search operation in TRIE using search string
output = search(trie, search_num)
if output:
    output.sort()
    for name in output:
        print(f"{name} {input_data[name]}")
else:
    print(" ")
