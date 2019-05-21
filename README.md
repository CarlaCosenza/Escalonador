# Escalonador
Operational Systems project

The objective of this project is to develop a process scheduler that prioritizes two queues. The first queue, q0, uses Round Robin with quantum 10 and is the one with the highest priority while the second queue, q1, uses FCFS and has the lowest priority. There is also an IO processor that has its own queue and executes one process each time. All IO executions last 20ms and every burst of a process has the same duration, which is given as an input along with the number of IOs. If a process stops execution because of the quantum time, it is transfered to the end of q1. If a process waits more than 25ms in q1, it is transfered to q0.

In order to execute the program, it is necessary to compile all the files. Use the command:

g++ processo.cpp fila.cpp roundRobin.cpp FCFS.cpp inputOutput.cpp escalonador.cpp main.cpp 

It is also necessary to have the header <bits/stdc++.h> for execution. 
