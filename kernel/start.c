// entry.S needs one stack per CPU.
__attribute__ ((aligned (16))) char stack0[4096];

#define RNG_DEVICE_ADDRESS 0x4200100

// entry.S jumps here in machine mode on stack0.
void
start()
{
  while (1) {
    volatile int x = *((int*) RNG_DEVICE_ADDRESS);
    (void) x;
  }
}
