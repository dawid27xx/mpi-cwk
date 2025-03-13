Complete the table below with your results, and then fill in the final two sections at the end.

Please do not edit or remove table or section headings, as the autograder script uses these to
locate the start and end of the table.

Each row of the table will be split into columns using the Python "split()" method. Therefore,
- fill in each column with values;
- only use whitespace between columns;
- do not add any non-numeric characters (which would cause the value to be read as zero);
- do not worry if your columns are not perfectly aligned.

For the parallel speed-up S, please note that:
- the time you should use is already output by the provided code;
- take as the serial execution time the time output by the code when run with a single process.
  Hence, the speed-up for 1 process in the table below must be 1.00.


No. Machines:   Total No. Processes:     Mean time (average of 3 runs) in seconds:        Parallel speed-up, S:
=============   ====================     =========================================        =====================
1                       1                 0.00508                                          1.00                                                 
1                       2                 0.00377                                          1.34965                                                                                        
1                       4                 0.00289                                          1.75630                                                                  
1                       8                 0.00192                                          2.64935
2                       16                0.02434                                          0.20885                                                                           
2                       32                0.02439                                          0.20843                                                                

Please state the number of cores per machine (for Bragg 2.05, this is typically 12): 16

A brief interpretation of your results:

The speedup increased as the number of processes increased on a single machine.
However, introducing a second machine caused a drastic performance decrease,
likely due to the overhead of inter-machine communication. The performance remained rougly the same for 16 and 32 
processes indicating that the communication overhead vastly outweighed the increase in the number of processes. 








