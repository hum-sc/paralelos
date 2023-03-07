using System;
namespace Tasks{
    internal class Tasks{
        private static int sumaEREW(int[]values){
            int[] sums = values;
            for(int k = 0; k< values.Length; k++){
                Console.Write(values[k]+"\t");
            }
            Console.Write("\n\n");

            int procesadores =(int) values.Length/2;
            int i=1;
            
            while (procesadores > 0){
                Parallel.For(0, values.Length/2, j=>{
                    if(2*(j) % Math.Pow(2,i) == 0){
                        values[2*(j)] = values[2*(j)]+ values[(int)(2 *(j) + Math.Pow(2,(i-1)))];
                    }
                });

                for(int k = 0; k< values.Length; k++){
                    Console.Write(values[k]+"\t");
                }
                Console.Write("\n\n");
                i++;
                procesadores /= 2;
            }
            return values[0];
        }
    }
}