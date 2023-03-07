using System;
namespace Tareas{
    internal class Tareas{
        public static void Main(string[] args){
            int[] values = {5,2,10,1,8,12,7,3};
            Console.WriteLine("Suma EREW \n "+sumaEREW(values));
            
            values =new int[] {5,2,10,1,8,12,7,3};
            Console.WriteLine("Suma CREW \n"+sumaCREW(values));

            double[] value = new double[] {2,-1,23,-4,2,5,-2,0,5,1,5,-5,8,5,3,-2};
            Console.WriteLine("busqueda EREW \n"+busquedaEREW(value, -2));
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

        // BUSQUEDA EREW

        public static int busquedaEREW(double[] values, double target){
            double[] temp = new double[values.Length];
            broadcast(temp, target);
            Console.WriteLine("Comparacion");
            Parallel.For(0, values.Length, i =>{
                if (values[i] == target) temp[i] = i;
                else temp[i] = Double.PositiveInfinity;
            });
            for(int j = 0; j<temp.Length; j++){
                Console.Write(temp[j]+"\t");
            }
            Console.Write('\n');

            return minimo(temp);
        }

        private static void broadcast(double[] temp, double target){
            temp[0] = target;
            Console.WriteLine("Broadcast");
            for (int i = 1; i< Math.Log2(temp.Length)+1; i++){
                Parallel.For((int)Math.Pow(2, i-1), (int)Math.Pow(2,i), j =>{
                    temp[j] = temp[j-(int)Math.Pow(2, i-1)];
                });
                for(int j = 0; j<temp.Length; j++){
                    Console.Write(temp[j]+"\t");
                }
                Console.Write('\n');
            }
        }

        private static int minimo(double[] temp){
            Console.WriteLine("Minimo");
            double[] readTemp = new double[temp.Length];
            
            for(int j =1; j < Math.Log2(temp.Length)+1; j++){
                Parallel.For(0, temp.Length, i =>{
                    readTemp[i] = temp[i];
                });
                int expJ = (int)Math.Pow(2,j);
                Parallel.For(1,(temp.Length/expJ)+1, i =>{
                    int expI = (2*i)-1;
                    temp[i-1] = (readTemp[expI-1] > readTemp[expI])? readTemp[expI]:readTemp[expI-1];
                });
                for(int k = 0; k<temp.Length; k++){
                    Console.Write(temp[k]+"\t");
                }
                Console.Write("\n\n");
            }
            return (int)temp[0];
        }
    }
}