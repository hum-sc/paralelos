using System;
using System.Threading.Tasks;
namespace Program
{
    internal class Programa
    {
        static void Main(string[] args)
        {
            sumaERW(4294967296);
        }

        private static int sumaERW(long n){
            //TODO: algo

            for(int i = 0; i<=n; i++ ){
                Task.Factory.StartNew(() =>{
                    Console.WriteLine("HelloWorld");
                }
                );
            }
            Console.WriteLine("Acabo");
            return 0;
        }


    }
}