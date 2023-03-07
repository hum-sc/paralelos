namespace SumaEREW
{
    internal class SumaEREW
    {
        static void Main(string[] args)
        {
            int[] values = {5,2,10,1,8,12,7,3};
            int result = sumaEREW(values);
            Console.WriteLine(result);
        }

        private static int sumaEREW(int[] values){
            //TODO: algo
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