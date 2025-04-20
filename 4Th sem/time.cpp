#include <stdio.h>
#include <time.h>
void take_enter() {
   printf("Press enter to stop the counter ");
   while(1) {
      if (getchar())
      break;
   }
}
main() {
   // Calculate the time taken by take_enter()
   clock_t s,e;
   s = clock();
   printf("Timer starts");
   take_enter();
   printf("Timer ends ");
   e = clock() ;
   double time_taken=e-s;
   time_taken = ((double)time_taken)/CLOCKS_PER_SEC; // calculate the elapsed time
   printf("The program took %f seconds to execute", time_taken);
}
