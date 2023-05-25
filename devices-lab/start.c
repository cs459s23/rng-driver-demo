// entry.S needs one stack per CPU.
__attribute__ ((aligned (16))) char stack0[4096];

void start() {
    // Your code here
    while(1);  // A simple infinite loop
}
