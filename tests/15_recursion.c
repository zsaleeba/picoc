int fact(int i) {
   if (i < 2) {
       return i;
   }
   return (i * fact(i - 1));
}

fact(5)
fact(6)

