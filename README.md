<br />
<div align="center">
  <h1 align="center">Microprocessors And Peripherals Assignment 1</h1>
  <h3 align="center">Aristotle University of Thessaloniki</h3>
  <h4 align="center">School of Electrical & Computer Engineering</h4>
  <p align="center">
    Contributors: Nikolaos Giannopoulos, <??>
    <br />
    Spring Semester 2021 - 2022
    <br />
    <br />
  </p>
</div>
<br />

- [1. Code philosophy](#1-code-philosophy)
- [2. Problems](#2-problems)
- [3. Testing](#3-testing)


# 1. Code philosophy 

The code based on the [main.c](https://github.com/NikolaosGian/MicroprocessorsAndPeripherals_1/blob/main/src/main.c) file written was based on the ASCII table to allow us to ignore lowercase Latin ,symbols. <br />
  <img src="https://github.com/NikolaosGian/MicroprocessorsAndPeripherals_1/blob/main/image/asciifull.gif"> <br />
  
  Figure 1 shows the `ASCII` table which in this paper/lab we used as a first check if the input to our routine by taking the `1byte` in register `r4` is `NUL` i.e. an empty alphanumeric if it is true then we go to the `EXIT` label and terminate our routine. Then we check if it is less than the decimal equivalent of `/` if true then we go to label `LOOP` and get the next byte otherwise we then check if it is less than the character `:` if it is then we go to label `START` otherwise if it is not less we go to the next check and see if it is greater than the character `@` if true then we go to label `START` otherwise again we go to label `LOOP` and get the next byte i.e. we ensure that if it is a symbol `: ? < = > ? @` then we ignore it and go to the next one. When we are inside after label `START` then we check if the character is greater than the symbol `[` if true then we go to label `LOOP` to get the next byte. Otherwise if it is not true then the whole process of checking the alphanumeric and converting it based on the `Hash table` of the task starts. Finally when we find the `EXIT` label then we write the final result from register `r5` to the memory location of `r1` which is the second argument of the function returning the value. <br />
  

<img src="https://github.com/NikolaosGian/MicroprocessorsAndPeripherals_1/blob/main/image/hashTable.PNG"> <br />
  
  
# 2. Problems
The main problem was the missing indication of the Keil tool as there were problems in the compile that required compiler version 5.The other issue was the white spaces where we were not given any help but had to find it ourselves as the tool did not clarify where there was a problem in the gaps.

# 3. Testing


The testing was done by giving values for each control mentioned above to verify its correct operation. We then tested the example given in the lab pdf i.e. value = "σAr, PE 2!" and we got the result of 66 as it should be.




