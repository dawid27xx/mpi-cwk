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
1                       1                                                                                              
1                       2                                                                                                                                     
1                       4                                                                                                               
1                       8                                                                                              
2                       16                                                                                                                       
2                       32                                                                                                            

Please state the number of cores per machine (for Bragg 2.05, this is typically 12): 16

A brief interpretation of your results:

(1,1) = 0.00512395, 0.0051244,  0.00500122 => 
(1,2) = 0.00356875, 0.00367536, 0.00405483 =>
(1,4) = 0.00287683, 0.00272203, 0.00308394 =>
(1,8) = 0.00185082, 0.00226172, 0.00164343 =>
(2,8) = 
(2,16) = 

