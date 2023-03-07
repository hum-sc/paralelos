using System;
namespace Tasks{
    internal class Tasks{
        public static void Main(string[] args){
            int[] values = {5,2,10,1,8,12,7,3};
            //Console.WriteLine("Suma EREW \n "+sumaEREW(values));
            values =new int[] {5,2,10,1,8,12,7,3};
            Console.WriteLine("Suma CREW \n"+sumaCREW(values));
        }
        public static int sumaEREW(int[]values){
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

        public static int sumaCREW(int[] values){
            for(int k = 0; k<values.Length; k++){
                Console.Write(values[k]+"\t");
            }
            Console.Write("\n\n");

            int procesadores = values.Length/2;

           
            int i = 1;
            while(procesadores > 0){
                int[] readValues =new int[values.Length];
                int exponente = (int)Math.Pow(2, i-1);
              
                Parallel.ForEach(values, (value,state, index) => {
                    readValues[index] = value;
                });

                Parallel.For(exponente,values.Length,j =>{
                    values[j]=readValues[j]+readValues[j-exponente];
                });
                 for(int k = 0; k< values.Length; k++){
                    Console.Write(values[k]+"\t");
                    }
                Console.Write("\n\n");
                procesadores/=2;
                i++;
            }
            return values[values.Length-1];
        }
    }
}