# OS_Scheduling_Algorithms_in_C++
Operating systems (OS) use scheduling algorithms to efficiently allocate resources, such as CPU time, among competing processes. There are several types of scheduling algorithms, including:

1. First-Come, First-Served (FCFS): This is the simplest scheduling algorithm where processes are executed in the order in which they arrive. The first process that enters the ready queue is the first to be executed.

2. Shortest Job First (SJF): This algorithm prioritizes the process with the shortest estimated execution time. It can be either preemptive or non-preemptive. In the preemptive version, a process with a shorter estimated time left can interrupt the currently running process.

3. Longest Job First (LJF): This algorithm prioritizes the process with the longest estimated execution time. It can be either preemptive or non-preemptive. In the preemptive version, a process with a longer estimated time left can interrupt the currently running process.

4. Priority Scheduling: Processes are assigned a priority based on their importance. The priority can be set by the user or by the system itself. Higher priority processes are executed first.

5. Highest Response Ratio Next (HRRN): This is a variant of SJF that takes into account both the length of the job and the amount of time it has already waited. The process with the highest response ratio (which is the ratio of waiting time to estimated service time) is executed first.

Sample outputs :-

<img width="900" alt="image" src="https://user-images.githubusercontent.com/92025482/223118863-cef2395c-0262-439c-9d16-39aa815f7c20.png">

<img width="886" alt="image" src="https://user-images.githubusercontent.com/92025482/223119423-6fee2d40-7a51-44f5-b549-1a1adbbfca4a.png">
